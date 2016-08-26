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

	// BubbleSort
	{
		std::cout << "BubbleSort" << std::endl;
		int sortDatas[] = { 5, 2, 1, 6, 3, 9, 4, 8, 7 };
		int length = sizeof(sortDatas) / sizeof(sortDatas[0]);
		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;

		JF::JFSortUtiles::BubbleSort(sortDatas, length);

		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	// InsertionSort
	{
		std::cout << "InsertionSort" << std::endl;
		int sortDatas[] = { 5, 2, 1, 6, 3, 9, 4, 8, 7 };
		int length = sizeof(sortDatas) / sizeof(sortDatas[0]);
		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;

		JF::JFSortUtiles::InsertionSort(sortDatas, length);

		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	// QuickSort
	{
		std::cout << "QuickSort" << std::endl;
		int sortDatas[] = { 17, 5, 21, 2, 12, 1, 18, 6, 25, 3, 9, 4, 8, 24, 7, 10, 15, 16, 23, 11, 13, 20, 19, 14, 22 };
		int length = sizeof(sortDatas) / sizeof(sortDatas[0]);
		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;

		JF::JFSortUtiles::QuickSort(sortDatas, 0, length - 1);

		for (int i = 0; i < length; ++i)
		{
			std::cout << sortDatas[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}

	// QuickSort And BinarySearch
	{
		std::cout << "QuickSort And BinarySearch" << std::endl;
		struct Data
		{
			Data(_In_ int _nGuid, _In_ int _nValue)
				: nGUID(_nGuid), nValue(_nValue) {}

			bool operator == (Data& _data)	{ if (nGUID == _data.nGUID) return true; else return false; }
			bool operator >(Data& _data)	{ if (nGUID > _data.nGUID) return true; else return false; }
			bool operator <(Data& _data)	{ if (nGUID < _data.nGUID) return true;	else return false; }
			bool operator >=(Data& _data)	{ if (nGUID >= _data.nGUID) return true; else return false; }
			bool operator <=(Data& _data)	{ if (nGUID <= _data.nGUID) return true; else return false; }

			bool operator == (int _data)	{ if (nGUID == _data) return true; else	return false; }
			bool operator >(int _data)		{ if (nGUID > _data) return true; else return false; }
			bool operator <(int _data)		{ if (nGUID < _data) return true; else return false; }
			bool operator >=(int _data)		{ if (nGUID >= _data) return true; else return false; }
			bool operator <=(int _data)		{ if (nGUID <= _data) return true; else return false; }

			int nGUID;
			int nValue;
		};

		Data dataList[] = {
			Data(20, 1), Data(2, 19), Data(3, 18), Data(5, 16), Data(6, 15), Data(15, 6), Data(8, 13), Data(7, 14), Data(9, 12), Data(10, 11),
			Data(11, 10), Data(12, 9), Data(13, 8), Data(14, 7), Data(4, 17), Data(16, 5), Data(17, 4), Data(18, 3), Data(19, 2), Data(1, 20)
		};
		int nLength = sizeof(dataList) / sizeof(dataList[0]);

		JF::JFSortUtiles::QuickSort(dataList, 0, nLength - 1);

		int nFindData = 5;
		Data* findData = JF::JFSearchUtiles::BinarySearch(dataList, nLength, nFindData);
		if(findData != nullptr)
			std::cout << "Find Data :" << nFindData << " Value : " << findData->nValue << std::endl;
		else
			std::cout << "BinarySearch No Data" << std::endl;

		std::cout << std::endl;
	}

	// RedBlackTree
	{
		std::cout << "RedBlackTree" << std::endl;

		JF::JFStudy::RedBlackTree<int> redblackTree;
		redblackTree.InsertNode(20);
		redblackTree.InsertNode(15);
		redblackTree.InsertNode(10);
		redblackTree.InsertNode(26);
		redblackTree.InsertNode(27);
		redblackTree.InsertNode(30);
		redblackTree.InsertNode(5);
		redblackTree.InsertNode(1);
		redblackTree.InsertNode(18);
		redblackTree.InsertNode(2);
		redblackTree.InsertNode(4);
		redblackTree.InsertNode(13);
		redblackTree.InsertNode(8);
		redblackTree.InsertNode(16);
		redblackTree.InsertNode(25);
		redblackTree.InsertNode(31);
		redblackTree.InsertNode(34);
		redblackTree.InsertNode(37);
		redblackTree.InsertNode(40);
		redblackTree.InsertNode(19);
		redblackTree.InsertNode(32);
		redblackTree.InsertNode(33);
		redblackTree.InsertNode(17);
		redblackTree.InsertNode(14);
		redblackTree.InsertNode(11);
		redblackTree.InsertNode(38);
		redblackTree.InsertNode(39);
		redblackTree.InsertNode(24);
		redblackTree.InsertNode(9);
		redblackTree.InsertNode(7);
		redblackTree.InsertNode(3);
		redblackTree.InsertNode(6);
		redblackTree.InsertNode(12);
		redblackTree.InsertNode(23);
		redblackTree.InsertNode(21);
		redblackTree.InsertNode(22);
		redblackTree.InsertNode(35);
		redblackTree.InsertNode(36);
		redblackTree.InsertNode(28);
		redblackTree.InsertNode(29);

		redblackTree.RemoveNode(15);

		redblackTree.PrintTree(0, 0);

		std::cout << std::endl;
	}
}