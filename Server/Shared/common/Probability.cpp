#include "probability.h"
#include "mathBase.h"
#include <time.h>

using namespace SWA;

Probability::Probability(void)
{
}


Probability::~Probability(void)
{
}

/*
 * �����ȡN�����飨������ظ���
 * source Դ����
 * target �������
 */

void Probability::getRandArray(const vector<int32>& source, vector<int32>& target, int32 tnum)
{
	target.clear();
	vector<int32> list(source);

	int32 snum = source.size();
	int32 i = 0;
	int32 rand = 0;
	srand((int32)time(NULL));
	for(;i<tnum;i++)
	{
		rand = MathBase::GetRandomInt( i , snum );
		target.push_back(list[rand]); 
		swap(list[i], list[rand]);
	}
}
/*
 * �����ȡN�����飨������ظ���
 * source Դ����
 * target �������
 */
void Probability::getRandArray(const int32 source[], int32 snum,  int32 target[], int32 tnum)
{
//	const sint32 snum = sizeof(source) / sizeof(source[0]);
//	const sint32 tnum = (sint32)(sizeof(source) / sizeof(sint32));
	int32 *list = new int32[snum];
	memcpy(list, source,  sizeof(int32) * snum);

	int32 i = 0;
	int32 rand = 0;
	srand((int32)time(NULL));
	for(;i<tnum;i++)
	{
		rand = MathBase::GetRandomInt( i , snum );
		target[i] = list[rand];
		swap(list[i], list[rand]);
	}
	delete []list;
}

/*
 * �����ȡN�����飨������ظ���
 * source Դ����
 * snum Դ�����С
 * target �������
 * tnum �������
 */
void Probability::getRandArray2(const int32 source[], int32 snum, int32 target[], int32 tnum)
{
	int32 i = 1;
	int32 nRand = 0;
	srand(time(NULL));
	for(; i < tnum; i++)
	{
		nRand = MathBase::GetRandomInt( 0 , snum-1 );
		target[i] = source[nRand];
	}
}

//��ȡ����֮�ļ���
bool Probability::selectByOdds(int32 upNum,int32 downNum)
{
	if (downNum < 1) return false;
	if (upNum < 1) return false;
	if (upNum > downNum - 1) return true;
	int32 m_rand =  MathBase::GetRandomInt( 1 , downNum );
	return (m_rand <= upNum);
}
