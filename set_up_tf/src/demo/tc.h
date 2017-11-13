/********************************************************************
* Description: tc.h
*   Discriminate-based trajectory planning
*
*   Derived from a work by Fred Proctor & Will Shackleford
*
* Author:byf
* License: Version 2
* System: rtlinux
*    
* Date: 2007/07/14 21:43:22 
********************************************************************/
#ifndef TC_H
#define TC_H

#include "posemath.h"
#include "robotpos.h"
#include "motionInterfaceBuffer.h"
#define MAX_FILENAME_LENGTH       255

#define ACTIVE_G_CODES 14
 #define TC_FILTER_SIZE     10

#define TC_IS_DONE 1

/* values for endFlag */
#define TC_TERM_COND_STOP 1
#define TC_TERM_COND_BLEND 2

#define TC_LINEAR 1
#define TC_CIRCULAR 2
#define TC_RIGIDTAP 3
#define TC_3DCIRCULAR 4
#define TC_JLINEAR 5
/* structure for individual trajectory elements */

typedef struct {
    PmLine xyz;
    PmLine abc;
    PmLine uvw;
} PmLine9;

typedef struct {
    Pm3DCircle xyz;
    PmLine abc;
    PmLine uvw;
} PmCircle3D9;

typedef struct {
    PmCircle xyz;
    PmLine abc;
    PmLine uvw;
} PmCircle9;
/*! \todo FIXME - */// 2010.05.18 tapping:��˿reversing:��ת(����ͣ) retraction:�˳�final_reversal:���շ�ת(����ͣ) final_placement:���ն�λ
typedef enum {
    TAPPING, REVERSING, RETRACTION, FINAL_REVERSAL, FINAL_PLACEMENT
} RIGIDTAP_STATE;


typedef struct {
    PmLine xyz;             // original, but elongated, move down
    PmLine aux_xyz;         // this will be generated on the fly, for the other
                            // two moves: retraction, final placement
    PmCartesian abc;
    PmCartesian uvw;
    double reversal_target;
    double spindlerevs_at_reversal;
    RIGIDTAP_STATE state;
} PmRigidTap;

typedef struct {
	double cycle_time;
	double progress;        // where are we in the segment?  0..target
	double target;          // segment length
	double tmp_target;          // segment length
	double reqvel;          // vel requested by F word, calc'd by task
	double maxAccel;        // accel calc'd by task
	double feed_override;   // feed override requested by user
	double maxvel;          // max possible vel (feed override stops here)
	double currentvel;      // keep track of current step (vel * cycle_time)
	double maxaccel;     /* accel may be used just in beginning accel phase,
					    and maxaccel <= maxAccel */
	double PL;
	double CR;
	int  nwait;
	int iotype;
//	int addrtype;
	int stopcondition;
	int ioaddress;

       int dotype;
	int addrtype;
//	int ioaddr;
	int iostate;
	double accScale;
	double decScale;
	double jvscale;
	double vMax;
	double aMax;
	double vLimit;
	double wMax;
	double wDotMax;
	double  wLimit;
	int id;                 // segment's serial number
	char fileName[MAX_FILENAME_LENGTH];           // �ļ���---11.07.25

	union {                 // describes the segment's start and end positions
		PmLine9 line;
		PmCircle9 circle;
		PmRigidTap rigidtap;
		PmCircle3D9 circle3D;
		PmJLine   jline;
		} coords;
	int free;
        int joint_num;
	int joint_type;
	PmJoint deltjoints;
	char motion_type;       // TC_LINEAR (coords.line) or 
	                    // TC_CIRCULAR (coords.circle) or
	                    // TC_RIGIDTAP (coords.rigidtap)
	char active;            // this motion is being executed
	int canon_motion_type;  // this motion is due to which canon function?
	int blend_with_next;    // gcode requests continuous feed at the end of 
	                    // this segment (g64 mode)
	int blending;           // segment is being blended into following segment
	double blend_vel;       // velocity below which we should start blending
	double tolerance;       // during the blend at the end of this move, 
	                    // stay within this distance from the path.
	int synchronized;       // spindle sync required for this move
	double vel_at_blend_start;
	unsigned char enables;  // Feed scale, etc, enable bits for this move
	double filter[TC_FILTER_SIZE];	
	double currentFilterVel;	
	double currentFilterPos;	
	int filterWait;	
	int execFilterNum;	
	double tmpSaveCurrentPos;
 	PmRotationVector Vector;
	PmRotationMatrix   robot_R0;
	PmRotationMatrix robot_RT;
	int cord_type;
       PmCartesian   robot_tcp;
       PmRotationMatrix   robot_tcf;
       PmRotationMatrix   robot_invtcf;
	PmHomogeneous  goalFrame;	
	int is_extaxis;
	UserCoordianteInformation usr;
	ToolCoordianteInformation tool;
	int tcFlag;
} TC_STRUCT;

/* TC_STRUCT functions */
extern int tcInit(TC_STRUCT *tc);
extern PmJoint tcGetJPos(TC_STRUCT * tc);
extern RobotPose tcGetPos(TC_STRUCT * tc);
PmCartesian tcGetEndingUnitVector(TC_STRUCT *tc);
PmCartesian tcGetStartingUnitVector(TC_STRUCT *tc);

/* queue of TC_STRUCT elements*/

typedef struct {
    TC_STRUCT *queue;		/* ptr to the tcs */
    int size;			/* size of queue */
    int _len;			/* number of tcs now in queue */
    int start, end;		/* indices to next to get, next to put */
    int allFull;		/* flag meaning it's actually full */
} TC_QUEUE_STRUCT;

/* TC_QUEUE_STRUCT functions */

/* create queue of _size */
extern int tcqCreate(TC_QUEUE_STRUCT * tcq, int _size,
		     TC_STRUCT * tcSpace);

/* free up queue */
/*! \todo FIXME - currently not be called by other function*/// 2010.05.18
//extern int tcqDelete(TC_QUEUE_STRUCT * tcq);  

/* reset queue to empty */
extern int tcqInit(TC_QUEUE_STRUCT * tcq);

/* put tc on end */
extern int tcqPut(TC_QUEUE_STRUCT * tcq, TC_STRUCT tc);

/* remove n tcs from front */
extern int tcqRemove(TC_QUEUE_STRUCT * tcq, int n);

/* how many tcs on queue */
extern int tcqLen(TC_QUEUE_STRUCT * tcq);

/* look at nth item, first is 0 */
extern TC_STRUCT *tcqItem(TC_QUEUE_STRUCT * tcq, int n, long period);

/* get full status */
extern int tcqFull(TC_QUEUE_STRUCT * tcq);

#endif				/* TC_H */
