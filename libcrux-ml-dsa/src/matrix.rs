use crate::{
    arithmetic::shift_left_then_reduce,
    constants::BITS_IN_LOWER_PART_OF_T,
    ntt::{invert_ntt_montgomery, ntt, ntt_multiply_montgomery},
    polynomial::SIMDPolynomialRingElement,
    sample::sample_ring_element_uniform,
    simd::traits::Operations,
};

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn expand_to_A<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    mut seed: [u8; 34],
) -> [[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A] {
    let mut A = [[SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); COLUMNS_IN_A]; ROWS_IN_A];

    // Mutable iterators won't go through hax, so we need these range loops.
    #[allow(clippy::needless_range_loop)]
    for i in 0..ROWS_IN_A {
        for j in 0..COLUMNS_IN_A {
            seed[32] = j as u8;
            seed[33] = i as u8;

            A[i][j] = sample_ring_element_uniform::<SIMDUnit>(seed);
        }
    }

    A
}

/// Compute InvertNTT(Â ◦ ŝ₁) + s₂
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_As1_plus_s2<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: &[[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    s1: &[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
    s2: &[SIMDPolynomialRingElement<SIMDUnit>; ROWS_IN_A],
) -> [SIMDPolynomialRingElement<SIMDUnit>; ROWS_IN_A] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); ROWS_IN_A];

    for (i, row) in A_as_ntt.iter().enumerate() {
        for (j, ring_element) in row.iter().enumerate() {
            let product =
                ntt_multiply_montgomery::<SIMDUnit>(ring_element, &ntt::<SIMDUnit>(s1[j]));
            result[i] = SIMDPolynomialRingElement::add(&result[i], &product);
        }

        result[i] = invert_ntt_montgomery::<SIMDUnit>(result[i]);
        result[i] = SIMDPolynomialRingElement::add(&result[i], &s2[i]);
    }

    result
}

/// Compute InvertNTT(Â ◦ ŷ)
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_A_times_mask<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: &[[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    mask: &[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
) -> [SIMDPolynomialRingElement<SIMDUnit>; ROWS_IN_A] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); ROWS_IN_A];

    for (i, row) in A_as_ntt.iter().enumerate() {
        for (j, ring_element) in row.iter().enumerate() {
            let product = ntt_multiply_montgomery(&ring_element, &ntt(mask[j]));
            result[i] = SIMDPolynomialRingElement::<SIMDUnit>::add(&result[i], &product);
        }

        result[i] = invert_ntt_montgomery(result[i]);
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn vector_times_ring_element<SIMDUnit: Operations, const DIMENSION: usize>(
    vector: &[SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    ring_element: &SIMDPolynomialRingElement<SIMDUnit>,
) -> [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for (i, vector_ring_element) in vector.iter().enumerate() {
        result[i] =
            invert_ntt_montgomery(ntt_multiply_montgomery(vector_ring_element, ring_element));
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn add_vectors<SIMDUnit: Operations, const DIMENSION: usize>(
    lhs: &[SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    rhs: &[SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        result[i] = SIMDPolynomialRingElement::<SIMDUnit>::add(&lhs[i], &rhs[i]);
    }

    result
}

#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn subtract_vectors<SIMDUnit: Operations, const DIMENSION: usize>(
    lhs: &[SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
    rhs: &[SIMDPolynomialRingElement<SIMDUnit>; DIMENSION],
) -> [SIMDPolynomialRingElement<SIMDUnit>; DIMENSION] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); DIMENSION];

    for i in 0..DIMENSION {
        result[i] = SIMDPolynomialRingElement::<SIMDUnit>::subtract(&lhs[i], &rhs[i]);
    }

    result
}

/// Compute InvertNTT(Â ◦ ẑ - ĉ ◦ NTT(t₁2ᵈ))
#[allow(non_snake_case)]
#[inline(always)]
pub(crate) fn compute_w_approx<
    SIMDUnit: Operations,
    const ROWS_IN_A: usize,
    const COLUMNS_IN_A: usize,
>(
    A_as_ntt: &[[SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A]; ROWS_IN_A],
    signer_response: [SIMDPolynomialRingElement<SIMDUnit>; COLUMNS_IN_A],
    verifier_challenge_as_ntt: SIMDPolynomialRingElement<SIMDUnit>,
    t1: [SIMDPolynomialRingElement<SIMDUnit>; ROWS_IN_A],
) -> [SIMDPolynomialRingElement<SIMDUnit>; ROWS_IN_A] {
    let mut result = [SIMDPolynomialRingElement::<SIMDUnit>::ZERO(); ROWS_IN_A];

    for (i, row) in A_as_ntt.iter().enumerate() {
        for (j, ring_element) in row.iter().enumerate() {
            let product = ntt_multiply_montgomery(&ring_element, &ntt(signer_response[j]));

            result[i] = SIMDPolynomialRingElement::<SIMDUnit>::add(&result[i], &product);
        }

        let t1_shifted = shift_left_then_reduce::<SIMDUnit>(t1[i], BITS_IN_LOWER_PART_OF_T);
        let challenge_times_t1_shifted =
            ntt_multiply_montgomery(&verifier_challenge_as_ntt, &ntt(t1_shifted));
        result[i] = invert_ntt_montgomery(SIMDPolynomialRingElement::<SIMDUnit>::subtract(
            &result[i],
            &challenge_times_t1_shifted,
        ));
    }

    result
}
