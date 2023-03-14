#ifndef TIMEMARK_H
#define TIMEMARK_H
#include "gtest/gtest.h"
#include "benchmark/benchmark.h"
#include <iostream>
//#include <Shlwapi.h>
#include "intrinipp.h"
#include "C:\NIR\7.0\7.0\include\ipps.h"
#include <chrono>
class timemark
{
public:
	timemark();
	//			ADD IPP
	void ippAdd_32f_Bench(benchmark::State&);
	void ippAdd_32f_I_Bench(benchmark::State&);
	void ippAddC_32fc_Bench(benchmark::State&);
	void ippAddC_32fc_I_Bench(benchmark::State&);
	void ippAdd_16s32f_Bench(benchmark::State&);

	//			ADD FAKE IPP
	void asmAdd_32f_Bench(benchmark::State&);
	void asmAdd_32f_I_Bench(benchmark::State&);
	void asmAddC_32fc_Bench(benchmark::State&);
	void asmAddC_32fc_I_Bench(benchmark::State&);
	void asmAdd_16s32f_Bench(benchmark::State&);
	//			SUB IPP
	void ippSub_32f_Bench(benchmark::State&);
	void ippSub_32f_I_Bench(benchmark::State&);
	void ippSubC_32f_I_Bench(benchmark::State&);
	//			SUB FAKE IPP
	void asmSub_32f_Bench(benchmark::State&);
	void asmSub_32f_I_Bench(benchmark::State&);
	void asmSubC_32f_I_Bench(benchmark::State&);
	//			MUL IPP
	void ippMulC_32f_I_Bench(benchmark::State&);
	void ippMul_32f_Bench(benchmark::State&);
	void ippMul_32f_I_Bench(benchmark::State&);

	void ippMulC_32fc_I_Bench(benchmark::State&);
	void ippMulC_32fc_Bench(benchmark::State&);
	void ippMul_32fc_I_Bench(benchmark::State&);
	void ippMulC_16s_I_Bench(benchmark::State&);
	//			MUL FAKE IPP
	void asmMulC_32f_I_Bench(benchmark::State&);
	void asmMul_32f_Bench(benchmark::State&);
	void asmMul_32f_I_Bench(benchmark::State&);

	void asmMulC_32fc_I_Bench(benchmark::State&);
	void asmMulC_32fc_Bench(benchmark::State&);
	void asmMul_32fc_I_Bench(benchmark::State&);
	void asmMulC_16s_I_Bench(benchmark::State&);
	//			DIV IPP
	void ippDivC_32f_I_Bench(benchmark::State&);
	//			DIV FAKE IPP
	void asmDivC_32f_I_Bench(benchmark::State&);
	//			SQRT IPP
	void ippSqrt_32f_I_Bench(benchmark::State&);
	//			SQRT FAKE IPP
	void asmSqrt_32f_I_Bench(benchmark::State&);
	//			SQR IPP
	void ippSqr_32f_Bench(benchmark::State&);
	//			SQR FAKE IPP
	void asmSqr_32f_Bench(benchmark::State&);
	//			MAX IPP
	void ippMax_32f_Bench(benchmark::State&);
	void ippMaxEvery_32f_I_Bench(benchmark::State&);
	void ippMaxIndx_32f_Bench(benchmark::State&);
	//			MAX FAKE IPP
	void asmMax_32f_Bench(benchmark::State&);
	void asmMaxEvery_32f_I_Bench(benchmark::State&);
	void asmMaxIndx_32f_Bench(benchmark::State&);
	//			ZERO IPP
	void ippZero_32f_Bench(benchmark::State&);
	void ippZero_64f_Bench(benchmark::State&);

	void ippZero_32fc_Bench(benchmark::State&);
	//			ZERO FAKE IPP
	void asmZero_32f_Bench(benchmark::State&);
	void asmZero_64f_Bench(benchmark::State&);

	void asmZero_32fc_Bench(benchmark::State&);
	//			SET IPP
	void ippSet_32f_Bench(benchmark::State&);
	void ippSet_64f_Bench(benchmark::State&);
	//			SET FAKE IPP
	void asmSet_32f_Bench(benchmark::State&);
	void asmSet_64f_Bench(benchmark::State&);
	//			SUM IPP
	void ippSum_32f_Bench(benchmark::State&);
	void ippSum_32fc_Bench(benchmark::State&);
	//			SUM FAKE IPP
	void asmSum_32f_Bench(benchmark::State&);
	void asmSum_32fc_Bench(benchmark::State&);
	//      ABS IPP
	void ippAbs_32f_I_Bench(benchmark::State&);
	//		ASB FAKE IPP
	void asmAbs_32f_I_Bench(benchmark::State&);
	//      CPLX IPP
	void ippRealToCplx_32f_Bench(benchmark::State&);
	void ippCplxToReal_16sc_Bench(benchmark::State&);
	//		CPLX FAKE IPP
	void asmRealToCplx_32f_Bench(benchmark::State&);
	void asmCplxToReal_16sc_Bench(benchmark::State&);
	//		CONVER IPP
	void ippConvert_16s32f_Bench(benchmark::State&);
	void ippConvert_32f16u_Sfs_Near(benchmark::State&);
	void ippConvert_32f16s_Sfs_Near(benchmark::State&);

	void ippConvert_32f16u_Sfs_Zero(benchmark::State&);
	void ippConvert_32f16s_Sfs_Zero(benchmark::State&);
	//		CONVERT FAKE IPP
	void asmConvert_16s32f_Bench(benchmark::State&);
	void asmConvert_32f16u_Sfs_Near(benchmark::State&);
	void asmConvert_32f16s_Sfs_Near(benchmark::State&);

	void asmConvert_32f16u_Sfs_Zero(benchmark::State&);
	void asmConvert_32f16s_Sfs_Zero(benchmark::State&);
	//      COPY IPP
	void ippCopy_32fc_Bench(benchmark::State&);
	void ippCopy_32f_Bench(benchmark::State&);
	//		COPY FAKE IPP
	void asmCopy_32fc_Bench(benchmark::State&);
	void asmCopy_32f_Bench(benchmark::State&);
	//      CONJ IPP
	void ippConj_32fc_Bench(benchmark::State&);
	void ippConj_32fc_I_Bench(benchmark::State&);
	//		CONJ FAKE IPP
	void asmConj_32fc_Bench(benchmark::State&);
	void asmConj_32fc_I_Bench(benchmark::State&);
	//      MEAN IPP
	void ippMean_32f_Bench(benchmark::State&);
	//		MEAN FAKE IPP
	void asmMean_32f_Bench(benchmark::State&);
	//      MAGNITUDE IPP
	void ippMagnitude_32fc_Bench(benchmark::State&);
	void ippMagnitude_32f_Bench(benchmark::State&);
	void ippMagnitude_16sc32f_Bench(benchmark::State&);
	//		MAGNITUDE FAKE IPP
	void asmMagnitude_32fc_Bench(benchmark::State&);
	void asmMagnitude_32f_Bench(benchmark::State&);
	void asmMagnitude_16sc32f_Bench(benchmark::State&);
	//      PROD IPP
	void ippDotProd_32f_Bench(benchmark::State&);
	void ippDotProd_32fc_Bench(benchmark::State&);
	//		PROD FAKE IPP
	void asmDotProd_32f_Bench(benchmark::State&); // netochnost`
	void asmDotProd_32fc_Bench(benchmark::State&);
	//      POLAR IPP
	void ippPolarToCart_32f_Bench(benchmark::State&);
	void ippPolarToCart_32fc_Bench(benchmark::State&);
	//		POLAR FAKE IPP
	void asmPolarToCart_32f_Bench(benchmark::State&);
	void asmPolarToCart_32fc_Bench(benchmark::State&);
	//      FFT IPP
	void ippFFTInit_C_32fc_Bench(benchmark::State&);
	void ippFFTGetSize_C_32fc_Bench(benchmark::State&);

	void ippFFTFwd_CToC_32fc_I_Bench(benchmark::State&);
	void ippFFTInv_CToC_32fc_I_Bench(benchmark::State&);
	//		FFT FAKE IPP
	void asmFFTInit_C_32fc_Bench(benchmark::State&);
	void asmFFTGetSize_C_32fc_Bench(benchmark::State&);

	void asmFFTFwd_CToC_32fc_I_Bench(benchmark::State&);
	void asmFFTInv_CToC_32fc_I_Bench(benchmark::State&);
	//      POWER IPP
	void ippPowerSpectr_32fc_Bench(benchmark::State&);
	//		POWER FAKE IPP
	void asmPowerSpectr_32fc_Bench(benchmark::State&);
	//      WIN IPP
	void ippWinHamming_32fc_I_Bench(benchmark::State&);
	void ippWinHann_32fc_I_Bench(benchmark::State&);
	//		WIN FAKE IPP
	void asmWinHamming_32fc_I_Bench(benchmark::State&);
	void asmWinHann_32fc_I_Bench(benchmark::State&);
	//      PHASE IPP
	void ippPhase_32fc_Bench(benchmark::State&);
	//		PHASE FAKE IPP
	void asmPhase_32fc_Bench(benchmark::State&);
	~timemark();

	int len;
	int order;
	int scaleFactor;
	int lenFFT;
	//          IPP_INIT
	Ipp32fc* ipp_comp;
	Ipp32fc* ipp_dstc;
	Ipp32fc* ipp_bufc;
	Ipp32f* ipp_plusNum;
	Ipp32f* ipp_vec1;
	Ipp32f* ipp_vec2;
	Ipp32f* ipp_vec3;
	Ipp32f* ipp_dst;
	Ipp32f* ipp_bufComp;
	Ipp16s* ipp_16s1;
	Ipp16s* ipp_16s2;
	Ipp16sc* ipp_16sc;
	int ipp_pIndex;
	Ipp64f* ipp_bufComp64;
	Ipp16u* ipp_16u1;
	Ipp8u* ipp_pSpec;
	Ipp8u* ipp_pSpecBuffer;
	Ipp8u* ipp_pBuf;
	IppsFFTSpec_C_32fc** ipp_ppFFTSpec;
	int ipp_pSpecSize;
	int ipp_pSpecBufferSize;
	int ipp_pBufferSize;
	Ipp32fc* ipp_dotProd1;
	Ipp32fc* ipp_dotProd2;
	//          FAKE_INIT
	Asm32fc* asm_comp;
	Asm32fc* asm_dstc;
	Asm32fc* asm_bufc;
	Asm32f* asm_plusNum;
	Asm32f* asm_vec1;
	Asm32f* asm_vec2;
	Asm32f* asm_vec3;
	Asm32f* asm_dst;
	Asm32f* asm_bufComp;
	Asm16s* asm_16s1;
	Asm16s* asm_16s2;
	Asm16sc* asm_16sc;
	int asm_pIndex;
	Asm64f* asm_bufComp64;
	Asm16u* asm_16u1;
	Asm8u* asm_pSpec;
	Asm8u* asm_pSpecBuffer;
	Asm8u* asm_pBuf;
	AsmFFTSpec_C_32fc** asm_ppFFTSpec;
	int asm_pSpecSize;
	int asm_pSpecBufferSize;
	int asm_pBufferSize;
	Asm32fc* asm_dotProd1;
	Asm32fc* asm_dotProd2;
	//          IPP_CONST_INIT
	Ipp32fc ipp_val_c;
	Ipp32f ipp_val;
	Ipp32f ipp_maxC;
	Ipp16s ipp_val16s;
	Ipp64f ipp_val64;
	IppHintAlgorithm ipp_hint;
	IppRoundMode ipp_rndModeNear;
	IppRoundMode ipp_rndModeZero;
	Ipp32f ipp_sumf;
	Ipp32fc ipp_sumfc;
	Ipp32f ipp_mean;
	Ipp32f ipp_dotProdf;
	Ipp32fc ipp_dotProdfc;
	//          FAKE_CONST_INIT
	Asm32fc asm_val_c;
	Asm32f asm_val;
	Asm32f asm_maxC;
	Asm16s asm_val16s;
	Asm64f asm_val64;
	AsmHintAlgorithm asm_hint;
	AsmRoundMode asm_rndModeNear;
	AsmRoundMode asm_rndModeZero;
	Asm32f asm_sumf;
	Asm32fc asm_sumfc;
	Asm32f asm_mean;
	Asm32f asm_dotProdf;
	Asm32fc asm_dotProdfc;
};
#endif