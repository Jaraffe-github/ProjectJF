//
#include <windows.h>

// �޸� üũ
#include "crtdbg.h"

// 1) ���� ����� Ŭ����.
#include "JFFileSystemClasses.h"

// ���ڿ� Ŭ����.
#include "JFStringClasses.h"

// ���ο� Ŭ����.
#include "JFStudyClasses.h"

// �׽�Ʈ�� Ŭ������
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