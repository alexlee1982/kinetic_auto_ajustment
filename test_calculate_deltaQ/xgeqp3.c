/*
 * File: xgeqp3.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 03-Nov-2017 14:06:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "xgeqp3.h"
#include "xnrm2.h"
#include "xzlarf.h"
#include "xzlarfg.h"
#include "xswap.h"
#include "ixamax.h"

/* Function Definitions */

/*
 * Arguments    : double A[456]
 *                double tau[19]
 *                int jpvt[24]
 * Return Type  : void
 */
void xgeqp3(double A[456], double tau[19], int jpvt[24])
{
  int k;
  double vn1[24];
  double vn2[24];
  double work[24];
  int pvt;
  int i;
  double temp1;
  int itemp;
  double temp2;
  k = 1;
  for (pvt = 0; pvt < 24; pvt++) {
    jpvt[pvt] = 1 + pvt;
    work[pvt] = 0.0;
    temp1 = xnrm2(A, k);
    vn2[pvt] = temp1;
    k += 19;
    vn1[pvt] = temp1;
  }

  for (i = 0; i < 19; i++) {
    k = i + i * 19;
    pvt = (i + ixamax(24 - i, vn1, i + 1)) - 1;
    if (pvt + 1 != i + 1) {
      xswap(A, 1 + 19 * pvt, 1 + 19 * i);
      itemp = jpvt[pvt];
      jpvt[pvt] = jpvt[i];
      jpvt[i] = itemp;
      vn1[pvt] = vn1[i];
      vn2[pvt] = vn2[i];
    }

    if (i + 1 < 19) {
      temp1 = A[k];
      tau[i] = xzlarfg(19 - i, &temp1, A, k + 2);
      A[k] = temp1;
    } else {
      tau[18] = 0.0;
    }

    temp1 = A[k];
    A[k] = 1.0;
    xzlarf(19 - i, 23 - i, k + 1, tau[i], A, (i + (i + 1) * 19) + 1, work);
    A[k] = temp1;
    for (pvt = i + 1; pvt + 1 < 25; pvt++) {
      if (vn1[pvt] != 0.0) {
        temp1 = fabs(A[i + 19 * pvt]) / vn1[pvt];
        temp1 = 1.0 - temp1 * temp1;
        if (temp1 < 0.0) {
          temp1 = 0.0;
        }

        temp2 = vn1[pvt] / vn2[pvt];
        temp2 = temp1 * (temp2 * temp2);
        if (temp2 <= 1.4901161193847656E-8) {
          if (i + 1 < 19) {
            vn1[pvt] = c_xnrm2(18 - i, A, (i + 19 * pvt) + 2);
            vn2[pvt] = vn1[pvt];
          } else {
            vn1[pvt] = 0.0;
            vn2[pvt] = 0.0;
          }
        } else {
          vn1[pvt] *= sqrt(temp1);
        }
      }
    }
  }
}

/*
 * File trailer for xgeqp3.c
 *
 * [EOF]
 */
