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

		char* pText = "Some regard the King James Bible to be a work of fiction, others the Holy word of God. I read the King James translation of the Bible some, when I was young, and more or less accepted what was taught about the King James Bible at the church I attended with my parents. "
			"When I grew older, I looked at the Bible for myself, and at one point, almost gave up on the whole idea of God and all.The church I attended - when I was growing up - put a lot of stock in the original languages for translation.There was a lot of ranting in the church about how terrible a translation the King James actually was."
			"Later, when I went to college, I took some years of Greek and a tad of Hebrew.I later came the conclusion that the Bible text was truthful, but that I had been mislead by the pastors teachings concerning what the Bible actually had to say."
			"I personally feel as though I understand why there are hostile attitudes toward the Bible text.Not so sure, however, that I understand why anyone would feel so hostile toward a book they believe to be purely fiction."
			"It is said that Life is stranger than fiction and perhaps, for some, truth is more mysterious."
			"I imagine a good deal of turmoil over the Bible text has to do with the plethora of men / women of the cloth who put their own special spin on the Bible; and perhaps, a generous portion of synagogue or church goers who are neither hearers, nor doers of good."
			"IMHO a lot of false ideas about the Bible text are popular.I imagine a majority of people dont know or care very little what the Bible text has to say, or even what it means.It seems common now for people to mock and deride the Bible.In the end, what is true will be true and what is false will be false."
			"Although, I imagine some of the positive reviewers of the Bible text may know very little of the Bibles contents, I feel as though - it may also be the case -that some of the Bibles more negative, or sarcastic reviewers, are just as rash in their willingness to post a judgmental rant or comment concerning the King James Bible text."
			"The King James translation of the Bible is maybe not the best translation for a modern reader, but for the most part is readable."
			"Another favorite verse : For what shall it profit a man, if he shall gain the whole world, and lose his own soul ";

		char* pSearchString = "James";
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
			std::cout << "No Match" << std::endl;
		}
		std::cout << std::endl;
	}
}