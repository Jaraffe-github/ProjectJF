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

	// 2) reverse ( �ε��� ���� �����ͷ� ���ǹ� 2�� �ɰ��Ҽ��������� ���ǹ��� �þ�°� ��ü�� �� �������� �����. )
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