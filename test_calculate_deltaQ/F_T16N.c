/*
 * File: F_T16N.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 03-Nov-2017 14:06:29
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculate_the_deltaq.h"
#include "F_T16N.h"
#include "cosd.h"
#include "sind.h"

/* Function Definitions */

/*
 * UNTITLED 此处显示有关此函数的摘要
 *    此处显示详细说明
 * Arguments    : const double th[6]
 *                const double L[5]
 *                double A[16]
 * Return Type  : void
 */
void F_T16N(const double th[6], const double L[5], double A[16])
{
  double d0;
  double d1;
  double d2;
  double d3;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double d10;
  double d11;
  double d12;
  double d13;
  double d14;
  double d15;
  double d16;
  double d17;
  double d18;
  double d19;
  double d20;
  double d21;
  double d22;
  double d23;
  double d24;
  double d25;
  double d26;
  double d27;
  double d28;
  double d29;
  double d30;
  double d31;
  double d32;
  double d33;
  double d34;
  double d35;
  double d36;
  double d37;
  double d38;
  double d39;
  double d40;
  double d41;
  double d42;
  double d43;
  double d44;
  double d45;
  double d46;
  double d47;
  double d48;
  double d49;
  double d50;
  double d51;
  double d52;
  double d53;
  double d54;
  double d55;
  double d56;
  double d57;
  double d58;
  double d59;
  double d60;
  double d61;
  double d62;
  double d63;
  double d64;
  double d65;
  double d66;
  double d67;
  double d68;
  double d69;
  double d70;
  double d71;
  double d72;
  double d73;
  double d74;
  double d75;
  double d76;
  double d77;
  double d78;
  double d79;
  double d80;
  double d81;
  double d82;
  double d83;
  double dv9[16];
  double dv10[16];
  int i2;
  double dv11[16];
  static const signed char iv0[4] = { 0, 0, 0, 1 };

  double dv12[16];
  int i3;
  int i4;

  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  /* UNTITLED2 此处显示有关此函数的摘要 */
  /*    此处显示详细说明 计算第num个关节变换矩阵的名义矩阵，th代表输入的关节角度。 */
  /* 定义一些常量 */
  d0 = th[0];
  cosd(&d0);
  d1 = th[0];
  sind(&d1);
  d2 = -90.0;
  cosd(&d2);
  d3 = th[0];
  sind(&d3);
  d4 = -90.0;
  sind(&d4);
  d5 = th[0];
  cosd(&d5);
  d6 = th[0];
  sind(&d6);
  d7 = th[0];
  cosd(&d7);
  d8 = -90.0;
  cosd(&d8);
  d9 = th[0];
  cosd(&d9);
  d10 = -90.0;
  sind(&d10);
  d11 = th[0];
  sind(&d11);
  d12 = -90.0;
  sind(&d12);
  d13 = -90.0;
  cosd(&d13);
  d14 = th[1];
  cosd(&d14);
  d15 = th[1];
  sind(&d15);
  d16 = 180.0;
  cosd(&d16);
  d17 = th[1];
  sind(&d17);
  d18 = 180.0;
  sind(&d18);
  d19 = th[1];
  cosd(&d19);
  d20 = th[1];
  sind(&d20);
  d21 = th[1];
  cosd(&d21);
  d22 = 180.0;
  cosd(&d22);
  d23 = th[1];
  cosd(&d23);
  d24 = 180.0;
  sind(&d24);
  d25 = th[1];
  sind(&d25);
  d26 = 180.0;
  sind(&d26);
  d27 = 180.0;
  cosd(&d27);
  d28 = th[2];
  cosd(&d28);
  d29 = th[2];
  sind(&d29);
  d30 = -90.0;
  cosd(&d30);
  d31 = th[2];
  sind(&d31);
  d32 = -90.0;
  sind(&d32);
  d33 = th[2];
  cosd(&d33);
  d34 = th[2];
  sind(&d34);
  d35 = th[2];
  cosd(&d35);
  d36 = -90.0;
  cosd(&d36);
  d37 = th[2];
  cosd(&d37);
  d38 = -90.0;
  sind(&d38);
  d39 = th[2];
  sind(&d39);
  d40 = -90.0;
  sind(&d40);
  d41 = -90.0;
  cosd(&d41);
  d42 = th[3];
  cosd(&d42);
  d43 = th[3];
  sind(&d43);
  d44 = 90.0;
  cosd(&d44);
  d45 = th[3];
  sind(&d45);
  d46 = 90.0;
  sind(&d46);
  d47 = th[3];
  cosd(&d47);
  d48 = th[3];
  sind(&d48);
  d49 = th[3];
  cosd(&d49);
  d50 = 90.0;
  cosd(&d50);
  d51 = th[3];
  cosd(&d51);
  d52 = 90.0;
  sind(&d52);
  d53 = th[3];
  sind(&d53);
  d54 = 90.0;
  sind(&d54);
  d55 = 90.0;
  cosd(&d55);
  d56 = th[4];
  cosd(&d56);
  d57 = th[4];
  sind(&d57);
  d58 = -90.0;
  cosd(&d58);
  d59 = th[4];
  sind(&d59);
  d60 = -90.0;
  sind(&d60);
  d61 = th[4];
  cosd(&d61);
  d62 = th[4];
  sind(&d62);
  d63 = th[4];
  cosd(&d63);
  d64 = -90.0;
  cosd(&d64);
  d65 = th[4];
  cosd(&d65);
  d66 = -90.0;
  sind(&d66);
  d67 = th[4];
  sind(&d67);
  d68 = -90.0;
  sind(&d68);
  d69 = -90.0;
  cosd(&d69);
  d70 = th[5];
  cosd(&d70);
  d71 = th[5];
  sind(&d71);
  d72 = 180.0;
  cosd(&d72);
  d73 = th[5];
  sind(&d73);
  d74 = 180.0;
  sind(&d74);
  d75 = th[5];
  cosd(&d75);
  d76 = th[5];
  sind(&d76);
  d77 = th[5];
  cosd(&d77);
  d78 = 180.0;
  cosd(&d78);
  d79 = th[5];
  cosd(&d79);
  d80 = 180.0;
  sind(&d80);
  d81 = th[5];
  sind(&d81);
  d82 = 180.0;
  sind(&d82);
  d83 = 180.0;
  cosd(&d83);
  dv9[0] = d0;
  dv9[4] = -d1 * d2;
  dv9[8] = d3 * d4;
  dv9[12] = L[0] * d5;
  dv9[1] = d6;
  dv9[5] = d7 * d8;
  dv9[9] = -d9 * d10;
  dv9[13] = L[0] * d11;
  dv9[2] = 0.0;
  dv9[6] = d12;
  dv9[10] = d13;
  dv9[14] = 0.0;
  dv10[0] = d14;
  dv10[4] = -d15 * d16;
  dv10[8] = d17 * d18;
  dv10[12] = L[1] * d19;
  dv10[1] = d20;
  dv10[5] = d21 * d22;
  dv10[9] = -d23 * d24;
  dv10[13] = L[1] * d25;
  dv10[2] = 0.0;
  dv10[6] = d26;
  dv10[10] = d27;
  dv10[14] = 0.0;
  for (i2 = 0; i2 < 4; i2++) {
    dv9[3 + (i2 << 2)] = iv0[i2];
    dv10[3 + (i2 << 2)] = iv0[i2];
  }

  dv12[0] = d28;
  dv12[4] = -d29 * d30;
  dv12[8] = d31 * d32;
  dv12[12] = L[2] * d33;
  dv12[1] = d34;
  dv12[5] = d35 * d36;
  dv12[9] = -d37 * d38;
  dv12[13] = L[2] * d39;
  dv12[2] = 0.0;
  dv12[6] = d40;
  dv12[10] = d41;
  dv12[14] = 0.0;
  for (i2 = 0; i2 < 4; i2++) {
    for (i3 = 0; i3 < 4; i3++) {
      dv11[i2 + (i3 << 2)] = 0.0;
      for (i4 = 0; i4 < 4; i4++) {
        dv11[i2 + (i3 << 2)] += dv9[i2 + (i4 << 2)] * dv10[i4 + (i3 << 2)];
      }
    }

    dv12[3 + (i2 << 2)] = iv0[i2];
  }

  dv10[0] = d42;
  dv10[4] = -d43 * d44;
  dv10[8] = d45 * d46;
  dv10[12] = 0.0 * d47;
  dv10[1] = d48;
  dv10[5] = d49 * d50;
  dv10[9] = -d51 * d52;
  dv10[13] = 0.0 * d53;
  dv10[2] = 0.0;
  dv10[6] = d54;
  dv10[10] = d55;
  dv10[14] = -L[3];
  for (i2 = 0; i2 < 4; i2++) {
    for (i3 = 0; i3 < 4; i3++) {
      dv9[i2 + (i3 << 2)] = 0.0;
      for (i4 = 0; i4 < 4; i4++) {
        dv9[i2 + (i3 << 2)] += dv11[i2 + (i4 << 2)] * dv12[i4 + (i3 << 2)];
      }
    }

    dv10[3 + (i2 << 2)] = iv0[i2];
  }

  dv12[0] = d56;
  dv12[4] = -d57 * d58;
  dv12[8] = d59 * d60;
  dv12[12] = 0.0 * d61;
  dv12[1] = d62;
  dv12[5] = d63 * d64;
  dv12[9] = -d65 * d66;
  dv12[13] = 0.0 * d67;
  dv12[2] = 0.0;
  dv12[6] = d68;
  dv12[10] = d69;
  dv12[14] = 0.0;
  for (i2 = 0; i2 < 4; i2++) {
    for (i3 = 0; i3 < 4; i3++) {
      dv11[i2 + (i3 << 2)] = 0.0;
      for (i4 = 0; i4 < 4; i4++) {
        dv11[i2 + (i3 << 2)] += dv9[i2 + (i4 << 2)] * dv10[i4 + (i3 << 2)];
      }
    }

    dv12[3 + (i2 << 2)] = iv0[i2];
  }

  dv10[0] = d70;
  dv10[4] = -d71 * d72;
  dv10[8] = d73 * d74;
  dv10[12] = 0.0 * d75;
  dv10[1] = d76;
  dv10[5] = d77 * d78;
  dv10[9] = -d79 * d80;
  dv10[13] = 0.0 * d81;
  dv10[2] = 0.0;
  dv10[6] = d82;
  dv10[10] = d83;
  dv10[14] = -L[4];
  for (i2 = 0; i2 < 4; i2++) {
    for (i3 = 0; i3 < 4; i3++) {
      dv9[i2 + (i3 << 2)] = 0.0;
      for (i4 = 0; i4 < 4; i4++) {
        dv9[i2 + (i3 << 2)] += dv11[i2 + (i4 << 2)] * dv12[i4 + (i3 << 2)];
      }
    }

    dv10[3 + (i2 << 2)] = iv0[i2];
  }

  for (i2 = 0; i2 < 4; i2++) {
    for (i3 = 0; i3 < 4; i3++) {
      A[i2 + (i3 << 2)] = 0.0;
      for (i4 = 0; i4 < 4; i4++) {
        A[i2 + (i3 << 2)] += dv9[i2 + (i4 << 2)] * dv10[i4 + (i3 << 2)];
      }
    }
  }
}

/*
 * File trailer for F_T16N.c
 *
 * [EOF]
 */
