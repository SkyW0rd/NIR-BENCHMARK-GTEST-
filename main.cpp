#include "timemark.h"
const double eps = 0.0001;
int len = 1600000;
timemark* tm = new timemark();

static void allTESTs(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        testing::InitGoogleTest();
        RUN_ALL_TESTS();
    }
}
//              IPP ADD FUNC
static void ippAdd_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAdd_32f_Bench(state);
    }
}
static void ippAdd_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAdd_32f_I_Bench(state);
    }
}
static void ippAddC_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAddC_32fc_Bench(state);
    }
}
static void ippAddC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAddC_32fc_I_Bench(state);
    }
}
static void ippAdd_16s32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAdd_16s32f_Bench(state);
    }
}
//              FAKE IPP ADD FUNC
static void asmAdd_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAdd_32f_Bench(state);
    }
}
static void asmAdd_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAdd_32f_I_Bench(state);
    }
}
static void asmAddC_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAddC_32fc_Bench(state);
    }
}
static void asmAddC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAddC_32fc_I_Bench(state);
    }
}
static void asmAdd_16s32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAdd_16s32f_Bench(state);
    }
}
//              IPP SUB FUNC
static void ippSub_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSub_32f_Bench(state);
    }
}
static void ippSub_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSub_32f_I_Bench(state);
    }
}
static void ippSubC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSubC_32f_I_Bench(state);
    }
}
//              FAKE IPP SUB FUNC
static void asmSub_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSub_32f_Bench(state);
    }
}
static void asmSub_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSub_32f_I_Bench(state);
    }
}
static void asmSubC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSubC_32f_I_Bench(state);
    }
}
//              IPP MUL FUNC
void ippMulC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMulC_32f_I_Bench(state);
    }
}
void ippMul_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMul_32f_Bench(state);
    }
}
void ippMul_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMul_32f_I_Bench(state);
    }
}

void ippMulC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMulC_32fc_I_Bench(state);
    }
}
void ippMulC_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMulC_32fc_Bench(state);
    }
}
void ippMul_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMul_32fc_I_Bench(state);
    }
}
void ippMulC_16s_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMulC_16s_I_Bench(state);
    }
}
//              FAKE IPP MUL FUNC
void asmMulC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMulC_32f_I_Bench(state);
    }
}
void asmMul_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMul_32f_Bench(state);
    }
}
void asmMul_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMul_32f_I_Bench(state);
    }
}

void asmMulC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMulC_32fc_I_Bench(state);
    }
}
void asmMulC_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMulC_32fc_Bench(state);
    }
}
void asmMul_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMul_32fc_I_Bench(state);
    }
}
void asmMulC_16s_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMulC_16s_I_Bench(state);
    }
}
//              IPP DIV FUNC
void ippDivC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippDivC_32f_I_Bench(state);
    }
}
//              FAKE IPP DIV FUNC
void asmDivC_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmDivC_32f_I_Bench(state);
    }
}
//              IPP SQRT FUNC
void ippSqrt_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSqrt_32f_I_Bench(state);
    }
}
//              FAKE IPP SQRT FUNC
void asmSqrt_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSqrt_32f_I_Bench(state);
    }
}
//              IPP SQR FUNC
void ippSqr_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSqr_32f_Bench(state);
    }
}
//			    FAKE IPP SQR FUNC
void asmSqr_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSqr_32f_Bench(state);
    }
}
//			    IPP MAX FUNC
void ippMax_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMax_32f_Bench(state);
    }
}
void ippMaxEvery_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMaxEvery_32f_I_Bench(state);
    }
}
void ippMaxIndx_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMaxIndx_32f_Bench(state);
    }
}
//			    FAKE IPP MAX FUNC
void asmMax_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMax_32f_Bench(state);
    }
}
void asmMaxEvery_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMaxEvery_32f_I_Bench(state);
    }
}
void asmMaxIndx_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMaxIndx_32f_Bench(state);
    }
}
//              IPP ZERO FUNC
void ippZero_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippZero_32f_Bench(state);
    }
}
void ippZero_64f_B(benchmark::State& state) 
{
    if (state.KeepRunning())
    {
        tm->ippZero_64f_Bench(state);
    }
}
void ippZero_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippZero_32fc_Bench(state);
    }
}
//              FAKE IPP ZERO FUNC
void asmZero_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmZero_32f_Bench(state);
    }
}
void asmZero_64f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmZero_64f_Bench(state);
    }
}
void asmZero_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmZero_32fc_Bench(state);
    }
}
//			SET IPP
void ippSet_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSet_32f_Bench(state);
    }
}
void ippSet_64f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSet_64f_Bench(state);
    }
}
//			SET FAKE IPP
void asmSet_32f_B(benchmark::State& state)
{
   if (state.KeepRunning())
    {
       tm->asmSet_32f_Bench(state);
    }
}
void asmSet_64f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSet_32f_Bench(state);
    }
}
//			SUM IPP
void ippSum_32f_B(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        tm->ippSum_32f_Bench(state);
    }
}
void ippSum_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippSum_32fc_Bench(state);
    }
}
//			SUM FAKE IPP
void asmSum_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSum_32f_Bench(state);
    }
}
void asmSum_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmSum_32fc_Bench(state);
    }
}
//      ABS IPP------------------------------------------------------------------------------------------------------------
void ippAbs_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippAbs_32f_I_Bench(state);
    }
}
//		ASB FAKE IPP
void asmAbs_32f_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmAbs_32f_I_Bench(state);
    }
}
//      CPLX IPP
void ippRealToCplx_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippRealToCplx_32f_Bench(state);
    }
}
void ippCplxToReal_16sc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippCplxToReal_16sc_Bench(state);
    }
}
//		CPLX FAKE IPP
void asmRealToCplx_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmRealToCplx_32f_Bench(state);
    }
}
void asmCplxToReal_16sc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmCplxToReal_16sc_Bench(state);
    }
}
//		CONVER IPP
void ippConvert_16s32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippConvert_16s32f_Bench(state);
    }
}
void ippConvert_32f16u_Sfs_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippConvert_32f16u_Sfs_Bench(state);
    }
}
void ippConvert_32f16s_Sfs_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippConvert_32f16s_Sfs_Bench(state);
    }
}
//		CONVERT FAKE IPP
void asmConvert_16s32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmConvert_16s32f_Bench(state);
    }
}
void asmConvert_32f16u_Sfs_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmConvert_32f16u_Sfs_Bench(state);
    }
}
void asmConvert_32f16s_Sfs_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmConvert_32f16s_Sfs_Bench(state);
    }
}
//      COPY IPP
void ippCopy_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippCopy_32fc_Bench(state);
    }
}
void ippCopy_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippCopy_32f_Bench(state);
    }
}
//		COPY FAKE IPP
void asmCopy_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmCopy_32fc_Bench(state);
    }
}
void asmCopy_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmCopy_32f_Bench(state);
    }
}
//      CONJ IPP
void ippConj_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippConj_32fc_Bench(state);
    }
}
void ippConj_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippConj_32fc_I_Bench(state);
    }
}
//		CONJ FAKE IPP
void asmConj_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmConj_32fc_Bench(state);
    }
}
void asmConj_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmConj_32fc_I_Bench(state);
    }
}
//      MEAN IPP
void ippMean_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMean_32f_Bench(state);
    }
}
//		MEAN FAKE IPP
void asmMean_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMean_32f_Bench(state);
    }
}
//      MAGNITUDE IPP
void ippMagnitude_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMagnitude_32fc_Bench(state);
    }
}
void ippMagnitude_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMagnitude_32f_Bench(state);
    }
}
void ippMagnitude_16sc32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippMagnitude_16sc32f_Bench(state);
    }
}
//		MAGNITUDE FAKE IPP
void asmMagnitude_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMagnitude_32fc_Bench(state);
    }
}
void asmMagnitude_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMagnitude_32f_Bench(state);
    }
}
void asmMagnitude_16sc32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmMagnitude_16sc32f_Bench(state);
    }
}
//      PROD IPP
void ippDotProd_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippDotProd_32f_Bench(state);
    }
}
void ippDotProd_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippDotProd_32fc_Bench(state);
    }
}
//		PROD FAKE IPP
void asmDotProd_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmDotProd_32f_Bench(state);
    }
}
void asmDotProd_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmDotProd_32fc_Bench(state);
    }
}
//      POLAR IPP
void ippPolarToCart_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippPolarToCart_32f_Bench(state);
    }
}
void ippPolarToCart_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippPolarToCart_32fc_Bench(state);
    }
}
//		POLAR FAKE IPP
void asmPolarToCart_32f_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmPolarToCart_32f_Bench(state);
    }
}
void asmPolarToCart_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmPolarToCart_32fc_Bench(state);
    }
}
//      FFT IPP
void ippFFTInit_C_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippFFTInit_C_32fc_Bench(state);
    }
}
void ippFFTGetSize_C_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippFFTGetSize_C_32fc_Bench(state);
    }
}

void ippFFTFwd_CToC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippFFTFwd_CToC_32fc_I_Bench(state);
    }
}
void ippFFTInv_CToC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippFFTInv_CToC_32fc_I_Bench(state);
    }
}
//		FFT FAKE IPP
void asmFFTInit_C_32fc_B(benchmark::State& state) 
{
    if (state.KeepRunning())
    {
        tm->asmFFTInit_C_32fc_Bench(state);
    }
}
void asmFFTGetSize_C_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmFFTGetSize_C_32fc_Bench(state);
    }
}

void asmFFTFwd_CToC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmFFTFwd_CToC_32fc_I_Bench(state);
    }
}
void asmFFTInv_CToC_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmFFTInv_CToC_32fc_I_Bench(state);
    }
}
//      POWER IPP
void ippPowerSpectr_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippPowerSpectr_32fc_Bench(state);
    }
}
//		POWER FAKE IPP
void asmPowerSpectr_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmPowerSpectr_32fc_Bench(state);
    }
}
//      WIN IPP
void ippWinHamming_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippWinHamming_32fc_I_Bench(state);
    }
}
void ippWinHann_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippWinHann_32fc_I_Bench(state);
    }
}
//		WIN FAKE IPP
void asmWinHamming_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmWinHamming_32fc_I_Bench(state);
    }
}
void asmWinHann_32fc_I_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmWinHann_32fc_I_Bench(state);
    }
}
//      PHASE IPP
void ippPhase_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->ippPhase_32fc_Bench(state);
    }
}
//		PHASE FAKE IPP
void asmPhase_32fc_B(benchmark::State& state)
{
    if (state.KeepRunning())
    {
        tm->asmPhase_32fc_Bench(state);
    }
}

//              ADD TEST FUNC
TEST(AddTest, Add_32f)
{
    ippsAdd_32f(tm->ipp_vec1, tm->ipp_dst, tm->ipp_bufComp, tm->len);
    asmAdd_32f(tm->asm_vec1, tm->asm_dst, tm->asm_bufComp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(AddTest, Add_32f_I)
{
    ippsAdd_32f_I(tm->ipp_vec1, tm->ipp_dst, tm->len);
    asmAdd_32f_I(tm->asm_vec1, tm->asm_dst, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
TEST(AddTest, AddC_32fc)
{
    ippsAddC_32fc(tm->ipp_comp, tm->ipp_val_c, tm->ipp_dstc, tm->len);
    asmAddC_32fc(tm->asm_comp, tm->asm_val_c, tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
TEST(AddTest, AddC_32fc_I)
{
    ippsAddC_32fc_I(tm->ipp_val_c, tm->ipp_comp, tm->len);
    asmAddC_32fc_I(tm->asm_val_c, tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
//TEST(AddTest, FourthTest)
//{
//    ippsAddC_32fc_I(tm->ipp_val_c, tm->ipp_comp, len);
//    asmAddC_32fc_I(tm->asm_val_c, tm->asm_comp, len);
//    for (int i = 0; i < tm->len; i++)
//    {
//        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
//        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
//    }
//}
//              SUB TEST FUNC
TEST(SubTest, Sub_32f)
{
    ippsSub_32f(tm->ipp_vec1, tm->ipp_dst, tm->ipp_bufComp, tm->len);
    asmSub_32f(tm->asm_vec1, tm->asm_dst, tm->asm_bufComp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(SubTest, Sub_32f_I)
{
    ippsSub_32f_I(tm->ipp_vec1, tm->ipp_dst, tm->len);
    asmSub_32f_I(tm->asm_vec1, tm->asm_dst, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
TEST(SubTest, SubC_32f_I)
{
    ippsSubC_32f_I(tm->ipp_val, tm->ipp_vec1, tm->len);
    asmSubC_32f_I(tm->asm_val, tm->asm_vec1, tm->len);
    for (int i = 0; i < len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }
}
//              MUL TEST FUNC
TEST(MulTest, MulC_32f_I)
{
    ippsMulC_32f_I(tm->ipp_val, tm->ipp_vec1, tm->len);
    asmMulC_32f_I(tm->asm_val, tm->asm_vec1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }

}
TEST(MulTest, Mul_32f)
{
    ippsMul_32f(tm->ipp_vec1, tm->ipp_dst, tm->ipp_bufComp, tm->len);
    asmMul_32f(tm->asm_vec1, tm->asm_dst, tm->asm_bufComp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(MulTest, Mul_32f_I)
{
    ippsMul_32f_I(tm->ipp_vec1, tm->ipp_dst, tm->len);
    asmMul_32f_I(tm->asm_vec1, tm->asm_dst, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}

TEST(MulTest, MulC_32fc_I)
{
    ippsMulC_32fc_I(tm->ipp_val_c, tm->ipp_comp, tm->len);
    asmMulC_32fc_I(tm->asm_val_c, tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
TEST(MulTest, MulC_32fc)
{
    ippsMulC_32fc(tm->ipp_comp, tm->ipp_val_c,tm->ipp_dstc, tm->len);
    asmMulC_32fc(tm->asm_comp, tm->asm_val_c, tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
TEST(MulTest, Mul_32fc_I)
{
    ippsMul_32fc_I(tm->ipp_comp, tm->ipp_dstc, tm->len);
    asmMul_32fc_I(tm->asm_comp, tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
TEST(MulTest, MulC_16s_I)
{
    ippsMulC_16s_I(tm->ipp_val16s, tm->ipp_16s1, tm->len);
    asmMulC_16s_I(tm->asm_val16s, tm->asm_16s1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_16s1[i], tm->asm_16s1[i], eps);
    }
}
//              DIV TEST FUNC
TEST(DivTest, DivC_32f_I)
{
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout  << tm->asm_vec1[i]<<"\t" << tm->ipp_bufComp[i] << "\t------ " << tm->asm_vec1[i] << "\t" << tm->asm_bufComp[i] << std::endl;
    //}
    ippsDivC_32f_I(tm->ipp_val, tm->ipp_vec1, tm->len);
    asmDivC_32f_I(tm->asm_val, tm->asm_vec1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }
}
//			    SQRT TEST FUNC
TEST(SqrtTest, Sqrt_32f_I)
{
    ippsSqrt_32f_I(tm->ipp_plusNum, tm->len);
    asmSqrt_32f_I(tm->asm_plusNum, tm->len);
    for (int i = 0; i < len; i++)
    {
        ASSERT_NEAR(tm->ipp_plusNum[i], tm->asm_plusNum[i], eps);
    }

}
//			    SQR TEST FUNC
TEST(SqrTest, Sqr_32f)
{
    ippsSqr_32f(tm->ipp_vec1, tm->ipp_bufComp, tm->len);
    asmSqr_32f(tm->asm_vec1, tm->asm_bufComp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
//			    MAX TEST FUNC
TEST(MaxTest, Max_32f)
{
    ippsMax_32f(tm->ipp_vec1, tm->len, tm->ipp_vec2);
    asmMax_32f(tm->asm_vec1, tm->len, tm->asm_vec2);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec2[i], tm->asm_vec2[i], eps);
    }
}
TEST(MaxTest, MaxEvery_32f_I)
{
    ippsMaxEvery_32f_I(tm->ipp_vec1, tm->ipp_dst, len);
    asmMaxEvery_32f_I(tm->asm_vec1, tm->asm_dst, len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
TEST(MaxTest, MaxIndx_32f)
{
    ippsMaxIndx_32f(tm->ipp_vec1, tm->len, tm->ipp_vec2, tm->ipp_pIndex);
    asmMaxIndx_32f(tm->asm_vec1, tm->len, tm->asm_vec2, tm->asm_pIndex);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec2[i], tm->asm_vec2[i], eps);
    }
}
//			ZERO TEST FUNC
TEST(ZeroTest, Zero_32f)
{
    ippsZero_32f(tm->ipp_bufComp, len);
    asmZero_32f(tm->asm_bufComp, len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(ZeroTest, Zero_64f)
{
    ippsZero_64f(tm->ipp_bufComp64, len);
    asmZero_64f(tm->asm_bufComp64, len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp64[i], tm->asm_bufComp64[i], eps);
    }
}
TEST(ZeroTest, Zero_32fc)
{
    ippsZero_32fc(tm->ipp_comp, len);
    asmZero_32fc(tm->asm_comp, len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
////			SET TEST FUNC
TEST(SetTest, Set_32f)
{
    ippsSet_32f(tm->ipp_val, tm->ipp_bufComp, tm->len);
    asmSet_32f(tm->asm_val, tm->asm_bufComp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }
}
TEST(SetTest, Set_64f)
{
    ippsSet_64f(tm->ipp_val64, tm->ipp_bufComp64, tm->len);
    asmSet_64f(tm->asm_val64, tm->asm_bufComp64, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp64[i], tm->asm_bufComp64[i], eps);
    }
}
////			SUM TEST FUNC
TEST(SumTest, Sum_32f)
{
    ippsSum_32f(tm->ipp_vec1, tm->len, tm->ipp_dst, tm->ipp_hint);
    asmSum_32f(tm->asm_vec1, tm->len, tm->asm_dst);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
TEST(SumTest, Sum_32fc)
{
    ippsSum_32fc(tm->ipp_comp, tm->len, tm->ipp_dstc, tm->ipp_hint);
    asmSum_32fc(tm->asm_comp, tm->len, tm->asm_dstc);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
////      ABS TEST FUNC
TEST(AbsTest, Abs_32f_I)
{
    ippsAbs_32f_I(tm->ipp_vec1, tm->len);
    asmAbs_32f_I(tm->ipp_vec1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }

}
////      CPLX TEST FUNC
TEST(CplxTest, RealToCplx_32f)
{
    ippsRealToCplx_32f(tm->ipp_vec1, tm->ipp_vec2, tm->ipp_comp, tm->len);
    asmRealToCplx_32f(tm->asm_vec1, tm->asm_vec2, tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
TEST(CplxTest, CplxToReal_16sc)
{
    ippsCplxToReal_16sc(tm->ipp_16sc, tm->ipp_16s1, tm->ipp_16s2, tm->len);
    asmCplxToReal_16sc(tm->asm_16sc, tm->asm_16s1, tm->asm_16s2, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_16s1[i], tm->asm_16s1[i], eps);
        ASSERT_NEAR(tm->ipp_16s2[i], tm->asm_16s2[i], eps);
    }
}
//		CONVER TEST FUNC
//TEST(ConverTest, Convert_16s32f)
//{
//    ippsConvert_16s32f(tm->ipp_16s1, tm->ipp_bufComp, tm->len);
//    asmConvert_16s32f(tm->asm_16s1, tm->asm_bufComp, tm->len);
//    for (int i = 0; i < tm->len; i++)
//    {
//        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
//    }
//}
//TEST(ConverTest, Convert_32f16u_Sfs)
//{
//    ippsConvert_32f16u_Sfs(tm->ipp_vec1, tm->ipp_16u1, tm->len, tm->ipp_rndMode, tm->scaleFactor);
//    asmConvert_32f16u_Sfs(tm->asm_vec1, tm->asm_16u1, tm->len, tm->asm_rndMode, tm->scaleFactor);
//    for (int i = 0; i < tm->len; i++)
//    {
//        ASSERT_NEAR(tm->ipp_16u1[i], tm->asm_16u1[i], eps);
//    }
//}
//TEST(ConverTest, Convert_32f16s_Sfs)
//{
//    ippsConvert_32f16s_Sfs(tm->ipp_vec1, tm->ipp_16s1, tm->len, tm->ipp_rndMode, tm->scaleFactor);
//    asmConvert_32f16s_Sfs(tm->asm_vec1, tm->asm_16s1, tm->len, tm->asm_rndMode, tm->scaleFactor);
//    for (int i = 0; i < tm->len; i++)
//    {
//        ASSERT_NEAR(tm->ipp_16s1[i], tm->asm_16s1[i], eps);
//    }
//}
////      COPY TEST FUNC
TEST(CopyTest, Copy_32fc)
{
    ippsCopy_32fc(tm->ipp_comp, tm->ipp_dstc, tm->len);
    asmCopy_32fc(tm->asm_comp, tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
TEST(CopyTest, Copy_32f)
{
    ippsCopy_32f(tm->ipp_vec1, tm->ipp_dst, tm->len);
    asmCopy_32f(tm->ipp_vec1, tm->ipp_dst, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
////      CONJ TEST FUNC
TEST(ConjTest, Conj_32fc)
{
    ippsConj_32fc(tm->ipp_comp, tm->ipp_dstc, tm->len);
    asmConj_32fc(tm->asm_comp, tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
TEST(ConjTest, Conj_32fc_I)
{
    ippsConj_32fc_I(tm->ipp_dstc, tm->len);
    asmConj_32fc_I(tm->asm_dstc, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dstc[i].im, tm->asm_dstc[i].im, eps);
        ASSERT_NEAR(tm->ipp_dstc[i].re, tm->asm_dstc[i].re, eps);
    }
}
////      MEAN TEST FUNC
TEST(MeanTest, Mean_32f)
{
    ippsMean_32f(tm->ipp_vec1, tm->len, tm->ipp_dst, tm->ipp_hint);
    asmMean_32f(tm->asm_vec1, tm->len, tm->asm_dst);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
////      MAGNITUDE TEST FUNC
TEST(MagnitudeTest, Magnitude_32fc)
{
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_vec1[i] << "\t" << tm->asm_vec1[i] << std::endl;
    //}
    ippsMagnitude_32fc(tm->ipp_comp, tm->ipp_vec1, tm->len);
    asmMagnitude_32fc(tm->asm_comp, tm->asm_vec1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }
}
TEST(MagnitudeTest, Magnitude_32f)
{
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_bufComp[i] << "\t" << tm->asm_bufComp[i] << std::endl;
    //}
    ippsMagnitude_32f(tm->ipp_vec1, tm->ipp_dst, tm->ipp_bufComp, tm->len);
    asmMagnitude_32f(tm->ipp_vec1, tm->ipp_dst, tm->ipp_bufComp, tm->len);
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_bufComp[i] << "\t" << tm->asm_bufComp[i] << std::endl;
    //}
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(MagnitudeTest, Magnitude_16sc32f)
{
    ippsMagnitude_16sc32f(tm->ipp_16sc, tm->ipp_dst, tm->len);
    asmMagnitude_16sc32f(tm->asm_16sc, tm->asm_dst, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }
}
////      PROD TEST FUNC
TEST(ProdTest, DotProd_32f)
{
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_vec1[i] << "\t" << tm->asm_vec1[i] << std::endl;
    //}
    ippsDotProd_32f(tm->ipp_vec1, tm->ipp_dst, tm->len, tm->ipp_bufComp);
    asmDotProd_32f(tm->asm_vec1, tm->asm_dst, tm->len, tm->asm_bufComp);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufComp[i], tm->asm_bufComp[i], eps);
    }
}
TEST(ProdTest, DotProd_32fc)
{
    ippsDotProd_32fc(tm->ipp_comp, tm->ipp_dstc, tm->len, tm->ipp_bufc);
    asmDotProd_32fc(tm->asm_comp, tm->asm_dstc, tm->len, tm->asm_bufc);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_bufc[i].im, tm->asm_bufc[i].im, eps);
        ASSERT_NEAR(tm->ipp_bufc[i].re, tm->asm_bufc[i].re, eps);
    }
}
////      POLAR TEST FUNC
TEST(PolarTest, PolarToCart_32f)
{
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_vec1[i] << "\t" << tm->asm_vec1[i] << std::endl;
    //}
    ippsPolarToCart_32f(tm->ipp_dst, tm->ipp_vec1, tm->ipp_vec2, tm->ipp_vec3, tm->len);
    asmPolarToCart_32f(tm->asm_dst, tm->asm_vec1, tm->asm_vec2, tm->asm_vec3, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec2[i], tm->asm_vec2[i], eps);
        ASSERT_NEAR(tm->ipp_vec3[i], tm->asm_vec3[i], eps);
    }
}
TEST(PolarTest, PolarToCart_32fc)
{
    ippsPolarToCart_32fc(tm->ipp_vec1, tm->ipp_dst, tm->ipp_comp, tm->len);
    asmPolarToCart_32fc(tm->asm_vec1, tm->asm_dst, tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
////      FFT TEST FUNC
TEST(FFTTest, FFTInit_C_32fc)
{
    ippsFFTInit_C_32fc(tm->ipp_ppFFTSpec, tm->order, IPP_FFT_DIV_INV_BY_N, tm->ipp_hint, tm->ipp_pSpec, tm->ipp_pBuf);
    asmFFTInit_C_32fc(tm->asm_ppFFTSpec, tm->order, IPP_FFT_DIV_INV_BY_N, tm->asm_hint, tm->asm_pSpec, tm->asm_pBuf);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_pBuf[i], tm->asm_pBuf[i], eps);
    }
}
TEST(FFTTest, FFTGetSize_C_32fc)
{
    ippsFFTGetSize_C_32fc(tm->order, IPP_FFT_DIV_INV_BY_N, tm->ipp_hint, tm->pSpecSize, tm->pSpecBufferSize, tm->pBufferSize);
    asmFFTGetSize_C_32fc(tm->order, IPP_FFT_DIV_INV_BY_N, tm->asm_hint, tm->pSpecSize, tm->pSpecBufferSize, tm->pBufferSize);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->pBufferSize[i], tm->pBufferSize[i], eps);
    }
}
TEST(FFTTest, FFTFwd_CToC_32fc_I)
{
    ippsFFTFwd_CToC_32fc_I(tm->ipp_dstc, tm->ipp_pFFTSpec, tm->ipp_pBuf);
    asmFFTFwd_CToC_32fc_I(tm->asm_dstc, tm->asm_pFFTSpec, tm->asm_pBuf);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_pBuf[i], tm->asm_pBuf[i], eps);
    }
}
TEST(FFTTest, FFTInv_CToC_32fc_I)
{
    ippsFFTInv_CToC_32fc_I(tm->ipp_dstc, tm->ipp_pFFTSpec, tm->ipp_pBuf);
    asmFFTInv_CToC_32fc_I(tm->asm_dstc, tm->asm_pFFTSpec, tm->asm_pBuf);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_pBuf[i], tm->asm_pBuf[i], eps);
    }
}
////      POWER TEST FUNC
TEST(PowerTest, PowerSpectr_32fc)
{
    ippsPowerSpectr_32fc(tm->ipp_comp, tm->ipp_dst, tm->len);
    asmPowerSpectr_32fc(tm->asm_comp, tm->asm_dst, tm->len);
    //for (int i = 0; i < len; i++)
    //{
    //    std::cout << tm->ipp_dst[i] << "\t" << tm->asm_dst[i] << std::endl;
    //}
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_dst[i], tm->asm_dst[i], eps);
    }

}
////      WIN TEST FUNC
TEST(WinTest, WinHamming_32fc_I)
{
    ippsWinHamming_32fc_I(tm->ipp_comp, tm->len);
    asmWinHamming_32fc_I(tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
TEST(WinTest, WinHann_32fc_I)
{
    ippsWinHann_32fc_I(tm->ipp_comp, tm->len);
    asmWinHann_32fc_I(tm->asm_comp, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_comp[i].im, tm->asm_comp[i].im, eps);
        ASSERT_NEAR(tm->ipp_comp[i].re, tm->asm_comp[i].re, eps);
    }
}
////      PHASE TEST FUNC
TEST(PhaseTest, Phase_32fc)
{
    ippsPhase_32fc(tm->ipp_comp, tm->ipp_vec1, tm->len);
    asmPhase_32fc(tm->asm_comp, tm->asm_vec1, tm->len);
    for (int i = 0; i < tm->len; i++)
    {
        ASSERT_NEAR(tm->ipp_vec1[i], tm->asm_vec1[i], eps);
    }
}

//      ALL RUNNING TIME BENCHMARK
BENCHMARK(allTESTs)->Iterations(1);

//      ADD BENCHMARK
BENCHMARK(ippAdd_32f_B);
BENCHMARK(asmAdd_32f_B);

BENCHMARK(ippAdd_32f_I_B);
BENCHMARK(asmAdd_32f_I_B);

BENCHMARK(ippAddC_32fc_B);
BENCHMARK(asmAddC_32fc_B);

BENCHMARK(ippAddC_32fc_I_B);
BENCHMARK(asmAddC_32fc_I_B);

BENCHMARK(ippAdd_16s32f_B);
BENCHMARK(asmAdd_16s32f_B);

//      SUB BENCHMARK
BENCHMARK(ippSub_32f_B);
BENCHMARK(asmSub_32f_B);

BENCHMARK(ippSub_32f_I_B);
BENCHMARK(asmSub_32f_I_B);

BENCHMARK(ippSubC_32f_I_B);
BENCHMARK(asmSubC_32f_I_B);

//      MUL BENCHMARK
BENCHMARK(ippMulC_32f_I_B);
BENCHMARK(asmMulC_32f_I_B);

BENCHMARK(ippMul_32f_B);
BENCHMARK(asmMul_32f_B);

BENCHMARK(ippMul_32f_I_B);
BENCHMARK(asmMul_32f_I_B);

BENCHMARK(ippMulC_32fc_I_B);
BENCHMARK(asmMulC_32fc_I_B);

BENCHMARK(ippMulC_32fc_B);
BENCHMARK(asmMulC_32fc_B);

BENCHMARK(ippMul_32fc_I_B);
BENCHMARK(asmMul_32fc_I_B);

BENCHMARK(ippMulC_16s_I_B);
BENCHMARK(asmMulC_16s_I_B);

//      DIV BENCHMARK
BENCHMARK(ippDivC_32f_I_B);
BENCHMARK(asmDivC_32f_I_B);

//      SQRT BENCHMARK
BENCHMARK(ippSqrt_32f_I_B);
BENCHMARK(asmSqrt_32f_I_B);

//      SQR BENCHMARK
BENCHMARK(ippSqr_32f_B);
BENCHMARK(asmSqr_32f_B);

//      MAX BENCHMARK
BENCHMARK(ippMax_32f_B);
BENCHMARK(asmMax_32f_B);

BENCHMARK(ippMaxEvery_32f_I_B);
BENCHMARK(asmMaxEvery_32f_I_B);

BENCHMARK(ippMaxIndx_32f_B);
BENCHMARK(asmMaxIndx_32f_B);

//      ZERO BENCHMARK
BENCHMARK(ippZero_32f_B);
BENCHMARK(asmZero_32f_B);

BENCHMARK(ippZero_64f_B);
BENCHMARK(asmZero_64f_B);

BENCHMARK(ippZero_32fc_B);
BENCHMARK(asmZero_32fc_B);

//      SET BENCHMARK
BENCHMARK(ippSet_32f_B);
BENCHMARK(asmSet_32f_B);

BENCHMARK(ippSet_64f_B);
BENCHMARK(asmSet_64f_B);

//      SUM BENCHMARK
BENCHMARK(ippSum_32f_B);
BENCHMARK(asmSum_32f_B);

BENCHMARK(ippSum_32fc_B);
BENCHMARK(asmSum_32fc_B);

//      ABS IPP
BENCHMARK(ippAbs_32f_I_B);
BENCHMARK(asmAbs_32f_I_B);

//      CPLX IPP
BENCHMARK(ippRealToCplx_32f_B);
BENCHMARK(asmRealToCplx_32f_B);

BENCHMARK(ippCplxToReal_16sc_B);
BENCHMARK(asmCplxToReal_16sc_B);

//		CONVER IPP
BENCHMARK(ippConvert_16s32f_B);
BENCHMARK(asmConvert_16s32f_B); // ошибка

BENCHMARK(ippConvert_32f16u_Sfs_B);
BENCHMARK(asmConvert_32f16u_Sfs_B); // ошибка

BENCHMARK(ippConvert_32f16s_Sfs_B);
BENCHMARK(asmConvert_32f16s_Sfs_B); // ошибка

//      COPY IPP
BENCHMARK(ippCopy_32fc_B);
BENCHMARK(asmCopy_32fc_B);

BENCHMARK(ippCopy_32f_B);
BENCHMARK(asmCopy_32f_B); // выводит len

//      CONJ IPP
BENCHMARK(ippConj_32fc_B);
BENCHMARK(asmConj_32fc_B);

BENCHMARK(ippConj_32fc_I_B);
BENCHMARK(asmConj_32fc_I_B);

//      MEAN IPP
BENCHMARK(ippMean_32f_B);
BENCHMARK(asmMean_32f_B);

//      MAGNITUDE IPP
BENCHMARK(ippMagnitude_32fc_B);
BENCHMARK(asmMagnitude_32fc_B);

BENCHMARK(ippMagnitude_32f_B);
BENCHMARK(asmMagnitude_32f_B);

BENCHMARK(ippMagnitude_16sc32f_B);
BENCHMARK(asmMagnitude_16sc32f_B);

//      PROD IPP
BENCHMARK(ippDotProd_32f_B);
BENCHMARK(asmDotProd_32f_B);

BENCHMARK(ippDotProd_32fc_B);
BENCHMARK(asmDotProd_32fc_B);

//      POLAR IPP
BENCHMARK(ippPolarToCart_32f_B);
BENCHMARK(asmPolarToCart_32f_B);

BENCHMARK(ippPolarToCart_32fc_B);
BENCHMARK(asmPolarToCart_32fc_B);

//      FFT IPP
BENCHMARK(ippFFTInit_C_32fc_B);
BENCHMARK(asmFFTInit_C_32fc_B);

BENCHMARK(ippFFTGetSize_C_32fc_B);
BENCHMARK(asmFFTGetSize_C_32fc_B);

BENCHMARK(ippFFTFwd_CToC_32fc_I_B);
BENCHMARK(asmFFTFwd_CToC_32fc_I_B);

BENCHMARK(ippFFTInv_CToC_32fc_I_B);
BENCHMARK(asmFFTInv_CToC_32fc_I_B);

//      POWER IPP
BENCHMARK(ippPowerSpectr_32fc_B);
BENCHMARK(asmPowerSpectr_32fc_B);

//      WIN IPP
BENCHMARK(ippWinHamming_32fc_I_B);
BENCHMARK(asmWinHamming_32fc_I_B);

BENCHMARK(ippWinHann_32fc_I_B);
BENCHMARK(asmWinHann_32fc_I_B);

//      PHASE IPP
BENCHMARK(ippPhase_32fc_B);
BENCHMARK(asmPhase_32fc_B);


BENCHMARK_MAIN();



//int main()
//{
//    auto start = std::chrono::steady_clock::now();
//    printf("Allocation starts\n\n");
//    mainCheackedTest();
//    //
//    //int order = 10;
//    //const int len = pow(2, order);
//    //int len = 1600000;
//
//    //          IPP_INIT
//    //Ipp32fc* ipp_comp = new Ipp32fc[len];
//    //Ipp32fc* ipp_comp1 = new Ipp32fc[len];
//    //Ipp32fc ipp_dstc; = new Ipp32fc[len];
//    //Ipp32f* ipp_vec1 = new Ipp32f[len];
//    //Ipp32f* ipp_vec2 = new Ipp32f[len];
//    //Ipp32f* ipp_vec3 = new Ipp32f[len];
//    //Ipp32f* ipp_vec4 = new Ipp32f[len];
//
//    //   Ipp64f* ipp_d1 = new Ipp64f[len];
//     //  Ipp64f* ipp_d2 = new Ipp64f[len];
//    //   Ipp64fc* ipp_dcomp = new Ipp64fc[len];
//
//   //    Ipp16s* ipp_vec_s1 = (Ipp16s*)malloc(sizeof(Ipp16s) * len);
//   //    Ipp16s* ipp_vec_s2 = (Ipp16s*)malloc(sizeof(Ipp16s) * len);
//   //    Ipp16sc* ipp_vec_sc = (Ipp16sc*)malloc(sizeof(Ipp16sc) * len);
//   //    Ipp16u* ipp_vec_u1 = (Ipp16u*)malloc(sizeof(Ipp16u) * len);
//
//     //  Ipp64f* ipp_dst64 = (Ipp64f*)malloc(sizeof(Ipp64f) * 1);
//    //Ipp32f* ipp_dst = new Ipp32f[len];
//    //
//    //
//    //
//    //
//    //float ipp_float = 4.7984f;
//    //float fake_ipp_float = 4.7983f;
//    //float eps = 0.00001;
//
//
//
//
//
//
//
//
//    //int* ipp_indx = (int*)malloc(sizeof(int) * len);
//    //          IPP INIT END        \\
//
//     //          FAKE INIT
//    //Ipp32fc* ipp_comp = new Ipp32fc[len];
//    //Ipp32fc* ipp_comp1 = new Ipp32fc[len];
//    //Ipp32fc* ipp_dstc = new Ipp32fc[len];
//    //Asm32f* asm_vec1 = new Asm32f[len];
//    //Asm32fc* asm_comp1 = new Asm32fc[len];
//    //Asm32fc* dstc = new Asm32fc[len];
//    //Ipp32f* ipp_vec2 = new Ipp32f[len];
//    //Ipp32f* ipp_vec3 = new Ipp32f[len];
//    //Ipp32f* ipp_vec4 = new Ipp32f[len];
//
//    //   Ipp64f* ipp_d1 = new Ipp64f[len];
//     //  Ipp64f* ipp_d2 = new Ipp64f[len];
//    //   Ipp64fc* ipp_dcomp = new Ipp64fc[len];
//
//   //    Ipp16s* ipp_vec_s1 = (Ipp16s*)malloc(sizeof(Ipp16s) * len);
//   //    Ipp16s* ipp_vec_s2 = (Ipp16s*)malloc(sizeof(Ipp16s) * len);
//   //    Ipp16sc* ipp_vec_sc = (Ipp16sc*)malloc(sizeof(Ipp16sc) * len);
//   //    Ipp16u* ipp_vec_u1 = (Ipp16u*)malloc(sizeof(Ipp16u) * len);
//
//     //  Ipp64f* ipp_dst64 = (Ipp64f*)malloc(sizeof(Ipp64f) * 1);
//    //Ipp32f* ipp_dst = new Ipp32f[len];
//    //int* ipp_indx = (int*)malloc(sizeof(int) * len);
//    //          FAKE INIT END        \\
//
//
//    //for (int i = 0; i < len; i++)
//    //{
//        // FLOAT
//
//        //ipp_vec1[i] = sin(3.14 * i / len) + i % 1220;
//        //asm_vec1[i] = sin(3.14 * i / len) + i % 1220;
//        /*ipp_vec2[i] = 1.156794f + i % 4;
//        ipp_vec1[i] = 1.1273f + i % 4;
//        ipp_vec2[i] = 1.1273f + i % 4;*/
//
//        //        ipp_dst[i] = -1* i/4 * 4.0f;
//        //        ipp_dcomp[i].re = sin(3.14 * i);
//        //        ipp_dcomp[i].im = cos(3.14 * i);
//
//        //// ========================
//
//        //// DOUBLE
////        ipp_d1[i] = 1.12256799 + i % 4;
////        ipp_d2[i] = 1.12256799 + i % 4;
//
////        //========================
//
////        ipp_vec_sc[i].re = 4 + i % 16;
////        ipp_vec_sc[i].im = 7 + i % 16;
//
////        ipp_vec_s1[i] = 4 + i % 16;
////        ipp_vec_s2[i] = 4;
//
//        //ipp_comp[i].re = sin(3.14 * i);
//        //ipp_comp[i].im = cos(3.14 * i);
//
//        //ipp_comp1[i].re = i;
//        //ipp_comp1[i].im = i / 4;
//        //asm_comp1[i].re = i;
//        //asm_comp1[i].im = i / 4;
//
//        /*ipp_comp1[i].re = cos(64.3512 * i / len);
//        ipp_comp1[i].im = sin(64.3512 * i / len);*/
//
//        //        ipp_dstc[i].re = i/2*3.0f;
//        //        ipp_dstc[i].im = i/2*4.0f;
//    //}
//    //    ipp_vec1[47] = 4700.0f;
//
//        //ipp_vec1[len / 2 - 1] = 3;
//
//    // FFT preparation
//    /*IppsFFTSpec_C_32fc** ppFFTSpec;
//    Ipp8u* pSpec;
//    Ipp8u* pSpecBuffer;
//    Ipp8u* pBuf;
//
//    ppFFTSpec = new IppsFFTSpec_C_32fc*;
//    int pSpecSize(0);
//    int pSpecBufferSize(0);
//    int pBufferSize(0);*/
//
//
//    //ippsFFTGetSize_C_32fc(order, IPP_FFT_DIV_INV_BY_N, ippAlgHintNone, &pSpecSize, &pSpecBufferSize, &pBufferSize);
//
//    //pSpec = new Ipp8u[pSpecSize];
//    //pSpecBuffer = (pSpecBufferSize > 0) ? new Ipp8u[pSpecBufferSize] : NULL;
//    //pBuf = new Ipp8u[pBufferSize];
//    //ippsFFTInit_C_32fc(ppFFTSpec, order, IPP_FFT_DIV_INV_BY_N, ippAlgHintNone, pSpec, pSpecBuffer);
//    //Ipp32fc val_c = { 1.55532f, 2.3231f };
//    //Asm32fc asm_val_c = { 1.55532f, 2.3231f };
//    //ippsAddC_32fc(ipp_comp1, val_c, ipp_dstc, len);
//    //asmAddC_32fc(asm_comp1, asm_val_c, dstc, len);
//
//
//    //printf("Allocation ended\n\n");
//
//    // IPP
//
//   //ippsMaxIndx_32f(ipp_vec1, len, ipp_dst, ipp_indx);
//   //Ipp32fc ipp_valc = {10.0f, 10.0f};
//   //ippsAddC_32fc_I(ipp_valc, ipp_comp, len);
//   //ippsSum_32fc(ipp_comp, len, ipp_dstc, ippAlgHintNone);
//   //ippsMulC_32fc(ipp_comp, ipp_valc, ipp_dstc, len);
//   //ippsMul_32fc_I(ipp_comp, ipp_dstc, len);
//   //ippsMul_32f(ipp_vec1, ipp_vec2, ipp_dst, len);
//   //ippsSet_64f(4.7, c4, len); //çàïîëíåíèå âåêòîðà ÷èñëîì
//   //ippsSum_32f(ipp_vec1, len, ipp_dst, ippAlgHintNone);
//   //ippsMul_32f_I(ipp_vec1, ipp_vec2, len);
//   //ippsDivC_32f_I(4.7f, ipp_vec2, len);
//   //ippsSqr_32f(ipp_vec1, ipp_dst, len);
//   //ippsRealToCplx_32f(ipp_vec1, ipp_vec2, ipp_dstc, len);
//   //ippsZero_32fc(ipp_dstc, len);
//   //ippsCopy_32fc(ipp_comp, ipp_dstc, len);
//   //ippsCopy_32f(ipp_vec1, ipp_dst, len);
//   //ippsRealToCplx_32f(ipp_vec1, ipp_vec2, ipp_dstc, len);
//   //ippsConj_32fc(ipp_comp, ipp_dstc, len);
//   //ippsCopy_32fc(ipp_comp, ipp_dstc, len);
//   //ippsCopy_32f(ipp_vec1, ipp_dst, len);
//   //ippsAddC_32fc(ipp_comp, ipp_valc, ipp_dstc, len);
//   //ippsConj_32fc_I(ipp_dstc, len);
//   //ippsMean_32f(ipp_vec1, len, ipp_dst, ippAlgHintNone);
//   //ippsMax_32f(ipp_vec1, len, ipp_dst);
//   //ippsAdd_32f_I(ipp_vec1, ipp_dst, len);
//   //ippsAddC_32fc_I(ipp_valc, ipp_dstc, len);
//   //ippsZero_64f(ipp_dst64, len);
//
//   //Ipp32fc ipp_valc = {10.0f, 10.0f};
//   //ippsSub_32f_I(ipp_vec1, ipp_dst, len);
//   //ippsSubC_32f_I(10.0f, ipp_dst, len);
//   //ippsZero_32fc(ipp_dstc, len);
//   //ippsSet_32f(4.7, ipp_dst, len);
//   //ippsSet_64f(4.7, ipp_dst64, len);
//   //ippsMul_32fc_I(ipp_comp, ipp_dstc, len);
//   //ippsAbs_32f_I(ipp_dst, len);
//   //ippsConvert_16s32f(ipp_vec_s, ipp_dst, len);
//   //ippsAdd_16s32f(ipp_vec_s, ipp_vec_s2, ipp_dst, len);
//   //ippsMagnitude_32fc(ipp_comp, ipp_dst, len);
//   //ippsMagnitude_32f(ipp_vec1, ipp_vec2, ipp_dst, len);
//   //ippsMagnitude_16sc32f(ipp_vec_sc, ipp_dst, len);
//   //ippsMean_32f(ipp_vec1, len, ipp_dst, ippAlgHintNone);
//   //ippsSum_32f(ipp_vec1, len, ipp_dst, ippAlgHintNone);
//   //ippsDotProd_32f(ipp_vec1, ipp_vec2, len, ipp_dst);
//   //ippsDotProd_64f(ipp_d1, ipp_d2, len, ipp_dst64);
//   //ippsMul_32f_I(ipp_vec1, ipp_dst, len);
//   //ippsWinHamming_32fc_I(ipp_dstc, len);
//   //ippsWinHann_32fc_I(ipp_dstc, len);
//   //ippsDotProd_32fc(ipp_comp, ipp_comp1, len, ipp_dstc);
//   //ippsPolarToCart_32f(ipp_vec1, ipp_vec2, ipp_vec3, ipp_vec4, len);
//   //ippsPolarToCart_32fc(ipp_vec1, ipp_vec2, ipp_dstc, len);
//   //ippsPhase_32fc(ipp_comp, ipp_dst, len);
//   //ippsPowerSpectr_32fc(ipp_comp, ipp_dst, len);
//   //ippsCplxToReal_16sc(ipp_vec_sc, ipp_vec_s1, ipp_vec_s2, len);
//   //ippsConvert_32f16u_Sfs(ipp_vec1, ipp_vec_u1, len, ippRndZero, 0);
//   //ippsMulC_16s_I(131, ipp_vec_s1, len);
//   //ippsSqrt_32f_I(ipp_vec1, len);
//   //ippsSum_32fc(ipp_comp1, len, &ipp_dstc, ippAlgHintNone);
//   //ippsMaxIndx_32f(ipp_vec1, len, &ipp_dst, &ipp_idx);
//
//
//
//    //    int ipp_idx = 0;
//   /* ippsFFTInv_CToC_32fc_I(ipp_comp, *ppFFTSpec, pBuf);
//
//    delete[] pSpec;
//    delete[] pSpecBuffer;
//    delete[] pBuf;
//    delete ppFFTSpec;*/
//
//    /*for (int i = 0; i < len; ++i)
//        printf("Ipp:%f  %f\n", ipp_comp[i].re, ipp_comp[i].im);
//    printf(">-----------------------BEGIN-----------------------<\n");*/
//
//    //for (int i = 0; i < 20; ++i)
//      //  printf("Ipp:%f %f \t Fake: %f %f\n", ipp_dstc[i].re, ipp_dstc[i].im, dstc[i].re, dstc[i].im);
//    //printf(">-----------------------BEGIN-----------------------<\n");
//
//
//    //delete[] ipp_vec1;
//    //delete[] asm_vec1;
//    //delete[] ipp_comp;
//    //delete[] dstc;
//    //delete[] ipp_dstc;
//    //delete[] asm_comp1;
//    //free(ipp_comp1);
//    //    free(ipp_vec_s1);
//    //    free(ipp_vec_s2);
//    //    free(ipp_vec_sc);
//    //    free(ipp_vec_u1);
//
//    //    _mm_free(s1);
//    //    _mm_free(s2);
//       // _mm_free(sc);
//     //   _mm_free(u1);
//
//
//    //delete[] ipp_dst;
//    //free(ipp_dst64);
////    free(ipp_d1);
////    free(ipp_d2);
//   // free(ipp_dcomp);
//    //free(ipp_dstc);
//
//    auto end = std::chrono::steady_clock::now();
//    std::cout << "Elapsed time in nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << std::endl;
//    return 0;
//}