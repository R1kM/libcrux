/* 
  This file was generated by KaRaMeL <https://github.com/FStarLang/karamel>
  KaRaMeL invocation: /Users/jonathan/Code/eurydice/eurydice --config ../c.yaml ../../libcrux_ml_kem.llbc ../../libcrux_sha3.llbc --log Phase2.2,Reassign
  F* version: 58c915a8
  KaRaMeL version: 5666a5de
 */

#include "libcrux_sha3_neon.h"

#include "internal/libcrux_core.h"

inline void libcrux_sha3_neon_sha512(Eurydice_slice digest, Eurydice_slice data)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void libcrux_sha3_neon_sha256(Eurydice_slice digest, Eurydice_slice data)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_neon_x2_shake256(
  Eurydice_slice input0,
  Eurydice_slice input1,
  Eurydice_slice out0,
  Eurydice_slice out1
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline libcrux_sha3_neon_x2_incremental_KeccakState2
libcrux_sha3_neon_x2_incremental_shake128_init(void)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_neon_x2_incremental_shake128_absorb_final(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice data0,
  Eurydice_slice data1
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_next_block(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice out0,
  Eurydice_slice out1
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void
libcrux_sha3_neon_x2_incremental_shake128_squeeze_first_three_blocks(
  libcrux_sha3_neon_x2_incremental_KeccakState2 *s,
  Eurydice_slice out0,
  Eurydice_slice out1
)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void libcrux_sha3_neon_sha224(Eurydice_slice digest, Eurydice_slice data)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

inline void libcrux_sha3_neon_sha384(Eurydice_slice digest, Eurydice_slice data)
{
  Prims_string
  buf[1U] = { "not implemented: The target architecture does not support neon instructions." };
  Eurydice_slice
  uu____0 = Eurydice_array_to_slice((size_t)1U, buf, Prims_string, Eurydice_slice);
  core_fmt_rt_Argument ret[0U];
  core_fmt_rt__core__fmt__rt__Argument__a__1__none(ret);
  LowStar_Ignore_ignore(core_fmt__core__fmt__Arguments__a__2__new_v1(uu____0,
      Eurydice_array_to_slice((size_t)0U, ret, core_fmt_rt_Argument, Eurydice_slice)),
    core_fmt_Arguments,
    void *);
  KRML_HOST_EPRINTF("KaRaMeL abort at %s:%d\n%s\n", __FILE__, __LINE__, "panic!");
  KRML_HOST_EXIT(255U);
}

