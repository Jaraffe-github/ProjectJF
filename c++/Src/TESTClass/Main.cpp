// 메모리 체크
#include "crtdbg.h"

// 문자열 클래스.
#include "JFStringClass/JFSTR.h"
#pragma comment(lib, "JFStringClasses_x64_v140_Debug.lib")

#include <string>

void main()
{
	// Debug Mode Memory Leak Check
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	JF::JFString t("tttt");
	JF::JFString tt(t);

	std::string asd;
	asd[0];
}