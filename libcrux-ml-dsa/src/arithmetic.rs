use crate::{
    constants::COEFFICIENTS_IN_RING_ELEMENT,
    polynomial::{PolynomialRingElement, SIMDPolynomialRingElement, SIMD_UNITS_IN_RING_ELEMENT},
    simd::traits::Operations,
};

#[inline(always)]
pub(crate) fn vector_infinity_norm_exceeds<SIMDUnit: Operations, const DIMENSION: usize>(
    vector: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    bound: i32,
) -> bool {
    let mut exceeds = false;

    // TODO: We can break out of this loop early if need be, but the most
    // straightforward way to do so (returning false) will not go through hax;
    // revisit if performance is impacted.
    for ring_element in vector.iter() {
        exceeds |= ring_element.infinity_norm_exceeds(bound);
    }

    exceeds
}

/// If 'x' denotes a value of type `fe`, values having this type hold a
/// representative y ≡ x·MONTGOMERY_R (mod FIELD_MODULUS).
/// We use 'fer' as a shorthand for this type.
pub(crate) type FieldElementTimesMontgomeryR = i32;

#[inline(always)]
pub(crate) fn shift_left_then_reduce<SIMDUnit: Operations>(
    re: SIMDPolynomialRingElement<SIMDUnit>,
    shift_by: usize,
) -> SIMDPolynomialRingElement<SIMDUnit> {
    let mut out = SIMDPolynomialRingElement::ZERO();

    for (i, simd_unit) in re.simd_units.iter().enumerate() {
        out.simd_units[i] = SIMDUnit::shift_left_then_reduce(*simd_unit, shift_by);
    }

    out
}

#[inline(always)]
pub(crate) fn power2round_vector<SIMDUnit: Operations, const DIMENSION: usize>(
    t: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> (
    [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) {
    let mut t0 = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];
    let mut t1 = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for (i, ring_element) in t.iter().enumerate() {
        for (j, simd_unit) in ring_element.simd_units.iter().enumerate() {
            let (t0_unit, t1_unit) = SIMDUnit::power2round(*simd_unit);

            t0[i].simd_units[j] = t0_unit;
            t1[i].simd_units[j] = t1_unit;
        }
    }

    (t0, t1)
}

#[inline(always)]
pub(crate) fn decompose_vector<SIMDUnit: Operations, const DIMENSION: usize, const GAMMA2: i32>(
    t: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> (
    [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) {
    let mut vector_low = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];
    let mut vector_high = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        for j in 0..SIMD_UNITS_IN_RING_ELEMENT {
            let (low, high) = SIMDUnit::decompose::<GAMMA2>(t[i].simd_units[j]);

            vector_low[i].simd_units[j] = low;
            vector_high[i].simd_units[j] = high;
        }
    }

    (vector_low, vector_high)
}

#[inline(always)]
pub(crate) fn make_hint<SIMDUnit: Operations, const DIMENSION: usize, const GAMMA2: i32>(
    low: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    high: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> ([[i32; COEFFICIENTS_IN_RING_ELEMENT]; DIMENSION], usize) {
    let mut hint = [[0; COEFFICIENTS_IN_RING_ELEMENT]; DIMENSION];
    let mut true_hints = 0;

    for i in 0..DIMENSION {
        let mut v_hint = SIMDPolynomialRingElement::ZERO();

        for j in 0..v_hint.simd_units.len() {
            let (one_hints_count, current_hint) =
                SIMDUnit::compute_hint::<GAMMA2>(low[i].simd_units[j], high[i].simd_units[j]);
            v_hint.simd_units[j] = current_hint;

            true_hints += one_hints_count;
        }

        hint[i] = v_hint.to_polynomial_ring_element().coefficients;
    }

    (hint, true_hints)
}

#[inline(always)]
pub(crate) fn use_hint<SIMDUnit: Operations, const DIMENSION: usize, const GAMMA2: i32>(
    hint: [[i32; COEFFICIENTS_IN_RING_ELEMENT]; DIMENSION],
    re_vector: [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        let v_hint = SIMDPolynomialRingElement::<SIMDUnit>::from_polynomial_ring_element(
            PolynomialRingElement {
                coefficients: hint[i],
            },
        );

        for j in 0..SIMD_UNITS_IN_RING_ELEMENT {
            result[i].simd_units[j] =
                SIMDUnit::use_hint::<GAMMA2>(re_vector[i].simd_units[j], v_hint.simd_units[j]);
        }
    }

    result
}
