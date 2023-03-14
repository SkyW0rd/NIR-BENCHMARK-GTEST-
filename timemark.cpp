#include "timemark.h"
timemark::timemark()
{
	len = 1600000;
	order = 10;
	scaleFactor = 0;
	lenFFT = 1048576;
	//          IPP_INIT
	ipp_comp = new Ipp32fc[len];
	ipp_dstc = new Ipp32fc[len];
	ipp_bufc = new Ipp32fc[len];
	ipp_plusNum = new Ipp32f[len];
	ipp_vec1 = new Ipp32f[len];
	ipp_vec2 = new Ipp32f[len];
	ipp_vec3 = new Ipp32f[len];
	ipp_dst = new Ipp32f[len];
	ipp_bufComp = new Ipp32f[len];
	ipp_16s1 = new Ipp16s[len];
	ipp_16s2 = new Ipp16s[len];
	ipp_16sc = new Ipp16sc[len];
	ipp_bufComp64 = new Ipp64f[len];
	ipp_16u1 = new Ipp16u[len];
	ipp_ppFFTSpec = new IppsFFTSpec_C_32fc*;
	ipp_pSpecSize = 0;
	ipp_pSpecBufferSize = 0;
	ipp_pBufferSize = 0;
	ipp_reim1 = new Ipp32fc[len];
	ipp_reim2 = new Ipp32fc[len];
	//          FAKE_INITD
	asm_comp = new Asm32fc[len];
	asm_dstc = new Asm32fc[len];
	asm_bufc = new Asm32fc[len];
	asm_plusNum = new Asm32f[len];
	asm_vec1 = new Asm32f[len];
	asm_vec2 = new Asm32f[len];
	asm_vec3 = new Asm32f[len];
	asm_dst = new Asm32f[len];
	asm_bufComp = new Asm32f[len];
	asm_16s1 = new Asm16s[len];
	asm_16s2 = new Asm16s[len];
	asm_16sc = new Asm16sc[len];
	asm_bufComp64 = new Asm64f[len];
	asm_16u1 = new Asm16u[len];
	asm_ppFFTSpec = new AsmFFTSpec_C_32fc*;
	asm_pSpecSize = 0;
	asm_pSpecBufferSize = 0;
	asm_pBufferSize = 0;
	asm_reim1 = new Asm32fc[len];
	asm_reim2 = new Asm32fc[len];
	//          IPP_CONST_INIT
	ipp_val_c = { 3.13931f, 7.1963f };
	ipp_val = { 3.213141f };
	ipp_val16s = { 7 };
	ipp_val64 = { 5.749234f };
	ipp_pIndex = { 2 };
	ipp_hint = ippAlgHintNone;
	ipp_rndModeNear = ippRndNear;
	ipp_rndModeZero = ippRndZero;
	ipp_sumf = 0;
	ipp_sumfc.im = 0;
	ipp_sumfc.re = 0;
	ipp_mean = 0;
	ipp_dotProdf = 0;
	ipp_dotProdfc.im = 0;
	ipp_dotProdfc.re = 0;
	//          FAKE_CONST_INIT
	asm_val_c = { 3.13931f, 7.1963f };
	asm_val = { 3.213141f };
	asm_val16s = { 7 };
	asm_val64 = { 5.749234f };
	asm_pIndex = { 2 };
	asm_rndModeNear = asmRndNear;
	asm_rndModeZero = asmRndZero;
	asm_hint = AlgHintNone;
	asm_sumf = 0;
	asm_sumfc.im = 0;
	asm_sumfc.re = 0;
	asm_mean = 0;
	asm_dotProdf = 0;
	asm_dotProdfc.im = 0;
	asm_dotProdfc.re = 0;
	for (int i = 0; i < len; i++)
	{
		//          IPP_ADD
		ipp_comp[i].re = sin(3.14 * i);
		ipp_comp[i].im = cos(3.14 * i);
		ipp_plusNum[i] = 1 * i / 4 * 4.0f;
		ipp_vec1[i] = sin(3.14 * i / len) + i % 1220;
		ipp_vec2[i] = cos(3.14 * i / len) + i % 1220;
		ipp_vec3[i] = sin(3.14 * i / len) / cos(3.14 * i / len) + i % 1220;
		ipp_dst[i] = -1 * i / 4 * 4.0f;
		ipp_dstc[i].re = 4 + i % 16;
		ipp_dstc[i].im = 7 + i % 16;
		ipp_16s1[i] = 4 + i % 16;
		ipp_16s2[i] = 4;
		ipp_16sc[i].re = 4 + i % 16;
		ipp_16sc[i].im = 7 + i % 16;
		ipp_16u1[i] = 3 + i % 17;
		ipp_bufComp[i] = 0;
		ipp_bufc[i].im = 0;
		ipp_bufc[i].re = 0;
		ipp_bufComp[i] = 0;
		ipp_reim1[i].im = sin(2 * 3.14 * i / len) + i % 1234;
		ipp_reim1[i].re = cos(2 * 3.14 * i / len) + i % 1234;
		ipp_reim2[i].im = sin(2.7 * 3.14 * i / len) + i % 4321;
		ipp_reim2[i].re = cos(2.7 * 3.14 * i / len) + i % 4321;
		//			FAKE_ADD
		asm_comp[i].re = sin(3.14 * i);
		asm_comp[i].im = cos(3.14 * i);
		asm_plusNum[i] = 1 * i / 4 * 4.0f;
		asm_vec1[i] = sin(3.14 * i / len) + i % 1220;
		asm_vec2[i] = cos(3.14 * i / len) + i % 1220;
		asm_vec3[i] = sin(3.14 * i / len) / cos(3.14 * i / len) + i % 1220;
		asm_dst[i] = -1 * i / 4 * 4.0f;
		asm_dstc[i].re = 4 + i % 16;
		asm_dstc[i].im = 7 + i % 16;
		asm_16s1[i] = 4 + i % 16;
		asm_16s2[i] = 4;
		asm_16sc[i].re = 4 + i % 16;
		asm_16sc[i].im = 7 + i % 16;
		asm_16u1[i] = 3 + i % 17;
		asm_bufComp[i] = 0;
		asm_bufc[i].im = 0;
		asm_bufc[i].re = 0;
		asm_bufComp[i] = 0;
		asm_reim1[i].im = sin(2 * 3.14 * i / len) + i % 1234;
		asm_reim1[i].re = cos(2 * 3.14 * i / len) + i % 1234;
		asm_reim2[i].im = sin(2.7 * 3.14 * i / len) + i % 4321;
		asm_reim2[i].re = cos(2.7 * 3.14 * i / len) + i % 4321;
	}
	ippsFFTGetSize_C_32fc(order, IPP_FFT_DIV_INV_BY_N, ippAlgHintNone, &ipp_pSpecSize, &ipp_pSpecBufferSize, &ipp_pBufferSize);
	asmFFTGetSize_C_32fc(order, ASM_FFT_DIV_INV_BY_N, AsmHintAlgorithm::AlgHintNone, &asm_pSpecSize, &asm_pSpecBufferSize, &asm_pBufferSize);
	//			FFT IPP INIT
	ipp_pSpec = new Ipp8u[ipp_pSpecSize];
	ipp_pSpecBuffer = (ipp_pSpecBufferSize > 0) ? new Ipp8u[ipp_pSpecBufferSize] : NULL;
	ipp_pBuf = new Ipp8u[ipp_pBufferSize];
	//			FFT FAKE IPP INIT
	asm_pSpec = new Asm8u[asm_pSpecSize];
	asm_pSpecBuffer = (asm_pSpecBufferSize > 0) ? new Asm8u[asm_pSpecBufferSize] : NULL;
	asm_pBuf = new Asm8u[asm_pBufferSize];
	ippsFFTInit_C_32fc(ipp_ppFFTSpec, order, IPP_FFT_DIV_INV_BY_N, ippAlgHintNone, ipp_pSpec, ipp_pSpecBuffer);
	asmFFTInit_C_32fc(asm_ppFFTSpec, order, IPP_FFT_DIV_INV_BY_N, AsmHintAlgorithm::AlgHintNone, asm_pSpec, asm_pSpecBuffer);
}

//					ADD IPP
void timemark::ippAdd_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAdd_32f(ipp_vec1, ipp_dst, ipp_bufComp, len));
	}
}
void timemark::ippAdd_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAdd_32f_I(ipp_vec1, ipp_dst, len));
	}
}
void timemark::ippAddC_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAddC_32fc(ipp_comp, ipp_val_c, ipp_dstc, len));
	}
}
void timemark::ippAddC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAddC_32fc_I(ipp_val_c, ipp_comp, len));
	}
}
void timemark::ippAdd_16s32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAdd_16s32f(ipp_16s1, ipp_16s2, ipp_bufComp, len));
	}
}
//					ADD FAKE IPP
void timemark::asmAdd_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAdd_32f(asm_vec1, asm_dst, asm_bufComp, len));
	}
}
void timemark::asmAdd_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAdd_32f_I(asm_vec1, asm_dst, len));
	}
}
void timemark::asmAddC_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAddC_32fc(asm_comp, asm_val_c, asm_dstc, len));
	}
}
void timemark::asmAddC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAddC_32fc_I(asm_val_c, asm_comp, len));
	}
}
void timemark::asmAdd_16s32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAdd_16s32f(asm_16s1, asm_16s2, asm_bufComp, len));
	}
}
//			SUB IPP
void timemark::ippSub_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSub_32f(ipp_vec1, ipp_dst, ipp_bufComp, len));
	}
}
void timemark::ippSub_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSub_32f_I(ipp_vec1, ipp_dst, len));
	}
}
void timemark::ippSubC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSubC_32f_I(ipp_val, ipp_vec1, len));
	}
}
//			SUB FAKE IPP
void timemark::asmSub_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSub_32f(asm_vec1, asm_dst, asm_bufComp, len));
	}
}
void timemark::asmSub_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSub_32f_I(asm_vec1, asm_dst, len));
	}
}
void timemark::asmSubC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSubC_32f_I(asm_val, asm_vec1, len));
	}
}
//			MUL IPP
void timemark::ippMulC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMulC_32f_I(ipp_val, ipp_vec1, len));
	}
}
void timemark::ippMul_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMul_32f(ipp_vec1, ipp_dst, ipp_bufComp, len));
	}
}
void timemark::ippMul_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMul_32f_I(ipp_vec1, ipp_dst, len));
	}
}

void timemark::ippMulC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMulC_32fc_I(ipp_val_c, ipp_comp, len));
	}
}
void timemark::ippMulC_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMulC_32fc(ipp_comp, ipp_val_c, ipp_dstc, len));
	}
}
void timemark::ippMul_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMul_32fc_I(ipp_comp, ipp_dstc, len));
	}
}
void timemark::ippMulC_16s_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMulC_16s_I(ipp_val16s, ipp_16s1, len));
	}
}
//			MUL FAKE IPP
void timemark::asmMulC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMulC_32f_I(asm_val, asm_vec1, len));
	}
}
void timemark::asmMul_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMul_32f(asm_vec1, asm_dst, asm_bufComp, len));
	}
}
void timemark::asmMul_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMul_32f_I(asm_vec1, asm_dst, len));
	}
}

void timemark::asmMulC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMulC_32fc_I(asm_val_c, asm_comp, len));
	}
}
void timemark::asmMulC_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMulC_32fc(asm_comp, asm_val_c, asm_dstc, len));
	}
}
void timemark::asmMul_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMul_32fc_I(asm_comp, asm_dstc, len));
	}
}
void timemark::asmMulC_16s_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMulC_16s_I(asm_val16s, asm_16s1, len));
	}
}
//			DIV IPP
void timemark::ippDivC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsDivC_32f_I(ipp_val, ipp_vec1, len));
	}
}
//			DIV FAKE IPP
void timemark::asmDivC_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmDivC_32f_I(asm_val, asm_vec1, len));
	}
}
//			SQRT IPP
void timemark::ippSqrt_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSqrt_32f_I(ipp_plusNum, len));
	}
}
//			SQRT FAKE IPP
void timemark::asmSqrt_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSqrt_32f_I(asm_plusNum, len));
	}
}
//			SQR IPP
void timemark::ippSqr_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSqr_32f(ipp_vec1, ipp_bufComp, len));
	}
}
//			SQR FAKE IPP
void timemark::asmSqr_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSqr_32f(asm_vec1, asm_bufComp, len));
	}
}
//			MAX IPP
void timemark::ippMax_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMax_32f(ipp_vec1, len, &ipp_maxC));
	}
}
void timemark::ippMaxEvery_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMaxEvery_32f_I(ipp_vec1, ipp_dst, len));
	}
}
void timemark::ippMaxIndx_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMaxIndx_32f(ipp_vec1, len, &ipp_maxC, &ipp_pIndex));
	}
}
//			MAX FAKE IPP
void timemark::asmMax_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMax_32f(asm_vec1, len, &asm_maxC));
	}
}
void timemark::asmMaxEvery_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMaxEvery_32f_I(asm_vec1, asm_dst, len));
	}
}
void timemark::asmMaxIndx_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMaxIndx_32f(asm_vec1, len, &asm_maxC, &asm_pIndex));
	}
}
//			ZERO IPP
void timemark::ippZero_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsZero_32f(ipp_bufComp, len));
	}
}
void timemark::ippZero_64f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsZero_64f(ipp_bufComp64, len));
	}
}

void timemark::ippZero_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsZero_32fc(ipp_comp, len));
	}
}
//			ZERO FAKE IPP
void timemark::asmZero_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmZero_32f(asm_bufComp, len));
	}
}
void timemark::asmZero_64f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmZero_64f(asm_bufComp64, len));
	}
}

void timemark::asmZero_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmZero_32fc(asm_comp, len));
	}
}
//			SET IPP
void timemark::ippSet_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSet_32f(ipp_val, ipp_vec1, len));
	}
}
void timemark::ippSet_64f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSet_64f(ipp_val64, ipp_bufComp64, len));
	}
}
//			SET FAKE IPP
void timemark::asmSet_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSet_32f(asm_val, asm_vec1, len));
	}
}
void timemark::asmSet_64f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSet_64f(asm_val64, asm_bufComp64, len));
	}
}
//			SUM IPP
void timemark::ippSum_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSum_32f(ipp_vec1, len, &ipp_sumf, ipp_hint));
	}
}
void timemark::ippSum_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsSum_32fc(ipp_comp, len, &ipp_sumfc, ipp_hint));
	}
}
//			SUM FAKE IPP
void timemark::asmSum_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSum_32f(asm_vec1, len, &asm_sumf, asm_hint));
	}
}
void timemark::asmSum_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmSum_32fc(asm_comp, len, &asm_sumfc, asm_hint));
	}
}
//			ABS IPP
void timemark::ippAbs_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsAbs_32f_I(ipp_vec1, len));
	}
}
//			ASB FAKE IPP
void timemark::asmAbs_32f_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmAbs_32f_I(asm_vec1, len));
	}
}
//			CPLX IPP
void timemark::ippRealToCplx_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsRealToCplx_32f(ipp_vec1, ipp_vec2, ipp_comp, len));
	}
}
void timemark::ippCplxToReal_16sc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsCplxToReal_16sc(ipp_16sc, ipp_16s1, ipp_16s2, len));
	}
}
//			CPLX FAKE IPP
void timemark::asmRealToCplx_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmRealToCplx_32f(asm_vec1, asm_vec2, asm_comp, len));
	}
}
void timemark::asmCplxToReal_16sc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmCplxToReal_16sc(asm_16sc, asm_16s1, asm_16s2, len));
	}
}
//			CONVER IPP
void timemark::ippConvert_16s32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConvert_16s32f(ipp_16s1, ipp_bufComp, len));
	}
}
void timemark::ippConvert_32f16u_Sfs_Near(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConvert_32f16u_Sfs(ipp_vec1, ipp_16u1, len, ipp_rndModeNear, scaleFactor));
	}
}
void timemark::ippConvert_32f16s_Sfs_Near(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConvert_32f16s_Sfs(ipp_vec1, ipp_16s1, len, ipp_rndModeNear, scaleFactor));
	}
}

void timemark::ippConvert_32f16u_Sfs_Zero(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConvert_32f16u_Sfs(ipp_vec1, ipp_16u1, len, ipp_rndModeZero, scaleFactor));
	}
}
void timemark::ippConvert_32f16s_Sfs_Zero(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConvert_32f16s_Sfs(ipp_vec1, ipp_16s1, len, ipp_rndModeZero, scaleFactor));
	}
}
//			CONVERT FAKE IPP
void timemark::asmConvert_16s32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConvert_16s32f(asm_16s1, asm_bufComp, len));
	}
}
void timemark::asmConvert_32f16u_Sfs_Near(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConvert_32f16u_Sfs(asm_vec1, asm_16u1, len, asm_rndModeNear, scaleFactor));
	}
}
void timemark::asmConvert_32f16s_Sfs_Near(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConvert_32f16s_Sfs(asm_vec1, asm_16s1, len, asm_rndModeNear, scaleFactor));
	}
}

void timemark::asmConvert_32f16u_Sfs_Zero(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConvert_32f16u_Sfs(asm_vec1, asm_16u1, len, asm_rndModeZero, scaleFactor));
	}
}
void timemark::asmConvert_32f16s_Sfs_Zero(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConvert_32f16s_Sfs(asm_vec1, asm_16s1, len, asm_rndModeZero, scaleFactor));
	}
}
//			COPY IPP
void timemark::ippCopy_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsCopy_32fc(ipp_comp, ipp_dstc, len));
	}
}
void timemark::ippCopy_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsCopy_32f(ipp_vec1, ipp_dst, len));
	}
}
//			COPY FAKE IPP
void timemark::asmCopy_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmCopy_32fc(asm_comp, asm_dstc, len));
	}
}
void timemark::asmCopy_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmCopy_32f(asm_vec1, asm_dst, len));
	}
}
//			CONJ IPP
void timemark::ippConj_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConj_32fc(ipp_comp, ipp_dstc, len));
	}
}
void timemark::ippConj_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsConj_32fc_I(ipp_dstc, len));
	}
}
//			CONJ FAKE IPP
void timemark::asmConj_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConj_32fc(asm_comp, asm_dstc, len));
	}
}
void timemark::asmConj_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmConj_32fc_I(asm_dstc, len));
	}
}
//			MEAN IPP
void timemark::ippMean_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMean_32f(ipp_vec1, len, &ipp_mean, ipp_hint));
	}
}
//			MEAN FAKE IPP
void timemark::asmMean_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMean_32f(asm_vec1, len, &asm_mean, asm_hint));
	}
}
//			MAGNITUDE IPP
void timemark::ippMagnitude_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMagnitude_32fc(ipp_comp, ipp_vec1, len));
	}
}
void timemark::ippMagnitude_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMagnitude_32f(ipp_vec1, ipp_dst, ipp_bufComp, len));
	}
}
void timemark::ippMagnitude_16sc32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsMagnitude_16sc32f(ipp_16sc, ipp_dst, len));
	}
}
//			MAGNITUDE FAKE IPP
void timemark::asmMagnitude_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMagnitude_32fc(asm_comp, asm_vec1, len));
	}
}
void timemark::asmMagnitude_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMagnitude_32f(asm_vec1, asm_dst, asm_bufComp, len));
	}
}
void timemark::asmMagnitude_16sc32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmMagnitude_16sc32f(asm_16sc, asm_dst, len));
	}
}
//			PROD IPP
void timemark::ippDotProd_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsDotProd_32f(ipp_vec2, ipp_vec3, len, &ipp_dotProdf));
	}
}
void timemark::ippDotProd_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsDotProd_32fc(ipp_reim1, ipp_reim2, len, &ipp_dotProdfc));
	}
}
//			PROD FAKE IPP
void timemark::asmDotProd_32f_Bench(benchmark::State& state) // netochnost`
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmDotProd_32f(asm_vec2, asm_vec3, len, &asm_dotProdf));
	}
}
void timemark::asmDotProd_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmDotProd_32fc(asm_reim1, asm_reim2, len, &asm_dotProdfc));
	}
}
//			POLAR IPP
void timemark::ippPolarToCart_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsPolarToCart_32f(ipp_dst, ipp_vec1, ipp_vec2, ipp_vec3, len));
	}
}
void timemark::ippPolarToCart_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsPolarToCart_32fc(ipp_vec1, ipp_dst, ipp_comp, len));
	}
}
//			POLAR FAKE IPP
void timemark::asmPolarToCart_32f_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmPolarToCart_32f(asm_dst, asm_vec1, asm_vec2, asm_vec3, len));
	}
}
void timemark::asmPolarToCart_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmPolarToCart_32fc(asm_vec1, asm_dst, asm_comp, len));
	}
}
//			FFT IPP
void timemark::ippFFTInit_C_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsFFTInit_C_32fc(ipp_ppFFTSpec, order, IPP_FFT_DIV_INV_BY_N, ipp_hint, ipp_pSpec, ipp_pBuf));
	}
}
void timemark::ippFFTGetSize_C_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsFFTGetSize_C_32fc(order, IPP_FFT_DIV_INV_BY_N, ipp_hint, &ipp_pSpecSize, &ipp_pSpecBufferSize, &ipp_pBufferSize));
	}
}

void timemark::ippFFTFwd_CToC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsFFTFwd_CToC_32fc_I(ipp_dstc, *ipp_ppFFTSpec, ipp_pBuf));
	}
}
void timemark::ippFFTInv_CToC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsFFTInv_CToC_32fc_I(ipp_dstc, *ipp_ppFFTSpec, ipp_pBuf));
	}
}
//			FFT FAKE IPP
void timemark::asmFFTInit_C_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmFFTInit_C_32fc(asm_ppFFTSpec, order, ASM_FFT_DIV_INV_BY_N, asm_hint, asm_pSpec, asm_pBuf));
	}
}
void timemark::asmFFTGetSize_C_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmFFTGetSize_C_32fc(order, ASM_FFT_DIV_INV_BY_N, asm_hint, &asm_pSpecSize, &asm_pSpecBufferSize, &asm_pBufferSize));
	}
}

void timemark::asmFFTFwd_CToC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmFFTFwd_CToC_32fc_I(asm_dstc, *asm_ppFFTSpec, asm_pBuf));
	}
}
void timemark::asmFFTInv_CToC_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmFFTInv_CToC_32fc_I(asm_dstc, *asm_ppFFTSpec, asm_pBuf));
	}
}
//			POWER IPP
void timemark::ippPowerSpectr_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsPowerSpectr_32fc(ipp_reim1, ipp_vec3, len));
	}
}
//			POWER FAKE IPP
void timemark::asmPowerSpectr_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmPowerSpectr_32fc(asm_reim1, asm_vec3, len));
	}
}
//			WIN IPP
void timemark::ippWinHamming_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsWinHamming_32fc_I(ipp_comp, len));
	}
}
void timemark::ippWinHann_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsWinHann_32fc_I(ipp_comp, len));
	}
}
//			WIN FAKE IPP
void timemark::asmWinHamming_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmWinHamming_32fc_I(asm_comp, len));
	}
}
void timemark::asmWinHann_32fc_I_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmWinHann_32fc_I(asm_comp, len));
	}
}
//			PHASE IPP
void timemark::ippPhase_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(ippsPhase_32fc(ipp_comp, ipp_vec1, len));
	}
}
//			PHASE FAKE IPP
void timemark::asmPhase_32fc_Bench(benchmark::State& state)
{
	while (state.KeepRunning())
	{
		benchmark::DoNotOptimize(asmPhase_32fc(asm_comp, asm_vec1, len));
	}
}
timemark::~timemark()
{
	//			DELETE IPP
	delete[] ipp_comp;
	delete[] ipp_dstc;
	delete[] ipp_bufc;
	delete[] asm_plusNum;
	delete[] ipp_vec1;
	delete[] ipp_vec2;
	delete[] ipp_vec3;
	delete[] ipp_dst;
	delete[] ipp_bufComp;
	delete[] ipp_16s1;
	delete[] ipp_16s2;
	delete[] ipp_16sc;
	delete[] ipp_bufComp64;
	delete[] ipp_16u1;
	delete[] ipp_pSpec;
	delete[] ipp_pSpecBuffer;
	delete[] ipp_pBuf;
	delete[] ipp_ppFFTSpec;
	delete[] ipp_reim1;
	delete[] ipp_reim2;
	//			DELETE FAKE IPP
	delete[] asm_comp;
	delete[] asm_dstc;
	delete[] asm_bufc;
	delete[] asm_plusNum;
	delete[] asm_vec1;
	delete[] asm_vec2;
	delete[] asm_vec3;
	delete[] asm_dst;
	delete[] asm_bufComp;
	delete[] asm_16s1;
	delete[] asm_16s2;
	delete[] asm_16sc;
	delete[] asm_bufComp64;
	delete[] asm_16u1;
	delete[] asm_pSpec;
	delete[] asm_pSpecBuffer;
	delete[] asm_pBuf;
	delete[] asm_ppFFTSpec;
	delete[] asm_reim1;
	delete[] asm_reim2;
}