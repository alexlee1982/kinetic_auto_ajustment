#ifndef MOTIONPARAMETERMODIFY_H
#define MOTIONPARAMETERMODIFY_H
/*���û����˱۳�����
	value��Ϊ�۳�������
	number Ϊ��е�ۺţ�ȡֵ��ΧΪ0-5��
*/
extern int SET_PUMA_A(double value,int number);
/*����ʾ��ֱ�ߵ����˶�������ٶ�
	value ��Ϊ�ٶ�֮����λΪmm/s
*/
extern int SET_TEACH_LINEAR_MOVE_MAX_VELOCITY(double value);
/*
	����ֱ�߲岹ָ��movl��movc������ٶ�
	value ��Ϊ�ٶ�֮����λΪmm/s	
*/
extern int SET_PLAY_LINEAR_MOVE_MAX_VELOCITY(double value);
/*
	����Ĭ��ֱ�߼���ʱ��
	time�м���ʱ��ֵ����λΪs
*/
extern int SET_LINEAR_MOVE_ACC_TIME(double time);
/*
	����Ĭ����ת�˶�����ʱ�䡣
	time��Ϊ����ʱ��ֵ����λΪs��
*/
extern int SET_ROTATE_MOVE_ACC_TIME(double time);

/*
	����ֱ������������г�
	value��Ϊ�г�ֵ����λΪmm������Ϊ��ֵ��
	axis��Ϊ��ţ�ȡֵ��ΧΪ��AXIS_X/AXIS_Y/AXIS_Z
*/
extern int SET_LINEAR_POSITIVE_LIMIT(double value,int axis);

/*
	����ֱ���Ḻ������г�
	value��Ϊ�г�ֵ����λΪmm,����Ϊ��ֵ��
	axis��Ϊ��ţ�ȡֵ��ΧΪ��AXIS_X/AXIS_Y/AXIS_Z
*/
extern int SET_LINEAR_NEGATIVE_LIMIT(double value,int axis);
/*
	���ùؽ�����������
	value �йؽڵĽǶ�ֵ����1-180�ĽǶ�ֵ��
	axis��Ϊ��ţ�ȡֵ��ΧΪ0-5
*/
extern int SET_JOINT_POSITIVE_LIMIT(double value,int axis);
/*
	���ùؽ��Ḻ������
	value��Ϊ�ؽڵĽǶ�֮����-180-0�ĽǶ�ֵ��
	axis��Ϊ��ţ�ȡֵ��ΧΪ0-5��

*/
extern int SET_JOINT_NEGATIVE_LIMIT(double value,int axis);
/*
	���ùؽ��������ٶ�
	value��Ϊ�ػ����ٶȣ���λ�Ƕ�/s��?
	axisΪ��ţ�ȡֵ��ΧΪ0-5��
*/
extern int SET_JOINTMOVE_MAX_VELOCITY(double value, int axis);
/*
	���ùؽ���ļ��ٱȡ�
	value��Ϊ���ٱȵ�ֵ��������ֵ��
	axisΪ��ţ�ȡֵ��ΧΪ0-5��
*/
extern int SET_MECHANICAL_TRANSMISSION_RATIO(double value,int axis);

/*
	���õ��������ÿת����������
	value��Ϊ�����ֵ������������ֵ��
	axisΪ��ţ�ȡֵ��ΧΪ0-5��
*/
extern int SET_SERVO_PULSE_PER_ROUND(unsigned int value,int axis);

/*
	���õ�������ķ������ԡ�
	polarity����д+1��-1 �����SERVO_POSITIVE��SERVO_NEGATIVE
	axis Ϊ���ȡֵ0-5��

extern SET_SERVO_ENCODER_POLARITY(int polarity,int axis);*/

/*
	���õ�������ת�١�
	velocity��д�����ת�١�����������λr/min.
	axis��д�����0-5��
*/
extern int SET_SERVO_MAX_VELOCITY(double velocity,int axis);

/*
	���õ�����������������ƫ������
	offset��д���������ƫ�������Ǹ�������
	axis��д�����0-5��
*/
extern int SET_ENCODER_ORIGIN_OFFSET(unsigned int offset, int axis);






#endif
