/*
 * @定义一些公共函数
 */
#ifndef __COMMON__H__
#define __COMMON__H__

#include "hi_type.h"
#include "stdbool.h"


//uint64_t NTPtime64(void);

struct SPoint{
	HI_U32 iX;
	HI_U32 iY;
};

struct SPointArray{
	struct SPoint *pPoint;
	HI_U32        iArraySize;
};

struct SPointPool{
	struct SPoint *pBegin;
	struct SPoint *pEnd;
	struct SPoint *pInsert;
	HI_U32        iPoolSize;
};

void pointpool_init(struct SPointPool *pPointPool_F);

bool pointpool_insert(struct SPointPool *pPointPool_F, 
		struct SPoint *pPoint_F);

bool pointpool_copy(struct SPointPool *pSrc_F, struct SPointPool *pDst_F);

bool pointpool_free(struct SPointPool *pPointPool_F);

struct SPoint* pointpool_begin(struct SPointPool *pPointPool_F);
HI_U32  pointpool_length(struct SPointPool *pPointPool_F);

#define POINTPOOL_FOREACH(F, p) for(p=F->pBegin; p != F->pInsert; ++p)


#endif