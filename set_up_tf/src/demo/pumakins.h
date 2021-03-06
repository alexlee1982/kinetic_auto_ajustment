/*****************************************************************
* Description: pumakins.h
*   Kinematics for a puma typed robot
*
*   Derived from a work by Fred Proctor
*
* Author: 
* License: GPL Version 2
* System: Linux
*    
* Copyright (c) 2004 All rights reserved.
*
* Last change:
* $Revision: 1.1 $
* $Author: alex_joni $
* $Date: 2007/02/03 16:28:58 $
*******************************************************************
* This is the header file to accompany pumakins.c.  
*******************************************************************
*/
#ifndef PUMA_H
#define PUMA_H
/* the default values for a PUMA 560 type robot, these can be changed as HAL parameters */
double amin[6]={-270,-270,-270,-270,-270,-350};
double amax[6]={270,270,270,270,270,350};
double old_joint[6];
int cflag[8];


#define SINGULAR_FUZZ 0.000001
#define FLAG_FUZZ     0.000001

/* flags for inverse kinematics */
#define PUMA_SHOULDER_RIGHT 0x01
#define PUMA_ELBOW_DOWN     0x02
#define PUMA_WRIST_DOWN   0x10
#define PUMA_WRIST_FLIP     0x04
#define PUMA_SINGULAR       0x08  /* joints at a singularity */

/* flags for forward kinematics */
#define PUMA_REACH          0x01  /* pose out of reach */

#endif /* PUMA_H */
