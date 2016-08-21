// 메모리 체크
#include "crtdbg.h"

// 문자열 클래스.
#include "JFStringClass/JFStringClasses.h"

// 공부용 클래스.
#include "JFStudyClasses/JFStudyClasses.h"

// test
#include <iostream>

#include <list>

void main()
{
	// Debug Mode Memory Leak Check
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// String Reverse
	{
		char Test[] = "I Don't have any Question";
		std::cout << Test << std::endl;
		JF::JFStringUT::Reverse(Test);
		std::cout << "Reverse" << Test << std::endl;
		std::cout << std::endl;
	}
	
	// DDL Node
	{
		JF::JFStudy::JFLinkedList<int> NodeTest;
		NodeTest.Push_Back(1);
		NodeTest.Push_Back(6);
		NodeTest.Push_Back(8);
		NodeTest.Push_Back(4);
		NodeTest.Push_Back(2);

		std::cout << "Node Count : " << NodeTest.GetCount() << std::endl;

		std::cout << "Node Datas" << std::endl;
		auto iterNode = NodeTest.BeginNode();
		while (iterNode != nullptr)
		{
			std::cout << iterNode->pData << " ";
			iterNode = iterNode->pNextNode;
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}