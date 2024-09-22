module Libcrux_ml_dsa.Ml_dsa_65_
#set-options "--fuel 0 --ifuel 1 --z3rlimit 100"
open Core
open FStar.Mul

let sign
      (signing_key: Libcrux_ml_dsa.Types.t_MLDSASigningKey (sz 4032))
      (message: t_Slice u8)
      (randomness: t_Array u8 (sz 32))
     =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.sign (sz 6) (sz 5) (sz 4) (sz 128) (sz 19) 261888l
    (sz 128) (sz 768) (sz 48) (sz 49) (sz 55) (sz 640) (sz 4032) (sz 3309)
    signing_key.Libcrux_ml_dsa.Types._0 message randomness

let verify
      (verification_key: Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (sz 1952))
      (message: t_Slice u8)
      (signature: Libcrux_ml_dsa.Types.t_MLDSASignature (sz 3309))
     =
  Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.verify (sz 6) (sz 5) (sz 3309) (sz 1952) (sz 19)
    (sz 640) 261888l 196l (sz 128) (sz 768) (sz 48) (sz 49) (sz 55)
    verification_key.Libcrux_ml_dsa.Types._0 message signature.Libcrux_ml_dsa.Types._0

let generate_key_pair (randomness: t_Array u8 (sz 32)) =
  let signing_key, verification_key:(t_Array u8 (sz 4032) & t_Array u8 (sz 1952)) =
    Libcrux_ml_dsa.Ml_dsa_generic.Multiplexing.generate_key_pair (sz 6)
      (sz 5)
      (sz 4)
      (sz 128)
      (sz 4032)
      (sz 1952)
      randomness
  in
  {
    Libcrux_ml_dsa.Types.f_signing_key
    =
    Libcrux_ml_dsa.Types.MLDSASigningKey signing_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSASigningKey (sz 4032);
    Libcrux_ml_dsa.Types.f_verification_key
    =
    Libcrux_ml_dsa.Types.MLDSAVerificationKey verification_key
    <:
    Libcrux_ml_dsa.Types.t_MLDSAVerificationKey (sz 1952)
  }
  <:
  Libcrux_ml_dsa.Types.t_MLDSAKeyPair (sz 1952) (sz 4032)
