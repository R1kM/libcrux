module Libcrux_ml_kem.Types
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let impl_6__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let impl_13__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let impl_20__len (v_SIZE: usize) (_: Prims.unit) = v_SIZE

let impl_6__as_slice (v_SIZE: usize) (self: t_MlKemCiphertext v_SIZE) = self.f_value

let impl_13__as_slice (v_SIZE: usize) (self: t_MlKemPrivateKey v_SIZE) = self.f_value

let impl_20__as_slice (v_SIZE: usize) (self: t_MlKemPublicKey v_SIZE) = self.f_value

let impl_21__from
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (sk: t_MlKemPrivateKey v_PRIVATE_KEY_SIZE)
      (pk: t_MlKemPublicKey v_PUBLIC_KEY_SIZE)
     = { f_sk = sk; f_pk = pk } <: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE

let impl_21__into_parts
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
     =
  self.f_sk, self.f_pk
  <:
  (t_MlKemPrivateKey v_PRIVATE_KEY_SIZE & t_MlKemPublicKey v_PUBLIC_KEY_SIZE)

let impl_21__new
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (sk: t_Array u8 v_PRIVATE_KEY_SIZE)
      (pk: t_Array u8 v_PUBLIC_KEY_SIZE)
     =
  {
    f_sk
    =
    Core.Convert.f_into #(t_Array u8 v_PRIVATE_KEY_SIZE)
      #(t_MlKemPrivateKey v_PRIVATE_KEY_SIZE)
      #FStar.Tactics.Typeclasses.solve
      sk;
    f_pk
    =
    Core.Convert.f_into #(t_Array u8 v_PUBLIC_KEY_SIZE)
      #(t_MlKemPublicKey v_PUBLIC_KEY_SIZE)
      #FStar.Tactics.Typeclasses.solve
      pk
  }
  <:
  t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE

let impl_21__pk
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
     = impl_20__as_slice v_PUBLIC_KEY_SIZE self.f_pk

let impl_21__private_key
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
     = self.f_sk

let impl_21__public_key
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
     = self.f_pk

let impl_21__sk
      (v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE: usize)
      (self: t_MlKemKeyPair v_PRIVATE_KEY_SIZE v_PUBLIC_KEY_SIZE)
     = impl_13__as_slice v_PRIVATE_KEY_SIZE self.f_sk
