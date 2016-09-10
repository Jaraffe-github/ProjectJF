#include "JFHuffman.h"
#include <malloc.h>
#include <iostream>
#include "JFPriorityQueue.h"

namespace JF
{
namespace JFStudy
{

	HuffmanNode* CreateNode(SymbolInfo _NewData)
	{
		HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
		newNode->pLeft	= nullptr;
		newNode->pRight = nullptr;
		newNode->Data	= _NewData;

		return newNode;
	}

	void DestroyNode(HuffmanNode* _pNode)
	{
		free(_pNode);
	}

	void DestroyTree(HuffmanNode* _pNode)
	{
		if (_pNode == nullptr)
			return;

		DestroyTree(_pNode->pLeft);
		DestroyTree(_pNode->pRight);
		DestroyNode(_pNode);
	}

	void AddBit(BitBuffer* _pBuffer, char _Bit)
	{
		UCHAR mask = 0x80;

		if (_pBuffer->nSize % 8 == 0)
		{
			_pBuffer->pBuffer = (UCHAR*)realloc(_pBuffer->pBuffer, sizeof(UCHAR) * ((_pBuffer->nSize / 8) + 1));
			_pBuffer->pBuffer[_pBuffer->nSize / 8] = 0x00;
		}

		mask >>= _pBuffer->nSize % 8;

		if (_Bit == 1)
			_pBuffer->pBuffer[_pBuffer->nSize / 8] |= mask;
		else
			_pBuffer->pBuffer[_pBuffer->nSize / 8] &= ~mask;

		++_pBuffer->nSize;
	}

	void Encode(HuffmanNode** _ppTree, UCHAR* _pSource, BitBuffer* _pEncoded, HuffmanCode _CodeTable[MAX_CHAR])
	{
		int i = 0;
		int j = 0;

		SymbolInfo	symbolInfoTable[MAX_CHAR];
		UCHAR		temporary[MAX_BIT];

		for (i = 0; i < MAX_CHAR; ++i)
		{
			symbolInfoTable[i].Symbol		= i;
			symbolInfoTable[i].Frequency	= 0;
		}

		i = 0;
		while (_pSource[i] != '\0')
		{
			++symbolInfoTable[_pSource[i++]].Frequency;
		}

		BuildPrefixTree(_ppTree, symbolInfoTable);
		BuildCodeTable(*_ppTree, _CodeTable, temporary, 0);

		i = 0;
		while (_pSource[i] != '\0')
		{
			int bitCount = _CodeTable[_pSource[i]].nSize;

			for (j = 0; j < bitCount; ++j)
				AddBit(_pEncoded, _CodeTable[_pSource[i]].Code[j]);

			++i;
		}
	}

	void Decode(HuffmanNode * _ppTree, BitBuffer * _pEncoded, UCHAR* _pDecoded)
	{
		int nIndex = 0;
		HuffmanNode* pCurrent = _ppTree;

		for (int i = 0; i <= _pEncoded->nSize; ++i)
		{
			UCHAR mask = 0x80;

			if (pCurrent->pLeft == nullptr && pCurrent->pRight == nullptr)
			{
				_pDecoded[nIndex++] = pCurrent->Data.Symbol;
				pCurrent = _ppTree;
			}

			mask >>= i % 8;

			if ((_pEncoded->pBuffer[i / 8] & mask) != mask)
				pCurrent = pCurrent->pLeft;
			else
				pCurrent = pCurrent->pRight;
		}

		_pDecoded[nIndex] = '\0';
	}

	void BuildPrefixTree(HuffmanNode ** _ppTree, SymbolInfo _SymbolInfoTable[MAX_CHAR])
	{
		PQNode<int, HuffmanNode*> result;
		PriorityQueue<int, HuffmanNode*> PQ(3);

		for (int i = 0; i < MAX_CHAR; ++i)
		{
			if (_SymbolInfoTable[i].Frequency > 0)
			{
				HuffmanNode* bitNode = CreateNode(_SymbolInfoTable[i]);

				PQNode<int, HuffmanNode*> newNode;
				newNode.Key		= _SymbolInfoTable[i].Frequency;
				newNode.Value	= bitNode;

				PQ.Enqueue(newNode);
			}
		}

		while (PQ.GetUsedSize() > 1)
		{
			SymbolInfo newData = { 0, 0 };

			HuffmanNode* pBitNode = CreateNode(newData);
			HuffmanNode* pLeft;
			HuffmanNode* pRight;

			PQNode<int, HuffmanNode*> qLeft;
			PQNode<int, HuffmanNode*> qRight;
			PQNode<int, HuffmanNode*> qNewNode;

			qLeft = *PQ.GetMinData();
			PQ.Dequeue();

			qRight = *PQ.GetMinData();
			PQ.Dequeue();

			pLeft	= (HuffmanNode*)qLeft.Value;
			pRight	= (HuffmanNode*)qRight.Value;

			pBitNode->Data.Symbol = 0;
			pBitNode->Data.Frequency = pLeft->Data.Frequency + pRight->Data.Frequency;

			pBitNode->pLeft		= pLeft;
			pBitNode->pRight	= pRight;

			qNewNode.Key	= pBitNode->Data.Frequency;
			qNewNode.Value	= pBitNode;

			PQ.Enqueue(qNewNode);
		}

		result = *PQ.GetMinData();
		PQ.Dequeue();

		*_ppTree = (HuffmanNode*)result.Value;
	}

	void BuildCodeTable(HuffmanNode * _pTree, HuffmanCode _CodeTable[MAX_CHAR], UCHAR _Code[MAX_BIT], int _nSize)
	{
		if (_pTree == nullptr)
			return;

		if (_pTree->pLeft != nullptr)
		{
			_Code[_nSize] = 0;
			BuildCodeTable(_pTree->pLeft, _CodeTable, _Code, _nSize + 1);
		}

		if (_pTree->pRight != nullptr)
		{
			_Code[_nSize] = 1;
			BuildCodeTable(_pTree->pRight, _CodeTable, _Code, _nSize + 1);
		}

		if (_pTree->pLeft == nullptr && _pTree->pRight == nullptr)
		{
			for (int i = 0; i < _nSize; ++i)
				_CodeTable[_pTree->Data.Symbol].Code[i] = _Code[i];

			_CodeTable[_pTree->Data.Symbol].nSize = _nSize;
		}
	}

	void PrintBinary(BitBuffer * _pBuffer)
	{
		for (int i = 0; i < _pBuffer->nSize; ++i)
		{
			UCHAR mask = 0x80;
			mask >>= i % 8;

			printf("%d", (_pBuffer->pBuffer[i/8] & mask) == mask);
		}
	}

}
}