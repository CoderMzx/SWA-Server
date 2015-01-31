#ifndef _GAMEPLAYER_H_
#define _GAMEPLAYER_H_

class SWA::NetSocket;
struct NetMsgHead;

// ���״̬
enum EPlayerStatus
{
	EPLAYER_STATUS_INITED		 ,	// ��ʼ����� 
	EPLAYER_STATUS_CONNECTED	 ,  // �Ѿ�������������� 
	EPLAYER_STATUS_ENCRYPTED	 ,	// �����Կ�ɹ���� 
	EPLAYER_STATUS_LOGINED		 ,	// ��¼������ 
	EPLAYER_STATUS_SELECTED		 ,  // ѡ���ɫ��� 
	EPLAYER_STATUS_OK			 ,	// ���Խ������ݽ������  
};

/*
 *
 *	Detail: �����
 *   
 *  Created by hzd 2015/01/26  
 *
 */

struct PlayerData
{

};

class Player
{
public:

	Player(SWA::NetSocket& rSocket);
	virtual ~Player();

	/*
	 *
	 *	Detail: ��������
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void LoadData(const PlayerData& rData);

	/*
	 *
	 *	Detail: ��ý�ɫID
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	uint64	UID();

	/*
	 *
	 *	Detail: ������Ϣ
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void SendMsg( NetMsgHead* pMsg);
	
	/*
	 *
	 *	Detail: ���ƽ̨�˺�
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void GetAccount(char o_arrAccount[MAX_ACCOUNT_LENG]);

	/*
	 *
	 *	Detail: no
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void SetStatus(EPlayerStatus eStatus);
	
	/*
	 *
	 *	Detail: ���״̬
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	EPlayerStatus GetStatus(){ return m_eStatus; };

	/*
	 *
	 *	Detail: ����ͨ����Կ
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void SetEncryptKey(char arrNewKey[MAX_ENCRYPT_LENTH]);

	/*
	 *
	 *	Detail: ���ͨ����Կ
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void GetEncryptKey(char o_arrEncryptKey[MAX_ACCOUNT_LENG]);

	/*
	 *
	 *	Detail: ����˳�
	 *   
	 *  Created by hzd 2015-1-21
	 *
	 */
	void Exist();

	/*
	 *
	 *	Detail: ��ʱѭ��������Ϊ��ʱ����
	 *   
	 *  Created by hzd 2015/01/21  
	 *
	 */
	void Update(uint32 nDelay);
		
private:

	uint64				m_nID;								// ��ɫID
	char				m_arrAccount[MAX_ACCOUNT_LENG];	// ƽ̨ID
	SWA::NetSocket&		m_rSocket;							// socket
	EPlayerStatus		m_eStatus;							// ��������״̬

	int32				mSendPackCount;						//����������У���˳�򡢶��������
	char				m_arrEncryptKey[MAX_ENCRYPT_LENTH];	//ͨ����Կ

};

#endif

