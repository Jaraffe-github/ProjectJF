#include "JFSTR.h"

char* JF::JFStringUT::Reverse(char* p_pStr)
{
	// Declear)
	char* plast = p_pStr;
	int length	= 0;

	// 1) Get Length And last Pointer
	while (*plast != '\0')
	{
		++plast;
		++length;
	}

	// 2)
	char* reversStr = new char[length + 1];

	// 3) Revers
	for (int i = 0; i < length; ++i)
	{
		reversStr[i] = *(--plast);
	}
	reversStr[length] = '\0';

	// Return)
	return reversStr;
}