#ifndef INTRINIPP_H
#define INTRINIPP_H

#include "defs.h"
#include <xmmintrin.h>
#include <emmintrin.h>
//#include <x86intrin.h>
#include <math.h>
#include <nmmintrin.h>
#include <smmintrin.h>
#include <immintrin.h>
#include <iostream>

#pragma once
// ��������
AsmStatus asmAdd_32f(Asm32f* pSrc, Asm32f* pDst, Asm32f* dst, int len);
AsmStatus asmAdd_32f_I(Asm32f* pSrc, Asm32f* pDst, int len);
AsmStatus asmAddC_32fc(const Asm32fc* pSrc, Asm32fc val, Asm32fc* pDst, int len);
AsmStatus asmAddC_32fc_I(Asm32fc val, Asm32fc* pSrcDst, int len);
AsmStatus asmAdd_16s32f(const Asm16s* pSrc1, const Asm16s* pSrc2, Asm32f* pDst, int len);

// ���������
AsmStatus asmSub_32f(Asm32f* pSrc1, Asm32f* pSrc2, Asm32f* dst, int len);
AsmStatus asmSub_32f_I(Asm32f* pSrc, Asm32f* pDst, int len);
AsmStatus asmSubC_32f_I(Asm32f value, Asm32f* pDst, int len);

// ���������
AsmStatus asmMulC_32f_I(Asm32f val, Asm32f* array, int len);
AsmStatus asmMul_32f(Asm32f* pSrc, Asm32f* pDst, Asm32f* dst, int len);
AsmStatus asmMul_32f_I(Asm32f* pSrc, Asm32f* pDst, int len);
AsmStatus asmMul_32fc_I(Asm32fc* pScr, Asm32fc* pDst, int len);

AsmStatus asmMulC_32fc_I(Asm32fc value, Asm32fc* pScrDst, int len);
AsmStatus asmMulC_32fc(const Asm32fc* pSrc, Asm32fc value, Asm32fc* pDst, int len);
AsmStatus asmMulC_16s_I(Asm16s val, Asm16s* pSrcDst, int len);

// �������
AsmStatus asmDivC_32f_I(Asm32f value, Asm32f* array, int len);

// ���������� ������
AsmStatus asmSqrt_32f_I(Asm32f* pSrcDst, int len);

// ���������� � �������
AsmStatus asmSqr_32f(const Asm32f* pSrc, Asm32f* pDst, int len);

// ������������ ��������
AsmStatus asmMax_32f(const Asm32f* pSrc, int len, Asm32f* pMax);
AsmStatus asmMaxEvery_32f_I(const Asm32f* pSrc, Asm32f* pSrcDst, int len);
AsmStatus asmMaxIndx_32f(const Asm32f* pSrc, int len, Asm32f* pMax, int* pIndx);

// ���������� ������
AsmStatus asmZero_32f(Asm32f* vec, int len);
AsmStatus asmZero_64f(Asm64f* vec, int len);

AsmStatus asmZero_32fc(Asm32fc* vec, int len);

//���������� ������
AsmStatus asmSet_32f(Asm32f value, Asm32f* vec, int len);
AsmStatus asmSet_64f(Asm64f value, Asm64f* vec, int len);


// ������� �����
AsmStatus asmSum_32f(Asm32f* vec, int len, Asm32f* dst, AsmHintAlgorithm hint);
AsmStatus asmSum_32fc(Asm32fc* vec, int len, Asm32fc* dst, AsmHintAlgorithm hint);

// ������
/*REDO WITH BOTTOM NOTES*/AsmStatus asmAbs_32f_I(Asm32f* pSrcDst, int len);

// �������������� ����������� �����
AsmStatus asmRealToCplx_32f(const Asm32f* pSrcRe, const Asm32f* pSrcIm, Asm32fc* pDst, int len);
AsmStatus asmCplxToReal_16sc(const Asm16sc* pSrc, Asm16s* pDstRe, Asm16s* pDstIm, int len);

// �������������� �����
/*������� ����� ������ ������ � ������*/
AsmStatus asmConvert_16s32f(const Asm16s* pSrc, Asm32f* pDst, int len); //����������� signed short � float
AsmStatus asmConvert_32f16u_Sfs(const Asm32f* pSrc, Asm16u* pDst, int len, AsmRoundMode rndMode, int scaleFactor); //- ����������� float � unsigned short
AsmStatus asmConvert_32f16s_Sfs(const Asm32f* pSrc, Asm16s* pDst, int len, AsmRoundMode rndMode, int scaleFactor);// - ����������� float � signed short

// �����������
AsmStatus asmCopy_32fc(const Asm32fc* pSrc, Asm32fc* pDst, int len);
AsmStatus asmCopy_32f(const Asm32f* pSrc, Asm32f* pDst, int len);

// �����������
AsmStatus asmConj_32fc(const Asm32fc* pSrc, Asm32fc* pDst, int len);
AsmStatus asmConj_32fc_I(Asm32fc* pSrcDst, int len);

// ������� ��������
AsmStatus asmMean_32f(Asm32f* pSrc, int len, Asm32f* pMean, AsmHintAlgorithm hint);

// ������� ����� ������������ ����� (���������)
AsmStatus asmMagnitude_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len);
AsmStatus asmMagnitude_32f(const Asm32f* pSrcRe, const Asm32f* pSrcIm, Asm32f* pDst, int len);
AsmStatus asmMagnitude_16sc32f(const Asm16sc* pSrc, Asm32f* pDst, int len);/*������� ����� ������ ������ � ������*/

// ��������� ������������
/*���������� �� ��� ������� ������ ����� �������*/AsmStatus asmDotProd_32f(const Asm32f* pSrc1, const Asm32f* pSrc2, int len, Asm32f* pDp);
AsmStatus asmDotProd_32fc(const Asm32fc* pSrc1, const Asm32fc* pSrc2, int len, Asm32fc* pDp);

// �������� ����������
// ����������� �������� ���������� � ���� ���������� ��������� � ���� �������� �������������� � ������ ������
AsmStatus asmPolarToCart_32f(const Asm32f* pSrcMagn, const Asm32f* pSrcPhase, Asm32f* pDstRe, Asm32f* pDstIm, int len);
// ����������� �������� ���������� � ���� ���������� ��������� � ����(X + iY)
AsmStatus asmPolarToCart_32fc(const Asm32f* pSrcMagn, const Asm32f* pSrcPhase, Asm32fc* pDst, int len);

inline int separate(Asm32fc* a, int n);
int separate64(Asm64fc* a, int n);
AsmStatus asmFFTInit_C_32fc(AsmFFTSpec_C_32fc** ppFFTSpec, int order, int flag, AsmHintAlgorithm hint, Asm8u* pSpec, Asm8u* pSpecBuffer);
AsmStatus asmFFTGetSize_C_32fc(int order, int flag, /*HintAlgorithm*/int hint, int* pSpecSize, int* pSpecBufferSize, int* pBufferSize);

AsmStatus asmFFTFwd_CToC_32fc_I(Asm32fc* pSrcDst, AsmFFTSpec_C_32fc* pFFTSpec, Asm8u* pBuffer); //(���)
AsmStatus asmFFTFwd_CToC_64fc_I(Asm64fc* pSrcDst, AsmFFTSpec_C_32fc* pFFTSpec, Asm8u* pBuffer);
AsmStatus asmFFTInv_CToC_32fc_I(Asm32fc* pSrcDst, AsmFFTSpec_C_32fc* pFFTSpec, Asm8u* pBuffer); //(�������� ���)

AsmStatus FFFT(Asm64fc* pSrcDst, int N);

//Computes sizes of the FFT specification structure and required working buffers


AsmStatus asmPowerSpectr_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len); // ������ � ��������

// ������� ��������
/*��������� ���������� �� ������� ������*/AsmStatus asmWinHamming_32fc_I(Asm32fc* pSrcDst, int len);
AsmStatus asmWinHann_32fc_I(Asm32fc* pSrcDst, int len);

// �������� ������������ �����
AsmStatus asmPhase_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len);


#endif // INTRINIPP_H


// ��� ���������:
// - � ������ ������� ������� �� ����: i + 4 <= len
// - � �������� � short ����������� ������������ __m64
// - loop unroll
// - � ����������� �������� round �� floor
// - � ����������� ������ ��������� ����, ���� �� �����
// - ������������ _mm_dp_pd ��� _mm_madd_epi16 - ��������� ������������
// - � simd.pdf � ������� bitwise ���� ������� ������ ���������� ���������
// - ABS = _mm_andnot_ps( _mm_set1_ps( -0.0f ), x )
// - _mm_cvtsi128_si32 - ����������� __m128i � int
// - _mm_extract_epi32(x, idx) - ��������� ������� idx �� ������� x