#ifndef INC_RTOS_H
#define	INC_RTOS_H

#include "Common.h"


#ifdef WIN32
#include <windows.h>
#include <iostream>
// ����ز���
typedef CRITICAL_SECTION t_lock;
#define	INIT_LOCK(lock)		InitializeCriticalSection(&(lock))
#define	LOCK(lock)			EnterCriticalSection(&(lock))
#define	UNLOCK(lock)		LeaveCriticalSection(&(lock))
#else
#include <pthread.h>
typedef pthread_mutex_t t_lock;
#define	INIT_LOCK(lock)		pthread_mutex_init(&(lock),NULL)
#define	LOCK(lock)			pthread_mutex_lock(&(lock))
#define	UNLOCK(lock)		pthread_mutex_unlock(&(lock))
#endif

#ifdef __cplusplus
extern "C"{
#endif

// ��ʼ����ֻ��Ҫ����һ��
void RTOS_Init();
// ��ȡϵͳʱ�䣬��λ������
u64 RTOS_GetTimeNs();
// ��usΪ��λ����
void RTOS_SleepUs(u32 us);
// ��nsΪ��λ����
void RTOS_SleepNs(u64 ns);





#ifdef __cplusplus
}
#endif



#endif

