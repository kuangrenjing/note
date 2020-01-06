#ifndef __DFS_MSG__H__
#define __DFS_MSG__H__

#include "dfs_config.h"

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
 *@OSD与cgi消息队列部分begin
 */

/*
 * @OSD命令定义
 *	1、当前只支持以OSD为单位进行操作，支持“添加”、“移除”、“修改”OSD
 *	2、修改OSD时只关注修改后的结果，即SOSDMsg中的SShape数组为修改后的结果
 */
typedef enum{
	eOSDCMDUndefined = 0,
	eOSDCMDAddOSD,
	eOSDCMDRemoveOSD,
	eOSDCMDChangeOSD
}EOSDCMDType;

#define CGI_MSG_PATH_MAX 64

#pragma pack(push) // 保持对齐方式
#pragma pack(1) // 设定1字节对齐
typedef struct {
	EOSDCMDType  eOSDCMDType;
	HI_U32       iOSDId;                                 //有效值：1~16
	HI_U32       iShapeNum;                              //有效值：0~16
	HI_CHAR      strCgiMasterMsgPath[CGI_MSG_PATH_MAX];  //PATH_MAX太长(4096)，消息队列放不了，规定为64
	HI_U8        iDummy                                  //SShape数组的第一个字节
}SOSDMsg;
#pragma pack(pop) // 恢复对齐方式


/*
 *@OSD与cgi消息队列部分end
 */


#endif