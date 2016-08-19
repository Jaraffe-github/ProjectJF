// 메모리 체크
#include "crtdbg.h"

// 문자열 클래스.
#include "JFStringClass/JFStringClasses.h"

// test
#include <iostream>

void main()
{
	// Debug Mode Memory Leak Check
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// String Reverse
	char Test[] = "I Don't have any Question";
	std::cout << Test << std::endl;
	JF::JFStringUT::Reverse(Test);
	std::cout << Test << std::endl;
}