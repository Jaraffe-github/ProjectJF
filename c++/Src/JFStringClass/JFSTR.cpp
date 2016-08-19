#include "JFSTR.h"

char* JF::JFStringUT::Reverse(char* p_pStr)
{
	// Declear)
	char* first = p_pStr;
	int maxIdx = 0;

	// 1) Get length.
	char* ptemp = p_pStr;
	while (*ptemp != '\0')
	{
		++ptemp;
		++maxIdx;
	}
	--maxIdx;

	// 2) reverse ( 인덱스 없이 포인터로 조건문 2개 걸고할수도있지만 조건문이 늘어나는것 자체가 더 느려지는 결과임. )
	char temp;
	int halflength = maxIdx / 2;
	for(int i = 0; i < halflength; ++i)
	{
		temp = p_pStr[i];
		p_pStr[i] = p_pStr[maxIdx - i];
		p_pStr[maxIdx - i] = temp;
	}

	return p_pStr;
}