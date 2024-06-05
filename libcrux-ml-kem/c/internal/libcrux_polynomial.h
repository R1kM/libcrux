/*
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /home/franziskus/eurydice//eurydice --config ../c.yaml
  ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc F* version: <unknown>
  KaRaMeL version: 40e3a603
 */

#ifndef __internal_libcrux_polynomial_H
#define __internal_libcrux_polynomial_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "../libcrux_polynomial.h"
#include "eurydice_glue.h"
#include "internal/libcrux_core.h"

extern const int16_t libcrux_ml_kem_polynomial_ZETAS_TIMES_MONTGOMERY_R[128U];

#define LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR ((size_t)16U)

#define LIBCRUX_ML_KEM_POLYNOMIAL_VECTORS_IN_RING_ELEMENT  \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT / \
   LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_ELEMENTS_IN_VECTOR)

#define LIBCRUX_ML_KEM_VECTOR_TRAITS_FIELD_MODULUS ((int16_t)3329)

#define LIBCRUX_ML_KEM_VECTOR_TRAITS_MONTGOMERY_R_SQUARED_MOD_FIELD_MODULUS \
  ((int16_t)1353)

#define LIBCRUX_ML_KEM_VECTOR_TRAITS_INVERSE_OF_MODULUS_MOD_MONTGOMERY_R \
  (62209U)

extern const uint8_t
    libcrux_ml_kem_vector_rej_sample_table_REJECTION_SAMPLE_SHUFFLE_TABLE[256U]
                                                                         [16U];

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___add(
    libcrux_ml_kem_vector_PortableVector lhs,
    libcrux_ml_kem_vector_PortableVector *rhs);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___sub(
    libcrux_ml_kem_vector_PortableVector lhs,
    libcrux_ml_kem_vector_PortableVector *rhs);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___multiply_by_constant(
    libcrux_ml_kem_vector_PortableVector v, int16_t c);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___cond_subtract_3329(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___barrett_reduce(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___compress_1(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___ntt_layer_1_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___ntt_layer_2_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta0, int16_t zeta1);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___ntt_layer_3_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___inv_ntt_layer_1_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta0, int16_t zeta1,
    int16_t zeta2, int16_t zeta3);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___inv_ntt_layer_2_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta0, int16_t zeta1);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___inv_ntt_layer_3_step(
    libcrux_ml_kem_vector_PortableVector a, int16_t zeta);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_1(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[2U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_1(
    Eurydice_slice a);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_4(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[8U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_4(
    Eurydice_slice a);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_5(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[10U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_5(
    Eurydice_slice a);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_10(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[20U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_10(
    Eurydice_slice a);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_11(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[22U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_11(
    Eurydice_slice a);

void libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___serialize_12(
    libcrux_ml_kem_vector_PortableVector a, uint8_t ret[24U]);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___deserialize_12(
    Eurydice_slice a);

size_t
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___rej_sample(
    Eurydice_slice a, Eurydice_slice out);

typedef struct
    K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_4size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
      fst[4U];
  uint8_t snd;
} K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_4size_t__uint8_t;

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_to_ring_element__libcrux_ml_kem_vector_PortableVector_4size_t(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *rhs);

typedef struct
    K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_3size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
      fst[3U];
  uint8_t snd;
} K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_3size_t__uint8_t;

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_to_ring_element__libcrux_ml_kem_vector_PortableVector_3size_t(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *rhs);

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_standard_error_reduce__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *error);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___compress___5int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___compress___4int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___compress___11int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___compress___10int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_message_error_reduce__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *message,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        result);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector_traits_decompress_1__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_vector_PortableVector v);

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_error_reduce__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *error);

typedef struct
    K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_2size_t__uint8_t_s {
  libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
      fst[2U];
  uint8_t snd;
} K___libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector_2size_t__uint8_t;

libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___ZERO__libcrux_ml_kem_vector_PortableVector(
    void);

libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___from_i16_array__libcrux_ml_kem_vector_PortableVector(
    Eurydice_slice a);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector_traits_to_unsigned_representative__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_vector_PortableVector a);

libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___subtract_reduce__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        b);

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___add_to_ring_element__libcrux_ml_kem_vector_PortableVector_2size_t(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *rhs);

libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___ntt_multiply__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self,
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *rhs);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___decompress_ciphertext_coefficient___5int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___decompress_ciphertext_coefficient___4int32_t(
    libcrux_ml_kem_vector_PortableVector v);

void libcrux_ml_kem_polynomial__libcrux_ml_kem__polynomial__PolynomialRingElement_Vector__TraitClause_0___poly_barrett_reduce__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_polynomial_PolynomialRingElement__libcrux_ml_kem_vector_PortableVector
        *self);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector_traits_montgomery_multiply_fe__libcrux_ml_kem_vector_PortableVector(
    libcrux_ml_kem_vector_PortableVector v, int16_t fer);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___decompress_ciphertext_coefficient___11int32_t(
    libcrux_ml_kem_vector_PortableVector v);

libcrux_ml_kem_vector_PortableVector
libcrux_ml_kem_vector___libcrux_ml_kem__vector__traits__Operations_for_libcrux_ml_kem__vector__PortableVector___decompress_ciphertext_coefficient___10int32_t(
    libcrux_ml_kem_vector_PortableVector v);

#if defined(__cplusplus)
}
#endif

#define __internal_libcrux_polynomial_H_DEFINED
#endif
