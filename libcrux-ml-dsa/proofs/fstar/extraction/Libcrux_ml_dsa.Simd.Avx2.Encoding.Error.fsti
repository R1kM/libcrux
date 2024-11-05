module Libcrux_ml_dsa.Simd.Avx2.Encoding.Error
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let deserialize_to_unsigned_when_eta_is_2___COEFFICIENT_MASK: i32 = (1l <<! 3l <: i32) -! 1l

let deserialize_to_unsigned_when_eta_is_4___COEFFICIENT_MASK: i32 = (1l <<! 4l <: i32) -! 1l

let serialize_when_eta_is_2___ETA: i32 = 2l

let serialize_when_eta_is_4___ETA: i32 = 4l

val deserialize_to_unsigned_when_eta_is_2_ (bytes: t_Slice u8)
    : Prims.Pure u8 Prims.l_True (fun _ -> Prims.l_True)

val deserialize_to_unsigned_when_eta_is_4_ (bytes: t_Slice u8)
    : Prims.Pure u8 Prims.l_True (fun _ -> Prims.l_True)

val deserialize_to_unsigned (v_ETA: usize) (serialized: t_Slice u8)
    : Prims.Pure u8 Prims.l_True (fun _ -> Prims.l_True)

val deserialize (v_ETA: usize) (serialized: t_Slice u8)
    : Prims.Pure u8 Prims.l_True (fun _ -> Prims.l_True)

val serialize_when_eta_is_2_ (v_OUTPUT_SIZE: usize) (simd_unit: u8)
    : Prims.Pure (t_Array u8 v_OUTPUT_SIZE) Prims.l_True (fun _ -> Prims.l_True)

val serialize_when_eta_is_4_ (v_OUTPUT_SIZE: usize) (simd_unit: u8)
    : Prims.Pure (t_Array u8 v_OUTPUT_SIZE) Prims.l_True (fun _ -> Prims.l_True)

val serialize (v_OUTPUT_SIZE: usize) (simd_unit: u8)
    : Prims.Pure (t_Array u8 v_OUTPUT_SIZE) Prims.l_True (fun _ -> Prims.l_True)