module Libcrux_ml_kem.Mlkem512.Portable
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let validate_private_key
      (private_key: Libcrux_ml_kem.Types.t_MlKemPrivateKey (sz 1632))
      (ciphertext: Libcrux_ml_kem.Types.t_MlKemCiphertext (sz 768))
     =
  Libcrux_ml_kem.Ind_cca.Instantiations.Portable.validate_private_key (sz 2)
    (sz 1632)
    (sz 768)
    private_key
    ciphertext

let decapsulate
      (private_key: Libcrux_ml_kem.Types.t_MlKemPrivateKey (sz 1632))
      (ciphertext: Libcrux_ml_kem.Types.t_MlKemCiphertext (sz 768))
     =
  Libcrux_ml_kem.Ind_cca.Instantiations.Portable.decapsulate (sz 2) (sz 1632) (sz 768) (sz 800)
    (sz 768) (sz 768) (sz 640) (sz 128) (sz 10) (sz 4) (sz 320) (sz 3) (sz 192) (sz 2) (sz 128)
    (sz 800) private_key ciphertext

let encapsulate
      (public_key: Libcrux_ml_kem.Types.t_MlKemPublicKey (sz 800))
      (randomness: t_Array u8 (sz 32))
     =
  Libcrux_ml_kem.Ind_cca.Instantiations.Portable.encapsulate (sz 2) (sz 768) (sz 800) (sz 768)
    (sz 640) (sz 128) (sz 10) (sz 4) (sz 320) (sz 3) (sz 192) (sz 2) (sz 128) public_key randomness

let generate_key_pair (randomness: t_Array u8 (sz 64)) =
  Libcrux_ml_kem.Ind_cca.Instantiations.Portable.generate_keypair (sz 2)
    (sz 768)
    (sz 1632)
    (sz 800)
    (sz 768)
    (sz 3)
    (sz 192)
    randomness

let validate_public_key (public_key: Libcrux_ml_kem.Types.t_MlKemPublicKey (sz 800)) =
  Libcrux_ml_kem.Ind_cca.Instantiations.Portable.validate_public_key (sz 2)
    (sz 768)
    (sz 800)
    public_key.Libcrux_ml_kem.Types.f_value
