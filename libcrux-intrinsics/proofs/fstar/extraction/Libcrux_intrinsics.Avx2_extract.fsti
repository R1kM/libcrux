module Libcrux_intrinsics.Avx2_extract
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core
open FStar.Mul

unfold type t_Vec128 = bit_vec 128
     val vec128_as_i16x8 (x:t_Vec128) : t_Array i16 (sz 8)
     let get_lane128 (v:t_Vec128) (i:nat{i < 8}) =
       Seq.index (vec128_as_i16x8 v) i

unfold type t_Vec256 = bit_vec 256
     val vec256_as_i16x16 (x:t_Vec256) : t_Array i16 (sz 16)
     let get_lane (v:t_Vec256) (i:nat{i < 16}) =
       Seq.index (vec256_as_i16x16 v) i

val mm256_add_epi16 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result ==
          Spec.Utils.map2 ( +. ) (vec256_as_i16x16 lhs) (vec256_as_i16x16 rhs))

val mm256_add_epi32 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_and_si256 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result ==
          Spec.Utils.map2 ( &. ) (vec256_as_i16x16 lhs) (vec256_as_i16x16 rhs))

val mm256_andnot_si256 (a b: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_blend_epi16 (v_CONTROL: i32) (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_castsi128_si256 (vector: t_Vec128)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm256_castsi256_si128 = BitVec.Intrinsics.mm256_castsi256_si128

val mm256_cmpgt_epi16 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_cvtepi16_epi32 (vector: t_Vec128)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm256_extracti128_si256 = BitVec.Intrinsics.mm256_extracti128_si256

val mm256_inserti128_si256 (v_CONTROL: i32) (vector: t_Vec256) (vector_i128: t_Vec128)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_loadu_si256_i16 (input: t_Slice i16)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_loadu_si256_u8 (input: t_Slice u8)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_madd_epi16 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_mul_epu32 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_mulhi_epi16 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result ==
          Spec.Utils.map2 (fun x y -> cast (((cast x <: i32) *. (cast y <: i32)) >>! 16l) <: i16)
            (vec256_as_i16x16 lhs)
            (vec256_as_i16x16 rhs))

unfold let mm256_mullo_epi16 = BitVec.Intrinsics.mm256_mullo_epi16
     let lemma_mm256_mullo_epi16 v1 v2 :
        Lemma (vec256_as_i16x16 (mm256_mullo_epi16 v1 v2) == 
            Spec.Utils.map2 mul_mod (vec256_as_i16x16 v1) (vec256_as_i16x16 v2))
            [SMTPat (vec256_as_i16x16 (mm256_mullo_epi16 v1 v2))] = admit()

val mm256_mullo_epi32 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_packs_epi32 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_permute2x128_si256 (v_IMM8: i32) (a b: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_permute4x64_epi64 (v_CONTROL: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_permutevar8x32_epi32 (vector control: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_set1_epi16 (constant: i16)
    : Prims.Pure t_Vec256
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result == Spec.Utils.create (sz 16) constant)

val mm256_set1_epi32 (constant: i32) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_set1_epi64x (a: i64) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm256_set_epi16 = BitVec.Intrinsics.mm256_set_epi16
let lemma_mm256_set_epi16 v15 v14 v13 v12 v11 v10 v9 v8 v7 v6 v5 v4 v3 v2 v1 v0 :
    Lemma (vec256_as_i16x16 (mm256_set_epi16 v15 v14 v13 v12 v11 v10 v9 v8 v7 v6 v5 v4 v3 v2 v1 v0) == 
            Spec.Utils.create16 v0 v1 v2 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 v13 v14 v15)
            [SMTPat (vec256_as_i16x16 (mm256_set_epi16 v15 v14 v13 v12 v11 v10 v9 v8 v7 v6 v5 v4 v3 v2 v1 v0))] = admit()

val mm256_set_epi32 (input7 input6 input5 input4 input3 input2 input1 input0: i32)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_set_epi8
      (byte31 byte30 byte29 byte28 byte27 byte26 byte25 byte24 byte23 byte22 byte21 byte20 byte19 byte18 byte17 byte16 byte15 byte14 byte13 byte12 byte11 byte10 byte9 byte8 byte7 byte6 byte5 byte4 byte3 byte2 byte1 byte0:
          i8)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_setzero_si256: Prims.unit -> Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_shuffle_epi32 (v_CONTROL: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_shuffle_epi8 (vector control: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm256_slli_epi16 = BitVec.Intrinsics.mm256_slli_epi16

val mm256_slli_epi32 (v_SHIFT_BY: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_slli_epi64 (v_LEFT: i32) (x: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_sllv_epi32 (vector counts: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_srai_epi16 (v_SHIFT_BY: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256
      (requires v_SHIFT_BY >=. 0l && v_SHIFT_BY <. 16l)
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result ==
          Spec.Utils.map_array (fun x -> x >>! v_SHIFT_BY) (vec256_as_i16x16 vector))

val mm256_srai_epi32 (v_SHIFT_BY: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm256_srli_epi16 = BitVec.Intrinsics.mm256_srli_epi16

val mm256_srli_epi32 (v_SHIFT_BY: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_srli_epi64 (v_SHIFT_BY: i32) (vector: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_storeu_si256_i16 (output: t_Slice i16) (vector: t_Vec256)
    : Prims.Pure (t_Slice i16) Prims.l_True (fun _ -> Prims.l_True)

val mm256_storeu_si256_u8 (output: t_Slice u8) (vector: t_Vec256)
    : Prims.Pure (t_Slice u8) Prims.l_True (fun _ -> Prims.l_True)

val mm256_sub_epi16 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec256 = result in
          vec256_as_i16x16 result ==
          Spec.Utils.map2 ( -. ) (vec256_as_i16x16 lhs) (vec256_as_i16x16 rhs))

val mm256_unpackhi_epi32 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_unpackhi_epi64 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_unpacklo_epi32 (lhs rhs: t_Vec256)
    : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_unpacklo_epi64 (a b: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm256_xor_si256 (lhs rhs: t_Vec256) : Prims.Pure t_Vec256 Prims.l_True (fun _ -> Prims.l_True)

val mm_add_epi16 (lhs rhs: t_Vec128)
    : Prims.Pure t_Vec128
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec128 = result in
          vec128_as_i16x8 result ==
          Spec.Utils.map2 ( +. ) (vec128_as_i16x8 lhs) (vec128_as_i16x8 rhs))

val mm_loadu_si128 (input: t_Slice u8) : Prims.Pure t_Vec128 Prims.l_True (fun _ -> Prims.l_True)

unfold let mm_movemask_epi8 = BitVec.Intrinsics.mm_movemask_epi8

val mm_mulhi_epi16 (lhs rhs: t_Vec128)
    : Prims.Pure t_Vec128
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec128 = result in
          vec128_as_i16x8 result ==
          Spec.Utils.map2 (fun x y -> cast (((cast x <: i32) *. (cast y <: i32)) >>! 16l) <: i16)
            (vec128_as_i16x8 lhs)
            (vec128_as_i16x8 rhs))

val mm_mullo_epi16 (lhs rhs: t_Vec128)
    : Prims.Pure t_Vec128
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec128 = result in
          vec128_as_i16x8 result ==
          Spec.Utils.map2 mul_mod (vec128_as_i16x8 lhs) (vec128_as_i16x8 rhs))

unfold let mm_packs_epi16 = BitVec.Intrinsics.mm_packs_epi16

val mm_set1_epi16 (constant: i16)
    : Prims.Pure t_Vec128
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec128 = result in
          vec128_as_i16x8 result == Spec.Utils.create (sz 8) constant)

val mm_set_epi8
      (byte15 byte14 byte13 byte12 byte11 byte10 byte9 byte8 byte7 byte6 byte5 byte4 byte3 byte2 byte1 byte0:
          u8)
    : Prims.Pure t_Vec128 Prims.l_True (fun _ -> Prims.l_True)

val mm_shuffle_epi8 (vector control: t_Vec128)
    : Prims.Pure t_Vec128 Prims.l_True (fun _ -> Prims.l_True)

val mm_storeu_bytes_si128 (output: t_Slice u8) (vector: t_Vec128)
    : Prims.Pure (t_Slice u8) Prims.l_True (fun _ -> Prims.l_True)

val mm_storeu_si128 (output: t_Slice i16) (vector: t_Vec128)
    : Prims.Pure (t_Slice i16)
      Prims.l_True
      (ensures
        fun output_future ->
          let output_future:t_Slice i16 = output_future in
          (Core.Slice.impl__len #i16 output_future <: usize) =.
          (Core.Slice.impl__len #i16 output <: usize))

val mm_sub_epi16 (lhs rhs: t_Vec128)
    : Prims.Pure t_Vec128
      Prims.l_True
      (ensures
        fun result ->
          let result:t_Vec128 = result in
          vec128_as_i16x8 result ==
          Spec.Utils.map2 ( -. ) (vec128_as_i16x8 lhs) (vec128_as_i16x8 rhs))
