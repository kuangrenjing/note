#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>   //IO IOfd

#include "config_ipc.h"

// bool configipc_master_init(sem_t **pSem, char **pShm, int *piMsg)
// {
// 	key_t    shm_key;
// 	int      shmid;
// 	key_t    msg_key;
// 	//bool     bRet;

// 	/*
// 	 * @开启信号量
// 	 */
// 	*pSem = sem_open(SEM_PATH, O_CREAT, 777, 1);
// 	if(*pSem == SEM_FAILED)
// 	{
// 		printf("sem_open failed:%s\n", strerror(errno));
// 		return false;
// 	}

// 	while(sem_trywait(*pSem) < 0)
// 	{
// 		sem_post(*pSem);
// 	}
// 	sem_post(*pSem);

// 	/*
// 	 * @开启共享内存
// 	 */
// 	shm_key = ftok(SHM_PATH, 400);
// 	if((shmid = shmget(shm_key, SHM_SIZE, 777)) < 0)
// 	{
// 		printf("shmget failed:%s\n", strerror(errno));
// 		return false;
// 	}
// 	if((*pShm = shmat(shmid, 0, 0)) == (void*)-1)
// 	{
// 		printf("shmat failed:%s\n", strerror(errno));
// 		return false;
// 	}

// 	/*
// 	 * @开启消息队列
// 	 */
// 	msg_key = ftok(MSG_PATH, 500);
// 	*piMsg = msgget(msg_key, IPC_CREAT);
// 	if(*piMsg < 0)
// 	{
// 		printf("msgget failed:%s\n", strerror(errno));
// 		return false;
// 	}
// 	return true;
// }

// bool configipc_semslaver_init(sem_t **pSem)
// {
// 	*pSem = sem_open(SEM_PATH, 0);
// 	if(*pSem == SEM_FAILED)
// 	{
// 		write(STDERR_FILENO, "sem_open failed\n", strlen("sem_open failed\n"));
// 		return false;
// 	}
// 	return true;
// }

// bool configipc_shmslaver_init(char **pShm)
// {
// 	key_t shm_key;
// 	int   shmid;

// 	shm_key = ftok(SHM_PATH, 400);
// 	if((shmid = shmget(shm_key, 1024, 777)) < 0)
// 	{
// 		write(STDERR_FILENO, "shmgt failed\n", strlen("shmgt failed\n"));
// 		return false;
// 	}
// 	if((*pShm = shmat(shmid, 0, 0)) == (void*)-1)
// 	{
// 		write(STDERR_FILENO, "shmat failed\n", strlen("shmat failed\n"));
// 		return false;
// 	}
// 	return true;
// }

// bool configipc_msgslaver_init(int *piMsg)
// {
// 	key_t msg_key;

// 	msg_key = ftok(MSG_PATH, 500);
// 	*piMsg = msgget(msg_key, 0);
// 	if(*piMsg < 0)
// 	{
// 		write(STDERR_FILENO, "msgget failed\n", strlen("msgget failed\n"));
// 		return false;
// 	}
// 	return true;
// }

// bool configipc_sendmsg(SConfigMsg *pConfigMsg_F)
// {
// 	int  iMsgTmp;
// 	bool bRet;

// 	/*
// 	 * @获取到配置模块的消息队列
// 	 */
// 	bRet = configipc_msgslaver_init(&iMsgTmp);
// 	if(!bRet)
// 		return false;

// 	/*
// 	 * @向配置模块的消息队列发送消息
// 	 */
// 	if(msgsnd(iMsgTmp, pConfigMsg_F, MSG_SIZE, 0) != 0)
// 		return false;

// 	return true;
// }

// void configipc_semlock(sem_t *pSem)
// {
// 	sem_wait(pSem);
// }
// void configipc_semunlock(sem_t *pSem)
// {
// 	sem_post(pSem);
// }




/*
 * @POSIX信号量、共享内存、消息队列主端初始化
 */
bool configipc_semmaster_init(char *pSemPath_F, sem_t **pSem_F)
{
	*pSem_F = sem_open(pSemPath_F, O_CREAT | O_EXCL, 777, 1);
	if(*pSem_F == SEM_FAILED)
	{
		printf("sem_open failed:%s\n", strerror(errno));
		return false;
	}

	return true;
}

bool configipc_shmmaster_init(char *pShmPath_F, char **pShm_F, uint iShmSize_F)
{
	key_t shm_key;
	int   shmid;

	shm_key = ftok(pShmPath_F, 400);
	if((shmid = shmget(shm_key, iShmSize_F, IPC_CREAT | IPC_EXCL)) < 0)
	{
		printf("shmget failed:%s\n", strerror(errno));
		return false;
	}
	if((*pShm_F = shmat(shmid, 0, 0)) == (void*)-1)
	{
		printf("shmat failed:%s\n", strerror(errno));
		return false;
	}
	return true;
}

bool configipc_msgmaster_init(char *pMsgPath_F, int *piMsg_F)
{
	key_t msg_key;
	int   iRet;

	msg_key = ftok(pMsgPath_F, 500);

	*piMsg_F = msgget(msg_key, IPC_CREAT | IPC_EXCL);
	if(*piMsg_F < 0)
	{
		printf("msgget failed:%s\n", strerror(errno));
		return false;
	}
	return true;
}

bool configipc_semmaster_free(char *pSemPath_F)
{
	sem_unlink(pSemPath_F);
}

bool configipc_shmmaster_free(char *pShmPath_F)
{
	key_t shm_key;
	int   shmid;
	int   iRet;

	shm_key = ftok(pShmPath_F, 400);
	if((shmid = shmget(shm_key, 0, 0)) < 0)
	{
		printf("[configipc_shmmaster_free]shm not exist!\n");
		return true;
	}
	else
	{
		iRet = shmctl(shmid, IPC_RMID, NULL);
		if(iRet < 0)
		{
			printf("[configipc_shmmaster_free]shmctl failed!\n");
			return false;
		}
	}
	return true;
}

bool configipc_msgmaster_free(char *pMsgPath_F)
{
	key_t msg_key;
	int   iRet;
	int   iMsg;

	msg_key = ftok(pMsgPath_F, 500);

	iMsg = msgget(msg_key, 0);
	if(iMsg < 0)
	{
		printf("[configipc_msgmaster_free]msglist not exist!\n");
		return true;
	}
	else
	{
		iRet = msgctl(iMsg, IPC_RMID, NULL);
		if(iRet < 0)
		{
			printf("[configipc_msgmaster_free]msgctl failed!\n");
			return false;
		}
	}
	return true;
}

/*
 * @POSIX信号量、共享内存、消息队列从端初始化
 */
bool configipc_semslaver_init(char *pSemPath_F, sem_t **pSem_F)
{
	*pSem_F = sem_open(pSemPath_F, 0);
	if(*pSem_F == SEM_FAILED)
	{
		printf("sem_open failed\n");
		return false;
	}
	return true;
}

bool configipc_shmslaver_init(char *pShmPath_F, char **pShm_F)
{
	key_t shm_key;
	int   shmid;

	shm_key = ftok(pShmPath_F, 400);
	if((shmid = shmget(shm_key, 0, 0)) < 0)
	{
		printf("shmgt failed\n");
		return false;
	}
	if((*pShm_F = shmat(shmid, 0, 0)) == (void*)-1)
	{
		printf("shmat failed\n");
		return false;
	}
	return true;
}

bool configipc_msgslaver_init(char *pMsgPath_F, int *piMsg_F)
{
	key_t msg_key;

	msg_key = ftok(pMsgPath_F, 500);
	*piMsg_F = msgget(msg_key, 0);
	if(*piMsg_F < 0)
	{
		write(STDERR_FILENO, "msgget failed\n", strlen("msgget failed\n"));
		return false;
	}
	return true;
}

//bool configipc_msgslaver_sendmsg();
//bool configipc_msgmaster_recvmsg();


void configipc_semlock(sem_t *pSem_F)
{
	sem_wait(pSem_F);
}


void configipc_semunlock(sem_t *pSem_F)
{
	sem_post(pSem_F);
}

bool configipc_msgmaster_recvmsg(SConfigMsgWrap *pMsg_F)
{
	ssize_t iRet = msgrcv(pMsg_F->iMsg, &(pMsg_F->ConfigMsg), pMsg_F->iMsgMax, 0, 0);

	if(iRet < 0)
		return false;
	else
		pMsg_F->iMsgLen = iRet;
}

void configipc_msgslaver_sendmsg(void *pMsg_F)
{
	SConfigMsgWrap *pMsgT = (SConfigMsgWrap*)pMsg_F;
	msgsnd(pMsgT->iMsg, &(pMsgT->ConfigMsg), pMsgT->iMsgLen, 0);
}
