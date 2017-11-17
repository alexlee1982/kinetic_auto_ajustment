#ifndef USR_MOTION_API_H
#define USR_MOTION_API_H
#include "motionCommandType.h"
#include "motionInterfaceBuffer.h"

#include "motionParameterType.h"
#include "motionConfig.h"
#include "motionFeedback.h"
#include "posemath.h"



#ifdef __cplusplus
extern "C" {
#endif

extern MotionConfig *emcmotConfig ;
extern MotionCommandBuffer *commandShmem ;
extern VRobotMotionCommand  *motCmd ;
extern MotionCommandQueue *interpList ;
extern VRobotMotionCommand *emcmotCommand;
extern MotionFeedback *motionFb;

extern int CTRL_ServoReset(void);			//�ŷ���λ�������ŷ��屨��
extern int CTRL_ServoEnable(int enable);	//�ŷ�ʹ�ܣ�enbale Ϊ0����ʹ�� Ϊ1����ʹ��


extern int CTRL_USR_Init(void);
extern void CTRL_USR_Exit(void);



extern int CTRL_AddSingleAxisMove(SingleAxisMove *singleMove); //�����˶�
extern int CTRL_AddJointMove(JointMoveInformation *jointMove,u32 lineNumber,u32 fileNumber);		//�ؽڲ岹movj
extern int CTRL_AddLinearMove(LinearMoveInformation *movl,u32 lineNumber,u32 fileNumber);			//ֱ�߲岹���յ�λ���ùؽڱ�ʾ
extern int CTRL_AddCircularMove(CircularMoveInformation *movC,u32 lineNumber,u32 fileNumber);
extern void CTRL_MovementStop();										//�˶�ֹͣ�����Һ���δִ�е�����Ҳ����ִ��
extern int CTRL_AddDescartesLinearMove(LinearDescartesMoveInformation *movDL,u32 lineNumber,u32 fileNumber);//ֱ�߲岹���յ�λ����x/y/z��ʾ��
extern int CTRL_AddDescartesCircularMove(CircularDescartesMoveInformation *movDC,u32 lineNumber,u32 fileNumber);//Բ���岹��Ŀ��λ��ʹ�õѿ���λ��ֵ
extern void CTRL_GetJointValue(JointPoint * joint);
extern double CTRL_GetJointValueFor3DTest(int jointNumber);
extern double CTRL_GetPositionValue(int axis);


extern int CTRL_GetTCPInUserSpace(PointPose *pos,JointPoint *joint,UserCoordianteInformation* user,ToolCoordianteInformation* tool);//����ؽ�λ�ã����㹤�߼�˵����û�����ϵ�µ�λ�ˡ�
 extern int CTRL_GetTCPInUserSpaceInMatrix(PmHomogeneous *pos,JointPoint *joint,UserCoordianteInformation* user,ToolCoordianteInformation* tool); // ����ڲ�ʹ��

extern int CTRL_GetTCPInJoint(JointPoint *joint,PointPose *point,UserCoordianteInformation* user,ToolCoordianteInformation* tool);//��֪����λ�ˣ�����ؽ�λ�ý���ŵ�joint�С�����ֵΪ0ʱ��ʾ�����Ч��
extern int CTRL_GetTCPInJointInMatrix(JointPoint *joint,JointPoint *preJoint,PmHomogeneous *point,UserCoordianteInformation* user,ToolCoordianteInformation* tool);

extern int CTRL_GetMotionStatus(MotionFeedback * fb); 
//extern	 void CTRL_SetSocket(char * IP, int port, int cycleTime);
//jp , �û������������Ĺؽ�ֵ��Ϣ��out ��������û�����ϵx/y/z/a/bc��ֵ��
extern int CTRL_UserCalibration(ThreeJointPoints *jp, ToolCoordianteInformation *tool,UserCoordianteInformation *out);
//�����ŷ������ԭ��ƫ��ֵ������offset ��ʾ����ı�������������ֵ��axis��ʾ���:1-6��
extern int CTRL_SetOriginOffset(s64 offset,u32 axis);
//��ȡԭ��ƫ��ֵ��axisΪ���(1-6)��offset����ƫ��ֵ��
extern int CTRL_GetOriginOffset(s64 * offset,u32 axis);
//���û��������˲���, length : ���˲������ȣ�num: ���˲�������
extern int CTRL_SetPUMA(f64 length,u32 num);

//��û��������˲���, length : ���˲������ȣ�num: ���˲�������
extern int CTRL_GetPUMA(f64 *length,u32 num);

//����ʾ��ʱ�����ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_SetTeachLinearVelocity(f64 velocity);

//���ʾ��ʱ�����ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_GetTeachLinearVelocity(f64 *velocity);
//����ֱ���˶�(MOVL) ������ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_SetLinearMaxVelocity(f64 velocity);
//���ֱ���˶�(MOVL) ������ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_GetLinearMaxVelocity(f64 *velocity);
//����ֱ���˶�(MOVL) �ļ��ٶȣ�acc: ���õļ��ٶ�ֵ
extern int CTRL_SetLinearMoveAcc(f64 acc);
//���ֱ���˶�(MOVL) �ļ��ٶȣ�acc: ���õļ��ٶ�ֵ
extern int CTRL_GetLinearMoveAcc(f64 *acc);
//������ת�˶����ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_SetRotateMoveVelocity(f64 velocity);
//�����ת�˶����ٶȣ�velocity: ���õ��ٶ�ֵ
extern int CTRL_GetRotateMoveVelocity(f64 *velocity);
//������ת�˶��ļ��ٶȣ�acc:���õļ��ٶ�ֵ��
extern int CTRL_SetRotateMoveAcc(f64 acc);
//�����ת�˶��ļ��ٶȣ�acc:���õļ��ٶ�ֵ��
extern int CTRL_GetRotateMoveAcc(f64 *acc);
//���������˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:X/Y/Z/A/B/C
extern int CTRL_SetLinearPositiveLimit(f64 limit,u32 axis);
//��ȡ�����˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:X/Y/Z/A/B/C
extern int CTRL_GetLinearPositiveLimit(f64 *limit,u32 axis);
//���������˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:X/Y/Z/A/B/C
extern int CTRL_SetLinearNegativeLimit(f64 limit,u32 axis);
//��ȡ�����˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:X/Y/Z/A/B/C
extern int CTRL_GetLinearNegativeLimit(f64 *limit,u32 axis);
//���ùؽ��˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_SetJointPositiveLimit(f64 limit,u32 axis);
//��ȡ�ؽ��˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_GetJointPositiveLimit(f64 *limit,u32 axis);
//���ùؽ��˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_SetJointNegativeLimit(f64 limit,u32 axis);
//��ȡ�ؽ��˶������ޣ�limit:������ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_GetJointNegativeLimit(f64 *limit,u32 axis);
//���ùؽ��˶�����ٶȣ�velocity:�ٶ�ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_SetJointMaxVelocity(f64 velocity,u32 axis);
//���ùؽ��˶�����ٶȣ�velocity:�ٶ�ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_GetJointMaxVelocity(f64 *velocity,u32 axis);

//���ùؽ��˶������ٶȣ�acc:���ٶ�ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_SetJointMaxAcc(f64 acc,u32 axis);
//��ȡ�ؽ��˶������ٶȣ�acc:���ٶ�ֵ��axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_GetJointMaxAcc(f64 *acc,u32 axis);
//���ø��ؽڵļ��ٱȣ�demoninator:���ٱȷ�ĸ��numerator:���ٱȷ��ӣ�axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_SetReductionRate(s64 demoninator, s64 numerator, u32 axis);
//��ȡ���ؽڵļ��ٱȣ�rate:���ٱ�axis:�ؽں�1-6  ���δ���:J1-J6
extern int CTRL_GetReductionRate(s64 *demoninator, s64 *numerator,u32 axis);

//����5/6�ؽڵ���ϱ�
extern int CTRL_SetCoupleRate(s64 rate);

//��ȡ5/6�ؽڵ���ϱ�
extern int CTRL_GetCoupleRate(s64 *rate);
 






#ifdef __cplusplus
}
#endif	
	

#endif

