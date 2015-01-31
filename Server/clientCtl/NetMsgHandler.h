#ifndef _NETMSGHANDLER_H_
#define _NETMSGHANDLER_H_

#include "CommonDefine.h"

typedef void( *NetMsgHandlerf )(NetMsgHead* head );

typedef struct 
{
	
    uint16 nType;// Э��
    NetMsgHandlerf pFun;	// ������
	//bool     need_auth; // �Ƿ���Ҫ��֤��¼

}   NetMsgHandler;

typedef	map< uint16 , NetMsgHandler > NetMsgHandlerMap;
typedef map< uint16 , NetMsgHandler >::iterator NetMsgHandlerMapIter;


bool			CheckMsg(const NetMsgHead* msg , uint16 size );

#define			CHECKMSG( classType ) const classType* msg = (classType*)head; if ( !CheckMsg( msg , sizeof( classType ) ) ){ FLOG4("CheckMsg Error! %d",msg->nType); return ;}

//return GAME_ERROR_NETMSG_SIZE;
void			OnNetMsgEnter( NetSocket& socket );
void			OnNetMsgExit( NetSocket& socket );
void           OnNetMsg( NetMsgHead* head );

void			OnError( int32 error , int32 ServiceID , NetSocket* socket , const char* buffer );

void			InitNetMsg();

#endif

