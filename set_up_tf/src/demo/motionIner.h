#ifndef MOTION_INER_H
#define MOTION_INER_H
#include "tp.h"


#define DOUT_NUM    6
#define DEFAULT_TC_QUEUE_SIZE  2000
#ifndef MAX_JOINTS
#define MAX_JOINTS 9
#endif
#define MAX_FILENAME_LENGTH       255
#define EMCMOT_ERROR_NUM 32	/* how many errors we can queue */
#define EMCMOT_ERROR_LEN 256	/* how long error string can be */
#define EMCMOT_ALARM_SIZE 32

#define CALCULATECYCLETIME 500000000	//nsec

 typedef unsigned long EMCMOT_MOTION_FLAG;
 
//IOtype
#define   NONE	 0
//#define   IN	        1
//#define   OUT	        2
/* bit masks */
#define EMCMOT_MOTION_ENABLE_BIT      0x00000001      //ʹ��
#define EMCMOT_MOTION_INPOS_BIT       0x00000002       //��λ
#define EMCMOT_MOTION_PLAY_BIT       0x00000004           //������ʽ
#define EMCMOT_MOTION_ERROR_BIT       0x00000008         //����
#define EMCMOT_MOTION_EMERG_BIT      0x00000010          //��ͣ
#define EMCMOT_MOTION_PAUSE_BIT      0x00000020          //��ͣ
#define EMCMOT_MOTION_SVALM_BIT     0x00000040
#define EMCMOT_MOTION_DIE_BIT           0x00000080

typedef unsigned long EMCMOT_MOTION_ERROR_FLAG;


typedef unsigned long EMCMOT_AXIS_ERROR_FLAG;


//add by swtang 20130121
typedef unsigned long EMCMOT_JOINT_FLAG;
 
#define EMCMOT_JOINT_ENABLE_BIT         0x00000001
#define EMCMOT_JOINT_INPOS_BIT          0x00000004
#define EMCMOT_JOINT_ERROR_BIT          0x00000008
#define EMCMOT_JOINT_FERROR_BIT         0x00001000
#define EMCMOT_JOINT_FAULT_BIT          0x00002000
#define EMCMOT_JOINT_HOMED_BIT          0x00000002


//add by swtang 20130121
typedef unsigned long EMCMOT_JOINT_ERROR_FLAG;

/* macros definition -- */
#define EMCMOT_JOINT_ERROR_FAULT_BIT                                 0x00000001
#define EMCMOT_JOINT_ERROR_MAX_SOFT_LIMIT_BIT             0x00000010
#define EMCMOT_JOINT_ERROR_MIN_SOFT_LIMIT_BIT             0x00000020
#define EMCMOT_JOINT_ERROR_MAX_HARD_LIMIT_BIT            0x00000004
#define EMCMOT_JOINT_ERROR_MIN_HARD_LIMIT_BIT            0x00000008
#define EMCMOT_JOINT_ERROR_OUTCHN_FAULT_BIT             0x00000010
#define EMCMOT_JOINT_ERROR_OUTCHN_SAME_BIT              0x00000020
#define EMCMOT_JOINT_ERROR_ENCCHN_FAULT_BIT             0x00000040
#define EMCMOT_JOINT_ERROR_ENCCHN_SAME_BIT              0x00000080
#define EMCMOT_JOINT_ENC_FAULT_BIT       0x00000100
#define EMCMOT_JOINT_SV_ALARM_BIT        0x00000200
/* motion controller states */

    typedef enum {
	EMCMOT_MOTION_DISABLED = 0,
	EMCMOT_MOTION_TEACH,
	EMCMOT_MOTION_PLAY
    } motion_state_t;

    typedef struct {
//add by swtang 20130121
EMCMOT_JOINT_ERROR_FLAG errorFlag;      /* �ؽڴ����־ */   
EMCMOT_JOINT_FLAG flag;	                           /* �ؽ�״̬��־ */
double pos_cmd;		                     /* �ؽ�����λ�� */
double jog_vel;         // ��jog �ٶ�
double pos_fb;		                     /* �ؽڷ���λ��*/
double ferror;		                            /*ʵ���涯��� */	
double ferror_high_mark;	             /* ����涯���*/
double max_ferror;	                   /* ����涯������� */
double min_ferror;	                      /* �����涯���*/
double max_pos_limit;	                  /* �ؽ�����λ�ü���*/
double min_pos_limit;  	                 /* �ؽڸ���λ�ü��� */
} robot_joint_status_t;

  typedef struct {
//add by swtang 20130121
EMCMOT_AXIS_ERROR_FLAG errorFlag;      /* �ؽڴ����־ */   
double pos_cmd;		                     /* �ؽ�����λ�� */
double jog_vel;         // ��jog �ٶ�
double pos_fb;		                     /* �ؽڷ���λ��*/
double ferror;		                            /*ʵ���涯��� */	
double ferror_high_mark;	             /* ����涯���*/
double max_ferror;	                   /* ����涯������� */
double min_ferror;	                      /* �����涯���*/
double max_pos_limit;	                  /* �ؽ�����λ�ü���*/
double min_pos_limit;  	                 /* �ؽڸ���λ�ü��� */
} robot_axis_status_t;
//add by swtang 20130121

typedef enum {
	EMCMOT_COMMAND_OK = 0,	/* cmd honored */
	EMCMOT_COMMAND_UNKNOWN_COMMAND,	/* cmd not understood */
	EMCMOT_COMMAND_INVALID_COMMAND,	/* cmd can't be handled now */
	EMCMOT_COMMAND_INVALID_PARAMS,	/* bad cmd params */
	EMCMOT_COMMAND_BAD_EXEC	/* error trying to initiate */
    } cmd_status_t;

typedef enum {
	JOINT_COOR = 0,         //�ؽ�����ϵ
	CAR_COOR,                    //ֱ������ϵ
	CYL_COOR,                    //Բ������ϵ
	USER_COOR ,                  //�û�����ϵ
	TOOL_COOR,                   //��������ϵ
	EXTA_CTL                   //
    } robot_coordinate_t;



    typedef struct {
	unsigned char head;	/* flag count for mutex detect */
	int split;		/* number of split command reads */
	TP_STRUCT queue;	/* coordinated mode planner */
	TP_STRUCT qtmp;	/* coordinated mode planner */
	TC_STRUCT queueTcSpace[DEFAULT_TC_QUEUE_SIZE + 10];
       int enabling;		/* starts up disabled */
	int teaching;	/* starts up in free mode */
       int playing;
	int linkSimTest;
        int allHomed;
        int svon_count;
	double net_feed_scale[MAX_JOINTS];                           //ʾ���޵�
	double rawOutput[MAX_JOINTS];
	int inputRot[MAX_JOINTS];
	int inputInit[MAX_JOINTS];
	int inputInitCount[MAX_JOINTS]; 
	unsigned char doutBuffer[DOUT_NUM];
	int    addrtype;
	int     ioaddr ;
	int     iostate; 
	int adjust;
	PmCartesian Xvector,Yvector,Zvector,ORG;
       PmCartesian   robot_tcp;
       PmRotationMatrix   robot_tcf;
       PmRotationMatrix   robot_invtcf;

	PmRotationMatrix   robot_R0;
	PmCartesian   robot_P0;
	PmRotationMatrix   robot_RT;
	PmCartesian   robot_PT;
	PmCartesian Porg;
	PmHomogeneous  goalFrame;	
	PmHomogeneous  currentFrame;	
	int has_extaxis;
	int home_free;
	int speed_level;

	unsigned char tail;	/* flag count for mutex detect */
    } MotionDebug;

typedef struct
{
	unsigned char head;	
	int commandEcho;   // ���������͵���Ӧ
	int commandNumEcho;	
	cmd_status_t commandStatus;	
	motion_state_t motion_state; 
	int IObyte;
       int rapidMode;
	int joint_type;                            //�ؽ��˶�����
	int config_num;
	unsigned int heartbeat;
	double net_feed_scale;                          
	int linkErr;                     
	double distance_was_gone;
	double distance_to_go;                       
	EMCMOT_MOTION_FLAG motionFlag;	
	EMCMOT_MOTION_ERROR_FLAG motErrorFlag;           

	int id;			      
	char  fileName[MAX_FILENAME_LENGTH];                  
	robot_coordinate_t coordinate_type;                  
	int on_soft_limit;	            
	int on_soft_limit2;	            
	int estop;                      
	int pause;                
        int playing;    	
	int enble;
	int running;
	int queueFull;	
	robot_joint_status_t  joint_status[MAX_JOINTS];      //�ؽ�״̬����
	robot_axis_status_t  axis_status[MAX_JOINTS];      //�ؽ�״̬����
	unsigned long linkAlmFlag;           
	unsigned long linkAlmReport;       
//	ALARM_MSG autoAlm[EMCMOT_ALARM_SIZE];           // �Զ�����(�ŷ�������ʽ�޸ĺ������ı���)
	//ALARM_MSG manuAlm[EMCMOT_ALARM_SIZE];          // �ֶ�����
      // Param_Modi param_modi;

	PmJoint joint_fb;                            //�ؽڷ���ֵ
	PmJoint joint_cmd;                        //�ؽ�����ֵ
	RobotPose carte_pos_cmd;	                        //ֱ����������λ��	
	RobotPose carte_pos_fb;	                           //ֱ�����귴��λ��
       double speed_scale;
//int speed_level;
       RobotPose tool_tcp;       //����������Ϣ
       
	unsigned char tail;	                              

   }MotionStatus;
 typedef struct {
        int  not_first_input;
	double max_pos_limit;	//�ؽ�������
	double min_pos_limit;	        //�ؽڸ�����
	double max_jog_limit;	       //jog����������
	double min_jog_limit;	       //jog����������
	int linkSimTest;
	double vel_limit;         // ���������ٶ�         -δʹ��
	double jog_vel;           // ��jog �ٶ�                         -δʹ��
	double acc_limit;	      // -δʹ��
	double min_ferror;	/* zero speed following error limit */
	double max_ferror;	/* max speed following error limit */
       unsigned long  errorFlag;      /* �ؽڴ����־ */   
	unsigned short  flag;	                           /* �ؽ�״̬��־ */
	double coarse_pos;	       //   -δʹ��
	double pos_cmd;		   //��ǰ��������λ��
        double old_pos_cmd;     //ǰһ��������λ��
	double cur_vel;               //���ٴ���ʱ��ǰ�ؽ��ٶ�
	double vel_cmd;		  //�ؽ������ٶ�
	double pos_fb;		   // �ؽڷ���λ��
	double ferror;		
	double ferror_limit;	/* limit depends on speed */
	double ferror_high_mark;	/* max following error */

	int motorInputOffset;
	int motorInputOffset2;
	int svNum;             // ���Ӧ���ŷ�������ͨ����
        int svtype;
        double pulse_value;
	double inv_pulse_value;
       int offsetInit;         //-δʹ��
//	PID_STRUCT pid;
       int     servoEncoderPolarity;  //����������
       int encoder_counts;              //����������
       double pitch;                          //˿�ܵ���
	int tranRatioNumer;             //�����ȷ���
	int tranRatioDenom;            //�����ȷ�ĸ
	double svMotorSafFac;        //����Jvel_limit���ȫϵ��
       double motor_max_vel;      //������ת��
       int servoOutputPolarity;      //�������
       double max_volt;                  //����ѹ
	double motorOutputScale;   //����������
	double servo_zero_offset;   // -δʹ��
       int rawMotorInput;                 //������λ��
	int oldMotorInput;                 //δʹ��
	double motorInputScale;       //����������
	double motorInverseInputScale; //��������������
//	CUBIC_STRUCT cubic;	    //δʹ��
	int on_pos_limit;	           //δʹ��
	int on_neg_limit;	           //δʹ��

	double teachJVel;     //�ؽ�ʾ���ٶ�
	double JVel;              //�ؽ������ٶ�
	double Jvel_limit;     //�ؽ�����ٶ�

	double Jteach_acc;   //�ؽ�ʾ�̼��ٶ�
	double Jplay_acc;    //�ؽ����ּ��ٶ�

	double high_speed_scale;	  //�����޵�����	
	double mid_speed_scale;	 //�����޵�����		
	double low_speed_scale;	//�����޵�����			
	double tiny_speed_scale;	//΢���޵�����			

//	home_state_t home_state;	/* state machine for homing */
	int pg_chn;
	int enc_position;
	int enc_input_chn;
	int enc_line_detect;

	double big_vel;		// - δʹ��
    } MotionJointParameter;


#endif
