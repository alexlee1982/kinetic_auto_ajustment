#ifndef MOTION_FEEDBACK_H
#define MOTION_FEEDBACK_H
#include "Common.h"
#include "motionInterfaceBuffer.h"



typedef struct
{

u32 motionState; 				//�˶�����ִ��״̬: 
							//COMMAND_DONE ��ɣ�COMMAND_EXEC ������ִ�У�COMMAND_ERROR :ִ�г���
u16 commandStatus;   //��
f64 distance_was_gone;		//����ָ���Ѿ�����ľ���
f64 distance_to_go;   			//����ָ�û����ľ���
u16 onSoftLimit;				//��ǰ��������λ��	          
u16 queueFull;				//�˶������Ƿ�Ϊ��
JointPoint jointCmd;			//�ؽ�����ֵ
JointPoint jointFeedback;		//�ؽڷ���ֵ
PointPose positionCmd;
PointPose usrCmd;
s64 servoEncoderValue[6];
s64 servoEncoderDestination[6];
u32 enable[6];

u32 linkError;					//�������Ӵ���

u64 errCode;

int lineNumber;				//��ǰ�к�

UserCoordianteInformation user;		//��ǰʹ�õ��û�����ϵ����Ϣ
ToolCoordianteInformation tool;		//��ǰʹ�õĹ�������ϵ����Ϣ
u16 socketConnectError;
}MotionFeedback;



#endif
