#ifndef _DBLOGINHANDLER_H_
#define _DBLOGINHANDLER_H_


class Player;

using namespace SWA;

// ��¼ƽ̨�˺ŷ���
void DBLoginRepAccount(void* pData ,const void* dbdata);


// ������ɫ
void DBLoginRepCreateRole(void* pData ,const void* dbdata);

// ���ؽ�ɫ�б�
void DBSelectRoleList(void* pData ,const void* dbdata);

// ѡ���ɫ���� 
void DBLoginRepSelectRole(void* pData ,const void* dbdata);

// ���������еĽ�ɫ���ݻص�
void NoDBCharacterLoadAllDataFinished(void* pData);

#endif



