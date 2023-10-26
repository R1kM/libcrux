module Libcrux.Kem.Kyber.Compress
#set-options "--fuel 0 --ifuel 1 --z3rlimit 15"
open Core

let compress_q (#v_COEFFICIENT_BITS: usize) (fe: u16) : i32 =
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        if ~.(v_COEFFICIENT_BITS <=. sz 11 <: bool)
        then
          Rust_primitives.Hax.never_to_any (Core.Panicking.panic "assertion failed: COEFFICIENT_BITS <= 11"

              <:
              Rust_primitives.Hax.t_Never)
      in
      ()
  in
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        if ~.(fe <. 3329us <: bool)
        then
          Rust_primitives.Hax.never_to_any (Core.Panicking.panic "assertion failed: fe < 3329"
              <:
              Rust_primitives.Hax.t_Never)
      in
      ()
  in
  let compressed:u32 = (cast fe <: u32) <<! (v_COEFFICIENT_BITS +! sz 1 <: usize) in
  let compressed:u32 = compressed +! (cast Libcrux.Kem.Kyber.Constants.v_FIELD_MODULUS <: u32) in
  let compressed:u32 =
    compressed /! (cast (Libcrux.Kem.Kyber.Constants.v_FIELD_MODULUS <<! 1l <: i32) <: u32)
  in
  cast (compressed &. ((1ul <<! v_COEFFICIENT_BITS <: u32) -! 1ul <: u32)) <: i32

let compress
      (#v_COEFFICIENT_BITS: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    {
      re with
      Libcrux.Kem.Kyber.Arithmetic.f_coefficients
      =
      Core.Array.impl_23__map re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
        (fun coefficient ->
            compress_q (Libcrux.Kem.Kyber.Conversions.to_unsigned_representative coefficient <: u16)
            <:
            i32)
    }
  in
  re

let decompress_q (#v_COEFFICIENT_BITS: usize) (fe: i32) : i32 =
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        if ~.(v_COEFFICIENT_BITS <=. sz 11 <: bool)
        then
          Rust_primitives.Hax.never_to_any (Core.Panicking.panic "assertion failed: COEFFICIENT_BITS <= 11"

              <:
              Rust_primitives.Hax.t_Never)
      in
      ()
  in
  let _:Prims.unit =
    if true
    then
      let _:Prims.unit =
        if ~.((0l <=. fe <: bool) && (fe <. (1l <<! 11l <: i32) <: bool))
        then
          Rust_primitives.Hax.never_to_any (Core.Panicking.panic "assertion failed: 0 <= fe && fe < (1 << 11)"

              <:
              Rust_primitives.Hax.t_Never)
      in
      ()
  in
  let decompressed:u32 =
    (cast fe <: u32) *! (cast Libcrux.Kem.Kyber.Constants.v_FIELD_MODULUS <: u32)
  in
  let decompressed:u32 = (decompressed <<! 1l <: u32) +! (1ul <<! v_COEFFICIENT_BITS <: u32) in
  let decompressed:u32 = decompressed >>! (v_COEFFICIENT_BITS +! sz 1 <: usize) in
  cast decompressed <: i32

let decompress
      (#v_COEFFICIENT_BITS: usize)
      (re: Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement)
    : Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
  let re:Libcrux.Kem.Kyber.Arithmetic.t_KyberPolynomialRingElement =
    {
      re with
      Libcrux.Kem.Kyber.Arithmetic.f_coefficients
      =
      Core.Array.impl_23__map re.Libcrux.Kem.Kyber.Arithmetic.f_coefficients
        (fun coefficient -> decompress_q coefficient <: i32)
    }
  in
  re