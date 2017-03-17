//
#include <windows.h>

// 메모리 체크
#include "crtdbg.h"

// 1) 파일 입출력 클래스.
#include "JFFileSystemClasses.h"

// 문자열 클래스.
#include "JFStringClasses.h"

// 공부용 클래스.
#include "JFStudyClasses.h"

// 테스트용 클래스들
#include "JFObjectClasses.h"

// test
#include <iostream>

#include <list>

void main()
{
	// Debug Mode Memory Leak Check
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

}