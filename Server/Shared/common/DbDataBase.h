#ifndef SWA_DB_DATABASE_H_
#define SWA_DB_DATABASE_H_

#include <time.h>
#include <queue>

#include "BaseSingle.h"
#include "BaseDefine.h"
#include "DbConfig.h"
#include "DbField.h"
#include "DbRecord.h"
#include "DbRecordSet.h"


const ulong DB_MAX_DBACCESSTIME	= 10;
const ulong DB_MAX_STRINGSIZE	= 256;

/*
*
*	Detail: ���ݿ������
*   
*  Created by hzd 2014-10-20
*
*/
class DataBase : public IDataBase
{
public:

	// ���������� 
	bool Open( const char* pHost, const char* pUsernName,const char* pPassword, const char* pDBName,bool bSQLChk = true );
		
	// �ر����� 
	void Close();
	
	// �ͷ��Լ� 
	virtual	void Release();

	// �������ID 
	virtual uint32 ID();
		
	// ͬ��ִ��sql���ؽ�� 
	virtual MYSQL_RES* ExecuteRsyncSQL( const char* pszSQL );

	// ����ִ��sql�Ƽ� 
	bool ExecuteAsyncSQL( const char* pszSQL , void* pUser , SQLResultCallBack pCallback );

	// ��ý���� 
	virtual DbResult* GetAsyncResult();

	// ��sqlִ�лص�����(���Ƽ�ʹ��) 
	virtual	bool ExecuteAsyncPlayer(void* pData,PlayerCallBack pCallback);
	
	// ��������� 
	virtual uint32 GetRequestSize();

	// ��ý���� 
	virtual uint32 GetResultSize();

	// ����������Ӷ��� 
	MYSQL* GetDBHandle();

	// �Ƿ������
	bool IsOpen();

private:

	DataBase();
	virtual ~DataBase();

	// ���sql����Ƿ�Ϸ� 
	bool CheckSQL( const char* szSQL );

	// �������ݿ� 
	MYSQL* Connect(char* szHost , char* szUser , char* szPasswd , char* szDB , uint32 nPort = MYSQL_PORT , char* szSocket = NULL , int32 nTimeout = 1000 );

	// ���ݿ��߳�ִ�е�ѭ������ 
	virtual int32 OnThreadCreate();

	// ���ݿ��߳����ٺ���
	virtual int32 OnThreadDestroy();

	// ����sqlִ�к���
	virtual int32 OnThreadProcess();

private:

	uint32	m_nID;								// ���ݿ�����ID 

	MYSQL*	m_pDbc;								// ���ݿ����Ӷ��� 
	mutex	m_cDBMutex;							// ��������� 
	mutex	m_cQueueMutex;						// ִ�ж����� 

	bool	m_bOpen;							// �Ƿ���� (һ�㲻���жϣ�����)
	char	m_arrHost[DB_MAX_STRINGSIZE];		// ���ݿ�host
	char	m_arrUser[DB_MAX_STRINGSIZE];		// ���ݿ�username
	char	m_arrPasswd[DB_MAX_STRINGSIZE];		// ���ݿ�password
	char	m_arrDBName[DB_MAX_STRINGSIZE];		// ���ݿ��� 
		
	queue<DbRequest*>	m_queAsyncSQLRequest;	// sql������� 
	queue<DbResult*>	m_queAsyncSQLResult;	// sqlִ�н������

	friend class DatabaseMgr;

};

// ���ݹ����� 
class DatabaseMgr : public BaseSingle<DatabaseMgr>
{
public:
	DatabaseMgr();
	/*
		*
		*	Detail: ���һ�����ݿ�����
		*   
		*  Created by hzd 2015-1-26
		*
		*/
	IDataBase* AddDatabase( const char* szDBServer , const char* szLoginName , const char* szPassword , const char* szDBName , bool bEnableSQLChk = true );

	/*
		*
		*	Detail: ���ĳ���ݿ�����
		*   
		*  Created by hzd 2015-1-26
		*
		*/
	IDataBase* GetDatabase(uint32 nDbID);

	/*
		*
		*	Detail: �����DB(Ĭ��Ϊ��һ������)
		*   
		*  Created by hzd 2015/01/29  
		*
		*/
	IDataBase* GetMainDB();

	/*
		*
		*	Detail: ������DB
		*   
		*  Created by hzd 2015/01/29  
		*
		*/
	void SetMainDB(IDataBase& rIDataBase);

private:

	std::vector<IDataBase*> m_vecDbDatabase;  // ������������ 

	IDataBase* m_pMainDB;					// ��DB

};



#endif

