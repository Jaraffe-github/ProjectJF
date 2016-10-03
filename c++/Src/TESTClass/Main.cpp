//
#include <windows.h>

// 메모리 체크
#include "crtdbg.h"

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

	// MergeSort
	{
		std::cout << "MergeSort" << std::endl;

		int datas[] = { 123, 231, 523, 122, 51, 24, 12, 45, 52, 59, 1245 };
		int nLength = sizeof datas / sizeof datas[0];

		JF::JFSortUtiles::MergeSort(datas, 0, nLength-1);

		for (int i = 0; i < nLength; ++i)
		{
			std::cout << datas[i] << " ";
		}
		std::cout << std::endl;
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

	// JFPriorityQueue
	{
		std::cout << "JFPriorityQueue" << std::endl;

		JF::JFStudy::PriorityQueue<int, char> priorityQueue(3);
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(5, 'e'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(2, 'b'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(8, 'h'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(3, 'c'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(6, 'f'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(1, 'a'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(4, 'd'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(9, 'i'));
		priorityQueue.Enqueue(JF::JFStudy::PQNode<int, char>(7, 'g'));

		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();
		std::cout << "MinValue Key : " << priorityQueue.GetMinData()->Key << " Value : " << priorityQueue.GetMinData()->Value << std::endl;
		priorityQueue.Dequeue();

		std::cout << std::endl;
	}

	// DivisionHashTable
	{
		std::cout << "DivisionHashTable" << std::endl;

		JF::JFStudy::JFDHashTable<char> hashTable(389);
		hashTable.Insert(165, 'a');
		hashTable.Insert(223, 'b');
		hashTable.Insert(307, 'c');
		hashTable.Insert(44, 'd');
		hashTable.Insert(501, 'e');
		hashTable.Insert(645, 'f');
		hashTable.Insert(72, 'g');
		hashTable.Insert(875, 'h');
		hashTable.Insert(923, 'i');

		int nkey = 501;
		std::cout << "Key : " << nkey << " Value : " << *hashTable.GetData(nkey) << std::endl;
	}

	// DighitsFolding
	{
		std::cout << "DighitsFolding" << std::endl;

		JF::JFStudy::JFDighitsFolding<int> hashTable(12289);
		hashTable.Insert("KFRE", 4, 1);
		hashTable.Insert("SNRZ", 4, 2);
		hashTable.Insert("c", 1, 3);
		hashTable.Insert("e", 1, 4);
		hashTable.Insert("f", 1, 5);
		hashTable.Insert("h", 1, 6);
		hashTable.Insert("i", 1, 7);

		char* nkey = "KFRE";
		std::cout << "Key : " << nkey << " Value : " << *hashTable.GetData(nkey, 4) << std::endl;
		std::cout << std::endl;
	}

	// BoyerMoore
	{
		std::cout << "BoyerMoore(String Search)" << std::endl;

		char* pText = "Some regard the King James Bible to be a work of fiction, others the Holy word of God.";

		char* pSearchString = "others";
		int nSearchStringLength = (int)strlen(pSearchString);
		
		std::cout << "SearchString : " << pSearchString << std::endl;
		int nSearchindex = JF::JFStudy::BoyerMoore(pText, (int)strlen(pText), 0, pSearchString, nSearchStringLength);
		if (nSearchindex > 0)
		{
			char* result = &pText[nSearchindex];
			for (int i = 0; i < nSearchStringLength; ++i)
			{
				std::cout << result[i];
			}
		}
		else
		{
			std::cout << "No Match num : " << nSearchindex << std::endl;
		}
		std::cout << std::endl;
	}

	// Power
	{
		std::cout << "Power" << std::endl;

		int nNumber = 2;
		int nExponent = 4;

		int nResult = JF::JFStudy::Pow(nNumber, nExponent);

		std::cout << "Number : " << nNumber << " Exponent : " << nExponent << " Result : " << nResult << std::endl;
		std::cout << std::endl;
	}

	// Fibonacci
	{
		std::cout << "Fibonacci" << std::endl;

		int n = 15;
		unsigned int nResult = JF::JFStudy::Fibonacci(n);

		std::cout << "Fibonacci N : " << n << " Result : " << nResult << std::endl;
		std::cout << std::endl;
	}

	// LCS
	{
		std::cout << "LCS" << std::endl;

		char* pX = "Long diff a";
		char* pY = "a dif gmp";
		char* pResult;

		int nLenX = strlen(pX);
		int nLenY = strlen(pY);

		int i = 0;
		int j = 0;
		int nLength = 0;

		JF::JFSearchUtiles::LCSTable table;

		table.ppData = (int**)malloc(sizeof(int*) * (nLenX + 1));

		for (i = 0; i < nLenX + 1; ++i)
		{
			table.ppData[i] = (int*)malloc(sizeof(int) * (nLenY + 1));
			memset(table.ppData[i], 0, sizeof(int) * (nLenY + 1));
		}

		nLength = JF::JFSearchUtiles::LCS(pX, pY, nLenX, nLenY, &table);

		JF::JFSearchUtiles::LCS_PrintTable(&table, pX, pY, nLenX, nLenY);

		pResult = (char*)malloc(table.ppData[nLenX][nLenY] + 1);
		sprintf(pResult, "");

		JF::JFSearchUtiles::LCS_TraceBack(pX, pY, nLenX, nLenY, &table, pResult);

		printf("\n");
		printf("LCS:\"%s\" (Length:%d)\n", pResult, nLength );

		std::cout << std::endl;
	}

	// Huffman
	{
		std::cout << "Huffman" << std::endl;

		char* pSource	= "안녕하세요. 허프만코드 압축 효율에대해서 알아보겠습니다.";
		char* pDecoded	= "";

		JF::JFStudy::HuffmanNode* pTree = nullptr;
		JF::JFStudy::BitBuffer encoded	= { nullptr, 0 };
		JF::JFStudy::HuffmanCode codeTable[MAX_CHAR];

		memset(&codeTable, 0, sizeof(JF::JFStudy::HuffmanCode) * MAX_CHAR);

		JF::JFStudy::Encode(&pTree, (UCHAR*)pSource, &encoded, codeTable);

		printf("Original Size : %d Encoded Size:%d\n", (strlen(pSource) + 1) * sizeof(char) * 8, encoded.nSize);

		pDecoded = (char*)malloc(sizeof(char) * (strlen(pSource) + 1));
		JF::JFStudy::Decode(pTree, &encoded, (UCHAR*)pDecoded);

		printf("Original : %s\n", pSource);
		printf("Encoded : ");

		JF::JFStudy::PrintBinary(&encoded);

		printf("\n");

		printf("Decoded : %s\n", pDecoded);

		JF::JFStudy::DestroyTree(pTree);
		free(pDecoded);
	}

	// API File
	{
		FILE_HANDLE file = JFAPI::FILE::Open(L"../Box.ASE", eFILE_OPERATION::READ);
		size_t fileSize = JFAPI::FILE::GetLength(file);

		char* buffer = new char[fileSize + 1];
		buffer[fileSize] = '\0';
		JFAPI::FILE::Read(file, fileSize, buffer);

		JFAPI::FILE::Close(file);
	}
}