/*
 * SPDX-FileCopyrightText: 2024 Cryspen Sarl <info@cryspen.com>
 *
 * SPDX-License-Identifier: MIT or Apache-2.0
 *
 * This code was generated with the following revisions:
 * Charon: 28d543bfacc902ba9cc2a734b76baae9583892a4
 * Eurydice: 1a65dbf3758fe310833718c645a64266294a29ac
 * Karamel: 15d4bce74a2d43e34a64f48f8311b7d9bcb0e152
 * F*: 650b216aeb5901ec6f1c44ff275acd924e54bdbd
 * Libcrux: ff16b9e8164d0fd89efabd103d4a6c874df0c127
 */

#ifndef __libcrux_mlkem1024_H
#define __libcrux_mlkem1024_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "eurydice_glue.h"
#include "libcrux_core.h"

#define LIBCRUX_ML_KEM_MLKEM1024_VECTOR_U_COMPRESSION_FACTOR_1024 ((size_t)11U)

#define LIBCRUX_ML_KEM_MLKEM1024_C1_BLOCK_SIZE_1024        \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM1024_VECTOR_U_COMPRESSION_FACTOR_1024 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 ((size_t)4U)

#define LIBCRUX_ML_KEM_MLKEM1024_C1_SIZE_1024    \
  (LIBCRUX_ML_KEM_MLKEM1024_C1_BLOCK_SIZE_1024 * \
   LIBCRUX_ML_KEM_MLKEM1024_RANK_1024)

#define LIBCRUX_ML_KEM_MLKEM1024_VECTOR_V_COMPRESSION_FACTOR_1024 ((size_t)5U)

#define LIBCRUX_ML_KEM_MLKEM1024_C2_SIZE_1024              \
  (LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT * \
   LIBCRUX_ML_KEM_MLKEM1024_VECTOR_V_COMPRESSION_FACTOR_1024 / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_CIPHERTEXT_SIZE_1024 \
  (LIBCRUX_ML_KEM_MLKEM1024_C1_SIZE_1024 +                    \
   LIBCRUX_ML_KEM_MLKEM1024_C2_SIZE_1024)

#define LIBCRUX_ML_KEM_MLKEM1024_T_AS_NTT_ENCODED_SIZE_1024 \
  (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 *                     \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *  \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_PUBLIC_KEY_SIZE_1024 \
  (LIBCRUX_ML_KEM_MLKEM1024_T_AS_NTT_ENCODED_SIZE_1024 + (size_t)32U)

#define LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_SECRET_KEY_SIZE_1024 \
  (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 *                       \
   LIBCRUX_ML_KEM_CONSTANTS_COEFFICIENTS_IN_RING_ELEMENT *    \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_COEFFICIENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA1 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA1_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM1024_ETA1 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA2 ((size_t)2U)

#define LIBCRUX_ML_KEM_MLKEM1024_ETA2_RANDOMNESS_SIZE \
  (LIBCRUX_ML_KEM_MLKEM1024_ETA2 * (size_t)64U)

#define LIBCRUX_ML_KEM_MLKEM1024_IMPLICIT_REJECTION_HASH_INPUT_SIZE \
  (LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE +                    \
   LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_CIPHERTEXT_SIZE_1024)

typedef libcrux_ml_kem_types_MlKemCiphertext_1f
    libcrux_ml_kem_mlkem1024_MlKem1024Ciphertext;

typedef libcrux_ml_kem_types_MlKemPrivateKey_95
    libcrux_ml_kem_mlkem1024_MlKem1024PrivateKey;

typedef libcrux_ml_kem_types_MlKemPublicKey_1f
    libcrux_ml_kem_mlkem1024_MlKem1024PublicKey;

#define LIBCRUX_ML_KEM_MLKEM1024_RANKED_BYTES_PER_RING_ELEMENT_1024 \
  (LIBCRUX_ML_KEM_MLKEM1024_RANK_1024 *                             \
   LIBCRUX_ML_KEM_CONSTANTS_BITS_PER_RING_ELEMENT / (size_t)8U)

#define LIBCRUX_ML_KEM_MLKEM1024_SECRET_KEY_SIZE_1024      \
  (LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_SECRET_KEY_SIZE_1024 + \
   LIBCRUX_ML_KEM_MLKEM1024_CPA_PKE_PUBLIC_KEY_SIZE_1024 + \
   LIBCRUX_ML_KEM_CONSTANTS_H_DIGEST_SIZE +                \
   LIBCRUX_ML_KEM_CONSTANTS_SHARED_SECRET_SIZE)

#if defined(__cplusplus)
}
#endif

#define __libcrux_mlkem1024_H_DEFINED
#endif
