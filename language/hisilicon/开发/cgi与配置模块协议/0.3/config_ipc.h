#ifndef __CONFIG_IPC__H__
#define __CONFIG_IPC__H__

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <semaphore.h>

#include <stdbool.h>


/*
 * @各模块与配置模块通信的IPC设计
 */

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 *	@Linux中，POSIX信号量的名字是基于文件系统的，且默认相对于/dev/shm/sem目录，
 *如果在sem_open函数中使用绝对路径，则会形成特别的路径格式。譬如sem_open中使用
 *"/tmp/sem1"路径，则实际的完整路径会是"/dev/shm/sem.tmp/sem1"。我们应在sem_open
 *函数中使用相对路径。
 */

/*
 * @配置模块作为主时使用的IPC路径
 */
#define CONFIGMASTER_SEM_PATH "sem_dfsipc"
#define CONFIGMASTER_SHM_PATH "/tmp/shm_dfsipc"
#define CONFIGMASTER_MSG_PATH "/tmp/msg_dfsipc"

#define CONFIGMASTER_SHM_SIZE (64*1024)
#define CONFIGMASTER_MSG_SIZE (2048)
#define CGI_MSG_SIZE (512)

/*
 * @CGI程序作为主使用的消息队列路径需在放在发给配置模块的消息中，
 *譬如SOSDMsg结构体的strCgiMasterMsgPath字段
 */


/*
 * @消息队列与cgi共享部分begin
 */
typedef enum{
	eCMTIRUSBConfig = 1,           //机芯配置改变(不可从零开始)
	eCMTIRUSBSnuc,                 //机芯单点校正
	eCMTRS485Config,              //云台串口配置改变
	eCMTYuntaiConfig,              //云台配置改变
	eCMTYuntaiPTZ,                 //云台运动、预置点、辅助功能
	eCMTVIConfig,
	eCMTVPSSConfig,
	eCMTVENCConfig,
	eCMTOSDConfig
}EConfigMsgType;

typedef enum{
	eCMTShapeNumErr,
	eCMTShapeTypeErr
}EConfigMsgErrType;

typedef struct{
	EConfigMsgErrType eMsgErrType;
}SToCGIAnswer;

typedef struct{
	long mtype;
	char mtext[CONFIGMASTER_MSG_SIZE];
}SConfigMsg;

typedef struct{
	int            iMsg;
	SConfigMsg     ConfigMsg;
	uint           iMsgMax;        //CONFIGMASTER_MSG_SIZE 或者 CGI_MSG_SIZE
	uint           iMsgLen;
}SConfigMsgWrap;

/*
 * @消息队列与cgi共享部分end
 */


/*
 * @POSIX信号量、共享内存、消息队列主端初始化
 *
 * @我们这里使用的三种IPC都“随内核持续”。
 */
bool configipc_semmaster_init(char *pSemPath_F, sem_t **pSem_F);
bool configipc_shmmaster_init(char *pShmPath_F, char **pShm_F, uint iShmSize);
bool configipc_msgmaster_init(char *pMsgPath_F, int  *piMsg_F);

/*
 * @主端可以先free再init
 * 
 * @cgi端不适合先free再init，而是应在退出时free
 */
bool configipc_semmaster_free(char *pSemPath_F);
bool configipc_shmmaster_free(char *pShmPath_F);
bool configipc_msgmaster_free(char *pMsgPath_F);

/*
 * @POSIX信号量、共享内存、消息队列从端初始化
 */
bool configipc_semslaver_init(char *pSemPath_F, sem_t **pSem_F);
bool configipc_shmslaver_init(char *pShmPath_F, char **pShm_F);
bool configipc_msgslaver_init(char *pMsgPath_F, int *piMsg_F);

void configipc_msgslaver_sendmsg(void *pMsg_F);
bool configipc_msgmaster_recvmsg(SConfigMsgWrap *pMsg_F);

void configipc_semlock(sem_t *pSem_F);
void configipc_semunlock(sem_t *pSem_F);

#endif