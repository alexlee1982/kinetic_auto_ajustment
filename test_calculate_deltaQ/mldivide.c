/*
 * File: mldivide.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 03-Nov-2017 14:06:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "mldivide.h"
#include "xgeqp3.h"

/* Function Definitions */

/*
 * Arguments    : const double A[456]
 *                const double B[19]
 *                double Y[24]
 * Return Type  : void
 */
void mldivide(const double A[456], const double B[19], double Y[24])
{
  double b_A[456];
  double tau[19];
  int jpvt[24];
  int rankR;
  double tol;
  double b_B[19];
  int j;
  int i;
  memcpy(&b_A[0], &A[0], 456U * sizeof(double));
  xgeqp3(b_A, tau, jpvt);
  rankR = 0;
  tol = 24.0 * fabs(b_A[0]) * 2.2204460492503131E-16;
  while ((rankR < 19) && (fabs(b_A[rankR + 19 * rankR]) >= tol)) {
    rankR++;
  }

  memset(&Y[0], 0, 24U * sizeof(double));
  memcpy(&b_B[0], &B[0], 19U * sizeof(double));
  for (j = 0; j < 19; j++) {
    if (tau[j] != 0.0) {
      tol = b_B[j];
      for (i = j + 1; i + 1 < 20; i++) {
        tol += b_A[i + 19 * j] * b_B[i];
      }

      tol *= tau[j];
      if (tol != 0.0) {
        b_B[j] -= tol;
        for (i = j + 1; i + 1 < 20; i++) {
          b_B[i] -= b_A[i + 19 * j] * tol;
        }
      }
    }
  }

  for (i = 0; i + 1 <= rankR; i++) {
    Y[jpvt[i] - 1] = b_B[i];
  }

  for (j = rankR - 1; j + 1 > 0; j--) {
    Y[jpvt[j] - 1] /= b_A[j + 19 * j];
    for (i = 0; i + 1 <= j; i++) {
      Y[jpvt[i] - 1] -= Y[jpvt[j] - 1] * b_A[i + 19 * j];
    }
  }
}

/*
 * File trailer for mldivide.c
 *
 * [EOF]
 */
