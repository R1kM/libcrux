/*
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /home/karthik/eurydice/eurydice --config ../c.yaml
  -funroll-loops 16 ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc F*
  version: f09228ef KaRaMeL version: 42a43169
 */

#ifndef __libcrux_mlkem_avx2_H
#define __libcrux_mlkem_avx2_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"
#include "libcrux_mlkem_portable.h"
#include "libcrux_sha3.h"
#include "libcrux_sha3_avx2.h"

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_zero(void);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ZERO(
    void);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_from_i16_array(
    Eurydice_slice array);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___from_i16_array(
    Eurydice_slice array);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_arithmetic_add(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i rhs);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___add(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i *rhs);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_arithmetic_sub(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i rhs);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___sub(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i *rhs);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_multiply_by_constant(
    core_core_arch_x86___m256i vector, int16_t constant);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___multiply_by_constant(
    core_core_arch_x86___m256i v, int16_t c);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_bitwise_and_with_constant(
    core_core_arch_x86___m256i vector, int16_t constant);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___bitwise_and_with_constant(
    core_core_arch_x86___m256i vector, int16_t constant);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_cond_subtract_3329(
    core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___cond_subtract_3329(
    core_core_arch_x86___m256i vector);

#define LIBCRUX_ML_KEM_VECTOR_AVX2_ARITHMETIC_BARRETT_MULTIPLIER \
  ((int16_t)20159)

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_arithmetic_barrett_reduce(
    core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___barrett_reduce(
    core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constant(
    core_core_arch_x86___m256i vector, int16_t constant);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___montgomery_multiply_by_constant(
    core_core_arch_x86___m256i vector, int16_t constant);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_compress_message_coefficient(
    core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___compress_1(
    core_core_arch_x86___m256i vector);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_compress_mulhi_mm256_epi32(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i rhs);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_by_constants(
    core_core_arch_x86___m256i v, core_core_arch_x86___m256i c);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_1_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_1_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_2_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_2_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1);

core_core_arch_x86___m128i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_multiply_m128i_by_constants(
    core_core_arch_x86___m128i v, core_core_arch_x86___m128i c);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_ntt_layer_3_step(
    core_core_arch_x86___m256i vector, int16_t zeta);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_layer_3_step(
    core_core_arch_x86___m256i vector, int16_t zeta);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_1_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_1_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_2_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_2_step(
    core_core_arch_x86___m256i vector, int16_t zeta0, int16_t zeta1);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_inv_ntt_layer_3_step(
    core_core_arch_x86___m256i vector, int16_t zeta);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___inv_ntt_layer_3_step(
    core_core_arch_x86___m256i vector, int16_t zeta);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2_arithmetic_montgomery_reduce_i32s(
    core_core_arch_x86___m256i v);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_ntt_ntt_multiply(
    core_core_arch_x86___m256i lhs, core_core_arch_x86___m256i rhs,
    int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___ntt_multiply(
    core_core_arch_x86___m256i *lhs, core_core_arch_x86___m256i *rhs,
    int16_t zeta0, int16_t zeta1, int16_t zeta2, int16_t zeta3);

void libcrux_ml_kem_vector_avx2_serialize_serialize_1(
    core_core_arch_x86___m256i vector, uint8_t ret[2U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_1(
    core_core_arch_x86___m256i vector, uint8_t ret[2U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_1(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_1(
    Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_4(
    core_core_arch_x86___m256i vector, uint8_t ret[8U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_4(
    core_core_arch_x86___m256i vector, uint8_t ret[8U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_4(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_4(
    Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_5(
    core_core_arch_x86___m256i vector, uint8_t ret[10U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_5(
    core_core_arch_x86___m256i vector, uint8_t ret[10U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_5(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_5(
    Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_10(
    core_core_arch_x86___m256i vector, uint8_t ret[20U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_10(
    core_core_arch_x86___m256i vector, uint8_t ret[20U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_10(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_10(
    Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_to_i16_array(core_core_arch_x86___m256i v,
                                             int16_t ret[16U]);

typedef struct libcrux_ml_kem_vector_avx2_portable_PortableVector_s {
  int16_t elements[16U];
} libcrux_ml_kem_vector_avx2_portable_PortableVector;

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_from_i16_array(int16_t array[16U]);

void libcrux_ml_kem_vector_avx2_portable_serialize_11(
    libcrux_ml_kem_vector_avx2_portable_PortableVector v, uint8_t ret[22U]);

void libcrux_ml_kem_vector_avx2_serialize_serialize_11(
    core_core_arch_x86___m256i vector, uint8_t ret[22U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_11(
    core_core_arch_x86___m256i vector, uint8_t ret[22U]);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_zero(void);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable_deserialize_11(Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_portable_to_i16_array(
    libcrux_ml_kem_vector_avx2_portable_PortableVector v, int16_t ret[16U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_11(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_11(
    Eurydice_slice bytes);

void libcrux_ml_kem_vector_avx2_serialize_serialize_12(
    core_core_arch_x86___m256i vector, uint8_t ret[24U]);

void libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___serialize_12(
    core_core_arch_x86___m256i vector, uint8_t ret[24U]);

core_core_arch_x86___m256i libcrux_ml_kem_vector_avx2_serialize_deserialize_12(
    Eurydice_slice bytes);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___deserialize_12(
    Eurydice_slice bytes);

size_t libcrux_ml_kem_vector_avx2_sampling_rejection_sample(
    Eurydice_slice input, Eurydice_slice output);

size_t
libcrux_ml_kem_vector_avx2___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__avx2__SIMD256Vector___rej_sample(
    Eurydice_slice input, Eurydice_slice output);

libcrux_ml_kem_vector_avx2_portable_PortableVector
libcrux_ml_kem_vector_avx2_portable___core__clone__Clone_for_libcrux_ml_kem__vector__avx2__portable__PortableVector___clone(
    libcrux_ml_kem_vector_avx2_portable_PortableVector *self);

core_core_arch_x86___m256i
libcrux_ml_kem_vector_avx2___core__clone__Clone_for_libcrux_ml_kem__vector__avx2__SIMD256Vector__1__clone(
    core_core_arch_x86___m256i *self);

typedef struct
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector_s {
  core_core_arch_x86___m256i coefficients[16U];
} libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      secret_as_ntt[3U];
} libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      t_as_ntt[3U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      A[3U][3U];
} libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t_s {
  libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t
      private_key;
  libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t
      public_key;
} libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__3size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      secret_as_ntt[4U];
} libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      t_as_ntt[4U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      A[4U][4U];
} libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t_s {
  libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t
      private_key;
  libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t
      public_key;
} libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__4size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      secret_as_ntt[2U];
} libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t
      ind_cpa_private_key;
  uint8_t implicit_rejection_value[32U];
} libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      t_as_ntt[2U];
  uint8_t seed_for_A[32U];
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_avx2_SIMD256Vector
      A[2U][2U];
} libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t_s {
  libcrux_ml_kem_types_unpacked_IndCpaPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t
      ind_cpa_public_key;
  uint8_t public_key_hash[32U];
} libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t;

typedef struct
    libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t_s {
  libcrux_ml_kem_types_unpacked_MlKemPrivateKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t
      private_key;
  libcrux_ml_kem_types_unpacked_MlKemPublicKeyUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t
      public_key;
} libcrux_ml_kem_types_unpacked_MlKemKeyPairUnpacked__libcrux_ml_kem_vector_avx2_SIMD256Vector__2size_t;

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem_avx2_H_DEFINED
#endif