#ifndef __CONFIG__H__
#define __CONFIG__H__

#include "define.h"

#ifdef DFS_HI3516A_MASTER


#include "hi_mipi.h"
#include "hi_comm_video.h"
#include "hi_comm_vb.h"
#include "hi_comm_sys.h"
#include "hi_comm_isp.h"
#include "hi_comm_vi.h"
#include "hi_comm_vpss.h"
#include "hi_comm_venc.h"
#include "hi_comm_region.h"
#include "hi_sns_ctrl.h"

#include "mpi_vb.h"
#include "mpi_sys.h"
#include "mpi_isp.h"
#include "mpi_ae.h"
#include "mpi_awb.h"
#include "mpi_af.h"
#include "mpi_vi.h"
#include "mpi_vpss.h"
#include "mpi_venc.h"
#include "mpi_region.h"

#endif

#include "hi_type.h"
#include "common.h"
#include "cJSON.h"
//#include "yuntai.h"


/*
 * @通过usb设置机芯的功能有：
 *	1亮度一致性lumconsist      (0~15)            S98 G99
 *	2对比度imgcontrast         (0~15)            S70 G100
 *	3亮度imgbrightness         (0~15)            S71 G101
 *	4放大倍数videozoomcoe      (0.0~4.0)         S60 G90
 *	5细节增强ddecoe            (0~15)            S72 G102
 *	6滤波系数filtersigma       (0~15)            S73 G103
 *	7极性videopolarhot         (0、1)            S64 G94
 *	8伪彩videocolor            (0、1、2、3)      S62 G92
 *	9挡板模式shutterauto       (auto 0 manual 1) S23
 *	10挡板状态shutter           (open 0 close 1)  S20
 *	11单点校正snuc                                S66
 *	12校正周期shuttertime                         S112 G97
 *	13校正温漂shutterdeltatemp                    S113 G111
 *
 * 系列函数返回值：
 *	set: 负值：错误代号  0：成功
 *	get: 负值：错误代号  正值：get到的长度
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
 * @云台配置与cgi共享内存部分begin
 */
typedef enum{
	eYuntaiPTLPelcoD
}EYuntaiPTLType;

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

#define MAXPRESET     256
#define MAXTOUR       4
#define MAXTOURPRESET 32

typedef struct {
	SPresetInfo          PresetInfo[MAXPRESET];
	STourPresetConfig    Tour[MAXTOUR][MAXTOURPRESET];
	int                  iWhichTourRun;  //-1不run
}SYuntaiConfig;

/*
 * @云台配置与cgi共享内存部分end
 */
#ifdef DFS_HI3516A_MASTER
bool rs485config_json2struct(cJSON *pItem_F, SRS485Config *pConfig_F);
void rs485config_struct2json(cJSON *pItem_F, SRS485Config *pConfig_F);
void rs485config_print(SRS485Config *pConfig_F);

bool yuntaiconfig_json2struct(cJSON *pItem_F, SYuntaiConfig *pConfig_F);
void yuntaiconfig_struct2json(cJSON *pItem_F, SYuntaiConfig *pConfig_F);
void yuntaiconfig_print(SYuntaiConfig *pConfig_F);
#endif

#ifndef DFS_HI3516A_MASTER
typedef enum hiVI_INTF_MODE_E
{
	VI_MODE_BT656 = 0,              /* ITU-R BT.656 YUV4:2:2 */
	VI_MODE_BT601,                  /* ITU-R BT.601 YUV4:2:2 */
	VI_MODE_DIGITAL_CAMERA,         /* digatal camera mode */
	VI_MODE_BT1120_STANDARD,        /* BT.1120 progressive mode */
	VI_MODE_BT1120_INTERLEAVED,     /* BT.1120 interstage mode */
	VI_MODE_MIPI,                   /*MIPI mode*/
	VI_MODE_LVDS,
	VI_MODE_HISPI, 
	VI_MODE_BUTT
}VI_INTF_MODE_E;

typedef struct hiRECT_S
{
	HI_S32 s32X;
	HI_S32 s32Y;
	HI_U32 u32Width;
	HI_U32 u32Height;
}RECT_S;

typedef enum hiPIXEL_FORMAT_E
{
	PIXEL_FORMAT_RGB_1BPP = 0,
	PIXEL_FORMAT_RGB_2BPP,
	PIXEL_FORMAT_RGB_4BPP,
	PIXEL_FORMAT_RGB_8BPP,
	PIXEL_FORMAT_RGB_444,

	PIXEL_FORMAT_RGB_4444,
	PIXEL_FORMAT_RGB_555,
	PIXEL_FORMAT_RGB_565,
	PIXEL_FORMAT_RGB_1555,

	/*  9 reserved */
	PIXEL_FORMAT_RGB_888,
	PIXEL_FORMAT_RGB_8888,

	PIXEL_FORMAT_RGB_PLANAR_888,
	PIXEL_FORMAT_RGB_BAYER_8BPP,
	PIXEL_FORMAT_RGB_BAYER_10BPP,
	PIXEL_FORMAT_RGB_BAYER_12BPP,
	PIXEL_FORMAT_RGB_BAYER_14BPP,

	PIXEL_FORMAT_RGB_BAYER,         /* 16 bpp */

	PIXEL_FORMAT_YUV_A422,
	PIXEL_FORMAT_YUV_A444,

	PIXEL_FORMAT_YUV_PLANAR_422,
	PIXEL_FORMAT_YUV_PLANAR_420,

	PIXEL_FORMAT_YUV_PLANAR_444,

	PIXEL_FORMAT_YUV_SEMIPLANAR_422,
	PIXEL_FORMAT_YUV_SEMIPLANAR_420,
	PIXEL_FORMAT_YUV_SEMIPLANAR_444,

	PIXEL_FORMAT_UYVY_PACKAGE_422,
	PIXEL_FORMAT_YUYV_PACKAGE_422,
	PIXEL_FORMAT_VYUY_PACKAGE_422,
	PIXEL_FORMAT_YCbCr_PLANAR,

	PIXEL_FORMAT_SINGLE,

	PIXEL_FORMAT_BUTT
} PIXEL_FORMAT_E;
#endif

/*
 * @当前的两种输入：
 *	1、BT656红外机芯
 *		VI_MODE_BT656  720*576*25
 *	2、LVDS IMX178可见光
 *		VI_MODE_LVDS   1920*1080*60
 *
 * @VI还有以下概念
 *	输入数据时序（BT656需要）
 *	输入数据格式（RGB还是YUV）
 *这些信息我们在处理中不关心，既无需更改又无需查询，所以不出现在这里。
 *这些不出现在配置结构体里的字段，使用VI_MODE_BT656和VI_MODE_LVDS进行区分
 *
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 *@VI特性：
 *	VI设备可做
 *		裁剪
 *			HI_MPI_VI_SetDevAttr
 *	Hi3516A VI物理通道可做
 *		帧率控制
 *			HI_MPI_VI_SetChnAttr(原始帧率、目的帧率要么同时为-1，要么同时不为-1)
 *		裁剪
 *			HI_MPI_VI_SetChnAttr
 *		缩放
 *			HI_MPI_VI_SetChnAttr
 *		CSC(色度空间转换 color space convert)
 *		镜头校正
 *		镜像
 *			HI_MPI_VI_SetChnAttr(Hi3516A不支持)
 *		翻转
 *			HI_MPI_VI_SetChnAttr(Hi3516A不支持)
 *		旋转(非翻转)
 *		CoverEx
 *		OverlayEx
 *	Hi3516A VI扩展通道可做帧率控制、裁剪、缩放、CoverEx、OverlayEx
 *
 *@VI物理通道属性
 *	RECT_S          stCapRect;          裁剪 仅对物理通道有效，宽与高为静态属性，起点可动态修改？
 *	SIZE_S          stDestSize;         VI不支持缩放，这个字段是为了单双场，双场时与stCapRect的宽高相同，单场时为stCapRect宽高的一半，静态属性
 *	VI_CAPSEL_E     enCapSel;           动态属性，但stDestSize是静态属性，所以只能动态选择底场或顶场？
 *	PIXEL_FORMAT_E  enPixFormat;        Hi3516A支持SP420、SP422
 *	COMPRESS_MODE_E enCompressMode;     支持非压缩与 256byte 段式压缩
 *	HI_BOOL         bMirror;            Hi3516A不支持
 *	HI_BOOL         bFlip;              Hi3516A不支持
 *	HI_S32          s32SrcFrameRate;    s32SrcFrameRate、s32DstFrameRate同时为-1或同时不为-1
 *	HI_S32          s32DstFrameRate;
 *
 *@像素格式枚举类型值：
 *	PIXEL_FORMAT_YUV_SEMIPLANAR_422    22
 *	PIXEL_FORMAT_YUV_SEMIPLANAR_420    23
 *	PIXEL_FORMAT_YUV_SEMIPLANAR_444    24
 *	PIXEL_FORMAT_UYVY_PACKAGE_422      25
 *	PIXEL_FORMAT_YUYV_PACKAGE_422      26
 *	PIXEL_FORMAT_VYUY_PACKAGE_422      27
 */
typedef struct {
	HI_U32           iInputWidth;
	HI_U32           iInputHeight;
	HI_U32           iInputFrameRate;
	VI_INTF_MODE_E   eInterfaceMode;
	RECT_S           DevCrop;           //VI设备裁剪，宽度、高度需是2的倍数
	HI_U32           iPhyChnFrameRate;  //VI物理通道帧率控制
	RECT_S           PhyChnCrop;        //VI物理通道裁剪，宽度需是8的倍数，高度需是4的倍数
	PIXEL_FORMAT_E   ePixelFormat;      //VI物理通道输出像素格式，不支持格式转换
}SVIConfig;

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 * @VPSS简介
 *	VPSS由GROUP、物理通道、扩展通道组成
 *
 *	对海思硬件资源而言，GROUP是一个虚拟概念，它分时复用VPSS硬件。
 *
 *	VPSS物理通道有两种工作模式：AUTO和USER(16 18V200 19V100只支持USER)，默认为AUTO，
 *可使用HI_MPI_VPSS_SetChnMode函数改成USER模式，在USER模式下，VPSS通道可与多个接收
 *者绑定。
 *
 *	VPSS支持通道低时延，低时延开启时，很多VPSS功能将失效。
 *
 *	文档说VPSS支持CoverEx/OverlayEx，实际从API来看只支持Cover/Overlay。
 *
 *	VPSS Grp主要用于
 *		去噪，
 *			HI_MPI_VPSS_CreateGrp    开启降噪
 *			HI_MPI_VPSS_SetGrpAttr
 *			HI_MPI_VPSS_SetGrpParam  设置各降噪系数强度
 *	还用于
 *		帧率控制(仅离线支持；GROUP必须已创建；帧率控制位于所有功能前，影响后续所有处理)
 *			HI_MPI_VPSS_SetGrpFrameRate
 *		裁剪
 *			HI_MPI_VPSS_SetGrpCrop
 *			支持相对坐标和绝对坐标
 *
 *
 *	VPSS通道用于
 *		帧率控制(在线、离线)
 *			HI_MPI_VPSS_SetChnAttr
 *		遮挡
 *			HI_MPI_VPSS_SetChnCover
 *			HI_MPI_VPSS_SetChnOverlay
 *		垂直翻转(flip)
 *			HI_MPI_VPSS_SetChnAttr
 *		旋转
 *			HI_MPI_VPSS_SetRotate
 *		镜像
 *			HI_MPI_VPSS_SetChnAttr
 *		裁剪
 *			HI_MPI_VPSS_SetChnCrop
 *			支持相对坐标和绝对坐标
 *		缩放
 *			HI_MPI_VPSS_SetChnMode
 *		去噪
 *			HI_MPI_VPSS_SetChnNR
 *			这项功能主要用于控制Hi3516A VPSS第4物理通道输出未经降噪还是经过降噪的图像
 *
 *	Mirror Flip Rotate三者什么区别？
 *
 * @VPSS Group属性
 *	HI_U32          u32MaxW;    最大宽度(在线：宽度，离线：最大宽度)，静态参数，只能创建Grp时指定
 *	HI_U32          u32MaxH;    最大宽度(在线：宽度，离线：最大宽度)，静态参数，只能创建Grp时指定
 *	PIXEL_FORMAT_E  enPixFmt;   输入图像像素格式。仅支持SP422、SP420和YUV400，静态属性，只能创建Grp时指定
 *	HI_BOOL         bIeEn;      纹理增强(在NR里边也有IE功能)                 保留HI_FALSE
 *	HI_BOOL         bDciEn;     自动对比度增强(Dynamic Contrast Improvement) 保留HI_FALSE
 *	HI_BOOL         bNrEn;      去噪使能开关
 *	HI_BOOL         bHistEn;    直方图保留                                   保留HI_FALSE
 *	VPSS_DIE_MODE_E enDieMode;  去隔行(De-interlace)                         保留VPSS_DIE_MODE_NODIE
 *
 * @VPSS物理通道属性
 *	HI_BOOL  bSpEn;            sp功能使能，Hi3516A不支持SP功能(SP是啥功能？) 只能为 HI_FALSE
 *	HI_BOOL  bBorderEn;        只能为 HI_FALSE
 *	HI_BOOL  bMirror;          Mirror 使能开关
 *	HI_BOOL  bFlip;            Flip 使能开关
 *	HI_S32   s32SrcFrameRate;  源帧率。 取值范围：(0, 240]，以及-1。
 *	HI_S32   s32DstFrameRate;  目标帧率。 取值范围：[-1, 240]。
 *	BORDER_S stBorder;         边框属性。因为不支持边框，所以无所谓配置与否
 *
 * @VPSS限制：
 *	Hi3516A支持128个Group，4个物理通道，8个扩展通道。
 *	0(第一)通道：图像宽度：[64, 2592]，图像高度：[64, 2592]，不支持缩放，不支持裁剪，不支持格式转换
 *	1(第二)通道：图像宽度：[64, 1280]，图像高度：[64, 2592]，支持缩放，输出小于1280支持SP422/SP420转换
 *	2(第三)通道：图像宽度：[64, 720]， 图像高度：[64, 2592]，支持缩放，输出小于720时支持SP422/SP420转换
 *	3(第四)通道：图像宽度：[64, 1920]，图像高度：[64, 2592]，支持缩放
 *
 *	Hi3516A VPSS图像尺寸（文档规定，未定义宏）
 *		VPSS_MIN_IMAGE_WIDTH     64
 *		VPSS_MIN_IMAGE_HEIGHT    64
 *		VPSS_MAX_IMAGE_WIDTH     2592
 *		VPSS_MAX_IMAGE_HEIGHT    2592
 *		VPSS_MAX_ZOOMIN          1      (物理通道最大放大倍数)
 *		VPSS_MAX_ZOOMOUT         15     (物理通道最大缩小倍数)
 *		VPSS_EXT_CHN_MAX_ZOOMIN  16     (扩展通道最大放大倍数)
 *		VPSS_EXT_CHN_MAX_ZOOMOUT 15     (扩展通道最大缩小倍数)
 */
typedef struct {
	HI_U32           iInputWidth;          //用于判断 未使用
	HI_U32           iInputHeight;         //用于判断 未使用
	HI_U32           iInputFrameRate;      //用于判断
	PIXEL_FORMAT_E   eInputPixelFormat;    //必须与eOutputPixelFormat相同
	RECT_S           GroupCrop;            //宽、高必须是2的倍数
	HI_U32           iGroupFrameRate;
	HI_U32           iChnFrameRate;
	/*
	 * @如果后接VENC编码H264/H265则必须为23
	 * @chn0不支持格式转换
	 * @chn1输出小于1280支持SP422/SP420转换
	 * @chn2输出小于720时支持SP422/SP420转换
	 */
	PIXEL_FORMAT_E   eOutputPixelFormat;
}SVPSSConfig;

/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 *@VENC简介
 *	H264/H265仅支持SP420像素格式图像输入；JPEG/MJPEG支持SP422、SP420两种像素格式
 *输入。
 *
 *	通道的帧率控制默认不打开，需要用户调用接口设置。RC中也具有帧率控制功能。推荐
 *使用RC的帧率控制，这样不会对码率控制造成过大的冲击。
 *
 *	Hi3516A各种编码情况下，宽度、高度、对齐限制：
 *             H264              JPEG       H265
 * 最大宽度    2592              8192       2592
 * 最小宽度    160               32         128
 * 最大高度    2592              8192       2592
 * 最小高度    64                32         128
 * 对齐        2(L*H = 32的倍数) 4          2
 *
 *
 * @编码质量 GOV不能调整
 */
typedef struct {
	/*
	 * @调用VGS进行缩放(只能缩小)，所以，如果输入图像尺寸比这个尺寸小，则VENC无输出。
	 */
	HI_U32         iInputWidth;
	HI_U32         iInputHeight;
	HI_U32         iInputFrameRate;
	/*
	 * @H264/H265编码只支持SP420格式
	 */
	PIXEL_FORMAT_E eInputPixelFormat;
}SVENCConfig;

#ifdef DFS_HI3516A_MASTER
bool viconfig_json2struct(cJSON *pItem_F, SVIConfig *pConfig_F);
void viconfig_struct2json(cJSON *pItem_F, SVIConfig *pConfig_F);
void viconfig_print(SVIConfig *pConfig_F);

bool vpssconfig_json2struct(cJSON *pItem_F, SVPSSConfig *pConfig_F);
void vpssconfig_struct2json(cJSON *pItem_F, SVPSSConfig *pConfig_F);
void vpssconfig_print(SVPSSConfig *pConfig_F);

bool vencconfig_json2struct(cJSON *pItem_F, SVENCConfig *pConfig_F);
void vencconfig_struct2json(cJSON *pItem_F, SVENCConfig *pConfig_F);
void vencconfig_print(SVENCConfig *pConfig_F);
#endif


/*
 *@OSD配置
 *
 *1、最多可以添加16个区域，每个区域最多可以有8个形状（线、圆、矩形、凸多边形），
 *总共最多可以有128个形状，如果是线或凸多边形，则每个形状最多有16个点。
 *
 *2、上位机应以OSD为单位向我发送配置信息。接受到之后，在SOSDSConfig找到一个osd空
 *位插入。
 *
 *3、基于第2点，Shape在SOSDConfig中是连续存储的，且不关心序号。
 */
#define MAXOSD           16
#define MAXOSDSHAPE      8
#define MAXOSDSHAPEPOINT 16

typedef enum {
	eShapeTypeUndefined = 0,
	eShapeTypeLine,
	eShapeTypeCircle,
	eShapeTypeRect,
	eShapeTypeCPolygon
}EShapeType;

typedef RECT_S SRect;

typedef struct{
	struct SPoint sOrigin;
	HI_U32        iRadius;
}SCircle;

typedef struct{
	struct SPoint sPoint[MAXOSDSHAPEPOINT];
	HI_U32 iPointNum;
}SLine, SCPolygon;

typedef struct{
	EShapeType    eShapeType;
	union{
		SLine     sLine;
		SCircle   sCircle;
		SRect     sRect;
		SCPolygon sCPolygon;
	}unShape;
}SShape;

typedef struct{
	SShape  sShape[MAXOSDSHAPE];
	HI_U32  iShapeNum;                  //有效值1~16（为0时什么也不做，也不返回错误）
	HI_S32  iOSDId;                     //有效Id = 1~16
}SOSDConfig;

typedef struct{
	SOSDConfig sOSDConfig[MAXOSD];
	HI_U32     iOSDNum;
}SOSDSConfig;

/*
 * @对内配置函数
 */
//void osdconfig_reinit(SOSDConfig *pConfig_F);
//void osdconfig_insert_shapeconfig();
/*
 * @对外配置函数
 */
#ifdef DFS_HI3516A_MASTER
void osdsconfig_reinit(SOSDSConfig *pConfig_F);
HI_BOOL osdsconfig_json2struct(cJSON *pItem_F, SOSDSConfig *pConfig_F);
void osdsconfig_struct2json(cJSON *pItem_F, SOSDSConfig *pConfig_F);
void osdsconfig_print(SOSDSConfig *pConfig_F);
void osdsconfig_insert_osdconfig();
#endif

typedef struct {
	char   pstrIPV4[16];
	HI_U16 uRTSPPort;
	HI_U16 uHTTPPort;
}SNetworkConfig;


typedef struct {
	SIRUSB_Config         IRUSBConfig;        //32
	SRS485Config          RS485Config;        //12
	SYuntaiConfig         YuntaiConfig;       //1284
	SVIConfig             VIConfig;           //56
	SVPSSConfig           VPSSConfig;         //44
	SVENCConfig           VENCConfig;         //16
	SOSDSConfig           OSDSConfig;         //16896 + 68
	SNetworkConfig        NetworkConfig;      //20
}SDFSCameraConfig;                            //

#ifdef DFS_HI3516A_MASTER
int config_init(void);
void config_load(void);
HI_VOID* config_thread_fun(HI_VOID *p);
void config_write(void);
#endif

/*
 * @配置生效策略
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
 *	配置模块保有一份私有配置并通过共享内存与其它模块共享一个共有配置。当其它模
 *块修改了共有配置并通过消息队列通知配置模块后，配置模块比较私有配置和共有配置，
 *然后决定哪些部分生效，如何生效。
 */


extern SDFSCameraConfig g_DFSCameraConfig;
#endif