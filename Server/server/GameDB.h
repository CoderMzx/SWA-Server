#ifndef _GAMEDB_H_
#define _GAMEDB_H_

#include "DbDataBase.h"

/*
 *
 *	Detail: �󲿷����ݣ�ֱ����mysql�򽻵���player������ݣ�ֻ�ǻ��棬����ÿ�δ�mysql�ж�ȡ����player��ֻ�ǻ��治̫��Ҫ������
 *  �Ͽ�����Ҳ�ᱣ�沿����Ҫ������
 *   
 *  Created by hzd 2014-10-7
 *
 */


const int32 MAX_SQL_BUFFER = 512;
extern char SQL_BUFFER[ MAX_SQL_BUFFER ];

#pragma pack(push,1)

struct DBAccountLogin
{
	uint32 nID;
	char  arrUsername[32];
};


#pragma pack(pop)


#endif

