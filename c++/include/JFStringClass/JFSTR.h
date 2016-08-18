#pragma once

namespace JF
{
	class JFString
	{
	public:
		JFString(char c);
		JFString(const char* str);
		JFString(const JFString& str);

	private:
		char*	m_pSTR;
		int		m_STRLength;
	};
}