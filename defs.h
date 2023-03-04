#ifndef DEFS_H
#define DEFS_H

#if defined( _WIN32 ) || defined ( _WIN64 )
#define __INT64    __int64
#define __UINT64    unsigned __int64
#else
#define __INT64    long long
#define __UINT64    unsigned long long
#endif

#pragma once
typedef unsigned char   Asm8u;
typedef unsigned short  Asm16u;
typedef unsigned int    Asm32u;

typedef signed char    Asm8s;
typedef signed short   Asm16s;
typedef signed int     Asm32s;
typedef float   Asm32f;
typedef __INT64 Asm64s;
typedef __UINT64 Asm64u;
typedef double  Asm64f;

typedef struct {
    Asm8s  re;
    Asm8s  im;
} Asm8sc;

typedef struct {
    Asm16s  re;
    Asm16s  im;
} Asm16sc;

typedef struct {
    Asm16u  re;
    Asm16u  im;
} Asm16uc;

typedef struct {
    Asm32s  re;
    Asm32s  im;
} Asm32sc;

typedef struct {
    Asm32f  re;
    Asm32f  im;
} Asm32fc;

typedef struct {
    Asm64s  re;
    Asm64s  im;
} Asm64sc;

typedef struct {
    Asm64f  re;
    Asm64f  im;
} Asm64fc;

typedef enum {
    asmStsNullPtrErr = -8,   /* Null pointer error. */
    asmStsSizeErr = -6,   /* Incorrect value for data size. */
    asmStsNoErr = 0   /* No errors. */
} AsmStatus;

typedef enum {
    asmRndZero = 0,     // truncated toward zero
    asmRndNear = 1,     // == 0.5 --> round to nearest even int, else --> classical round
    asmRndFinancial = 2 // < 0.5 --> round to lower int, => 0.5 --> round to upper int.
} AsmRoundMode;

typedef enum {
    AlgHintNone,
    AlgHintFast,
    AlgHintAccurate
} AsmHintAlgorithm;

enum {
    ASM_FFT_DIV_FWD_BY_N = 1,
    ASM_FFT_DIV_INV_BY_N = 2,
    ASM_FFT_DIV_BY_SQRTN = 4,
    ASM_FFT_NODIV_BY_ANY = 8
};

#define _MM_SHUFFLE64(fp1,fp0) \
 (((fp1) << 2) | (fp0))

typedef struct
{
    int size;
    int flag;
    int buf_size;
    int divider;
    int inv_divider;
} AsmFFTSpec_C_32fc;


#define PI 3.1415926535897932384626433832
#define PI2 6.28318530717958647692


#if !defined( _OWN_BLDPCS )


#endif /* _OWN_BLDPCS */

#endif // DEFS_H
