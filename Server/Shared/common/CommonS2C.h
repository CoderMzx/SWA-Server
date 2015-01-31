#ifndef __COMMONS2C_H_
#define __COMMONS2C_H_

#include "CommonDefine.h"


// s2cЭ��
enum EProS2C
{

	// ����Э��
	PRO_S2C_ENCRYPT_INFO			= 900,	// ������Կ��Ϣ

	// ����Э��ŷ�Χ0~65536
	// ����Э�鷶Χ  1000\3000\5000\��������
	PRO_S2C_CHARACTER_LIST			= 2000,	// ��¼�ʺŷ��ص����н�ɫ����Ϣ
	PRO_S2C_CHARACTER_INFO			= 2001,	// ѡ�񵥸���ɫ���ؽ�ɫ��ϸ��Ϣ
	PRO_S2C_LOGIN_RESULT			= 2002,	// ��¼�Ľ��
	PRO_S2C_SELECT_RESULT			= 2003,	// ѡ���ɫ�Ľ��
	PRO_S2C_CHAT_TO_WORLD			= 2004,	// ����������Ϣ
};


#pragma pack(push, 1)

// ���ص�¼��Ϣ
struct S2CLoginResult : public NetMsgHead
{
	S2CLoginResult():NetMsgHead(PRO_S2C_LOGIN_RESULT)
	{

	}

	enum ELoginResult
	{
		LR_SUCCESS,
		LR_SIGN_FAIL,
		LR_FAIL,
		LR_REPEAT,
	} eStatus; // ��¼���

};

// ������Կ
struct S2CEncryptInfo : public NetMsgHead
{
	S2CEncryptInfo():NetMsgHead(PRO_S2C_ENCRYPT_INFO)
	{
		nSize = sizeof(*this);
	}
	char arrEncryptKey[MAX_ENCRYPT_LENTH];
};


#pragma pack(pop)




#endif