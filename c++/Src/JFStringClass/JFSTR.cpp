#include "JFSTR.h"
#include <string>

JF::JFString::JFString(char c)
{
	m_pSTR		= new char[1];
	m_pSTR[0]	= c;
	
	m_STRLength = 1;
}

JF::JFString::JFString(const char* str)
{
	m_STRLength = strlen(str);
	m_pSTR		= new char[m_STRLength];
	for (int i = 0; i != m_STRLength; ++i)
	{
		m_pSTR[i] = str[i];
	}
}

JF::JFString::JFString(const JFString& str)
{
	m_STRLength = str.m_STRLength;
	m_pSTR		= str.m_pSTR;

	m_pSTR[0] = 'b';
}

