module Libcrux_ml_dsa.Ml_dsa_44_.Avx2
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let sign
      (signing_key: Libcrux_ml_dsa.Types.t_MLDSASigningKey (sz 2560))
      (message: t_Slice u8)
      (randomness: t_Array u8 (sz 32))
     =
  Libcrux_ml_dsa.Ml_dsa_generic.Instantiations.Avx2.sign (sz 4) (sz 4) (sz 2) (sz 96) (sz 17) 95232l
    (sz 192) (sz 768) (sz 32) (sz 39) (sz 80) (sz 576) (sz 2560) (sz 2420)
    signing_key.Libcrux_ml_dsa.Types._0 message randomness

let verify
      (verification_key: Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (sz 1312))
      (message: t_Slice u8)
      (signature: Libcrux_ml_dsa.Types.t_MLDSASignature (sz 2420))
     =
  Libcrux_ml_dsa.Ml_dsa_generic.Instantiations.Avx2.verify (sz 4) (sz 4) (sz 2420) (sz 1312) (sz 17)
    (sz 576) 95232l 78l (sz 192) (sz 768) (sz 32) (sz 39) (sz 80)
    verification_key.Libcrux_ml_dsa.Types._0 message signature.Libcrux_ml_dsa.Types._0

let generate_key_pair (randomness: t_Array u8 (sz 32)) =
  let signing_key, verification_key:(t_Array u8 (sz 2560) & t_Array u8 (sz 1312)) =
    Libcrux_ml_dsa.Ml_dsa_generic.Instantiations.Avx2.generate_key_pair (sz 4)
      (sz 4)
      (sz 2)
      (sz 96)
      (sz 2560)
      (sz 1312)
      randomness
  in
  {
    Libcrux_ml_dsa.Types.f_signing_key
    =
    Libcrux_ml_dsa.Types.MLDSASigningKey signing_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSASigningKey (sz 2560);
    Libcrux_ml_dsa.Types.f_verification_key
    =
    Libcrux_ml_dsa.Types.MLDSAVerificationKey verification_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (sz 1312)
  }
  <:
  Libcrux_ml_dsa.Types.t_MLDSAKeyPair (sz 1312) (sz 2560)
