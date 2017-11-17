/*
 * File: calculate_the_deltaq.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 03-Nov-2017 14:06:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "F_J_z.h"
#include "F_J_y.h"
#include "F_J_x.h"
#include "F_T16N.h"
#include "mldivide.h"
#include<QtCore>
#include<QDebug>
#include <stdio.h>
/* Function Definitions */

/*
 * UNTITLED �˴���ʾ�йش˺�����ժҪ
 *    �˴���ʾ��ϸ˵��
 *  th Ϊ����ĽǶ�ֵ��Ϊһ��20*6�ľ���disR�ǲ�����ʵ�ʾ���ֵ��EΪ���ֵ����һ��19*1��������
 * ����th������������Ȼ����������λ�ã�������룬�ſ˱Ⱦ���Ȼ�����J
 * JΪһ��20*24�ľ����������deltaq=J\E���������ʶ������
 * Arguments    : const double th[120]
 *                const double disR[19]
 *                const double L[5]
 *                double deltaq[24]
 * Return Type  : void
 */
void calculate_the_deltaq(const double th[120], const double disR[19], const
  double L[5], double deltaq[24])
{
  double E[19];
  double J[456];
  int i;
  double b_th[6];
  int i0;
  double T16N_A[16];
  double T16N_B[16];
  double a;
  double b_a;
  double c_a;
  double disN;
  double dv0[24];
  double dv1[24];
  double dv2[24];
  double dv3[24];
  double dv4[24];
  double dv5[24];
  double dv6[72];
  double dv7[72];
  double b_T16N_B[3];
  double dv8[72];
  int i1;

  for(i=0;i<5;i++)
  {
    qDebug()<<"L"<<i<<"="<<L[i];
    //printf("L[%d]=%f\n",i,L[i]);
  }

  for(i=0;i<19;i++)
  {
    qDebug()<<"dis"<<i<<"="<<disR[i];
    //printf("L[%d]=%f\n",i,L[i]);
  }
  for(i=0;i<120;i++)
  {
    qDebug()<<"th"<<i<<"="<<th[i];
    //printf("L[%d]=%f\n",i,L[i]);
  }

  /* L=[100 300 20 300 100]; */
  for (i = 0; i < 19; i++) {
    /* ����th�����ݣ���������λ������� */
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[i + 20 * i0];
    }

    F_T16N(b_th, L, T16N_A);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[(i + 20 * i0) + 1];
    }

    F_T16N(b_th, L, T16N_B);
    a = T16N_B[12] - T16N_A[12];
    b_a = T16N_B[13] - T16N_A[13];
    c_a = T16N_B[14] - T16N_A[14];
    disN = sqrt((a * a + b_a * b_a) + c_a * c_a);
    E[i] = disN - disR[i];
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[i + 20 * i0];
    }

    F_J_x(b_th, L, dv0);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[i + 20 * i0];
    }

    F_J_y(b_th, L, dv1);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[i + 20 * i0];
    }

    F_J_z(b_th, L, dv2);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[(i + 20 * i0) + 1];
    }

    F_J_x(b_th, L, dv3);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[(i + 20 * i0) + 1];
    }

    F_J_y(b_th, L, dv4);
    for (i0 = 0; i0 < 6; i0++) {
      b_th[i0] = th[(i + 20 * i0) + 1];
    }

    F_J_z(b_th, L, dv5);
    b_T16N_B[0] = (T16N_B[12] - T16N_A[12]) / disN;
    b_T16N_B[1] = (T16N_B[13] - T16N_A[13]) / disN;
    b_T16N_B[2] = (T16N_B[14] - T16N_A[14]) / disN;
    for (i0 = 0; i0 < 24; i0++) {
      dv6[3 * i0] = dv0[i0];
      dv6[1 + 3 * i0] = dv1[i0];
      dv6[2 + 3 * i0] = dv2[i0];
      dv7[3 * i0] = dv3[i0];
      dv7[1 + 3 * i0] = dv4[i0];
      dv7[2 + 3 * i0] = dv5[i0];
      J[i + 19 * i0] = 0.0;
      for (i1 = 0; i1 < 3; i1++) {
        dv8[i1 + 3 * i0] = dv6[i1 + 3 * i0] - dv7[i1 + 3 * i0];
        J[i + 19 * i0] += b_T16N_B[i1] * dv8[i1 + 3 * i0];
      }
    }
  }

  mldivide(J, E, deltaq);
}

/*
 * File trailer for calculate_the_deltaq.c
 *
 * [EOF]
 */
