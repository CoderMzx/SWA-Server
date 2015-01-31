
#ifndef PROTOCOL_DEFIEN_H_
#define PROTOCOL_DEFIEN_H_

#include "BaseDefine.h"

#ifndef __COMMONDEF_H_
#define __COMMONDEF_H_

#include <memory>
union ValueType
{
	ValueType()
	{
		memset(this, 0, sizeof(*this));
	}

	template<typename T>
	ValueType(T v)
	{
		if (!(sizeof(*this) < sizeof(T)))
		{
			memcpy(this, &v, sizeof(T));
		}
	}
	int8	nInt8;
	int16	nInt16;
	int32	nInt32;
	int64	nInt64;
	uint8	nUint8;
	uint16	nUint16;
	uint32	nUint32;
	uint64	nUint64;
	float32	fFloat;
};

#endif


typedef vector< string > StringVector;
typedef vector< string >::iterator StringIter;

typedef vector< int32 > IntVector;
typedef vector< int32 >::iterator IntIter;

#define EncryptDefualt "1234567890ABCDEFGHIJKLMNOPQSRTWX"

/*���ó�������*/
enum 
{
	MAX_ACCOUNT_LENG				= 32,	// ƽ̨�˺���󳤶�
	MAX_PASSWORD_LENG				= 32,   // ƽ̨������󳤶�
	MAX_NICK_LENGTH					= 32,	// �ǳ���󳤶�
	MAX_ROLE_TYPE_COUNT				= 4,	// һ��ƽ̨�ʺ������������ɫ����
	MAX_CHAT_MSG_LENGTH				= 128,	// ����������󳤶�
	MAX_ENCRYPT_LENTH				= 32,	// ��Կ����
};

//�ͻ��˵�ǰ״̬
enum ClientStatus
{
	CS_INVALID  = 0,
	CS_LOGIN_ING,			//	��¼��
	CS_LOGIN_OK	,			//	��¼���
	CS_REGISTER_ING,		//  ע����
	CS_REGISTER_OK,			//	ע��ɹ�
	CS_LOADDATA_ING,		//	��ʼ��������
	CS_LOADDATA_OK,			//	��ʼ���������
	CS_IN_GAME	,			//	������Ϸ(ѡ���ע���ɫ��)
	CS_RES_OK	,			//	ǰ����Դ�������
};


template <typename T> void Swap(T*  obj1,T* obj2)  
{  
	unsigned char * pObj1 = reinterpret_cast<unsigned char *>(obj1);  
	unsigned char * pObj2 = reinterpret_cast<unsigned char *>(obj2);  
	for (unsigned long x = 0; x < sizeof(T); ++x)  
	{  
		pObj1[x] ^= pObj2[x];  
		pObj2[x] ^= pObj1[x];  
		pObj1[x] ^= pObj2[x];  
	}  
}


// ��ɫ����
enum EPlayerRoleType
{
	ROLE_TYPE_INVAILD = 0,// ��Ч��
	ROLE_TYPE_1 ,
	ROLE_TYPE_2,
	ROLE_TYPE_3,
	ROLE_TYPE_4,

};


struct NetMsgHead
{
	NetMsgHead(uint32 _nType):nType(_nType)
	{}
	uint32 nSize;	// ��С
	uint32 nType;	// Э��
};

#endif