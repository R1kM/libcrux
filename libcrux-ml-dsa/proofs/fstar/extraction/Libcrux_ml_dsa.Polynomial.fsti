module Libcrux_ml_dsa.Polynomial
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let _ =
  (* This module has implicit dependencies, here we make them explicit. *)
  (* The implicit dependencies arise from typeclasses instances. *)
  let open Libcrux_ml_dsa.Simd.Traits in
  ()

let v_SIMD_UNITS_IN_RING_ELEMENT: usize =
  Libcrux_ml_dsa.Constants.v_COEFFICIENTS_IN_RING_ELEMENT /!
  Libcrux_ml_dsa.Simd.Traits.v_COEFFICIENTS_IN_SIMD_UNIT

type t_PolynomialRingElement
  (v_SIMDUnit: Type0) {| i1: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
  = { f_simd_units:t_Array v_SIMDUnit (sz 32) }

val impl__ZERO:
    #v_SIMDUnit: Type0 ->
    {| i1: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |} ->
    Prims.unit
  -> Prims.Pure (t_PolynomialRingElement v_SIMDUnit) Prims.l_True (fun _ -> Prims.l_True)

val impl__add
      (#v_SIMDUnit: Type0)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (self rhs: t_PolynomialRingElement v_SIMDUnit)
    : Prims.Pure (t_PolynomialRingElement v_SIMDUnit) Prims.l_True (fun _ -> Prims.l_True)

val impl__from_i32_array
      (#v_SIMDUnit: Type0)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (array: t_Slice i32)
    : Prims.Pure (t_PolynomialRingElement v_SIMDUnit) Prims.l_True (fun _ -> Prims.l_True)

val impl__infinity_norm_exceeds
      (#v_SIMDUnit: Type0)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (self: t_PolynomialRingElement v_SIMDUnit)
      (bound: i32)
    : Prims.Pure bool Prims.l_True (fun _ -> Prims.l_True)

val impl__subtract
      (#v_SIMDUnit: Type0)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (self rhs: t_PolynomialRingElement v_SIMDUnit)
    : Prims.Pure (t_PolynomialRingElement v_SIMDUnit) Prims.l_True (fun _ -> Prims.l_True)

val impl__to_i32_array
      (#v_SIMDUnit: Type0)
      {| i2: Libcrux_ml_dsa.Simd.Traits.t_Operations v_SIMDUnit |}
      (self: t_PolynomialRingElement v_SIMDUnit)
    : Prims.Pure (t_Array i32 (sz 256)) Prims.l_True (fun _ -> Prims.l_True)
