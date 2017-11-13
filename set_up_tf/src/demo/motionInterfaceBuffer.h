#ifndef MOTIONINTERFACEBUFFER_H
#define MOTIONINTERFACEBUFFER_H

#define MOTION_COMMAD_QUEUE_SIZE 2000
#define MAX_FILE_NAME_NUMBER 255

#define COMMAND_DONE		1 
#define COMMAND_EXEC		2
#define COMMAND_ERROR		3

#define COORDINATE_TYPE_JOINT 	1
#define COORDINATE_TYPE_LINEAR 	2
#define COORDINATE_TYPE_USER		3
#define COORDINATE_TYPE_TOOL		4


#define MOVE_DIR_POSITIVE 		1
#define MOVE_DIR_NEGATIVE 		-1
#include "Common.h"
//�ؽ�λ�õ�

//__pragma(pack(push, 4))
#pragma pack(push, 1)

typedef struct
{
	double j1;
	double j2;
	double j3;
	double j4;
	double j5;
	double j6;
}JointPoint;

typedef struct
{
	JointPoint org;
	JointPoint ox;
	JointPoint oy;
}ThreeJointPoints;


//�ѿ�������ϵ�µĵ�λ��Ϣ
typedef struct
{
double x;
double y;
double z;
}DescartesPoint;
//�ѿ���λ���µ���̬��Ϣ(rpy��)
typedef struct
{
double a;			//��x����ת�ĽǶ�(��λΪ��)
double b;			//��y����ת�ĽǶ�(��λΪ��)
double c;			//��z����ת�ĽǶ�(��λΪ��)
}Pose;
//�ѿ�������ϵ�µ�λ����Ϣ
typedef struct
{
double x;
double y;
double z;
double a;
double b;
double c;
}PointPose;


/*�û�����ϵ��Ϣ
x/y/z��ʾ�û�����ϵԭ��Ի���������ϵԭ���ƫ��
a/b/c��ʾ������������ϵ��z����תc�ȣ�
����y����תb�ȣ�����x����תa�ȿ��Եõ��û�����ϵ��
*/
typedef struct
{
	double x,y,z,a,b,c;
}UserCoordianteInformation;


//��ת������Ϣ��x,y,z�ֱ��ʾ����̬X/Y/Z����ԭ����ϵ�µ�������
typedef struct
{
DescartesPoint x,y,z;
}RotationMatrix;

//�ŷ�ʹ�ܲ�����0Ϊ��ʹ�ܣ�1Ϊ��ʹ�ܡ�
typedef struct
{
int enable;
}ServoEnable;


//�û�����ϵ��Ҫ��������������
typedef struct
{	
	JointPoint originPoint;	//ԭ��λ����Ϣ��
	JointPoint AxisXPoint;	// X����һ��λ����Ϣ��
	JointPoint PlaneXYPoint;	//XYƽ����һ��λ����Ϣ��
}CalUserCoordianteInformation;

//��������ϵ��Ҫ��������������
typedef struct
{
	double x,y,z,rx,ry,rz;	//��������ϵ��ƫ������

}ToolCoordianteInformation;

//������Ϣ�ṹ�壬��ʱֻ֧�ֹؽ���ֱ�ǡ�
typedef struct
{
	u32 coordinateType;	//����ϵ����ʹ�ú�: 
								//COORDIANTE_TYPE_JOINT,COORDINATE_TYPE_LINEAR,
								//COORDINATE_TYPE_TOOL
	//������������ϵ�Ĳ���ʵ���û�����ϵ�빤������ϵ
	
		union{
			
		UserCoordianteInformation user;
		ToolCoordianteInformation tool;
		}CoordinateInformation;

															
}CoordinatInformation;



//�����˶��ṹ�����·�������ʱ��
//��VRobotMotionCommand�õ�typeָ��ΪSINGLE_AXIS_MOVE_TYPE
//�����������е�singleMove��ֵ��
typedef struct
{
	int axis;		//���:1-6	//��д�ɺꡣ
	 int direction;	//�˶�����:����: MOVE_DIR_POSITIVE ����MOVE_DIR_NEGATIVE 
	 double vel;			//�����˶��ٶȰٷֱȣ�0.0-100.0
	double endPoint;	// �յ�λ�ã���ʱûʵ�ָù��ܡ�
	CoordinatInformation coordinate;	//����ϵ��Ϣ��
}SingleAxisMove;
//�ؽ��˶���Ϣ������ֻ����λ�õ����ٶ�������������������������Ϣ��
typedef struct
{
	JointPoint endPoint;		//�յ�λ����Ϣ��
	double vJ;				//�ٶ���Ϣ��ȡֵ��Χ���ݾ�����Ƹı䡣
	double acc;				//���ٶ�
	double dec;				//���ٶ�
	int id;					//������룬��������ָ�����ݱ�ʶ��

}JointMoveInformation;

//�ѿ���ֱ���˶���Ϣ������ֻ����λ�õ����ٶ�������������������������Ϣ��
typedef struct
{
	DescartesPoint endPoint;		//�յ�λ����Ϣ��
	//RotationMatrix rot;				//�յ���̬��Ϣ
	Pose zyx;					//�յ���̬ZYXŷ����
	//PmEulerZyx zyx;				//�յ���̬ZYXŷ����
	int free;						//Ϊ0ʱѡ��rot��Ϊ�յ���̬��Ϊ1ʱʹ�������̬
	double vL;				//�ٶ���Ϣ��ȡֵ��Χ���ݾ�����Ƹı䡣��λmm/s?
	double vR;				//��̬�ٶȣ���λΪ��/��
	double acc;				//���ٶ�
	double dec;				//���ٶ�
	int id;					//������룬��������ָ�����ݱ�ʶ��
	UserCoordianteInformation user;			//�û�����ϵ��Ϣ
	ToolCoordianteInformation tool;			//��������ϵ��Ϣ
}LinearDescartesMoveInformation;





//ֱ���˶���Ϣ������ֻ����λ�õ����ٶ�������������������������Ϣ��
typedef struct
{
	JointPoint endPoint;		//�յ�λ����Ϣ��
	double vL;				//�ٶ���Ϣ��ȡֵ��Χ���ݾ�����Ƹı䡣��λmm/s?
	double vR;				//��̬�ٶȣ���λΪ��/��
	double acc;				//���ٶ�
	double dec;				//���ٶ�
	int id;					//������룬��������ָ�����ݱ�ʶ��
}LinearMoveInformation;
//Բ���˶���Ϣ������ֻ����λ�õ����ٶ�������������������������Ϣ��
typedef struct
{
	JointPoint endPoint[3];		//Բ���岹��3����λ��Ϣ��
	double vL;				//�ٶ���Ϣ��
	double vR;
	double acc;				//���ٶ�
	double dec;				//���ٶ�
	int id ;					//������롣
}CircularMoveInformation;

typedef struct
{
	DescartesPoint endPoint[3];		//�յ�λ����Ϣ��0-2���ζ�ӦԲ�����/�м��/�յ�
	//RotationMatrix rot[3];			//�յ���̬��Ϣ��0-2���ζ�Ӧ���/�м��/�յ���̬
								//��ʱrot[1]���м����̬���Բ��û����
	Pose zyx[3];					//ZYX ŷ���Ǳ�ʾ����̬��a-X ,b-y,c-z
	int free;						//�Ƿ�ѡ����һ���˶��ε��յ���̬��ΪԲ�����е���̬��
								//0Ϊʹ��rot�е���Ϣ��freeΪʹ��ǰһ�����̬
	double vL;				//�ٶ���Ϣ��ȡֵ��Χ���ݾ�����Ƹı䡣��λmm/s?
	double vR;
	double acc;				//���ٶ�
	double dec;				//���ٶ�
	int id;					//������룬��������ָ�����ݱ�ʶ��
	UserCoordianteInformation user;			//�û�����ϵ��Ϣ
	ToolCoordianteInformation tool;			//��������ϵ��Ϣ
}CircularDescartesMoveInformation;

//�˶��������
typedef union
{
	ServoEnable svEable;
	SingleAxisMove singleMove;			//�����˶���ʼ��VRobotMotionCommand�õ�type
									//�����˶�ֹͣ��ֻ��Ҫһ��typeû�в�����
									//�·�һ������ֹͣ���������ᶼֹͣ����ܷ��ա�			
	JointMoveInformation movJ;				//�ؽڲ岹�˶�movj
	LinearMoveInformation movL;				//ֱ�߲岹�˶�movl
	CircularMoveInformation movC;				//Բ���岹�˶�movc
	LinearDescartesMoveInformation movDL;		//�ѿ�����������ֱ�߲岹
	CircularDescartesMoveInformation movDC;		//�ѿ�����������Բ���岹
}MotionCommandParameter;


//�˶�����ṹ�壬�������˶�ģ�����ִ�еĸ�������
typedef struct
{
	u32 head; //д������ʱ��head+1��
					//д��ʱ��head��tailдΪ��ͬ��ֵ��
					//��head ��tail Ϊ��ͬ��ֵʱ���˶�ģ�鲻���ȡ���е�ֵ��
	int type;		//�������ͣ���:������motionCommandType.h�ļ���

	int serialNumber;	//����ţ�ÿ���·���ָ��Ӧ������һ��ָ���+1��
	u32 currentLineNumber; //��ָ���Ӧ�������кš�
	u32 currentFileNumber; //��ָ�����ڵ��ļ���
	MotionCommandParameter motionCmdParameter;	//�˶�ָ�����
	u32 tail;

}VRobotMotionCommand;



//������У����ζ��С�
typedef struct
{
	int start,end; // ���е�����β��λ�á�
	int motionState;	//�˶�ģ���ִ��״̬��
					//��Ϊ�˶�ִ��������:DONE ����ִ��:EXECUTE �����г���ERROR
	u32 currentLineNumber;	//��ǰ����ָ����к�
	u32 currentFileName[MAX_FILE_NAME_NUMBER]; //��ǰִ��ָ����ļ���
	VRobotMotionCommand motionCmd[MOTION_COMMAD_QUEUE_SIZE]; //�˶���������
}MotionCommandQueue;
//�˶�����棬���а��������������������
typedef struct
{
	MotionCommandQueue motionCmdQ;	//��������
	VRobotMotionCommand motionCmd;	//�˶���������

}MotionCommandBuffer;
typedef VRobotMotionCommand * Command_PTR;
#pragma pack(pop)
//__pragma(pack(pop))
#endif
