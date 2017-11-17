/*
 * File: F_J_z.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 03-Nov-2017 14:06:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "F_J_z.h"

/* Function Definitions */

/*
 * UNTITLED3 �˴���ʾ�йش˺�����ժҪ
 *    �˴���ʾ��ϸ˵��
 * Arguments    : const double th[6]
 *                const double L[5]
 *                double J[24]
 * Return Type  : void
 */
void F_J_z(const double th[6], const double L[5], double J[24])
{
  double th2;
  double th3;
  double th4;
  double th5;
  double th6;
  th2 = th[1] * 0.017453292519943295;
  th3 = th[2] * 0.017453292519943295;
  th4 = th[3] * 0.017453292519943295;
  th5 = th[4] * 0.017453292519943295;
  th6 = th[5] * 0.017453292519943295;
  J[0] = 0.0;
  J[1] = (((-L[3] * (cos(th2) * sin(th3) - cos(th3) * sin(th2)) - L[1] * cos(th2))
           - L[4] * (cos(th5) * (cos(th2) * sin(th3) - cos(th3) * sin(th2)) +
                     cos(th4) * sin(th5) * (cos(th2) * cos(th3) + sin(th2) * sin
             (th3)))) - L[2] * cos(th2) * cos(th3)) - L[2] * sin(th2) * sin(th3);
  J[2] = ((L[3] * (cos(th2) * sin(th3) - cos(th3) * sin(th2)) + L[4] * (cos(th5)
            * (cos(th2) * sin(th3) - cos(th3) * sin(th2)) + cos(th4) * sin(th5) *
            (cos(th2) * cos(th3) + sin(th2) * sin(th3)))) + L[2] * cos(th2) *
          cos(th3)) + L[2] * sin(th2) * sin(th3);
  J[3] = -L[4] * sin(th4) * sin(th5) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[4] = L[4] * (sin(th5) * (cos(th2) * cos(th3) + sin(th2) * sin(th3)) + cos
                 (th4) * cos(th5) * (cos(th2) * sin(th3) - cos(th3) * sin(th2)));
  J[5] = 0.0;
  J[6] = L[4] * sin(th4) * sin(th5);
  J[7] = L[4] * cos(th2) * sin(th4) * sin(th5);
  J[8] = L[4] * sin(th4) * sin(th5) * (cos(th2) * cos(th3) + sin(th2) * sin(th3));
  J[9] = -L[4] * cos(th5) * sin(th4) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[10] = -L[4] * sin(th4) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[11] = 0.0;
  J[12] = 0.0;
  J[13] = -sin(th2);
  J[14] = cos(th2) * sin(th3) - cos(th3) * sin(th2);
  J[15] = cos(th4) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[16] = sin(th5) * (cos(th2) * cos(th3) + sin(th2) * sin(th3)) + cos(th4) *
    cos(th5) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[17] = cos(th6) * (sin(th5) * (cos(th2) * cos(th3) + sin(th2) * sin(th3)) +
                      cos(th4) * cos(th5) * (cos(th2) * sin(th3) - cos(th3) *
    sin(th2))) - sin(th4) * sin(th6) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[18] = 1.0;
  J[19] = 0.0;
  J[20] = 0.0;
  J[21] = cos(th2) * cos(th3) + sin(th2) * sin(th3);
  J[22] = sin(th4) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
  J[23] = cos(th5) * (cos(th2) * cos(th3) + sin(th2) * sin(th3)) - cos(th4) *
    sin(th5) * (cos(th2) * sin(th3) - cos(th3) * sin(th2));
}

/*
 * File trailer for F_J_z.c
 *
 * [EOF]
 */
