#ifndef _OBJECTMANAGER_H_
#define _OBJECTMANAGER_H_

#include "Player.h"


/*
 *
 *	Detail: ��ҹ�����
 *   
 *  Created by hzd 2015/01/26  
 *
 */
class SWA::NetServer;

class PlayerMgr : public BaseSingle< PlayerMgr >
{

	typedef map< uint64 , Player* >	UIDPlayerMap;  // 
	typedef map< uint64 , Player* >::iterator	UIDPlayerMapIter;

public:

	PlayerMgr();
	~PlayerMgr();

	/*
	 *
	 *	Detail: ��ʼ�����еȴ����ӵ�Player
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	void Init(SWA::NetServer& rNetServer);	

	/*
	 *
	 *	Detail: �ͷ�Player
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	void Release();

	/*
	 *
	 *	Detail: ���Player
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	Player*	GetPlayer( uint64 nUid);

	/*
	 *
	 *	Detail: ��ø�Player(Player��Socket����Զ�󶨵ģ�������Ϊ�����Ч��)
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	Player&	GetPlayer( SWA::NetSocket& rSocket );
		  
	/*
	 *
	 *	Detail: �㲥��Ϣ
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	void SendToAll( NetMsgHead* msg );

	/*
	 *
	 *	Detail: ����
	 *   
	 *  Created by hzd 2015/01/26  
	 *
	 */
	void Update(uint32 nDelay);

private:

	Player*			m_arrPlayerCache[MAX_SOCKET_CONNECT];	// ������һ���(������δ����)
	UIDPlayerMap	m_mapUIDPlayer;							// UID��ӦPlayer	

};


#endif

