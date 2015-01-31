#ifndef PROBABILITY_H_
#define PROBABILITY_H_

#include "BaseDefine.h"

namespace SWA
{
	template <class T>
	int32 getArrayLen(T& array)  //ʹ��ģ�嶨��һ������getArrayLen,�ú�������������array�ĳ���
	{
	  return (int32)(sizeof(array) / sizeof(array[0]));
	}

	class Probability
	{
	public:
		Probability(void);
		~Probability(void);
		static void getRandArray(const vector<int32>& source, vector<int32>& target, int32 tnum);
		static void getRandArray(const int32 source[], int32 snum,  int32 target[], int32 tnum);
		static void getRandArray2(const int32 source[], int32 snum, int32 target[], int32 tnum);
		static bool selectByOdds(int32 upNum,int32 downNum);
		
	};
}
#endif