


/*
 * @1、消息队列部分
 */
#define SEM_PATH "sem_dfsipc"
#define SHM_PATH "/tmp/shm_dfsipc"
#define MSG_PATH "/tmp/msg_dfsipc"

#define SHM_SIZE (64*1024)
#define MSG_SIZE (1024)

typedef enum{
	eCMTIRUSBConfig = 1,           //机芯配置改变(不可从零开始)
	eCMTIRUSBSnuc,                 //机芯单点校正
	eCMTYuntaiSerial,              //云台串口配置改变
	eCMTYuntaiConfig,              //云台配置改变
	eCMTYuntaiPTZ                  //云台运动、预置点、辅助功能
}EConfigMsgType;

typedef struct{
	long mtype;
	char mtext[MSG_SIZE];
}SConfigMsg;


/*
 * @云台与cgi消息队列部分begin
 */

/*
 * @SMovement
 *
 * @绝对值解释：
 *	fPanMoveVelocity、fTiltMoveVelocity、fZoomMoveVelocity都是云台高速的百分比，
 *(0~100)当这三个值的绝对值大于100时，表示使用turbo速度(web暂不实现)
 *
 * @符号解释
 * @1、连续运动时
 *	iPanMoveVelocity在(0 100]范围内，向右运动；在[-100 0)范围内，向左运动, 0表示不动
 *	iTiltMoveVelocity在(0 100]范围内，向上运动；在[-100 0)范围内，向下运动, 0表示不动
 *	iZoomMoveVelocity在(0 100]范围内，放大；在[-100 0)范围内，缩小, 0表示不动
 * @2、相对运动时
 *	待添加
 * @3、绝对运动时
 *	待添加
 */
typedef struct {
	int iPanMoveVelocity;
	int iTiltMoveVelocity;
	int iZoomMoveVelocity;
	//float fARDstPosition;
}SMovement;

typedef struct {
	uint iPresetId;
}SPreset;

typedef struct {
	uint iAuxiliaryId;
}SAuxiliary;

typedef struct{
	uint iTourIndex;
	uint iTourPresetIndex;
}STourRun;

typedef enum{
	eCMDAbsoluteMove,  //暂不支持
	eCMDContinueMove,
	eCMDRelativeMove,  //暂不支持
	eCMDStop,
	eCMDGetPrest,      //暂不支持
	eCMDSetPreset,
	eCMDGotoPreset,
	eCMDClearPreset,
	eCMDBeginAuxiliary,
	eCMDEndAuxiliary,
	eCMDTourRun,        //要停止tour只需把iWhichTourRun设置为-1，无需发送消息
}ECMDType;


typedef struct {
	ECMDType eCMDType;
	union {
		SMovement   Movement;
		SPreset     Preset;
		SAuxiliary  Auxiliary;
		STourRun    TourRun;
	}CMDPara;
}SPTZ;

/*
 * @云台与cgi消息队列部分end
 */

/*
 * @2、共享内存部分
 */
/*
 * @机芯配置与cgi共享部分begin
 */
typedef struct {
	HI_U16    iLumConsist;
	HI_U16    iImgContrast;
	HI_U16    iImagBrightness;
	HI_U16    iDdeCoe;
	HI_DOUBLE fVideoZoomCoe;
	HI_U16    iFilterSigma;
	HI_U16    iVideoPolarHot;
	HI_U16    iVideoColor;
	HI_U16    iShutterMode;
	HI_U16    iShutterStatus;
	HI_U16    iShutterTime;
	HI_U16    iShutterDeltaTemp;
}SIRUSB_Config;
/*
 * @机芯配置与cgi共享部分end
 */

/*
 * @云台配置与cgi共享部分begin
 */
typedef enum{
	eYuntaiPTLPelcoD
}EYuntaiPTLType;

/*
 * @SRS485Config 与 SYuntaiConfig 在共享内存
 */
typedef struct {
	uint              iSerialBaud;       //2400 4800 9600 19200 38400 57600 115200 230400 460800 576000 921600
	unsigned char     iSerialDataBits;   //8
	unsigned char     cSerialParity;     //'O' 'E' 'N'
	unsigned char     iSerialStopBits;   //1 2
	unsigned char     iAddr;
	EYuntaiPTLType    eProtocolType;
}SRS485Config;

typedef struct{
	bool bPresetBeSeted;
}SPresetInfo;

typedef struct{
	uint iPresetId;
	uint iTimeInterval; //s
}STourPresetConfig;

typedef struct {
	SPresetInfo          PresetInfo[256];    //此字段cgi只读但不写
	STourPresetConfig    Tour[4][32];
	int                  iWhichTourRun;  //-1不run
}SYuntaiConfig;

/*
 * @云台配置与cgi共享部分end
 */



typedef struct {
	SIRUSB_Config         IRUSBConfig;
	SRS485Config          RS485Config
	SYuntaiConfig         YuntaiConfig;
}SDFSCameraConfig;