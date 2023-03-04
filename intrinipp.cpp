#include "intrinipp.h"
#include <stdio.h>
//#include <omp.h>



// СЛОЖЕНИЕ
AsmStatus asmAdd_32f(Asm32f* fst, Asm32f* snd, Asm32f* dst, int len)
{
    if (!dst || !fst || !snd)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;
    //#ifndef __QNXMNTO__
    //
    //#endif
        //#pragma omp parallel for
    int decr = len & ~0x03;
    for (int i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&dst[i], _mm_add_ps(
            _mm_set_ps(fst[i], fst[i + 1], fst[i + 2], fst[i + 3]),
            _mm_set_ps(snd[i], snd[i + 1], snd[i + 2], snd[i + 3])));
    }

    //    for (i; i < len; i++)
    //        dst[i] = fst[i] + snd[i];

    if (decr == len - 1)
    {
        dst[decr] = fst[decr] + snd[decr];
    }
    else if (decr == len - 2)
    {
        dst[decr] = fst[decr] + snd[decr];
        dst[decr + 1] = fst[decr + 1] + snd[decr + 1];
    }
    else
    {
        dst[decr] = fst[decr] + snd[decr];
        dst[decr + 1] = fst[decr + 1] + snd[decr + 1];
        dst[decr + 2] = fst[decr + 2] + snd[decr + 2];
    }

    return asmStsNoErr;
}


AsmStatus asmAdd_32f_I(Asm32f* pSrc, Asm32f* pSrcDst, int len)
{
    if (!pSrc || !pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    int decr = len & ~0x03;
    int i = 0;
    for (i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_add_ps(
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]),
            _mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3])));
    }

    for (i; i < len; i++)
        pSrcDst[i] += pSrc[i];

    //    if (decr == len - 1)
    //    {
    //        pSrcDst[decr] += pSrc[decr];

    //    }
    //    else if (decr == len - 2)
    //    {
    //        pSrcDst[decr] += pSrc[decr];
    //        pSrcDst[decr+1] += pSrc[decr+1];
    //    }
    //    else
    //    {
    //        pSrcDst[decr] += pSrc[decr];
    //        pSrcDst[decr+1] += pSrc[decr+1];
    //        pSrcDst[decr+2] += pSrc[decr+2];
    //    }


    return asmStsNoErr;
}

AsmStatus asmAddC_32fc(const Asm32fc* pSrc, Asm32fc val, Asm32fc* pDst, int len)
{
    //    #pragma omp parallel for
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_add_ps(_mm_set_ps(val.re, val.im, val.re, val.im), _mm_set_ps(pSrc[i].re, pSrc[i].im, pSrc[i + 1].re, pSrc[i + 1].im)));
        _mm_storer_ps(&pDst[i + 2].re, _mm_add_ps(_mm_set_ps(val.re, val.im, val.re, val.im), _mm_set_ps(pSrc[i + 2].re, pSrc[i + 2].im, pSrc[i + 3].re, pSrc[i + 3].im)));
    }

    for (i; i < len; i++)
    {
        pDst[i].re = pSrc[i].re + val.re;
        pDst[i].im = pSrc[i].im + val.im;
    }

    return asmStsNoErr;
}

AsmStatus asmAddC_32fc_I(Asm32fc val, Asm32fc* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i].re, _mm_add_ps(_mm_set_ps(val.re, val.im, val.re, val.im), _mm_set_ps(pSrcDst[i].re, pSrcDst[i].im, pSrcDst[i + 1].re, pSrcDst[i + 1].im)));
        _mm_storer_ps(&pSrcDst[i + 2].re, _mm_add_ps(_mm_set_ps(val.re, val.im, val.re, val.im), _mm_set_ps(pSrcDst[i + 2].re, pSrcDst[i + 2].im, pSrcDst[i + 3].re, pSrcDst[i + 3].im)));
    }

    for (i; i < len; i++)
    {
        pSrcDst[i].re = pSrcDst[i].re + val.re;
        pSrcDst[i].im = pSrcDst[i].im + val.im;
    }

    return asmStsNoErr;
}

AsmStatus asmAdd_16s32f(const Asm16s* pSrc1, const Asm16s* pSrc2, Asm32f* pDst, int len)
{
    if (!pDst || !pSrc1 || !pSrc2)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    /*int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_store_ps(&pDst[i],  _mm_add_ps(
            _mm_cvtpi16_ps(_mm_set_pi16(pSrc1[i], pSrc1[i + 1], pSrc1[i + 2], pSrc1[i + 3])),
            _mm_cvtpi16_ps(_mm_set_pi16(pSrc2[i], pSrc2[i + 1], pSrc2[i + 2], pSrc2[i + 3]))));
    }
    for (i; i < decr; ++i)
    {
        pDst[i] = (float)(pSrc1[i]+pSrc2[i]);
    }*/

    return asmStsNoErr;
}

//////////////

// ВЫЧИТАНИЕ
AsmStatus asmSub_32f(Asm32f* fst, Asm32f* snd, Asm32f* dst, int len)
{
    if (!fst || !snd || !dst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&dst[i], _mm_sub_ps(
            _mm_set_ps(snd[i], snd[i + 1], snd[i + 2], snd[i + 3]),
            _mm_set_ps(fst[i], fst[i + 1], fst[i + 2], fst[i + 3])));
    }


    for (i; i < len; i++)
    {
        dst[i] = snd[i] - fst[i];
    }

    return asmStsNoErr;
}


AsmStatus asmSub_32f_I(Asm32f* pSrc, Asm32f* pSrcDst, int len)
{
    if (!pSrc || !pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_sub_ps(
            _mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3]),
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3])));
    }

    for (i; i < len; i++)
    {
        pSrcDst[i] -= pSrc[i];
    }


    return asmStsNoErr;
}

AsmStatus asmSubC_32f_I(Asm32f value, Asm32f* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_sub_ps(
            _mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3]),
            _mm_set_ps1(value)));
    }

    for (i; i < len; i++)
    {
        pSrcDst[i] -= value;
    }

    return asmStsNoErr;
}
////////////

// заполнение вектора
AsmStatus asmZero_32f(Asm32f* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x07;
    int i = 0;

    for (i; i < decr; i += 8)
    {
        _mm_store_ps1(&pSrc[i], _mm_setzero_ps());
        _mm_store_ps1(&pSrc[i + 4], _mm_setzero_ps());
    }

    for (i; i < len; i++)
    {
        pSrc[i] = 0;
    }

    return asmStsNoErr;
}

AsmStatus asmZero_64f(Asm64f* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    //memset(pSrc, 0, len * sizeof(Asm64f));
    int decr = len & ~0x01;
    for (int i = 0; i < decr; i += 2)
    {
        _mm_store1_pd(&pSrc[i], _mm_setzero_pd());
    }

    if (decr != len)
        pSrc[decr] = 0;

    return asmStsNoErr;
}


AsmStatus asmZero_32fc(Asm32fc* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    //memset(pSrc, 0, len * sizeof(Asm32fc));
    for (int i = 0; i < len / 2; i += 2)
    {
        _mm_store1_ps(&pSrc[i].re, _mm_setzero_ps());
        _mm_store1_ps(&pSrc[len - i - 2].re, _mm_setzero_ps());
    }
    return asmStsNoErr;
}


// заполнение числом
AsmStatus asmSet_32f(Asm32f value, Asm32f* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    //#pragma omp parallel for
    for (i; i < decr; i += 4)
    {
        _mm_store_ps1(&pSrc[i], _mm_set_ps1(value));
    }

    for (i; i < len; ++i)
    {
        pSrc[i] = value;
    }
    return asmStsNoErr;
}

AsmStatus asmSet_64f(Asm64f value, Asm64f* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    int decr = len & ~0x01;
    int i = 0;
    //#pragma omp parallel for

    for (i; i < decr; i += 2)
    {
        _mm_store1_pd(&pSrc[i], _mm_set1_pd(value));
    }

    for (i; i < len; ++i)
    {
        pSrc[i] = value;
    }
    return asmStsNoErr;
}

////////////


// сумма

AsmStatus asmSum_32f(Asm32f* pSrc, int len, Asm32f* pSum)
{
    if (!pSrc || !pSum)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    __m128d sum = _mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[1], pSrc[0]));

    int decr = len & ~0x01, i = 2;
    for (i; i < decr; i += 2)
    {
        sum = _mm_add_pd(_mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[i + 1], pSrc[0])), sum);
    }

    sum = _mm_add_pd(sum, _mm_shuffle_pd(sum, sum, _MM_SHUFFLE64(0, 1)));
    _mm_store_ss(pSum, _mm_cvtpd_ps(sum));

    for (i; i < len; ++i)
    {
        *pSum += pSrc[i];
    }

    return asmStsNoErr;
}

AsmStatus asmSum_32fc(Asm32fc* pSrc, int len, Asm32fc* dst)
{
    if (!pSrc || !dst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    __m128d sum_re = _mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[1].re, pSrc[0].re));
    __m128d sum_im = _mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[1].im, pSrc[0].im));

    int decr = len & ~0x01, i = 2;

    for (i; i < decr; i += 2)
    {
        sum_re = _mm_add_pd(_mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[i + 1].re, pSrc[i].re)), sum_re);
        sum_im = _mm_add_pd(_mm_cvtps_pd(_mm_set_ps(0.0, 0.0, pSrc[i + 1].im, pSrc[i].im)), sum_im);
    }

    sum_re = _mm_add_pd(sum_re, _mm_shuffle_pd(sum_re, sum_re, _MM_SHUFFLE64(0, 1)));
    sum_im = _mm_add_pd(sum_im, _mm_shuffle_pd(sum_im, sum_im, _MM_SHUFFLE64(0, 1)));

    _mm_store_ss(&dst->re, _mm_cvtpd_ps(sum_re));
    _mm_store_ss(&dst->im, _mm_cvtpd_ps(sum_im));

    for (i; i < len; ++i)
    {
        dst->re += pSrc[i].re;
        dst->im += pSrc[i].im;
    }
    return asmStsNoErr;
}

///////////


// умножение
AsmStatus asmMulC_32f_I(Asm32f value, Asm32f* pSrc, int len)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrc[i], _mm_mul_ps(_mm_set_ps1(value),
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3])));
    }

    for (i; i < len; ++i)
    {
        pSrc[i] *= value;
    }

    return asmStsNoErr;
}


AsmStatus asmMul_32f(Asm32f* fst, Asm32f* snd, Asm32f* dst, int len)
{
    if (!fst || !snd || !dst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&dst[i], _mm_mul_ps(
            _mm_set_ps(fst[i], fst[i + 1], fst[i + 2], fst[i + 3]),
            _mm_set_ps(snd[i], snd[i + 1], snd[i + 2], snd[i + 3])));
    }
    for (i; i < len; ++i)
    {
        dst[i] = fst[i] * snd[i];
    }

    return asmStsNoErr;
}


AsmStatus asmMul_32f_I(Asm32f* pSrc, Asm32f* pSrcDst, int len)
{
    if (!pSrc || !pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_mul_ps(
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]),
            _mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3])));
    }
    for (i; i < len; ++i)
    {
        pSrcDst[i] *= pSrc[i];
    }

    return asmStsNoErr;
}



AsmStatus asmMulC_32fc_I(Asm32fc value, Asm32fc* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    //res.re = re * value.re - im * value.im;
    //res.im = re * value.im + im * value.re;
    __m128 val_res = _mm_set_ps(value.re, value.im, value.re, value.im);
    __m128 val_im = _mm_set_ps(-1 * value.im, value.re, -1 * value.im, value.re);

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i].re, _mm_add_ps(_mm_mul_ps(val_res, _mm_set_ps(pSrcDst[i].re, pSrcDst[i].re, pSrcDst[i + 1].re, pSrcDst[i + 1].re)),
            _mm_mul_ps(val_im, _mm_set_ps(pSrcDst[i].im, pSrcDst[i].im, pSrcDst[i + 1].im, pSrcDst[i + 1].im))));
        _mm_storer_ps(&pSrcDst[i + 2].re, _mm_add_ps(_mm_mul_ps(val_res, _mm_set_ps(pSrcDst[i + 2].re, pSrcDst[i + 2].re, pSrcDst[i + 3].re, pSrcDst[i + 3].re)),
            _mm_mul_ps(val_im, _mm_set_ps(pSrcDst[i + 2].im, pSrcDst[i + 2].im, pSrcDst[i + 3].im, pSrcDst[i + 3].im))));
    }

    for (i; i < len; ++i)
    {
        pSrcDst[i].re *= pSrcDst[i].re * value.re - pSrcDst[i].im * value.im;
        pSrcDst[i].im *= pSrcDst[i].re * value.im + pSrcDst[i].im * value.re;
    }

    return asmStsNoErr;
}

AsmStatus asmMulC_32fc(const Asm32fc* pSrc, Asm32fc value, Asm32fc* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    //res.re = re * value.re - im * value.im;
    //res.im = re * value.im + im * value.re;
    __m128 val_res = _mm_set_ps(value.re, value.im, value.re, value.im);
    __m128 val_im = _mm_set_ps(-1 * value.im, value.re, -1 * value.im, value.re);


    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_add_ps(_mm_mul_ps(val_res, _mm_set_ps(pSrc[i].re, pSrc[i].re, pSrc[i + 1].re, pSrc[i + 1].re)),
            _mm_mul_ps(val_im, _mm_set_ps(pSrc[i].im, pSrc[i].im, pSrc[i + 1].im, pSrc[i + 1].im))));
        _mm_storer_ps(&pDst[i + 2].re, _mm_add_ps(_mm_mul_ps(val_res, _mm_set_ps(pSrc[i + 2].re, pSrc[i + 2].re, pSrc[i + 3].re, pSrc[i + 3].re)),
            _mm_mul_ps(val_im, _mm_set_ps(pSrc[i + 2].im, pSrc[i + 2].im, pSrc[i + 3].im, pSrc[i + 3].im))));
    }

    for (i; i < len; ++i)
    {
        pDst[i].re *= pSrc[i].re * value.re - pSrc[i].im * value.im;
        pDst[i].im *= pSrc[i].re * value.im + pSrc[i].im * value.re;
    }

    return asmStsNoErr;
}

AsmStatus asmMul_32fc_I(Asm32fc* pSrc, Asm32fc* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    //res.re = re * value.re - im * value.im;
    //res.im = re * value.im + im * value.re;

    int decr = len & ~0x03;

    for (int i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_add_ps(_mm_mul_ps(_mm_set_ps(pDst[i].re, pDst[i].im, pDst[i + 1].re, pDst[i + 1].im),
            _mm_set_ps(pSrc[i].re, pSrc[i].re, pSrc[i + 1].re, pSrc[i + 1].re)),
            _mm_mul_ps(_mm_set_ps(-1 * pDst[i].im, pDst[i].re, -1 * pDst[i + 1].im, pDst[i + 1].re),
                _mm_set_ps(pSrc[i].im, pSrc[i].im, pSrc[i + 1].im, pSrc[i + 1].im))));

        _mm_storer_ps(&pDst[i + 2].re, _mm_add_ps(_mm_mul_ps(_mm_set_ps(pDst[i + 2].re, pDst[i + 2].im, pDst[i + 3].re, pDst[i + 3].im),
            _mm_set_ps(pSrc[i + 2].re, pSrc[i + 2].re, pSrc[i + 3].re, pSrc[i + 3].re)),
            _mm_mul_ps(_mm_set_ps(-1 * pDst[i + 2].im, pDst[i + 2].re, -1 * pDst[i + 3].im, pDst[i + 3].re),
                _mm_set_ps(pSrc[i + 2].im, pSrc[i + 2].im, pSrc[i + 3].im, pSrc[i + 3].im))));
    }

    if (decr == len - 2)
    {
        _mm_storer_ps(&pDst[decr].re, _mm_add_ps(_mm_mul_ps(_mm_set_ps(pDst[decr].re, pDst[decr].im, pDst[decr + 1].re, pDst[decr + 1].im),
            _mm_set_ps(pSrc[decr].re, pSrc[decr].re, pSrc[decr + 1].re, pSrc[decr + 1].re)),
            _mm_mul_ps(_mm_set_ps(-1 * pDst[decr].im, pDst[decr].re, -1 * pDst[decr + 1].im, pDst[decr + 1].re),
                _mm_set_ps(pSrc[decr].im, pSrc[decr].im, pSrc[decr + 1].im, pSrc[decr + 1].im))));
    }
    else if (decr == len - 1)
    {
        Asm32f buf_re = pDst[decr].re;
        Asm32f buf_im = pDst[decr].im;
        pDst[decr].re = buf_re * pSrc[decr].re - buf_im * pSrc[decr].im;
        pDst[decr].im = buf_im * pSrc[decr].re + buf_re * pSrc[decr].im;
    }
    else
    {
        Asm32f buf_re = pDst[decr].re;
        Asm32f buf_im = pDst[decr].im;
        _mm_storer_ps(&pDst[decr].re, _mm_add_ps(_mm_mul_ps(_mm_set_ps(pDst[decr].re, pDst[decr].im, pDst[decr + 1].re, pDst[decr + 1].im),
            _mm_set_ps(pSrc[decr].re, pSrc[decr].re, pSrc[decr + 1].re, pSrc[decr + 1].re)),
            _mm_mul_ps(_mm_set_ps(-1 * pDst[decr].im, pDst[decr].re, -1 * pDst[decr + 1].im, pDst[decr + 1].re),
                _mm_set_ps(pSrc[decr].im, pSrc[decr].im, pSrc[decr + 1].im, pSrc[decr + 1].im))));
        pDst[decr + 2].re = buf_re * pSrc[decr + 2].re - buf_im * pSrc[decr + 2].im;
        pDst[decr + 2].im = buf_im * pSrc[decr + 2].re + buf_re * pSrc[decr + 2].im;
    }



    return asmStsNoErr;
}

AsmStatus asmMulC_16s_I(Asm16s value, Asm16s* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x07, i = 0;

    __m128i num, val, one, two;
    for (i; i < decr; i += 8)
    {
        num = _mm_set_epi16(pSrcDst[i + 7], pSrcDst[i + 6], pSrcDst[i + 5], pSrcDst[i + 4],
            pSrcDst[i + 3], pSrcDst[i + 2], pSrcDst[i + 1], pSrcDst[i]);
        val = _mm_mullo_epi16(num, _mm_set1_epi16(value));
        _mm_stream_si128((__m128i*) & pSrcDst[i], val);
    }

    for (i; i < len; ++i)
    {
        pSrcDst[i] *= value;
    }

    return asmStsNoErr;
}

//////////


// деление
AsmStatus asmDivC_32f_I(Asm32f value, Asm32f* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_div_ps(_mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3]),
            _mm_set_ps1(value)));
    }
    for (i; i < len; ++i)
    {
        pSrcDst[i] /= value;
    }

    return asmStsNoErr;
}
/////////

// квадратный корень
AsmStatus asmSqrt_32f_I(Asm32f* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03, i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_sqrt_ps(_mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3])));
    }
    for (i; i < len; ++i)
    {
        pSrcDst[i] = sqrt(pSrcDst[i]);
    }

    return asmStsNoErr;
}
////////

// возведение в квадрат
AsmStatus asmSqr_32f(const Asm32f* pSrc, Asm32f* pDst, int len)
{
    if (!pDst || !pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i], _mm_mul_ps(
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]),
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3])));
    }
    for (i; i < len; ++i)
    {
        pDst[i] = pSrc[i] * pSrc[i];
    }

    return asmStsNoErr;
}
////////

// максимальное значение
AsmStatus asmMax_32f(const Asm32f* pSrc, int len, Asm32f* pMax)
{
    if (!pSrc)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    __m128 max = _mm_max_ps(_mm_set_ps(pSrc[0], pSrc[1], pSrc[2], pSrc[3]),
        _mm_set_ps(pSrc[4], pSrc[5], pSrc[6], pSrc[7]));


    for (int i = 8; i < len / 2; i += 4)
    {
        max = _mm_max_ps(_mm_max_ps(_mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]), max),
            _mm_max_ps(_mm_set_ps(pSrc[len - i + 7], pSrc[len - i + 6], pSrc[len - i + 5], pSrc[len - i + 4]), max));
    }

    max = _mm_max_ps(max, _mm_shuffle_ps(max, max, _MM_SHUFFLE(2, 3, 0, 1)));
    max = _mm_max_ps(max, _mm_shuffle_ps(max, max, _MM_SHUFFLE(1, 0, 3, 2)));

    _mm_store_ss(pMax, max);

    return asmStsNoErr;
}

AsmStatus asmMaxEvery_32f_I(const Asm32f* pSrc, Asm32f* pSrcDst, int len)
{
    if (!pSrc || !pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;


    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_max_ps(
            _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]),
            _mm_set_ps(pSrcDst[i], pSrcDst[i + 1], pSrcDst[i + 2], pSrcDst[i + 3])));
    }

    for (i; i < len; ++i)
    {
        if (pSrc[i] > pSrcDst[i])
            pSrcDst[i] = pSrc[i];
    }

    return asmStsNoErr;
}

AsmStatus asmMaxIndx_32f(const Asm32f* pSrc, int len, Asm32f* pMax, int* pIndx)
{
    if (!pSrc || !pMax || !pIndx)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;
    __m128 pre_max = _mm_load_ps(pSrc), max = _mm_max_ps(pre_max, _mm_load_ps(pSrc + 4));

    // сравнение работает так: если неравны, то -1, иначе 0 (-1 == true, 0 == false)
    __m128i mask = _mm_castps_si128(_mm_cmpneq_ps(pre_max, max)), not_mask = _mm_add_epi32(mask, _mm_set1_epi32(1));

    int i = 8, decr = len & ~0x03;
    __m128i index = _mm_add_epi32(_mm_mullo_epi32(_mm_abs_epi32(mask), _mm_set_epi32(7, 6, 5, 4)), _mm_mullo_epi32(not_mask, _mm_set_epi32(3, 2, 1, 0)));
    for (i; i < decr; i += 4)
    {
        pre_max = max;
        max = _mm_max_ps(pre_max, _mm_load_ps(pSrc + i));
        mask = _mm_castps_si128(_mm_cmpneq_ps(pre_max, max));
        not_mask = _mm_add_epi32(mask, _mm_set1_epi32(1));
        index = _mm_add_epi32(_mm_mullo_epi32(_mm_abs_epi32(mask), _mm_set_epi32(i + 3, i + 2, i + 1, i)), _mm_mullo_epi32(not_mask, index));
    }

    max = _mm_max_ps(max, _mm_shuffle_ps(max, max, _MM_SHUFFLE(2, 3, 0, 1)));
    max = _mm_max_ps(max, _mm_shuffle_ps(max, max, _MM_SHUFFLE(1, 0, 3, 2)));

    _mm_store_ss(pMax, max);
    not_mask = _mm_castps_si128(_mm_cmpeq_ps(pre_max, max));
    index = _mm_mullo_epi32(_mm_abs_epi32(not_mask), index);

    index = _mm_max_epi32(index, _mm_shuffle_epi32(index, _MM_SHUFFLE(2, 3, 0, 1)));
    index = _mm_max_epi32(index, _mm_shuffle_epi32(index, _MM_SHUFFLE(1, 0, 3, 2)));

    *pIndx = _mm_cvtsi128_si32(index);
    //_mm_storeu_si128((__m128i*)pIndx,  index);

    for (i; i < len; ++i)
    {
        if (pSrc[i] > *pMax)
        {
            *pMax = pSrc[i];
            *pIndx = i;
        }
    }

    return asmStsNoErr;
}
///////


// модуль
AsmStatus asmAbs_32f_I(Asm32f* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i], _mm_max_ps(_mm_load_ps(&pSrcDst[i]), _mm_set_ps(-1 * pSrcDst[i], -1 * pSrcDst[i + 1], -1 * pSrcDst[i + 2], -1 * pSrcDst[i + 3])));
    }

    for (i; i < len; ++i)
    {
        if (pSrcDst[i] < 0)
            pSrcDst[i] *= -1;
    }

    return asmStsNoErr;
}
//////////

// преобразование комплексных чисел

AsmStatus asmRealToCplx_32f(const Asm32f* pSrcRe, const Asm32f* pSrcIm, Asm32fc* pDst, int len)
{
    if (!pSrcRe || !pSrcIm || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;

    //    #pragma simd
    //    #pragma vector aligned
    for (int i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_set_ps(pSrcRe[i], pSrcIm[i], pSrcRe[i + 1], pSrcIm[i + 1]));
        _mm_storer_ps(&pDst[i + 2].re, _mm_set_ps(pSrcRe[i + 2], pSrcIm[i + 2], pSrcRe[i + 3], pSrcIm[i + 3]));
    }

    if (len % 4 > 1)
    {
        int i = decr;
        for (i; i < len; ++i)
        {
            pDst[i].re = pSrcRe[i];
            pDst[i].im = pSrcIm[i];
        }
    }
    else if (len % 4 == 1)
    {
        pDst[decr].re = pSrcRe[decr];
        pDst[decr].im = pSrcIm[decr];
    }

    return asmStsNoErr;
}

AsmStatus asmCplxToReal_16sc(const Asm16sc* pSrc, Asm16s* pDstRe, Asm16s* pDstIm, int len)
{
    if (!pSrc || !pDstRe || !pDstIm)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x07, i = 0;

    for (i; i < decr; i += 8)
    {
        _mm_storeu_si128((__m128i*) & pDstRe[i], _mm_set_epi16(pSrc[i].re, pSrc[i + 1].re, pSrc[i + 2].re, pSrc[i + 3].re,
            pSrc[i + 4].re, pSrc[i + 5].re, pSrc[i + 6].re, pSrc[i + 7].re));
        _mm_storeu_si128((__m128i*) & pDstIm[i], _mm_set_epi16(pSrc[i].im, pSrc[i + 1].im, pSrc[i + 2].im, pSrc[i + 3].im,
            pSrc[i + 4].im, pSrc[i + 5].im, pSrc[i + 6].im, pSrc[i + 7].im));
    }

    for (i; i < len; ++i)
    {
        pDstRe[i] = pSrc[i].re;
        pDstIm[i] = pSrc[i].im;
    }

    return asmStsNoErr;
}

//////////

// Преобразование типов

AsmStatus asmConvert_16s32f(const Asm16s* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    /*for (int i = 0; i < len/2; i += 4)
    {
        _mm_store_ps(&pDst[i], _mm_cvtpi16_ps(_mm_set_pi16(pSrc[i],pSrc[i+1], pSrc[i+2], pSrc[i+3])));
        _mm_store_ps(&pDst[len-i], _mm_cvtpi16_ps(_mm_set_pi16(pSrc[len-i],pSrc[len - i - 1], pSrc[len - i - 2], pSrc[len - i - 3])));
    }*/

    //version 3.0
//    static const __m128i magicInt = _mm_set1_epi16(0x4B00);
//    static const __m128 magicFloat = _mm_set1_ps(8388608.0f);

//    __m128i xlo = _mm_unpacklo_epi16(x, magicInt);
//    __m128i xhi = _mm_unpackhi_epi16(x, magicInt);
//    __m128 ylo = _mm_sub_ps(_mm_castsi128_ps(xlo), magicFloat);
//    __m128 yhi = _mm_sub_ps(_mm_castsi128_ps(xhi), magicFloat);


    //version 2.0
//    __m128i xlo = _mm_unpacklo_epi16(x, _mm_set1_epi16(0));
//    __m128i xhi = _mm_unpackhi_epi16(x, _mm_set1_epi16(0));
//    __m128 ylo = _mm_cvtepi32_ps(xlo);
//    __m128 yhi = _mm_cvtepi32_ps(xhi);
    return asmStsNoErr;
}

AsmStatus asmConvert_32f16u_Sfs(const Asm32f* pSrc, Asm16u* pDst, int len, AsmRoundMode rndMode, int scaleFactor)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    /*if(rndMode == asmRndNear)
        for (int i = 0; i < len/2; i += 4)
        {
            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(
                              _mm_max_ps(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i]), _mm_setzero_ps())));
            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(
                        _mm_max_ps(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i]), _mm_setzero_ps())));
        }
    else if(rndMode == asmRndZero)
        for (int i = 0; i < len/2; i += 4)
        {
            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(_mm_round_ps(
                                            _mm_max_ps(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i]), _mm_setzero_ps()), _MM_FROUND_TO_ZERO)));
            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(_mm_round_ps(
                                            _mm_max_ps(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i]), _mm_setzero_ps()), _MM_FROUND_TO_ZERO)));
        }*/
        //    else if(rndMode == asmRndFinancial)
        //        for (int i = 0; i < len/2; i += 4)
        //        {
        //            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(_mm_round_ps(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i]), _MM_FROUND_));
        //            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i])));
        //        }
    return asmStsNoErr;
}

AsmStatus asmConvert_32f16s_Sfs(const Asm32f* pSrc, Asm16s* pDst, int len, AsmRoundMode rndMode, int scaleFactor)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    /*if(rndMode == asmRndNear)
        for (int i = 0; i < len/2; i += 4)
        {
            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i])));
            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i])));
        }
    else if(rndMode == asmRndZero)
        for (int i = 0; i < len/2; i += 4)
        {
            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(_mm_round_ps(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i]), _MM_FROUND_TO_ZERO)));
            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(_mm_round_ps(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i]), _MM_FROUND_TO_ZERO)));
        }*/
        //    else if(rndMode == asmRndFinancial)
        //        for (int i = 0; i < len/2; i += 4)
        //        {
        //            _mm_stream_pi((__m64*)&pDst[i], _mm_cvtps_pi16(_mm_round_ps(_mm_set_ps(pSrc[i + 3], pSrc[i + 2], pSrc[i + 1], pSrc[i]), _MM_FROUND_));
        //            _mm_stream_pi((__m64*)&pDst[len-i], _mm_cvtps_pi16(_mm_set_ps(pSrc[len-i-3], pSrc[len-i-2], pSrc[len-i-1], pSrc[len-i])));
        //        }
    return asmStsNoErr;
}

//////////

// Копирование данных

AsmStatus asmCopy_32fc(const Asm32fc* pSrc, Asm32fc* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_set_ps(pSrc[i].re, pSrc[i].im, pSrc[i + 1].re, pSrc[i + 1].im));
        _mm_storer_ps(&pDst[i + 2].re, _mm_set_ps(pSrc[i + 2].re, pSrc[i + 2].im, pSrc[i + 3].re, pSrc[i + 3].im));
    }

    for (i; i < len; ++i)
    {
        pDst[i].re = pSrc[i].re;
        pDst[i].im = pSrc[i].im;
    }

    return asmStsNoErr;
}

AsmStatus asmCopy_32f(const Asm32f* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;

    int i = 0;
    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i], _mm_set_ps(pSrc[i], pSrc[i + 1], pSrc[i + 2], pSrc[i + 3]));
    }
    printf("%d", i);
    for (i; i < len; ++i)
    {
        pDst[i] = pSrc[i];
    }


    return asmStsNoErr;
}

//////////

// сопряженное
AsmStatus asmConj_32fc(const Asm32fc* pSrc, Asm32fc* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_set_ps(pSrc[i].re, -1 * pSrc[i].im, pSrc[i + 1].re, -1 * pSrc[i + 1].im));
        _mm_storer_ps(&pDst[i + 2].re, _mm_set_ps(pSrc[i + 2].re, -1 * pSrc[i + 2].im, pSrc[i + 3].re, -1 * pSrc[i + 3].im));
    }

    for (i; i < len; ++i)
    {
        pDst[i].re = pSrc[i].re;
        pDst[i].im = -1 * pSrc[i].im;
    }


    return asmStsNoErr;
}

AsmStatus asmConj_32fc_I(Asm32fc* pSrcDst, int len)
{

    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;
    for (i = 0; i < decr; i += 4)
    {
        _mm_storer_ps(&pSrcDst[i].re, _mm_set_ps(pSrcDst[i].re, -1 * pSrcDst[i].im, pSrcDst[i + 1].re, -1 * pSrcDst[i + 1].im));
        _mm_storer_ps(&pSrcDst[i + 2].re, _mm_set_ps(pSrcDst[i + 2].re, -1 * pSrcDst[i + 2].im, pSrcDst[i + 3].re, -1 * pSrcDst[i + 3].im));
    }

    for (i; i < len; ++i)
    {
        pSrcDst[i].re = pSrcDst[i].re;
        pSrcDst[i].im = -1 * pSrcDst[i].im;
    }


    return asmStsNoErr;
}

//////////

// среднее значение
AsmStatus asmMean_32f(Asm32f* pSrc, int len, Asm32f* pMean)
{
    if (!pSrc || !pMean)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    __m128 mean = _mm_set_ps(pSrc[0], pSrc[1], pSrc[2], pSrc[3]);


    int decr = len & ~0x03;
    int i = 4;
    for (i; i < decr; i += 4)
    {
        mean = _mm_add_ps(_mm_load_ps(&pSrc[i]), mean);
    }

    mean = _mm_add_ps(mean, _mm_shuffle_ps(mean, mean, _MM_SHUFFLE(2, 3, 0, 1)));
    mean = _mm_add_ps(mean, _mm_shuffle_ps(mean, mean, _MM_SHUFFLE(1, 0, 3, 2)));

    _mm_store_ss(pMean, mean);
    for (i; i < len; ++i)
    {
        printf("*pMean = %f, \tpSrc[%d] = %f\n", *pMean, i, pSrc[i]);
        *pMean += pSrc[i];
    }
    *pMean /= len;

    return asmStsNoErr;
}

//////////

// Подсчет длины комплексного числа
AsmStatus asmMagnitude_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    __m128 sqr_buf;/* = _mm_set_ps(pSrc[0].re, pSrc[0].im, pSrc[1].re, pSrc[1].im);*/
    for (i; i < decr; i += 4)
    {
        sqr_buf = _mm_sqrt_ps(_mm_add_ps(_mm_mul_ps(
            _mm_set_ps(pSrc[i].re, pSrc[i + 1].re, pSrc[i + 2].re, pSrc[i + 3].re),
            _mm_set_ps(pSrc[i].re, pSrc[i + 1].re, pSrc[i + 2].re, pSrc[i + 3].re)),
            _mm_mul_ps(
                _mm_set_ps(pSrc[i].im, pSrc[i + 1].im, pSrc[i + 2].im, pSrc[i + 3].im),
                _mm_set_ps(pSrc[i].im, pSrc[i + 1].im, pSrc[i + 2].im, pSrc[i + 3].im))));
        _mm_storer_ps(&pDst[i], sqr_buf);
    }

    for (i; i < len; ++i)
    {
        pDst[i] = sqrt(pSrc[i].re * pSrc[i].re + pSrc[i].im * pSrc[i].im);
    }

    return asmStsNoErr;
}

AsmStatus asmMagnitude_32f(const Asm32f* pSrcRe, const Asm32f* pSrcIm, Asm32f* pDst, int len)
{
    if (!pSrcRe || !pSrcIm || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    __m128 sqr_buf;/* = _mm_set_ps(pSrc[0].re, pSrc[0].im, pSrc[1].re, pSrc[1].im);*/
    for (i; i < decr; i += 4)
    {
        sqr_buf = _mm_sqrt_ps(_mm_add_ps(_mm_mul_ps(
            _mm_set_ps(pSrcRe[i], pSrcRe[i + 1], pSrcRe[i + 2], pSrcRe[i + 3]),
            _mm_set_ps(pSrcRe[i], pSrcRe[i + 1], pSrcRe[i + 2], pSrcRe[i + 3])),
            _mm_mul_ps(
                _mm_set_ps(pSrcIm[i], pSrcIm[i + 1], pSrcIm[i + 2], pSrcIm[i + 3]),
                _mm_set_ps(pSrcIm[i], pSrcIm[i + 1], pSrcIm[i + 2], pSrcIm[i + 3]))));
        _mm_storer_ps(&pDst[i], sqr_buf);
    }

    for (i; i < len; ++i)
    {
        pDst[i] = sqrt(pSrcRe[i] * pSrcRe[i] + pSrcIm[i] * pSrcIm[i]);
    }

    return asmStsNoErr;
}

AsmStatus asmMagnitude_16sc32f(const Asm16sc* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    /* int decr = len & ~0x03;
     int i = 0;

     __m128 sqr_buf, rePart, imPart;
     for (i; i < decr; i += 4)
     {
         rePart = _mm_cvtpi16_ps(_mm_set_pi16(pSrc[i].re, pSrc[i+1].re, pSrc[i+2].re, pSrc[i+3].re));
         imPart = _mm_cvtpi16_ps(_mm_set_pi16(pSrc[i].im, pSrc[i+1].im, pSrc[i+2].im, pSrc[i+3].im));

         sqr_buf = _mm_sqrt_ps((_mm_add_ps(_mm_mul_ps(rePart,rePart),
                                           _mm_mul_ps (imPart, imPart))));
         _mm_storer_ps(&pDst[i], sqr_buf);
     }

     for(i; i < len; ++i)
     {
         pDst[i] = (float)(sqrt(pSrc[i].re * pSrc[i].re + pSrc[i].im * pSrc[i].im));
     }*/

    return asmStsNoErr;
}

//////////

// скалярное произведение
// плохая точность, можно исправить преобразовав float в double
// можно либо преобразовать сначала в __m128, а его в __m64
// скорее всего из-за этого будет просадка по времени
AsmStatus asmDotProd_32f(const Asm32f* pSrc1, const Asm32f* pSrc2, int len, Asm32f* pDp)
{
    //fst[0]*snd[0]+fst[1]*snd[1]+....

    if (!pSrc1 || !pSrc2)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x01;
    int i = 2;

    __m128d scalar = _mm_mul_pd(_mm_cvtps_pd(_mm_load_ps(pSrc1)), _mm_cvtps_pd(_mm_load_ps(pSrc2)));

    for (i; i < decr; i += 2)
    {
        //       scalar = _mm_add_ps(scalar, _mm_mul_ps(/*_mm_cvtps_pd*/(_mm_set_ps(pSrc1[i], pSrc1[i+1], pSrc1[i+2], pSrc1[i+3])),
        //                                              /*_mm_cvtps_pd*/(_mm_set_ps(pSrc2[i], pSrc2[i+1], pSrc2[i+2], pSrc2[i+3]))));
        scalar = _mm_add_pd(scalar, _mm_mul_pd(_mm_cvtps_pd(_mm_load_ps(pSrc1 + i)),
            _mm_cvtps_pd(_mm_load_ps(pSrc2 + i))));
    }
    /*scalar = _mm_add_ps(scalar, _mm_shuffle_ps(scalar, scalar, _MM_SHUFFLE(2, 3, 0, 1)));
    scalar = _mm_add_ps(scalar, _mm_shuffle_ps(scalar, scalar, _MM_SHUFFLE(1, 0, 3, 2)))*/;
    scalar = _mm_add_pd(scalar, _mm_shuffle_pd(scalar, scalar, _MM_SHUFFLE64(0, 1)));

    _mm_store_ss(pDp, _mm_cvtpd_ps(scalar));

    for (i; i < len; ++i)
    {
        *pDp += pSrc1[i] * pSrc2[i];
    }


    // версия из интернетов, может оказаться быстрее за счет подзагрузки в кэш

 //    int i;
 //    __m128 *xx,*yy;
 //    __m128 p,s;

 //    xx=(__m128 *)pSrc1;
 //    yy=(__m128 *)pSrc2;
 //    s=_mm_set_ps1(0);

 //    for (i=0;i<len/4;i++)
 //    { // предвыборка данных в кэш (на несколько итераций вперед)
 ////      _mm_prefetch((float *)&xx[i+4],_MM_HINT_NTA);
 ////      _mm_prefetch((float *)&yy[i+4],_MM_HINT_NTA);
 //      p=_mm_mul_ps(xx[i], yy[i]); // векторное умножение четырех чисел
 //      s=_mm_add_ps(s,p);          // векторное сложение четырех чисел
 //    }

 ////    p=_mm_movehl_ps(p,s); // перемещение двух старших значений s в младшие p
 ////    s=_mm_add_ps(s,p);    // векторное сложение
 ////    p=_mm_shuffle_ps(s,s,1); //перемещение второго значения в s в младшую позицию в p
 ////    s=_mm_add_ss(s,p);    // скалярное сложение


 ////    s = _mm_add_ps(s, _mm_shuffle_ps(s, s, _MM_SHUFFLE(2, 3, 0, 1)));
 ////    s = _mm_add_ps(s, _mm_shuffle_ps(s, s, _MM_SHUFFLE(1, 0, 3, 2)));
 //    _mm_store_ss(pDp, s); // запись младшего значения в память

    return asmStsNoErr;
}


AsmStatus asmDotProd_32fc(const Asm32fc* pSrc1, const Asm32fc* pSrc2, int len, Asm32fc* pDp)
{
    //fst[0]*snd[0]+fst[1]*snd[1]+....

    if (!pSrc1 || !pSrc2)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int i = 2, decr = len & ~0x01;
    __m128 scalar_re = _mm_mul_ps(_mm_set_ps(pSrc1[0].re, -1 * pSrc1[0].im, pSrc1[1].re, -1 * pSrc1[1].im),
        _mm_set_ps(pSrc2[0].re, pSrc2[0].im, pSrc2[1].re, pSrc2[1].im));
    __m128 scalar_im = _mm_mul_ps(_mm_set_ps(pSrc1[0].re, pSrc1[0].im, pSrc1[1].re, pSrc1[1].im),
        _mm_set_ps(pSrc2[0].im, pSrc2[0].re, pSrc2[1].im, pSrc2[1].re));


    for (i; i < decr; i += 2)
    {
        scalar_re = _mm_add_ps(scalar_re, _mm_mul_ps(_mm_set_ps(pSrc1[i].re, -1 * pSrc1[i].im, pSrc1[i + 1].re, -1 * pSrc1[i + 1].im),
            _mm_set_ps(pSrc2[i].re, pSrc2[i].im, pSrc2[i + 1].re, pSrc2[i + 1].im)));
        scalar_im = _mm_add_ps(scalar_im, _mm_mul_ps(_mm_set_ps(pSrc1[i].re, pSrc1[i].im, pSrc1[i + 1].re, pSrc1[i + 1].im),
            _mm_set_ps(pSrc2[i].im, pSrc2[i].re, pSrc2[i + 1].im, pSrc2[i + 1].re)));
    }

    scalar_re = _mm_add_ps(scalar_re, _mm_shuffle_ps(scalar_re, scalar_re, _MM_SHUFFLE(2, 3, 0, 1)));
    scalar_re = _mm_add_ps(scalar_re, _mm_shuffle_ps(scalar_re, scalar_re, _MM_SHUFFLE(1, 0, 3, 2)));

    scalar_im = _mm_add_ps(scalar_im, _mm_shuffle_ps(scalar_im, scalar_im, _MM_SHUFFLE(2, 3, 0, 1)));
    scalar_im = _mm_add_ps(scalar_im, _mm_shuffle_ps(scalar_im, scalar_im, _MM_SHUFFLE(1, 0, 3, 2)));


    _mm_store_ss(&pDp->re, scalar_re);
    _mm_store_ss(&pDp->im, scalar_im);

    for (i; i < len; ++i)
    {
        pDp->re += pSrc1[i].re * pSrc2[i].re - pSrc1[i].im * pSrc2[i].im;
        pDp->im += pSrc1[i].re * pSrc2[i].im + pSrc1[i].im * pSrc2[i].re;
    }


    //    __m128d scalar = _mm_mul_pd(_mm_cvtps_pd(_mm_set_ps(0.0f, 0.0f, pSrc1[0].re, pSrc1[0].im)),
    //        _mm_cvtps_pd(_mm_set_ps(0.0f, 0.0f, pSrc2[0].re, pSrc2[0].im)));

    //    for (int i; i < len; i++)
    //    {
    //        scalar = _mm_add_pd(scalar, _mm_mul_pd(_mm_cvtps_pd(_mm_set_ps(0.0f, 0.0f, pSrc1[i].re, pSrc1[i].im)),
    //            _mm_cvtps_pd(_mm_set_ps(0.0f, 0.0f, pSrc2[i].re, pSrc2[i].im))));
    //    }
    //    scalar = _mm_add_pd(scalar, _mm_shuffle_pd(scalar, scalar, _MM_SHUFFLE64(0, 1)));


    //    _mm_store_ss(&pDp[0].im, _mm_cvtpd_ps(scalar));

    return asmStsNoErr;
}

//////////

// формулы Хэмминга
AsmStatus asmWinHamming_32fc_I(Asm32fc* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 3)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 2) {
        _mm_storer_ps(&pSrcDst[i].re, _mm_mul_ps(_mm_set_ps(pSrcDst[i].re, pSrcDst[i].im, pSrcDst[i + 1].re, pSrcDst[i + 1].im),
            _mm_set_ps(
                (0.54f - 0.46f * cos(6.28318530717958647692 * i / (len - 1))),
                (0.54f - 0.46f * cos(6.28318530717958647692 * i / (len - 1))),
                (0.54f - 0.46f * cos(6.28318530717958647692 * (i + 1) / (len - 1))),
                (0.54f - 0.46f * cos(6.28318530717958647692 * (i + 1) / (len - 1))))));
    }

    for (i; i < len; ++i)
    {
        pSrcDst[i].re = pSrcDst[i].re * (0.54f - 0.46f * cos(6.28318530717958647692 * i / (len - 1)));
        pSrcDst[i].im = pSrcDst[i].im * (0.54f - 0.46f * cos(6.28318530717958647692 * i / (len - 1)));
    }

    return asmStsNoErr;
}

AsmStatus asmWinHann_32fc_I(Asm32fc* pSrcDst, int len)
{
    if (!pSrcDst)
        return asmStsNullPtrErr;
    if (len < 3)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    for (i; i < decr; i += 2) {
        _mm_storer_ps(&pSrcDst[i].re, _mm_mul_ps(_mm_set_ps(pSrcDst[i].re, pSrcDst[i].im, pSrcDst[i + 1].re, pSrcDst[i + 1].im),
            _mm_set_ps(
                (0.5f - 0.5f * cos(6.28318530717958647692 * i / (len - 1))),
                (0.5f - 0.5f * cos(6.28318530717958647692 * i / (len - 1))),
                (0.5f - 0.5f * cos(6.28318530717958647692 * (i + 1) / (len - 1))),
                (0.5f - 0.5f * cos(6.28318530717958647692 * (i + 1) / (len - 1))))));
    }

    for (i; i < len; ++i)
    {
        pSrcDst[i].re = pSrcDst[i].re * (0.5f - 0.5f * cos(6.28318530717958647692 * i / (len - 1)));
        pSrcDst[i].im = pSrcDst[i].im * (0.5f - 0.5f * cos(6.28318530717958647692 * i / (len - 1)));
    }

    return asmStsNoErr;
}

//////////

// magn - радиус, phase - угол(фи)
AsmStatus asmPolarToCart_32f(const Asm32f* pSrcMagn, const Asm32f* pSrcPhase, Asm32f* pDstRe, Asm32f* pDstIm, int len)
{
    if (!pSrcMagn || !pSrcPhase || !pDstRe || !pDstIm)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int i = 0, decr = len & ~0x03;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDstRe[i], _mm_mul_ps(_mm_set_ps(pSrcMagn[i], pSrcMagn[i + 1], pSrcMagn[i + 2], pSrcMagn[i + 3]),
            _mm_set_ps(cos(pSrcPhase[i]), cos(pSrcPhase[i + 1]), cos(pSrcPhase[i + 2]), cos(pSrcPhase[i + 3]))));
        _mm_storer_ps(&pDstIm[i], _mm_mul_ps(_mm_set_ps(pSrcMagn[i], pSrcMagn[i + 1], pSrcMagn[i + 2], pSrcMagn[i + 3]),
            _mm_set_ps(sin(pSrcPhase[i]), sin(pSrcPhase[i + 1]), sin(pSrcPhase[i + 2]), sin(pSrcPhase[i + 3]))));
    }

    for (i; i < len; ++i)
    {
        pDstRe[i] = pSrcMagn[i] * cos(pSrcPhase[i]);
        pDstIm[i] = pSrcMagn[i] * sin(pSrcPhase[i]);
    }
    return asmStsNoErr;
}

AsmStatus asmPolarToCart_32fc(const Asm32f* pSrcMagn, const Asm32f* pSrcPhase, Asm32fc* pDst, int len)
{
    if (!pSrcMagn || !pSrcPhase || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int i = 0, decr = len & ~0x03;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i].re, _mm_mul_ps(_mm_set_ps(pSrcMagn[i], pSrcMagn[i], pSrcMagn[i + 1], pSrcMagn[i + 1]),
            _mm_set_ps(cos(pSrcPhase[i]), sin(pSrcPhase[i]), cos(pSrcPhase[i + 1]), sin(pSrcPhase[i + 1]))));
        _mm_storer_ps(&pDst[i + 2].re, _mm_mul_ps(_mm_set_ps(pSrcMagn[i + 2], pSrcMagn[i + 2], pSrcMagn[i + 3], pSrcMagn[i + 3]),
            _mm_set_ps(cos(pSrcPhase[i + 2]), sin(pSrcPhase[i + 2]), cos(pSrcPhase[i + 3]), sin(pSrcPhase[i + 3]))));
    }

    for (i; i < len; ++i)
    {
        pDst[i].re = pSrcMagn[i] * cos(pSrcPhase[i]);
        pDst[i].im = pSrcMagn[i] * sin(pSrcPhase[i]);
    }

    return asmStsNoErr;
}

// FFT (БПФ)
AsmStatus asmFFTInit_C_32fc(AsmFFTSpec_C_32fc** ppFFTSpec, int order, int flag, AsmHintAlgorithm /*hint*/, Asm8u* /*pSpec*/, Asm8u* /*pSpecBuffer*/) {
    if (order < 1)
        return asmStsSizeErr;

    *ppFFTSpec = new AsmFFTSpec_C_32fc;
    (*ppFFTSpec)->size = int(pow(2, order + 1));
    (*ppFFTSpec)->flag = flag;
    (*ppFFTSpec)->buf_size = (*ppFFTSpec)->size;
    (*ppFFTSpec)->divider = 1;

    if (flag == ASM_FFT_DIV_FWD_BY_N)
        (*ppFFTSpec)->divider = (*ppFFTSpec)->size / 2;
    if (flag == ASM_FFT_DIV_INV_BY_N)
        (*ppFFTSpec)->inv_divider = (*ppFFTSpec)->size / 2;
    if (flag == ASM_FFT_DIV_BY_SQRTN)
    {
        (*ppFFTSpec)->inv_divider = sqrt((*ppFFTSpec)->size / 2);
        (*ppFFTSpec)->divider = sqrt((*ppFFTSpec)->size / 2);
    }

    return asmStsNoErr;
}

AsmStatus asmFFTGetSize_C_32fc(int order, int flag, /*HintAlgorithm*/int hint, int* pSpecSize, int* pSpecBufferSize, int* pBufferSize) {
    *pSpecSize = sizeof(AsmFFTSpec_C_32fc);
    *pSpecBufferSize = 0;
    *pBufferSize = 0;
    return asmStsNoErr;
}

int separate(Asm32fc* a, int n)
{
    Asm32fc* b = new Asm32fc[n / 2];				// get temp heap storage

    for (int i = 0; i < n / 2; i++)		// copy all odd elements to heap storage
        b[i] = a[i * 2 + 1];
    for (int i = 0; i < n / 2; i++)		// copy all even elements to lower-half of a[]
        a[i] = a[i * 2];
    for (int i = 0; i < n / 2; i++)		// copy all odd (from heap) to upper-half of a[]
        a[i + n / 2] = b[i];

    delete[] b;							// delete heap storage
    return 0;
}

AsmStatus asmFFTFwd_CToC_32fc_I(Asm32fc* pSrcDst, AsmFFTSpec_C_32fc* pFFTSpec, Asm8u* pBuffer)
{
    (*pFFTSpec).buf_size /= 2;
    if ((*pFFTSpec).buf_size < 2)
    {
        // bottom of recursion.
        // Do nothing here, because already X[0] = x[0]
    }
    else
    {
        separate(pSrcDst, (*pFFTSpec).buf_size);							// all evens to lower half, all odds to upper half
        asmFFTFwd_CToC_32fc_I(pSrcDst, pFFTSpec, pBuffer);					// recurse even items
        asmFFTFwd_CToC_32fc_I(pSrcDst + (*pFFTSpec).buf_size / 2, pFFTSpec, pBuffer);			// recurse odd  items

        // combine results of two half recursions
        if ((*pFFTSpec).buf_size == 2)  // если прогоним только одно число, то преобразуем в double
        {
            //__m128d e = _mm_load_pd( (double *)&pSrcDst[k] );   // even
            __m128d o = _mm_cvtps_pd(_mm_load_ps(&pSrcDst[(*pFFTSpec).buf_size / 2].re));   // odd

            __m128d wr = _mm_set1_pd(1.0);			//__m128d wr =  _mm_set_pd( cc,cc );		// cc
            __m128d wi = _mm_set_pd(0.0, 0.0);		// -d | d	, note that it is reverse order

            // compute the w*o
            wr = _mm_mul_pd(o, wr);					// ac|bc
            __m128d n1 = _mm_shuffle_pd(o, o, _MM_SHUFFLE2(0, 1)); // invert
            wi = _mm_mul_pd(n1, wi);				// -bd|ad
            n1 = _mm_add_pd(wr, wi);				// ac-bd|bc+ad

            o = _mm_cvtps_pd(_mm_load_ps(&pSrcDst[0].re));		// load even part
            wr = _mm_add_pd(o, n1);					// compute even part, X_e + w * X_o;
            wi = _mm_sub_pd(o, n1);					// compute odd part,  X_e - w * X_o;
            __m128 a = _mm_cvtpd_ps(wr);
            __m128 b = _mm_set_ps(pSrcDst[1].im, pSrcDst[1].re, 0.0f, 0.0f);

            _mm_storeu_ps((float*)&pSrcDst[0].re, _mm_add_ps(a, b));

            a = _mm_cvtpd_ps(wi);
            b = _mm_set_ps(pSrcDst[(*pFFTSpec).buf_size / 2 + 1].im, pSrcDst[(*pFFTSpec).buf_size / 2 + 1].re, 0.0f, 0.0f);
            //_mm_div_ps(_mm_add_ps(a,b), _mm_set1_ps((*pFFTSpec).size))
            _mm_storeu_ps((float*)&pSrcDst[(*pFFTSpec).buf_size / 2].re, _mm_add_ps(a, b));

            //std::cout << "Separate 32:\n";
            //for (int i = 0; i < 16; i++)
            //    std::cout << i << ": " << pSrcDst[i].re << "\t" << pSrcDst[i].im << std::endl;
            //std::cout << "buf_size: " << (*pFFTSpec).buf_size << std::endl;
        }
        else
        {
            //init
            __m128 o, wr, wi, n1;
            for (int k = 0; k < (*pFFTSpec).buf_size / 2; k += 2)
            {
                int idx = k + (*pFFTSpec).buf_size / 2;
                o = _mm_set_ps(pSrcDst[idx].re, pSrcDst[idx].im, pSrcDst[idx + 1].re, pSrcDst[idx + 1].im);   // a, b - odd

                float cc_0 = (float)cos(-PI2 * k / (*pFFTSpec).buf_size), cc_1 = (float)cos(-(k + 1) * PI2 / (*pFFTSpec).buf_size);
                float dd_0 = (float)sin(-PI2 * k / (*pFFTSpec).buf_size), dd_1 = (float)sin(-(k + 1) * PI2 / (*pFFTSpec).buf_size);
                wr = _mm_set_ps(cc_0, cc_0, cc_1, cc_1);			// cc
                wi = _mm_set_ps(-dd_0, dd_0, -dd_1, dd_1);		// -d | d	, note that it is reverse order

                // compute the w*o
                wr = _mm_mul_ps(o, wr);					// ac|bc
                n1 = _mm_shuffle_ps(o, o, _MM_SHUFFLE(2, 3, 0, 1)); // invert
                wi = _mm_mul_ps(n1, wi);				// -bd|ad
                n1 = _mm_add_ps(wr, wi);				// ac-bd|bc+ad

                // load even part
                o = _mm_set_ps(pSrcDst[k].re, pSrcDst[k].im, pSrcDst[k + 1].re, pSrcDst[k + 1].im);
                wr = _mm_add_ps(o, n1);					// compute even part, X_e + w * X_o;
                wi = _mm_sub_ps(o, n1);					// compute odd part,  X_e - w * X_o;
                _mm_storer_ps(&pSrcDst[k].re, wr);
                _mm_storer_ps(&pSrcDst[idx].re, wi);


                //                std::cout << "Separate 32:\n";
                //                for (int i = 0; i < 16; i++)
                //                    std::cout << i << ": " << pSrcDst[i].re << "\t" << pSrcDst[i].im << std::endl;
                //                std::cout << "buf_size: " << (*pFFTSpec).buf_size << std::endl;

            }
        }
    }

    (*pFFTSpec).buf_size *= 2;
    if ((*pFFTSpec).buf_size == (*pFFTSpec).size && (*pFFTSpec).flag != ASM_FFT_NODIV_BY_ANY)
    {
        std::cout << "Separate 32:" << (*pFFTSpec).size << std::endl;
        int div = (*pFFTSpec).divider, i = 0;
        for (i; i < (*pFFTSpec).size; i += 4)
        {
            _mm_storer_ps(&pSrcDst[i].re, _mm_div_ps(_mm_set_ps(pSrcDst[i].re, pSrcDst[i].im, pSrcDst[i + 1].re, pSrcDst[i + 1].im),
                _mm_set_ps1(div)));
            _mm_storer_ps(&pSrcDst[i + 2].re, _mm_div_ps(_mm_set_ps(pSrcDst[i + 2].re, pSrcDst[i + 2].im, pSrcDst[i + 3].re, pSrcDst[i + 3].im),
                _mm_set_ps1(div)));
        }
    }

    return asmStsNoErr;
}

AsmStatus asmFFTInv_CToC_32fc_I(Asm32fc* pSrcDst, AsmFFTSpec_C_32fc* pFFTSpec, Asm8u* pBuffer)
{
    (*pFFTSpec).buf_size /= 2;
    if ((*pFFTSpec).buf_size < 2)
    {
        // bottom of recursion.
        // Do nothing here, because already X[0] = x[0]
    }
    else
    {
        separate(pSrcDst, (*pFFTSpec).buf_size);							// all evens to lower half, all odds to upper half
        asmFFTInv_CToC_32fc_I(pSrcDst, pFFTSpec, pBuffer);					// recurse even items
        asmFFTInv_CToC_32fc_I(pSrcDst + (*pFFTSpec).buf_size / 2, pFFTSpec, pBuffer);			// recurse odd  items

        // combine results of two half recursions
        if ((*pFFTSpec).buf_size == 2)  // если прогоним только одно число, то преобразуем в double
        {
            //__m128d e = _mm_load_pd( (double *)&pSrcDst[k] );   // even
            __m128d o = _mm_cvtps_pd(_mm_load_ps(&pSrcDst[(*pFFTSpec).buf_size / 2].re));   // odd

            __m128d wr = _mm_set1_pd(1.0);			//__m128d wr =  _mm_set_pd( cc,cc );		// cc
            __m128d wi = _mm_set_pd(0.0, 0.0);		// -d | d	, note that it is reverse order

            // compute the w*o
            wr = _mm_mul_pd(o, wr);					// ac|bc
            __m128d n1 = _mm_shuffle_pd(o, o, _MM_SHUFFLE2(0, 1)); // invert
            wi = _mm_mul_pd(n1, wi);				// -bd|ad
            n1 = _mm_add_pd(wr, wi);				// ac-bd|bc+ad

            o = _mm_cvtps_pd(_mm_load_ps(&pSrcDst[0].re));		// load even part
            wr = _mm_add_pd(o, n1);					// compute even part, X_e + w * X_o;
            wi = _mm_sub_pd(o, n1);					// compute odd part,  X_e - w * X_o;
            __m128 a = _mm_cvtpd_ps(wr);
            __m128 b = _mm_set_ps(pSrcDst[1].im, pSrcDst[1].re, 0.0f, 0.0f);

            _mm_storeu_ps((float*)&pSrcDst[0].re, _mm_add_ps(a, b));

            a = _mm_cvtpd_ps(wi);
            b = _mm_set_ps(pSrcDst[(*pFFTSpec).buf_size / 2 + 1].im, pSrcDst[(*pFFTSpec).buf_size / 2 + 1].re, 0.0f, 0.0f);
            //_mm_div_ps(_mm_add_ps(a,b), _mm_set1_ps((*pFFTSpec).size))
            _mm_storeu_ps((float*)&pSrcDst[(*pFFTSpec).buf_size / 2].re, _mm_add_ps(a, b));

            //std::cout << "Separate 32:\n";
            //for (int i = 0; i < 16; i++)
            //    std::cout << i << ": " << pSrcDst[i].re << "\t" << pSrcDst[i].im << std::endl;
            //std::cout << "buf_size: " << (*pFFTSpec).buf_size << std::endl;
        }
        else
        {
            //init
            __m128 o, wr, wi, n1;
            for (int k = 0; k < (*pFFTSpec).buf_size / 2; k += 2)
            {
                int idx = k + (*pFFTSpec).buf_size / 2;
                o = _mm_set_ps(pSrcDst[idx].re, pSrcDst[idx].im, pSrcDst[idx + 1].re, pSrcDst[idx + 1].im);   // a, b - odd

                float cc_0 = (float)cos(PI2 * k / (*pFFTSpec).buf_size), cc_1 = (float)cos((k + 1) * PI2 / (*pFFTSpec).buf_size);
                float dd_0 = (float)sin(PI2 * k / (*pFFTSpec).buf_size), dd_1 = (float)sin((k + 1) * PI2 / (*pFFTSpec).buf_size);
                wr = _mm_set_ps(cc_0, cc_0, cc_1, cc_1);			// cc
                wi = _mm_set_ps(-dd_0, dd_0, -dd_1, dd_1);		// -d | d	, note that it is reverse order

                // compute the w*o
                wr = _mm_mul_ps(o, wr);					// ac|bc
                n1 = _mm_shuffle_ps(o, o, _MM_SHUFFLE(2, 3, 0, 1)); // invert
                wi = _mm_mul_ps(n1, wi);				// -bd|ad
                n1 = _mm_add_ps(wr, wi);				// ac-bd|bc+ad

                // load even part
                o = _mm_set_ps(pSrcDst[k].re, pSrcDst[k].im, pSrcDst[k + 1].re, pSrcDst[k + 1].im);
                wr = _mm_add_ps(o, n1);					// compute even part, X_e + w * X_o;
                wi = _mm_sub_ps(o, n1);					// compute odd part,  X_e - w * X_o;
                _mm_storer_ps(&pSrcDst[k].re, wr);
                _mm_storer_ps(&pSrcDst[idx].re, wi);


                //                std::cout << "Separate 32:\n";
                //                for (int i = 0; i < 16; i++)
                //                    std::cout << i << ": " << pSrcDst[i].re << "\t" << pSrcDst[i].im << std::endl;
                //                std::cout << "buf_size: " << (*pFFTSpec).buf_size << std::endl;

            }
        }
    }

    (*pFFTSpec).buf_size *= 2;
    if ((*pFFTSpec).buf_size == (*pFFTSpec).size && (*pFFTSpec).flag != ASM_FFT_NODIV_BY_ANY)
    {
        std::cout << "Separate 32:" << (*pFFTSpec).size << std::endl;
        int div = (*pFFTSpec).inv_divider, i = 0;
        for (i; i < (*pFFTSpec).size; i += 4)
        {
            _mm_storer_ps(&pSrcDst[i].re, _mm_div_ps(_mm_set_ps(pSrcDst[i].re, pSrcDst[i].im, pSrcDst[i + 1].re, pSrcDst[i + 1].im),
                _mm_set_ps1(div)));
            _mm_storer_ps(&pSrcDst[i + 2].re, _mm_div_ps(_mm_set_ps(pSrcDst[i + 2].re, pSrcDst[i + 2].im, pSrcDst[i + 3].re, pSrcDst[i + 3].im),
                _mm_set_ps1(div)));
        }
    }

    return asmStsNoErr;
}
///////

// радиус в квадрате
AsmStatus asmPowerSpectr_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int decr = len & ~0x03;
    int i = 0;

    __m128 sqr_buf;/* = _mm_set_ps(pSrc[0].re, pSrc[0].im, pSrc[1].re, pSrc[1].im);*/
    for (i; i < decr; i += 4)
    {
        sqr_buf = _mm_add_ps(_mm_mul_ps(_mm_set_ps(pSrc[i].re, pSrc[i + 1].re, pSrc[i + 2].re, pSrc[i + 3].re),
            _mm_set_ps(pSrc[i].re, pSrc[i + 1].re, pSrc[i + 2].re, pSrc[i + 3].re)),
            _mm_mul_ps(_mm_set_ps(pSrc[i].im, pSrc[i + 1].im, pSrc[i + 2].im, pSrc[i + 3].im),
                _mm_set_ps(pSrc[i].im, pSrc[i + 1].im, pSrc[i + 2].im, pSrc[i + 3].im)));
        _mm_storer_ps(&pDst[i], sqr_buf);
    }

    for (i; i < len; ++i)
    {
        pDst[i] = pSrc[i].re * pSrc[i].re + pSrc[i].im * pSrc[i].im;
    }

    return asmStsNoErr;
}

AsmStatus asmPhase_32fc(const Asm32fc* pSrc, Asm32f* pDst, int len)
{
    if (!pSrc || !pDst)
        return asmStsNullPtrErr;
    if (len < 1)
        return asmStsSizeErr;

    int i = 0, decr = len & ~0x03;

    for (i; i < decr; i += 4)
    {
        _mm_storer_ps(&pDst[i], _mm_set_ps(atan2(pSrc[i].im, pSrc[i].re), atan2(pSrc[i + 1].im, pSrc[i + 1].re),
            atan2(pSrc[i + 2].im, pSrc[i + 2].re), atan2(pSrc[i + 3].im, pSrc[i + 3].re)));
    }

    for (i; i < len; ++i)
    {
        pDst[i] = atan2(pSrc[i].im, pSrc[i].re);
    }

    return asmStsNoErr;
}
