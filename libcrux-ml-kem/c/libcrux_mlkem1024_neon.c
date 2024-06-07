/*
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml
  ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc F* version: b5cb71b8 KaRaMeL
  version: 40e3a603
 */

#include "libcrux_mlkem1024_neon.h"

void libcrux_ml_kem_mlkem1024_neon_decapsulate(
    libcrux_ml_kem_types_MlKemPrivateKey____3168size_t *private_key,
    libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext *ciphertext,
    uint8_t ret[32U]) {
  uint8_t ret0[32U];
  libcrux_ml_kem_ind_cca_instantiations_neon_decapsulate___4size_t_3168size_t_1536size_t_1568size_t_1568size_t_1536size_t_1408size_t_160size_t_11size_t_5size_t_352size_t_2size_t_128size_t_2size_t_128size_t_1600size_t(
      private_key, ciphertext, ret0);
  memcpy(ret, ret0, (size_t)32U * sizeof(uint8_t));
}

K___libcrux_ml_kem_types_MlKemCiphertext___1568size_t___uint8_t_32size_t_
libcrux_ml_kem_mlkem1024_neon_encapsulate(
    libcrux_ml_kem_types_MlKemPublicKey____1568size_t *public_key,
    uint8_t randomness[32U]) {
  libcrux_ml_kem_types_MlKemPublicKey____1568size_t *uu____0 = public_key;
  uint8_t uu____1[32U];
  memcpy(uu____1, randomness, (size_t)32U * sizeof(uint8_t));
  return libcrux_ml_kem_ind_cca_instantiations_neon_encapsulate___4size_t_1568size_t_1568size_t_1536size_t_1408size_t_160size_t_11size_t_5size_t_352size_t_2size_t_128size_t_2size_t_128size_t(
      uu____0, uu____1);
}

libcrux_ml_kem_mlkem1024_MlKem1024KeyPair
libcrux_ml_kem_mlkem1024_neon_generate_key_pair(uint8_t randomness[64U]) {
  uint8_t uu____0[64U];
  memcpy(uu____0, randomness, (size_t)64U * sizeof(uint8_t));
  return libcrux_ml_kem_ind_cca_instantiations_neon_generate_keypair___4size_t_1536size_t_3168size_t_1568size_t_1536size_t_2size_t_128size_t(
      uu____0);
}

core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1568size_t__
libcrux_ml_kem_mlkem1024_neon_validate_public_key(
    libcrux_ml_kem_types_MlKemPublicKey____1568size_t public_key) {
  core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1568size_t__
      uu____0;
  if (libcrux_ml_kem_ind_cca_instantiations_neon_validate_public_key___4size_t_1536size_t_1568size_t(
          public_key.value)) {
    uu____0 = ((
        core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1568size_t__){
        .tag = core_option_Some, .f0 = public_key});
  } else {
    uu____0 = ((
        core_option_Option__libcrux_ml_kem_types_MlKemPublicKey___1568size_t__){
        .tag = core_option_None});
  }
  return uu____0;
}
