module Libcrux_ml_dsa.Simd.Avx2.Arithmetic
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let add (lhs rhs: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 lhs rhs

let compute_hint (v_GAMMA2: i32) (low high: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let gamma2:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 v_GAMMA2
  in
  let minus_gamma2:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (Core.Ops.Arith.Neg.neg v_GAMMA2 <: i32)
  in
  let low_within_bound:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_cmpgt_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_abs_epi32
          low
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
      gamma2
  in
  let low_equals_minus_gamma2:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_cmpeq_epi32 low minus_gamma2
  in
  let low_equals_minus_gamma2_and_high_is_nonzero:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sign_epi32 low_equals_minus_gamma2 high
  in
  let hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_or_si256 low_within_bound
      low_equals_minus_gamma2_and_high_is_nonzero
  in
  let hints_mask:i32 =
    Libcrux_intrinsics.Avx2_extract.mm256_movemask_ps (Libcrux_intrinsics.Avx2_extract.mm256_castsi256_ps
          hints
        <:
        u8)
  in
  (cast (Core.Num.impl__i32__count_ones hints_mask <: u32) <: usize),
  Libcrux_intrinsics.Avx2_extract.mm256_and_si256 hints
    (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 1l <: Libcrux_intrinsics.Avx2_extract.t_Vec256
    )
  <:
  (usize & Libcrux_intrinsics.Avx2_extract.t_Vec256)

let infinity_norm_exceeds (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256) (bound: i32) =
  let absolute_values:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_abs_epi32 simd_unit
  in
  let bound:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (bound -! 1l <: i32)
  in
  let compare_with_bound:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_cmpgt_epi32 absolute_values bound
  in
  let result:i32 =
    Libcrux_intrinsics.Avx2_extract.mm256_testz_si256 compare_with_bound compare_with_bound
  in
  if result =. 1l then false else true

let simd_multiply_i32_and_return_high (lhs rhs: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let prod02:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mul_epi32 lhs rhs
  in
  let prod13:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mul_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_shuffle_epi32
          245l
          lhs
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
      (Libcrux_intrinsics.Avx2_extract.mm256_shuffle_epi32 245l rhs
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  Libcrux_intrinsics.Avx2_extract.mm256_unpackhi_epi64 (Libcrux_intrinsics.Avx2_extract.mm256_unpacklo_epi32
        prod02
        prod13
      <:
      Libcrux_intrinsics.Avx2_extract.t_Vec256)
    (Libcrux_intrinsics.Avx2_extract.mm256_unpackhi_epi32 prod02 prod13
      <:
      Libcrux_intrinsics.Avx2_extract.t_Vec256)

let subtract (lhs rhs: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 lhs rhs

let shift_left_then_reduce (v_SHIFT_BY: i32) (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let shifted:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_slli_epi32 v_SHIFT_BY simd_unit
  in
  let quotient:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 shifted
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (1l <<! 22l <: i32)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let quotient:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 23l quotient
  in
  let quotient_times_field_modulus:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 quotient
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 shifted quotient_times_field_modulus

let to_unsigned_representatives (t: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let signs:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 31l t
  in
  let conditional_add_field_modulus:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_and_si256 signs
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 t conditional_add_field_modulus

let power2round (r: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let r:Libcrux_intrinsics.Avx2_extract.t_Vec256 = to_unsigned_representatives r in
  let r1:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 r
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 ((1l <<!
              (Libcrux_ml_dsa.Constants.v_BITS_IN_LOWER_PART_OF_T -! sz 1 <: usize)
              <:
              i32) -!
            1l
            <:
            i32)
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let r1:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 13l r1
  in
  let r0:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_slli_epi32 13l r1
  in
  let r0:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 r r0
  in
  r0, r1 <: (Libcrux_intrinsics.Avx2_extract.t_Vec256 & Libcrux_intrinsics.Avx2_extract.t_Vec256)

let montgomery_multiply (lhs rhs: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let field_modulus:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS
  in
  let inverse_of_modulus_mod_montgomery_r:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (cast (Libcrux_ml_dsa.Simd.Traits.v_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R
            <:
            u64)
        <:
        i32)
  in
  let product_low:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 lhs rhs
  in
  let k:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 product_low
      inverse_of_modulus_mod_montgomery_r
  in
  let c:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    simd_multiply_i32_and_return_high k field_modulus
  in
  let product_high:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    simd_multiply_i32_and_return_high lhs rhs
  in
  Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 product_high c

let montgomery_multiply_by_constant
      (simd_unit: Libcrux_intrinsics.Avx2_extract.t_Vec256)
      (constant: i32)
     =
  let constant:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 constant
  in
  let field_modulus:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS
  in
  let inverse_of_modulus_mod_montgomery_r:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (cast (Libcrux_ml_dsa.Simd.Traits.v_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R
            <:
            u64)
        <:
        i32)
  in
  let product_low:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 simd_unit constant
  in
  let k:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 product_low
      inverse_of_modulus_mod_montgomery_r
  in
  let c:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    simd_multiply_i32_and_return_high k field_modulus
  in
  let product_high:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    simd_multiply_i32_and_return_high simd_unit constant
  in
  Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 product_high c

let decompose (v_GAMMA2: i32) (r: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let r:Libcrux_intrinsics.Avx2_extract.t_Vec256 = to_unsigned_representatives r in
  let field_modulus_halved:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 ((Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS -!
          1l
          <:
          i32) /!
        2l
        <:
        i32)
  in
  let (v_ALPHA: i32):i32 = v_GAMMA2 *! 2l in
  let ceil_of_r_by_128_:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 r
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 127l
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let ceil_of_r_by_128_:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 7l ceil_of_r_by_128_
  in
  let r1:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    match v_ALPHA with
    | 190464l ->
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 ceil_of_r_by_128_
          (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 11275l
            <:
            Libcrux_intrinsics.Avx2_extract.t_Vec256)
      in
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 result
          (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (1l <<! 23l <: i32)
            <:
            Libcrux_intrinsics.Avx2_extract.t_Vec256)
      in
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 24l result
      in
      let mask:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32
              43l
            <:
            Libcrux_intrinsics.Avx2_extract.t_Vec256)
          result
      in
      let mask:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 31l mask
      in
      let not_result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_xor_si256 result mask
      in
      Libcrux_intrinsics.Avx2_extract.mm256_and_si256 result not_result
    | 523776l ->
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 ceil_of_r_by_128_
          (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 1025l
            <:
            Libcrux_intrinsics.Avx2_extract.t_Vec256)
      in
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 result
          (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 (1l <<! 21l <: i32)
            <:
            Libcrux_intrinsics.Avx2_extract.t_Vec256)
      in
      let result:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
        Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 22l result
      in
      Libcrux_intrinsics.Avx2_extract.mm256_and_si256 result
        (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 15l
          <:
          Libcrux_intrinsics.Avx2_extract.t_Vec256)
    | _ ->
      Rust_primitives.Hax.never_to_any (Core.Panicking.panic "internal error: entered unreachable code"

          <:
          Rust_primitives.Hax.t_Never)
  in
  let r0:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_mullo_epi32 r1
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 v_ALPHA
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let r0:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 r r0
  in
  let mask:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 field_modulus_halved r0
  in
  let mask:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_srai_epi32 31l mask
  in
  let field_modulus_and_mask:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_and_si256 mask
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 Libcrux_ml_dsa.Simd.Traits.v_FIELD_MODULUS
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  in
  let r0:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 r0 field_modulus_and_mask
  in
  r0, r1 <: (Libcrux_intrinsics.Avx2_extract.t_Vec256 & Libcrux_intrinsics.Avx2_extract.t_Vec256)

let use_hint (v_GAMMA2: i32) (r hint: Libcrux_intrinsics.Avx2_extract.t_Vec256) =
  let r0, r1:(Libcrux_intrinsics.Avx2_extract.t_Vec256 & Libcrux_intrinsics.Avx2_extract.t_Vec256) =
    decompose v_GAMMA2 r
  in
  let all_zeros:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_setzero_si256 ()
  in
  let negate_hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.vec256_blendv_epi32 all_zeros hint r0
  in
  let negate_hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_slli_epi32 1l negate_hints
  in
  let hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_sub_epi32 hint negate_hints
  in
  let r1_plus_hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
    Libcrux_intrinsics.Avx2_extract.mm256_add_epi32 r1 hints
  in
  match v_GAMMA2 with
  | 95232l ->
    let max:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 43l
    in
    let r1_plus_hints:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.vec256_blendv_epi32 r1_plus_hints max r1_plus_hints
    in
    let greater_than_or_equal_to_max:Libcrux_intrinsics.Avx2_extract.t_Vec256 =
      Libcrux_intrinsics.Avx2_extract.mm256_cmpgt_epi32 r1_plus_hints max
    in
    Libcrux_intrinsics.Avx2_extract.vec256_blendv_epi32 r1_plus_hints
      all_zeros
      greater_than_or_equal_to_max
  | 261888l ->
    Libcrux_intrinsics.Avx2_extract.mm256_and_si256 r1_plus_hints
      (Libcrux_intrinsics.Avx2_extract.mm256_set1_epi32 15l
        <:
        Libcrux_intrinsics.Avx2_extract.t_Vec256)
  | _ ->
    Rust_primitives.Hax.never_to_any (Core.Panicking.panic "internal error: entered unreachable code"

        <:
        Rust_primitives.Hax.t_Never)
