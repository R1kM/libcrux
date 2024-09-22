module Libcrux_ml_dsa.Encoding.Signature
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_dsa.Simd.Traits in
  ()

val impl__deserialize
      (#v_SIMDUnit: Type0)
      (v_COMMITMENT_HASH_SIZE v_COLUMNS_IN_A v_ROWS_IN_A v_GAMMA1_EXPONENT v_GAMMA1_RING_ELEMENT_SIZE v_MAX_ONES_IN_HINT v_SIGNATURE_SIZE:
          usize)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (serialized: t_Array u8 v_SIGNATURE_SIZE)
    : Prims.Pure
      (Core.Result.t_Result
          (Libcrux_ml_dsa.Ml_dsa_generic.t_Signature v_SIMDUnit
              v_COMMITMENT_HASH_SIZE
              v_COLUMNS_IN_A
              v_ROWS_IN_A) Libcrux_ml_dsa.Ml_dsa_generic.t_VerificationError)
      Prims.l_True
      (fun _ -> Prims.l_True)

val impl__serialize
      (#v_SIMDUnit: Type0)
      (v_COMMITMENT_HASH_SIZE v_COLUMNS_IN_A v_ROWS_IN_A v_GAMMA1_EXPONENT v_GAMMA1_RING_ELEMENT_SIZE v_MAX_ONES_IN_HINT v_SIGNATURE_SIZE:
          usize)
      {| i1: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (self:
          Libcrux_ml_dsa.Ml_dsa_generic.t_Signature v_SIMDUnit
            v_COMMITMENT_HASH_SIZE
            v_COLUMNS_IN_A
            v_ROWS_IN_A)
    : Prims.Pure (t_Array u8 v_SIGNATURE_SIZE) Prims.l_True (fun _ -> Prims.l_True)
