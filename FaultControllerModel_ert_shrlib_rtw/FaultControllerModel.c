/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FaultControllerModel.c
 *
 * Code generated for Simulink model 'FaultControllerModel'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Apr 16 08:39:16 2023
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FaultControllerModel.h"
#include "rtwtypes.h"
#include "FaultControllerModel_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <string.h>

/* Block states (default storage) */
DW_FaultControllerModel_T FaultControllerModel_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FaultControllerModel_T FaultControllerModel_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FaultControllerModel_T FaultControllerModel_Y;

/* Real-time model */
static RT_MODEL_FaultControllerModel_T FaultControllerModel_M_;
RT_MODEL_FaultControllerModel_T *const FaultControllerModel_M =
  &FaultControllerModel_M_;

/* Forward declaration for local functions */
static real_T FaultControllerModel_xnrm2(int32_T n, const real_T x[48], int32_T
  ix0);
static real_T FaultControllerModel_xdotc(int32_T n, const real_T x[48], int32_T
  ix0, const real_T y[48], int32_T iy0);
static void FaultControllerModel_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[48], int32_T iy0);
static real_T FaultControllerModel_xnrm2_e(int32_T n, const real_T x[6], int32_T
  ix0);
static void FaultControllerModel_xaxpy_d(int32_T n, real_T a, const real_T x[48],
  int32_T ix0, real_T y[8], int32_T iy0);
static void FaultControllerModel_xaxpy_dr(int32_T n, real_T a, const real_T x[8],
  int32_T ix0, real_T y[48], int32_T iy0);
static real_T FaultControllerModel_xdotc_k(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0);
static void FaultControllerModel_xaxpy_drt(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0);
static void FaultControllerModel_xswap(real_T x[36], int32_T ix0, int32_T iy0);
static void FaultControllerModel_xswap_i(real_T x[48], int32_T ix0, int32_T iy0);
static void FaultControllerModel_xrotg(real_T *a, real_T *b, real_T *c, real_T
  *s);
static void FaultControllerModel_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void FaultControllerModel_xrot_d(real_T x[48], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void FaultControllerModel_svd(const real_T A[48], real_T U[48], real_T s
  [6], real_T V[36]);
void rt_invd6x6_snf(const real_T u[36], real_T y[36])
{
  real_T x[36];
  real_T smax;
  int32_T c;
  int32_T idxmax;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  int32_T jj;
  int32_T kAcol;
  int32_T pipk;
  int32_T temp_tmp;
  int8_T ipiv[6];
  int8_T p[6];
  for (idxmax = 0; idxmax < 36; idxmax++) {
    y[idxmax] = 0.0;
    x[idxmax] = u[idxmax];
  }

  for (idxmax = 0; idxmax < 6; idxmax++) {
    ipiv[idxmax] = (int8_T)(idxmax + 1);
  }

  for (j = 0; j < 5; j++) {
    pipk = j * 7 + 2;
    jj = j * 7;
    c = 6 - j;
    idxmax = 1;
    smax = fabs(x[jj]);
    for (jA = 2; jA <= c; jA++) {
      real_T s;
      s = fabs(x[(pipk + jA) - 3]);
      if (s > smax) {
        idxmax = jA;
        smax = s;
      }
    }

    if (x[(pipk + idxmax) - 3] != 0.0) {
      if (idxmax - 1 != 0) {
        idxmax += j;
        ipiv[j] = (int8_T)idxmax;
        for (jA = 0; jA < 6; jA++) {
          temp_tmp = jA * 6 + j;
          smax = x[temp_tmp];
          c = (jA * 6 + idxmax) - 1;
          x[temp_tmp] = x[c];
          x[c] = smax;
        }
      }

      idxmax = pipk - j;
      for (c = pipk; c <= idxmax + 4; c++) {
        x[c - 1] /= x[jj];
      }
    }

    c = 5 - j;
    jA = jj;
    for (kAcol = 0; kAcol < c; kAcol++) {
      smax = x[(kAcol * 6 + jj) + 6];
      if (smax != 0.0) {
        idxmax = jA + 8;
        temp_tmp = jA - j;
        for (ijA = idxmax; ijA <= temp_tmp + 12; ijA++) {
          x[ijA - 1] += x[((pipk + ijA) - jA) - 9] * -smax;
        }
      }

      jA += 6;
    }
  }

  for (idxmax = 0; idxmax < 6; idxmax++) {
    p[idxmax] = (int8_T)(idxmax + 1);
  }

  for (jA = 0; jA < 5; jA++) {
    j = ipiv[jA];
    if (j > jA + 1) {
      pipk = p[j - 1];
      p[j - 1] = p[jA];
      p[jA] = (int8_T)pipk;
    }
  }

  for (jA = 0; jA < 6; jA++) {
    jj = (p[jA] - 1) * 6;
    y[jA + jj] = 1.0;
    for (j = jA + 1; j < 7; j++) {
      idxmax = (jj + j) - 1;
      if (y[idxmax] != 0.0) {
        for (c = j + 1; c < 7; c++) {
          pipk = (jj + c) - 1;
          y[pipk] -= x[((j - 1) * 6 + c) - 1] * y[idxmax];
        }
      }
    }
  }

  for (j = 0; j < 6; j++) {
    jj = 6 * j;
    for (jA = 5; jA >= 0; jA--) {
      kAcol = 6 * jA;
      idxmax = jA + jj;
      smax = y[idxmax];
      if (smax != 0.0) {
        y[idxmax] = smax / x[jA + kAcol];
        temp_tmp = jA - 1;
        for (c = 0; c <= temp_tmp; c++) {
          pipk = c + jj;
          y[pipk] -= x[c + kAcol] * y[idxmax];
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static real_T FaultControllerModel_xnrm2(int32_T n, const real_T x[48], int32_T
  ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static real_T FaultControllerModel_xdotc(int32_T n, const real_T x[48], int32_T
  ix0, const real_T y[48], int32_T iy0)
{
  real_T d;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[48], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static real_T FaultControllerModel_xnrm2_e(int32_T n, const real_T x[6], int32_T
  ix0)
{
  real_T y;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      real_T scale;
      int32_T kend;
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        real_T absxk;
        absxk = fabs(x[k - 1]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xaxpy_d(int32_T n, real_T a, const real_T x[48],
  int32_T ix0, real_T y[8], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp;
      tmp_0 = (iy0 + k) - 1;
      tmp = _mm_loadu_pd(&y[tmp_0]);
      _mm_storeu_pd(&y[tmp_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 + k) -
        1]), _mm_set1_pd(a)), tmp));
    }

    for (k = scalarLB; k < n; k++) {
      tmp_0 = (iy0 + k) - 1;
      y[tmp_0] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xaxpy_dr(int32_T n, real_T a, const real_T x[8],
  int32_T ix0, real_T y[48], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp;
      tmp_0 = (iy0 + k) - 1;
      tmp = _mm_loadu_pd(&y[tmp_0]);
      _mm_storeu_pd(&y[tmp_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 + k) -
        1]), _mm_set1_pd(a)), tmp));
    }

    for (k = scalarLB; k < n; k++) {
      tmp_0 = (iy0 + k) - 1;
      y[tmp_0] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static real_T FaultControllerModel_xdotc_k(int32_T n, const real_T x[36],
  int32_T ix0, const real_T y[36], int32_T iy0)
{
  real_T d;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    for (k = 0; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }

  return d;
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xaxpy_drt(int32_T n, real_T a, int32_T ix0,
  real_T y[36], int32_T iy0)
{
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xswap(real_T x[36], int32_T ix0, int32_T iy0)
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xswap_i(real_T x[48], int32_T ix0, int32_T iy0)
{
  int32_T k;
  for (k = 0; k < 8; k++) {
    real_T temp;
    int32_T temp_tmp;
    int32_T tmp;
    temp_tmp = (ix0 + k) - 1;
    temp = x[temp_tmp];
    tmp = (iy0 + k) - 1;
    x[temp_tmp] = x[tmp];
    x[tmp] = temp;
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xrotg(real_T *a, real_T *b, real_T *c, real_T
  *s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xrot(real_T x[36], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T k;
  for (k = 0; k < 6; k++) {
    real_T temp_tmp_0;
    real_T temp_tmp_2;
    int32_T temp_tmp;
    int32_T temp_tmp_1;
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_xrot_d(real_T x[48], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T k;
  for (k = 0; k < 8; k++) {
    real_T temp_tmp_0;
    real_T temp_tmp_2;
    int32_T temp_tmp;
    int32_T temp_tmp_1;
    temp_tmp = (iy0 + k) - 1;
    temp_tmp_0 = x[temp_tmp];
    temp_tmp_1 = (ix0 + k) - 1;
    temp_tmp_2 = x[temp_tmp_1];
    x[temp_tmp] = temp_tmp_0 * c - temp_tmp_2 * s;
    x[temp_tmp_1] = temp_tmp_2 * c + temp_tmp_0 * s;
  }
}

/* Function for MATLAB Function: '<S2>/Take inverse' */
static void FaultControllerModel_svd(const real_T A[48], real_T U[48], real_T s
  [6], real_T V[36])
{
  __m128d tmp;
  real_T b_A[48];
  real_T Vf[36];
  real_T work[8];
  real_T b_s[6];
  real_T e[6];
  real_T nrm;
  real_T r;
  real_T rt;
  real_T smm1;
  real_T ztest0;
  int32_T e_k;
  int32_T h;
  int32_T i;
  int32_T kase;
  int32_T qjj;
  int32_T qp1;
  int32_T qp1jj;
  int32_T qq;
  memcpy(&b_A[0], &A[0], 48U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    b_s[i] = 0.0;
    e[i] = 0.0;
  }

  memset(&work[0], 0, sizeof(real_T) << 3U);
  memset(&U[0], 0, 48U * sizeof(real_T));
  memset(&Vf[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    boolean_T apply_transform;
    qp1 = i + 2;
    qp1jj = i << 3;
    qq = (qp1jj + i) + 1;
    apply_transform = false;
    nrm = FaultControllerModel_xnrm2(8 - i, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        b_s[i] = -nrm;
      } else {
        b_s[i] = nrm;
      }

      if (fabs(b_s[i]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b_s[i];
        h = (qq - i) + 7;
        qjj = ((((h - qq) + 1) / 2) << 1) + qq;
        kase = qjj - 2;
        for (e_k = qq; e_k <= kase; e_k += 2) {
          tmp = _mm_loadu_pd(&b_A[e_k - 1]);
          _mm_storeu_pd(&b_A[e_k - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
        }

        for (e_k = qjj; e_k <= h; e_k++) {
          b_A[e_k - 1] *= nrm;
        }
      } else {
        h = (qq - i) + 7;
        qjj = ((((h - qq) + 1) / 2) << 1) + qq;
        kase = qjj - 2;
        for (e_k = qq; e_k <= kase; e_k += 2) {
          tmp = _mm_loadu_pd(&b_A[e_k - 1]);
          _mm_storeu_pd(&b_A[e_k - 1], _mm_div_pd(tmp, _mm_set1_pd(b_s[i])));
        }

        for (e_k = qjj; e_k <= h; e_k++) {
          b_A[e_k - 1] /= b_s[i];
        }
      }

      b_A[qq - 1]++;
      b_s[i] = -b_s[i];
    } else {
      b_s[i] = 0.0;
    }

    for (kase = qp1; kase < 7; kase++) {
      qjj = ((kase - 1) << 3) + i;
      if (apply_transform) {
        FaultControllerModel_xaxpy(8 - i, -(FaultControllerModel_xdotc(8 - i,
          b_A, qq, b_A, qjj + 1) / b_A[i + (i << 3)]), qq, b_A, qjj + 1);
      }

      e[kase - 1] = b_A[qjj];
    }

    for (kase = i + 1; kase < 9; kase++) {
      qjj = (qp1jj + kase) - 1;
      U[qjj] = b_A[qjj];
    }

    if (i + 1 <= 4) {
      nrm = FaultControllerModel_xnrm2_e(5 - i, e, i + 2);
      if (nrm == 0.0) {
        e[i] = 0.0;
      } else {
        if (e[i + 1] < 0.0) {
          e[i] = -nrm;
        } else {
          e[i] = nrm;
        }

        nrm = e[i];
        if (fabs(e[i]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[i];
          qjj = ((((5 - i) / 2) << 1) + i) + 2;
          kase = qjj - 2;
          for (qp1jj = qp1; qp1jj <= kase; qp1jj += 2) {
            tmp = _mm_loadu_pd(&e[qp1jj - 1]);
            _mm_storeu_pd(&e[qp1jj - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qp1jj = qjj; qp1jj < 7; qp1jj++) {
            e[qp1jj - 1] *= nrm;
          }
        } else {
          qjj = ((((5 - i) / 2) << 1) + i) + 2;
          kase = qjj - 2;
          for (qp1jj = qp1; qp1jj <= kase; qp1jj += 2) {
            tmp = _mm_loadu_pd(&e[qp1jj - 1]);
            _mm_storeu_pd(&e[qp1jj - 1], _mm_div_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qp1jj = qjj; qp1jj < 7; qp1jj++) {
            e[qp1jj - 1] /= nrm;
          }
        }

        e[i + 1]++;
        e[i] = -e[i];
        for (qjj = qp1; qjj < 9; qjj++) {
          work[qjj - 1] = 0.0;
        }

        for (qjj = qp1; qjj < 7; qjj++) {
          FaultControllerModel_xaxpy_d(7 - i, e[qjj - 1], b_A, (i + ((qjj - 1) <<
            3)) + 2, work, i + 2);
        }

        for (qjj = qp1; qjj < 7; qjj++) {
          FaultControllerModel_xaxpy_dr(7 - i, -e[qjj - 1] / e[i + 1], work, i +
            2, b_A, (i + ((qjj - 1) << 3)) + 2);
        }
      }

      for (qjj = qp1; qjj < 7; qjj++) {
        Vf[(qjj + 6 * i) - 1] = e[qjj - 1];
      }
    }
  }

  i = 4;
  e[4] = b_A[44];
  e[5] = 0.0;
  for (qp1 = 5; qp1 >= 0; qp1--) {
    qp1jj = qp1 << 3;
    qq = qp1jj + qp1;
    if (b_s[qp1] != 0.0) {
      for (kase = qp1 + 2; kase < 7; kase++) {
        qjj = (((kase - 1) << 3) + qp1) + 1;
        FaultControllerModel_xaxpy(8 - qp1, -(FaultControllerModel_xdotc(8 - qp1,
          U, qq + 1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (kase = qp1 + 1; kase < 9; kase++) {
        qjj = (qp1jj + kase) - 1;
        U[qjj] = -U[qjj];
      }

      U[qq]++;
      for (qjj = 0; qjj < qp1; qjj++) {
        U[qjj + qp1jj] = 0.0;
      }
    } else {
      memset(&U[qp1jj], 0, sizeof(real_T) << 3U);
      U[qq] = 1.0;
    }
  }

  for (qp1 = 5; qp1 >= 0; qp1--) {
    if ((qp1 + 1 <= 4) && (e[qp1] != 0.0)) {
      qjj = (6 * qp1 + qp1) + 2;
      for (kase = qp1 + 2; kase < 7; kase++) {
        qp1jj = ((kase - 1) * 6 + qp1) + 2;
        FaultControllerModel_xaxpy_drt(5 - qp1, -(FaultControllerModel_xdotc_k(5
          - qp1, Vf, qjj, Vf, qp1jj) / Vf[qjj - 1]), qjj, Vf, qp1jj);
      }
    }

    for (qjj = 0; qjj < 6; qjj++) {
      Vf[qjj + 6 * qp1] = 0.0;
    }

    Vf[qp1 + 6 * qp1] = 1.0;
  }

  qp1 = 0;
  nrm = 0.0;
  for (qp1jj = 0; qp1jj < 6; qp1jj++) {
    ztest0 = e[qp1jj];
    if (b_s[qp1jj] != 0.0) {
      rt = fabs(b_s[qp1jj]);
      r = b_s[qp1jj] / rt;
      b_s[qp1jj] = rt;
      if (qp1jj + 1 < 6) {
        ztest0 /= r;
      }

      qq = (qp1jj << 3) + 1;
      qjj = 8 + qq;
      kase = qq + 6;
      for (h = qq; h <= kase; h += 2) {
        tmp = _mm_loadu_pd(&U[h - 1]);
        _mm_storeu_pd(&U[h - 1], _mm_mul_pd(tmp, _mm_set1_pd(r)));
      }

      for (h = qjj; h <= qq + 7; h++) {
        U[h - 1] *= r;
      }
    }

    if ((qp1jj + 1 < 6) && (ztest0 != 0.0)) {
      rt = fabs(ztest0);
      r = rt / ztest0;
      ztest0 = rt;
      b_s[qp1jj + 1] *= r;
      qq = (qp1jj + 1) * 6 + 1;
      qjj = 6 + qq;
      kase = qq + 4;
      for (h = qq; h <= kase; h += 2) {
        tmp = _mm_loadu_pd(&Vf[h - 1]);
        _mm_storeu_pd(&Vf[h - 1], _mm_mul_pd(tmp, _mm_set1_pd(r)));
      }

      for (h = qjj; h <= qq + 5; h++) {
        Vf[h - 1] *= r;
      }
    }

    nrm = fmax(nrm, fmax(fabs(b_s[qp1jj]), fabs(ztest0)));
    e[qp1jj] = ztest0;
  }

  while ((i + 2 > 0) && (qp1 < 75)) {
    boolean_T exitg1;
    qp1jj = i + 1;
    exitg1 = false;
    while (!(exitg1 || (qp1jj == 0))) {
      ztest0 = fabs(e[qp1jj - 1]);
      if (ztest0 <= (fabs(b_s[qp1jj - 1]) + fabs(b_s[qp1jj])) *
          2.2204460492503131E-16) {
        e[qp1jj - 1] = 0.0;
        exitg1 = true;
      } else if ((ztest0 <= 1.0020841800044864E-292) || ((qp1 > 20) && (ztest0 <=
        2.2204460492503131E-16 * nrm))) {
        e[qp1jj - 1] = 0.0;
        exitg1 = true;
      } else {
        qp1jj--;
      }
    }

    if (i + 1 == qp1jj) {
      kase = 4;
    } else {
      qjj = i + 2;
      kase = i + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= qp1jj)) {
        qjj = kase;
        if (kase == qp1jj) {
          exitg1 = true;
        } else {
          ztest0 = 0.0;
          if (kase < i + 2) {
            ztest0 = fabs(e[kase - 1]);
          }

          if (kase > qp1jj + 1) {
            ztest0 += fabs(e[kase - 2]);
          }

          rt = fabs(b_s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * ztest0) || (rt <=
               1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qjj == qp1jj) {
        kase = 3;
      } else if (i + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        qp1jj = qjj;
      }
    }

    switch (kase) {
     case 1:
      ztest0 = e[i];
      e[i] = 0.0;
      for (qjj = i + 1; qjj >= qp1jj + 1; qjj--) {
        FaultControllerModel_xrotg(&b_s[qjj - 1], &ztest0, &r, &smm1);
        if (qjj > qp1jj + 1) {
          rt = e[qjj - 2];
          ztest0 = rt * -smm1;
          e[qjj - 2] = rt * r;
        }

        FaultControllerModel_xrot(Vf, 6 * (qjj - 1) + 1, 6 * (i + 1) + 1, r,
          smm1);
      }
      break;

     case 2:
      ztest0 = e[qp1jj - 1];
      e[qp1jj - 1] = 0.0;
      for (qjj = qp1jj + 1; qjj <= i + 2; qjj++) {
        FaultControllerModel_xrotg(&b_s[qjj - 1], &ztest0, &r, &smm1);
        rt = e[qjj - 1];
        ztest0 = rt * -smm1;
        e[qjj - 1] = rt * r;
        FaultControllerModel_xrot_d(U, ((qjj - 1) << 3) + 1, ((qp1jj - 1) << 3)
          + 1, r, smm1);
      }
      break;

     case 3:
      {
        real_T emm1;
        real_T shift;
        ztest0 = b_s[i + 1];
        rt = fmax(fmax(fmax(fmax(fabs(ztest0), fabs(b_s[i])), fabs(e[i])), fabs
                       (b_s[qp1jj])), fabs(e[qp1jj]));
        ztest0 /= rt;
        smm1 = b_s[i] / rt;
        emm1 = e[i] / rt;
        r = b_s[qp1jj] / rt;
        smm1 = ((smm1 + ztest0) * (smm1 - ztest0) + emm1 * emm1) / 2.0;
        emm1 *= ztest0;
        emm1 *= emm1;
        if ((smm1 != 0.0) || (emm1 != 0.0)) {
          shift = sqrt(smm1 * smm1 + emm1);
          if (smm1 < 0.0) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0;
        }

        ztest0 = (r + ztest0) * (r - ztest0) + shift;
        rt = e[qp1jj] / rt * r;
        for (qjj = qp1jj + 1; qjj <= i + 1; qjj++) {
          FaultControllerModel_xrotg(&ztest0, &rt, &r, &smm1);
          if (qjj > qp1jj + 1) {
            e[qjj - 2] = ztest0;
          }

          rt = e[qjj - 1];
          emm1 = b_s[qjj - 1];
          e[qjj - 1] = rt * r - emm1 * smm1;
          ztest0 = smm1 * b_s[qjj];
          b_s[qjj] *= r;
          FaultControllerModel_xrot(Vf, 6 * (qjj - 1) + 1, 6 * qjj + 1, r, smm1);
          b_s[qjj - 1] = emm1 * r + rt * smm1;
          FaultControllerModel_xrotg(&b_s[qjj - 1], &ztest0, &r, &smm1);
          ztest0 = e[qjj - 1] * r + smm1 * b_s[qjj];
          b_s[qjj] = e[qjj - 1] * -smm1 + r * b_s[qjj];
          rt = smm1 * e[qjj];
          e[qjj] *= r;
          FaultControllerModel_xrot_d(U, ((qjj - 1) << 3) + 1, (qjj << 3) + 1, r,
            smm1);
        }

        e[i] = ztest0;
        qp1++;
      }
      break;

     default:
      if (b_s[qp1jj] < 0.0) {
        b_s[qp1jj] = -b_s[qp1jj];
        qp1 = 6 * qp1jj + 1;
        qjj = 6 + qp1;
        kase = qp1 + 4;
        for (qq = qp1; qq <= kase; qq += 2) {
          tmp = _mm_loadu_pd(&Vf[qq - 1]);
          _mm_storeu_pd(&Vf[qq - 1], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
        }

        for (qq = qjj; qq <= qp1 + 5; qq++) {
          Vf[qq - 1] = -Vf[qq - 1];
        }
      }

      qp1 = qp1jj + 1;
      while ((qp1jj + 1 < 6) && (b_s[qp1jj] < b_s[qp1])) {
        rt = b_s[qp1jj];
        b_s[qp1jj] = b_s[qp1];
        b_s[qp1] = rt;
        FaultControllerModel_xswap(Vf, 6 * qp1jj + 1, 6 * (qp1jj + 1) + 1);
        FaultControllerModel_xswap_i(U, (qp1jj << 3) + 1, ((qp1jj + 1) << 3) + 1);
        qp1jj = qp1;
        qp1++;
      }

      qp1 = 0;
      i--;
      break;
    }
  }

  for (qp1 = 0; qp1 < 6; qp1++) {
    s[qp1] = b_s[qp1];
    for (i = 0; i < 6; i++) {
      V[i + 6 * qp1] = Vf[6 * qp1 + i];
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void FaultControllerModel_step(void)
{
  __m128d tmp_9;
  __m128d tmp_a;
  real_T A[48];
  real_T U[48];
  real_T X[48];
  real_T V[36];
  real_T tmp[36];
  real_T catArgs[9];
  real_T rtb_y_p[9];
  real_T rtb_ClampforcestoMax[8];
  real_T rtb_ElementProduct[6];
  real_T tmp_3[6];
  real_T tmp_4[6];
  real_T tmp_5[6];
  real_T tmp_6[6];
  real_T rtb_Subtract2[3];
  real_T rtb_angularforces[3];
  real_T rtb_linearforces[3];
  real_T tmp_0[3];
  real_T tmp_1[3];
  real_T tmp_2[3];
  real_T absx;
  real_T err_idx_3;
  real_T q_idx_1;
  real_T q_idx_2;
  real_T q_idx_3;
  real_T rtb_y_n_tmp;
  real_T rtb_y_n_tmp_0;
  real_T rtb_y_n_tmp_1;
  real_T rtb_y_n_tmp_2;
  real_T rtb_y_n_tmp_3;
  int32_T ar;
  int32_T b_ic;
  int32_T c_k;
  int32_T ib;
  int32_T j;
  int32_T r;
  int32_T vcol;
  int32_T vectorUB;
  boolean_T p;

  /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Robot Center of Mass'
   *  Inport: '<Root>/Robot Mass'
   *  Inport: '<Root>/Robot Moments of Inertia'
   */
  V[0] = FaultControllerModel_U.RobotMass;
  V[6] = 0.0;
  V[12] = 0.0;
  V[18] = 0.0;
  absx = FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[2];
  V[24] = absx;
  q_idx_1 = -FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[1];
  V[30] = q_idx_1;
  V[1] = 0.0;
  V[7] = FaultControllerModel_U.RobotMass;
  V[13] = 0.0;
  q_idx_2 = -FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[2];
  V[19] = q_idx_2;
  V[25] = 0.0;
  q_idx_3 = FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[0];
  V[31] = q_idx_3;
  V[2] = 0.0;
  V[8] = 0.0;
  V[14] = FaultControllerModel_U.RobotMass;
  err_idx_3 = FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[1];
  V[20] = err_idx_3;
  rtb_y_n_tmp_3 = -FaultControllerModel_U.RobotMass *
    FaultControllerModel_U.RobotCenterofMass[0];
  V[26] = rtb_y_n_tmp_3;
  V[32] = 0.0;
  V[3] = 0.0;
  V[9] = q_idx_2;
  V[15] = err_idx_3;
  V[21] = FaultControllerModel_U.RobotMomentsofInertia[0];
  V[27] = 0.0;
  V[33] = 0.0;
  V[4] = absx;
  V[10] = 0.0;
  V[16] = rtb_y_n_tmp_3;
  V[22] = 0.0;
  V[28] = FaultControllerModel_U.RobotMomentsofInertia[1];
  V[34] = 0.0;
  V[5] = q_idx_1;
  V[11] = q_idx_3;
  V[17] = 0.0;
  V[23] = 0.0;
  V[29] = 0.0;
  V[35] = FaultControllerModel_U.RobotMomentsofInertia[2];

  /* Product: '<S2>/Reciprocal' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  rt_invd6x6_snf(V, tmp);

  /* MATLAB Function: '<S2>/Take inverse' incorporates:
   *  Inport: '<Root>/Thruster Configuration'
   *  Product: '<S2>/Create Thruster control Matrix'
   */
  for (c_k = 0; c_k < 8; c_k++) {
    for (vectorUB = 0; vectorUB < 6; vectorUB++) {
      vcol = (vectorUB << 3) + c_k;
      A[vcol] = 0.0;
      for (j = 0; j < 6; j++) {
        A[vcol] += tmp[6 * j + vectorUB] *
          FaultControllerModel_U.ThrusterConfiguration[6 * c_k + j];
      }
    }
  }

  p = true;
  for (c_k = 0; c_k < 48; c_k++) {
    absx = A[c_k];
    X[c_k] = 0.0;
    if (p && (rtIsInf(absx) || rtIsNaN(absx))) {
      p = false;
    }
  }

  if (!p) {
    for (c_k = 0; c_k < 48; c_k++) {
      X[c_k] = (rtNaN);
    }
  } else {
    FaultControllerModel_svd(A, U, rtb_ElementProduct, V);
    absx = fabs(rtb_ElementProduct[0]);
    if (rtIsInf(absx) || rtIsNaN(absx)) {
      absx = (rtNaN);
    } else if (absx < 4.4501477170144028E-308) {
      absx = 4.94065645841247E-324;
    } else {
      frexp(absx, &r);
      absx = ldexp(1.0, r - 53);
    }

    absx *= 8.0;
    r = -1;
    c_k = 0;
    while ((c_k < 6) && (rtb_ElementProduct[c_k] > absx)) {
      r++;
      c_k++;
    }

    if (r + 1 > 0) {
      vcol = 1;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / rtb_ElementProduct[j];
        c_k = 6 + vcol;
        vectorUB = vcol + 4;
        for (ar = vcol; ar <= vectorUB; ar += 2) {
          tmp_a = _mm_loadu_pd(&V[ar - 1]);
          _mm_storeu_pd(&V[ar - 1], _mm_mul_pd(tmp_a, _mm_set1_pd(absx)));
        }

        for (ar = c_k; ar <= vcol + 5; ar++) {
          V[ar - 1] *= absx;
        }

        vcol += 6;
      }

      vcol = 0;
      for (c_k = 0; c_k <= 42; c_k += 6) {
        for (vectorUB = c_k + 1; vectorUB <= c_k + 6; vectorUB++) {
          X[vectorUB - 1] = 0.0;
        }
      }

      for (j = 0; j <= 42; j += 6) {
        int32_T b;
        ar = -1;
        vcol++;
        b = (r << 3) + vcol;
        for (ib = vcol; ib <= b; ib += 8) {
          c_k = j + 7;
          vectorUB = j + 5;
          for (b_ic = j + 1; b_ic <= vectorUB; b_ic += 2) {
            tmp_a = _mm_loadu_pd(&V[(ar + b_ic) - j]);
            tmp_9 = _mm_loadu_pd(&X[b_ic - 1]);
            _mm_storeu_pd(&X[b_ic - 1], _mm_add_pd(_mm_mul_pd(tmp_a, _mm_set1_pd
              (U[ib - 1])), tmp_9));
          }

          for (b_ic = c_k; b_ic <= j + 6; b_ic++) {
            X[b_ic - 1] += V[(ar + b_ic) - j] * U[ib - 1];
          }

          ar += 6;
        }
      }
    }
  }

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Robot Orientation'
   */
  q_idx_3 = 1.0 / sqrt(((FaultControllerModel_U.RobotOrientation[0] *
    FaultControllerModel_U.RobotOrientation[0] +
    FaultControllerModel_U.RobotOrientation[1] *
    FaultControllerModel_U.RobotOrientation[1]) +
                        FaultControllerModel_U.RobotOrientation[2] *
                        FaultControllerModel_U.RobotOrientation[2]) +
                       FaultControllerModel_U.RobotOrientation[3] *
                       FaultControllerModel_U.RobotOrientation[3]);
  absx = FaultControllerModel_U.RobotOrientation[0] * q_idx_3;
  q_idx_1 = FaultControllerModel_U.RobotOrientation[1] * q_idx_3;
  q_idx_2 = FaultControllerModel_U.RobotOrientation[2] * q_idx_3;
  q_idx_3 *= FaultControllerModel_U.RobotOrientation[3];
  err_idx_3 = q_idx_3 * q_idx_3;
  rtb_y_n_tmp_3 = q_idx_2 * q_idx_2;
  rtb_y_p[0] = 1.0 - (rtb_y_n_tmp_3 + err_idx_3) * 2.0;
  rtb_y_n_tmp = q_idx_1 * q_idx_2;
  rtb_y_n_tmp_0 = absx * q_idx_3;
  rtb_y_p[1] = (rtb_y_n_tmp - rtb_y_n_tmp_0) * 2.0;
  rtb_y_n_tmp_1 = q_idx_1 * q_idx_3;
  rtb_y_n_tmp_2 = absx * q_idx_2;
  rtb_y_p[2] = (rtb_y_n_tmp_1 + rtb_y_n_tmp_2) * 2.0;
  rtb_y_p[3] = (rtb_y_n_tmp + rtb_y_n_tmp_0) * 2.0;
  rtb_y_n_tmp = q_idx_1 * q_idx_1;
  rtb_y_p[4] = 1.0 - (rtb_y_n_tmp + err_idx_3) * 2.0;
  err_idx_3 = q_idx_2 * q_idx_3;
  rtb_y_n_tmp_0 = absx * q_idx_1;
  rtb_y_p[5] = (err_idx_3 - rtb_y_n_tmp_0) * 2.0;
  rtb_y_p[6] = (rtb_y_n_tmp_1 - rtb_y_n_tmp_2) * 2.0;
  rtb_y_p[7] = (err_idx_3 + rtb_y_n_tmp_0) * 2.0;
  rtb_y_p[8] = 1.0 - (rtb_y_n_tmp + rtb_y_n_tmp_3) * 2.0;
  memcpy(&catArgs[0], &rtb_y_p[0], 9U * sizeof(real_T));
  for (c_k = 0; c_k < 3; c_k++) {
    r = ((int8_T)(c_k + 1) - 1) * 3;
    rtb_y_p[(int8_T)(c_k + 1) - 1] = catArgs[r];
    rtb_y_p[(int8_T)(c_k + 1) + 2] = catArgs[r + 1];
    rtb_y_p[(int8_T)(c_k + 1) + 5] = catArgs[r + 2];
  }

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* SignalConversion generated from: '<S9>/force due to gravity' incorporates:
   *  Constant: '<S9>/gravity'
   *  Inport: '<Root>/Robot Mass'
   *  Product: '<S9>/Product'
   */
  absx = FaultControllerModel_U.RobotMass * 9.81;

  /* SignalConversion generated from: '<S9>/force due to boyancy' incorporates:
   *  Constant: '<S9>/gravity'
   *  Inport: '<Root>/Robot Volume'
   *  Product: '<S9>/Product1'
   */
  q_idx_1 = 9.81 * FaultControllerModel_U.RobotVolume;

  /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  for (r = 0; r <= 0; r += 2) {
    __m128d tmp_7;
    __m128d tmp_8;

    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Product: '<S9>/force due to gravity' */
    tmp_a = _mm_loadu_pd(&rtb_y_p[r]);
    tmp_9 = _mm_set1_pd(0.0);

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
    tmp_a = _mm_mul_pd(tmp_a, tmp_9);

    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Product: '<S9>/force due to gravity' */
    tmp_7 = _mm_loadu_pd(&rtb_y_p[r + 3]);

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
    tmp_7 = _mm_mul_pd(tmp_7, tmp_9);

    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Product: '<S9>/force due to gravity' */
    tmp_8 = _mm_loadu_pd(&rtb_y_p[r + 6]);

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
    tmp_a = _mm_add_pd(tmp_7, _mm_add_pd(tmp_a, tmp_9));

    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Product: '<S9>/force due to gravity' */
    tmp_9 = _mm_add_pd(_mm_mul_pd(tmp_8, _mm_set1_pd(absx)), tmp_a);

    /* Product: '<S9>/force due to boyancy' */
    tmp_a = _mm_mul_pd(_mm_add_pd(_mm_mul_pd(tmp_8, _mm_set1_pd(q_idx_1)), tmp_a),
                       _mm_set1_pd(-1.0));

    /* Sum: '<S9>/linear forces' incorporates:
     *  Product: '<S9>/force due to gravity'
     */
    _mm_storeu_pd(&rtb_linearforces[r], _mm_add_pd(tmp_9, tmp_a));

    /* Gain: '<S9>/Gain' incorporates:
     *  Product: '<S9>/force due to gravity'
     */
    _mm_storeu_pd(&rtb_Subtract2[r], tmp_a);

    /* Product: '<S9>/force due to gravity' */
    _mm_storeu_pd(&rtb_angularforces[r], tmp_9);

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
  for (r = 2; r < 3; r++) {
    /* Product: '<S9>/force due to gravity' incorporates:
     *  Product: '<S9>/force due to boyancy'
     */
    err_idx_3 = rtb_y_p[r] * 0.0;
    q_idx_2 = rtb_y_p[r + 3];
    q_idx_3 = q_idx_2 * 0.0 + err_idx_3;

    /* Product: '<S9>/force due to boyancy' */
    err_idx_3 += q_idx_2 * 0.0;

    /* Product: '<S9>/force due to gravity' */
    q_idx_2 = rtb_y_p[r + 6];
    q_idx_3 += q_idx_2 * absx;

    /* Product: '<S9>/force due to boyancy' */
    q_idx_2 = q_idx_2 * q_idx_1 + err_idx_3;

    /* Sum: '<S9>/linear forces' */
    rtb_linearforces[r] = q_idx_3 - q_idx_2;

    /* Gain: '<S9>/Gain' */
    rtb_Subtract2[r] = -q_idx_2;

    /* Product: '<S9>/force due to gravity' */
    rtb_angularforces[r] = q_idx_3;
  }

  /* Product: '<S11>/Element Product' incorporates:
   *  Inport: '<Root>/Robot Center of Mass'
   *  Product: '<S12>/Element Product'
   */
  rtb_ElementProduct[1] = rtb_angularforces[0] *
    FaultControllerModel_U.RobotCenterofMass[2];
  rtb_ElementProduct[2] = FaultControllerModel_U.RobotCenterofMass[0] *
    rtb_angularforces[1];
  rtb_ElementProduct[5] = rtb_angularforces[0] *
    FaultControllerModel_U.RobotCenterofMass[1];

  /* Sum: '<S11>/Sum' incorporates:
   *  Inport: '<Root>/Robot Center of Mass'
   *  Product: '<S11>/Element Product'
   *  Sum: '<S9>/angular forces'
   */
  rtb_angularforces[0] = FaultControllerModel_U.RobotCenterofMass[1] *
    rtb_angularforces[2] - rtb_angularforces[1] *
    FaultControllerModel_U.RobotCenterofMass[2];
  rtb_angularforces[1] = rtb_ElementProduct[1] -
    FaultControllerModel_U.RobotCenterofMass[0] * rtb_angularforces[2];
  rtb_angularforces[2] = rtb_ElementProduct[2] - rtb_ElementProduct[5];

  /* Sum: '<S9>/angular forces' incorporates:
   *  Inport: '<Root>/Robot Center of Buoyancy'
   *  Product: '<S12>/Element Product'
   *  Sum: '<S12>/Sum'
   */
  rtb_angularforces[0] += FaultControllerModel_U.RobotCenterofBuoyancy[1] *
    rtb_Subtract2[2] - rtb_Subtract2[1] *
    FaultControllerModel_U.RobotCenterofBuoyancy[2];
  rtb_angularforces[1] += rtb_Subtract2[0] *
    FaultControllerModel_U.RobotCenterofBuoyancy[2] -
    FaultControllerModel_U.RobotCenterofBuoyancy[0] * rtb_Subtract2[2];
  rtb_angularforces[2] += FaultControllerModel_U.RobotCenterofBuoyancy[0] *
    rtb_Subtract2[1] - rtb_Subtract2[0] *
    FaultControllerModel_U.RobotCenterofBuoyancy[1];

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Reference orientation'
   *  Inport: '<Root>/Robot Orientation'
   */
  q_idx_2 = (FaultControllerModel_U.RobotOrientation[0] *
             FaultControllerModel_U.Referenceorientation[1] +
             FaultControllerModel_U.Referenceorientation[0] *
             -FaultControllerModel_U.RobotOrientation[1]) +
    (-FaultControllerModel_U.RobotOrientation[2] *
     FaultControllerModel_U.Referenceorientation[3] -
     FaultControllerModel_U.Referenceorientation[2] *
     -FaultControllerModel_U.RobotOrientation[3]);
  q_idx_3 = (FaultControllerModel_U.RobotOrientation[0] *
             FaultControllerModel_U.Referenceorientation[2] +
             FaultControllerModel_U.Referenceorientation[0] *
             -FaultControllerModel_U.RobotOrientation[2]) +
    (FaultControllerModel_U.Referenceorientation[1] *
     -FaultControllerModel_U.RobotOrientation[3] -
     -FaultControllerModel_U.RobotOrientation[1] *
     FaultControllerModel_U.Referenceorientation[3]);
  err_idx_3 = (FaultControllerModel_U.RobotOrientation[0] *
               FaultControllerModel_U.Referenceorientation[3] +
               FaultControllerModel_U.Referenceorientation[0] *
               -FaultControllerModel_U.RobotOrientation[3]) +
    (-FaultControllerModel_U.RobotOrientation[1] *
     FaultControllerModel_U.Referenceorientation[2] -
     FaultControllerModel_U.Referenceorientation[1] *
     -FaultControllerModel_U.RobotOrientation[2]);

  /* Sum: '<S3>/Subtract' incorporates:
   *  Inport: '<Root>/Reference linear Position'
   *  Inport: '<Root>/Robot Linear Position'
   */
  rtb_y_n_tmp_3 = FaultControllerModel_U.RobotLinearPosition[0] -
    FaultControllerModel_U.ReferencelinearPosition[0];

  /* Sum: '<S3>/Subtract1' incorporates:
   *  Inport: '<Root>/Reference Linear Velocity'
   *  Inport: '<Root>/Robot Linear Velocity'
   */
  rtb_y_n_tmp = FaultControllerModel_U.RobotLinearVelocity[0] -
    FaultControllerModel_U.ReferenceLinearVelocity;

  /* Sum: '<S3>/Subtract' incorporates:
   *  Inport: '<Root>/Reference linear Position'
   *  Inport: '<Root>/Robot Linear Position'
   */
  rtb_y_n_tmp_0 = FaultControllerModel_U.RobotLinearPosition[1] -
    FaultControllerModel_U.ReferencelinearPosition[1];

  /* Sum: '<S3>/Subtract1' incorporates:
   *  Inport: '<Root>/Reference Linear Velocity'
   *  Inport: '<Root>/Robot Linear Velocity'
   */
  rtb_y_n_tmp_1 = FaultControllerModel_U.RobotLinearVelocity[1] -
    FaultControllerModel_U.ReferenceLinearVelocity;

  /* Sum: '<S3>/Subtract' incorporates:
   *  Inport: '<Root>/Reference linear Position'
   *  Inport: '<Root>/Robot Linear Position'
   */
  absx = FaultControllerModel_U.RobotLinearPosition[2] -
    FaultControllerModel_U.ReferencelinearPosition[2];

  /* Sum: '<S3>/Subtract1' incorporates:
   *  Inport: '<Root>/Reference Linear Velocity'
   *  Inport: '<Root>/Robot Linear Velocity'
   */
  q_idx_1 = FaultControllerModel_U.RobotLinearVelocity[2] -
    FaultControllerModel_U.ReferenceLinearVelocity;

  /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  for (c_k = 0; c_k <= 0; c_k += 2) {
    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Sum: '<S3>/Subtract2' incorporates:
     *  Inport: '<Root>/Reference Angular Velocity'
     *  Inport: '<Root>/Robot Angular Velocity'
     */
    _mm_storeu_pd(&tmp_1[c_k], _mm_sub_pd(_mm_loadu_pd
      (&FaultControllerModel_U.RobotAngularVelocity[c_k]), _mm_set1_pd
      (FaultControllerModel_U.ReferenceAngularVelocity)));

    /* Product: '<S4>/Matrix Multiply1' */
    tmp_a = _mm_set1_pd(0.0);

    /* Sum: '<S4>/Sum' incorporates:
     *  Inport: '<Root>/Linear P Gains'
     *  Inport: '<Root>/Robot Angular Velocity'
     *  Product: '<S4>/Matrix Multiply'
     *  Product: '<S4>/Matrix Multiply1'
     *  Sum: '<S3>/Subtract2'
     */
    _mm_storeu_pd(&rtb_Subtract2[c_k], _mm_sub_pd(tmp_a, _mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&FaultControllerModel_U.LinearPGains[c_k + 3]),
                  _mm_set1_pd(rtb_y_n_tmp_0)), _mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.LinearPGains[c_k]), _mm_set1_pd(rtb_y_n_tmp_3))),
      _mm_mul_pd(_mm_loadu_pd(&FaultControllerModel_U.LinearPGains[c_k + 6]),
                 _mm_set1_pd(absx)))));

    /* Sum: '<S4>/Sum1' incorporates:
     *  Inport: '<Root>/Angular P Gains'
     *  Inport: '<Root>/Robot Angular Velocity'
     *  MATLAB Function: '<S3>/MATLAB Function'
     *  Product: '<S4>/Matrix Multiply1'
     *  Product: '<S4>/Matrix Multiply3'
     *  Sum: '<S3>/Subtract2'
     */
    _mm_storeu_pd(&tmp_2[c_k], _mm_sub_pd(tmp_a, _mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&FaultControllerModel_U.AngularPGains[c_k + 3]),
                  _mm_set1_pd(q_idx_3)), _mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.AngularPGains[c_k]), _mm_set1_pd(q_idx_2))),
      _mm_mul_pd(_mm_loadu_pd(&FaultControllerModel_U.AngularPGains[c_k + 6]),
                 _mm_set1_pd(err_idx_3)))));

    /* Product: '<S4>/Matrix Multiply1' incorporates:
     *  Inport: '<Root>/Linear Velocity Gains'
     *  Inport: '<Root>/Robot Angular Velocity'
     *  Sum: '<S3>/Subtract2'
     */
    _mm_storeu_pd(&tmp_0[c_k], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.LinearVelocityGains[c_k + 6]), _mm_set1_pd
      (q_idx_1)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.LinearVelocityGains[c_k + 3]), _mm_set1_pd
      (rtb_y_n_tmp_1)), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.LinearVelocityGains[c_k]), _mm_set1_pd
      (rtb_y_n_tmp)), tmp_a))));

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
  for (c_k = 2; c_k < 3; c_k++) {
    /* Sum: '<S3>/Subtract2' incorporates:
     *  Inport: '<Root>/Reference Angular Velocity'
     *  Inport: '<Root>/Robot Angular Velocity'
     */
    tmp_1[c_k] = FaultControllerModel_U.RobotAngularVelocity[c_k] -
      FaultControllerModel_U.ReferenceAngularVelocity;

    /* Sum: '<S4>/Sum' incorporates:
     *  Inport: '<Root>/Linear P Gains'
     *  Product: '<S4>/Matrix Multiply'
     */
    rtb_Subtract2[c_k] = 0.0 - ((FaultControllerModel_U.LinearPGains[c_k + 3] *
      rtb_y_n_tmp_0 + FaultControllerModel_U.LinearPGains[c_k] * rtb_y_n_tmp_3)
      + FaultControllerModel_U.LinearPGains[c_k + 6] * absx);

    /* Sum: '<S4>/Sum1' incorporates:
     *  Inport: '<Root>/Angular P Gains'
     *  MATLAB Function: '<S3>/MATLAB Function'
     *  Product: '<S4>/Matrix Multiply3'
     */
    tmp_2[c_k] = 0.0 - ((FaultControllerModel_U.AngularPGains[c_k + 3] * q_idx_3
                         + FaultControllerModel_U.AngularPGains[c_k] * q_idx_2)
                        + FaultControllerModel_U.AngularPGains[c_k + 6] *
                        err_idx_3);

    /* Product: '<S4>/Matrix Multiply1' incorporates:
     *  Inport: '<Root>/Linear Velocity Gains'
     */
    tmp_0[c_k] = (FaultControllerModel_U.LinearVelocityGains[c_k + 3] *
                  rtb_y_n_tmp_1 + FaultControllerModel_U.LinearVelocityGains[c_k]
                  * rtb_y_n_tmp) +
      FaultControllerModel_U.LinearVelocityGains[c_k + 6] * q_idx_1;
  }

  /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  for (c_k = 0; c_k <= 0; c_k += 2) {
    /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
    /* Sum: '<S4>/Sum2' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    tmp_a = _mm_loadu_pd(&rtb_linearforces[c_k]);
    _mm_storeu_pd(&rtb_ElementProduct[c_k], tmp_a);
    tmp_a = _mm_loadu_pd(&rtb_angularforces[c_k]);
    _mm_storeu_pd(&rtb_ElementProduct[c_k + 3], tmp_a);

    /* Sum: '<S4>/Sum' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    tmp_a = _mm_loadu_pd(&rtb_Subtract2[c_k]);
    tmp_9 = _mm_loadu_pd(&tmp_0[c_k]);

    /* Sum: '<S4>/Sum2' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_3[c_k], _mm_sub_pd(tmp_a, tmp_9));

    /* Sum: '<S4>/Sum1' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    tmp_a = _mm_loadu_pd(&tmp_2[c_k]);

    /* Sum: '<S4>/Sum2' incorporates:
     *  Inport: '<Root>/Angular Velocity Gains'
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_3[c_k + 3], _mm_sub_pd(tmp_a, _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&FaultControllerModel_U.AngularVelocityGains[c_k + 6]),
       _mm_set1_pd(tmp_1[2])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.AngularVelocityGains[c_k + 3]), _mm_set1_pd
      (tmp_1[1])), _mm_add_pd(_mm_mul_pd(_mm_loadu_pd
      (&FaultControllerModel_U.AngularVelocityGains[c_k]), _mm_set1_pd(tmp_1[0])),
      _mm_set1_pd(0.0))))));

    /* Inport: '<Root>/Robot Linear Velocity' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    tmp_a = _mm_loadu_pd(&FaultControllerModel_U.RobotLinearVelocity[c_k]);

    /* Product: '<S10>/Product' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_4[c_k], tmp_a);

    /* Inport: '<Root>/Robot Angular Velocity' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    tmp_9 = _mm_loadu_pd(&FaultControllerModel_U.RobotAngularVelocity[c_k]);

    /* Product: '<S10>/Product' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_4[c_k + 3], tmp_9);

    /* Abs: '<S10>/Abs' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_5[c_k], tmp_a);
    _mm_storeu_pd(&tmp_5[c_k + 3], tmp_9);

    /* Product: '<S10>/Product1' incorporates:
     *  Product: '<S4>/Matrix Multiply2'
     */
    _mm_storeu_pd(&tmp_6[c_k], tmp_a);
    _mm_storeu_pd(&tmp_6[c_k + 3], tmp_9);

    /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/FaultControllerModel' */
  for (c_k = 2; c_k < 3; c_k++) {
    /* Sum: '<S4>/Sum2' incorporates:
     *  Inport: '<Root>/Angular Velocity Gains'
     *  Product: '<S4>/Matrix Multiply2'
     *  Sum: '<S4>/Sum'
     *  Sum: '<S4>/Sum1'
     */
    rtb_ElementProduct[c_k] = rtb_linearforces[c_k];
    rtb_ElementProduct[c_k + 3] = rtb_angularforces[c_k];
    tmp_3[c_k] = rtb_Subtract2[c_k] - tmp_0[c_k];
    tmp_3[c_k + 3] = tmp_2[c_k] -
      ((FaultControllerModel_U.AngularVelocityGains[c_k + 3] * tmp_1[1] +
        FaultControllerModel_U.AngularVelocityGains[c_k] * tmp_1[0]) +
       FaultControllerModel_U.AngularVelocityGains[c_k + 6] * tmp_1[2]);

    /* Product: '<S10>/Product' incorporates:
     *  Inport: '<Root>/Robot Angular Velocity'
     *  Inport: '<Root>/Robot Linear Velocity'
     */
    tmp_4[c_k] = FaultControllerModel_U.RobotLinearVelocity[c_k];
    tmp_4[c_k + 3] = FaultControllerModel_U.RobotAngularVelocity[c_k];

    /* Abs: '<S10>/Abs' incorporates:
     *  Inport: '<Root>/Robot Angular Velocity'
     *  Inport: '<Root>/Robot Linear Velocity'
     */
    tmp_5[c_k] = FaultControllerModel_U.RobotLinearVelocity[c_k];
    tmp_5[c_k + 3] = FaultControllerModel_U.RobotAngularVelocity[c_k];

    /* Product: '<S10>/Product1' incorporates:
     *  Inport: '<Root>/Robot Angular Velocity'
     *  Inport: '<Root>/Robot Linear Velocity'
     */
    tmp_6[c_k] = FaultControllerModel_U.RobotLinearVelocity[c_k];
    tmp_6[c_k + 3] = FaultControllerModel_U.RobotAngularVelocity[c_k];
  }

  /* Sum: '<S4>/Sum2' incorporates:
   *  Abs: '<S10>/Abs'
   *  Inport: '<Root>/Linear Drag Coefficients'
   *  Inport: '<Root>/Quadratic Drag Coefficients'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Sum: '<S10>/Sum3'
   */
  for (c_k = 0; c_k < 6; c_k++) {
    FaultControllerModel_Y.NetForce[c_k] = (tmp_6[c_k] * fabs(tmp_5[c_k]) *
      FaultControllerModel_U.QuadraticDragCoefficients[c_k] + tmp_4[c_k] *
      FaultControllerModel_U.LinearDragCoefficients[c_k]) +
      (rtb_ElementProduct[c_k] + tmp_3[c_k]);
  }

  /* Product: '<S2>/Get Thruster forces' incorporates:
   *  MATLAB Function: '<S2>/Take inverse'
   *  Sum: '<S4>/Sum2'
   */
  for (c_k = 0; c_k < 8; c_k++) {
    FaultControllerModel_Y.ThrusterForces[c_k] = 0.0;
    for (vectorUB = 0; vectorUB < 6; vectorUB++) {
      FaultControllerModel_Y.ThrusterForces[c_k] += X[6 * c_k + vectorUB] *
        FaultControllerModel_Y.NetForce[vectorUB];
    }
  }

  /* End of Product: '<S2>/Get Thruster forces' */

  /* MinMax: '<S5>/Clamp forces to Max' incorporates:
   *  Inport: '<Root>/Misc Thruster force to DShot Values'
   *  MATLAB Function: '<S5>/Create 8 row vector of the maximum thruster forces'
   *  Product: '<S2>/Get Thruster forces'
   */
  rtb_ClampforcestoMax[0] = fmin(FaultControllerModel_Y.ThrusterForces[0],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[1] = fmin(FaultControllerModel_Y.ThrusterForces[1],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[2] = fmin(FaultControllerModel_Y.ThrusterForces[2],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[3] = fmin(FaultControllerModel_Y.ThrusterForces[3],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[4] = fmin(FaultControllerModel_Y.ThrusterForces[4],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[5] = fmin(FaultControllerModel_Y.ThrusterForces[5],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[6] = fmin(FaultControllerModel_Y.ThrusterForces[6],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);
  rtb_ClampforcestoMax[7] = fmin(FaultControllerModel_Y.ThrusterForces[7],
    FaultControllerModel_U.MiscThrusterforcetoDShotValues[0]);

  /* MATLAB Function: '<S5>/Convert to DShot' incorporates:
   *  Inport: '<Root>/Misc Thruster force to DShot Values'
   *  Inport: '<Root>/Thruster Directions'
   *  MinMax: '<S5>/Clamp forces to Max'
   */
  for (r = 0; r < 8; r++) {
    absx = rtb_ClampforcestoMax[r];
    if (fabs(absx) < FaultControllerModel_U.MiscThrusterforcetoDShotValues[1]) {
      FaultControllerModel_Y.DshotCommands[r] = 0;
    } else if ((absx > 0.0) && (absx <=
                FaultControllerModel_U.MiscThrusterforcetoDShotValues[2])) {
      if (FaultControllerModel_U.ThrusterDirections == 0.0) {
        absx = rt_roundd_snf
          (FaultControllerModel_U.MiscThrusterforcetoDShotValues[3] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[4]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      } else {
        absx = rt_roundd_snf
          (-FaultControllerModel_U.MiscThrusterforcetoDShotValues[3] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[6]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      }
    } else if ((absx > 0.0) && (absx >
                FaultControllerModel_U.MiscThrusterforcetoDShotValues[2])) {
      if (FaultControllerModel_U.ThrusterDirections == 0.0) {
        absx = rt_roundd_snf
          (FaultControllerModel_U.MiscThrusterforcetoDShotValues[7] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[8]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      } else {
        absx = rt_roundd_snf
          (-FaultControllerModel_U.MiscThrusterforcetoDShotValues[7] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[10]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      }
    } else if ((absx < 0.0) && (absx >=
                -FaultControllerModel_U.MiscThrusterforcetoDShotValues[2])) {
      if (FaultControllerModel_U.ThrusterDirections == 0.0) {
        absx = rt_roundd_snf
          (FaultControllerModel_U.MiscThrusterforcetoDShotValues[5] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[6]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      } else {
        absx = rt_roundd_snf
          (-FaultControllerModel_U.MiscThrusterforcetoDShotValues[5] * absx +
           FaultControllerModel_U.MiscThrusterforcetoDShotValues[4]);
        if (absx < 32768.0) {
          if (absx >= -32768.0) {
            FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
          }
        } else {
          FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
        }
      }
    } else if (absx < 0.0) {
      if (absx < -FaultControllerModel_U.MiscThrusterforcetoDShotValues[2]) {
        if (FaultControllerModel_U.ThrusterDirections == 0.0) {
          absx = rt_roundd_snf
            (FaultControllerModel_U.MiscThrusterforcetoDShotValues[9] * absx +
             FaultControllerModel_U.MiscThrusterforcetoDShotValues[10]);
          if (absx < 32768.0) {
            if (absx >= -32768.0) {
              FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
            } else {
              FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
            }
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
          }
        } else {
          absx = rt_roundd_snf
            (FaultControllerModel_U.MiscThrusterforcetoDShotValues[9] * absx +
             FaultControllerModel_U.MiscThrusterforcetoDShotValues[8]);
          if (absx < 32768.0) {
            if (absx >= -32768.0) {
              FaultControllerModel_Y.DshotCommands[r] = (int16_T)absx;
            } else {
              FaultControllerModel_Y.DshotCommands[r] = MIN_int16_T;
            }
          } else {
            FaultControllerModel_Y.DshotCommands[r] = MAX_int16_T;
          }
        }
      } else {
        FaultControllerModel_Y.DshotCommands[r] = 0;
      }
    } else {
      FaultControllerModel_Y.DshotCommands[r] = 0;
    }
  }

  /* End of MATLAB Function: '<S5>/Convert to DShot' */
  /* End of Outputs for SubSystem: '<Root>/FaultControllerModel' */
}

/* Model initialize function */
void FaultControllerModel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void FaultControllerModel_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
