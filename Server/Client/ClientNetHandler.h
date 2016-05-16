#ifndef CLIENT_NET_HANDLER_H_
#define CLIENT_NET_HANDLER_H_

/*
 *
 *	Detail: �ͻ���Handler�¼�
 *   
 *  Created by hzd 2015/01/26  
 *
 */
class ClientNetHandler
{
public:

	ClientNetHandler(void);
	~ClientNetHandler(void);

	// �����ɷ����������Ͽ�
	static void SendRequestClose();

	/////////////////////////////����/////////////////////////////////////////////
	static void SendEncrypt();
	static void SendLogin();
	static void SendCharacterList();
	static void SendRegister();
	static void SendChar2World();
	static void SendLoadResed();

	/////////////////////////////����/////////////////////////////////////////////

	static void RecvEncryptInfo(NetMsgHead* head);
	static void RevcCharacterList(NetMsgHead* head);
	static void RevcLoginResult(NetMsgHead* head);
	static void RecvSelectResult(NetMsgHead* head);
	static void RecvRegisterResult(NetMsgHead* head);
	static void RecvCharacterInfo(NetMsgHead* head);
	static void RecvChatInfo(NetMsgHead* head);


};

#endif

