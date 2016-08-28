#pragma once

namespace JF
{
	namespace JFStudy
	{
		template<typename TData>
		struct QueueHeap
		{
			TData Data;
		};

		template<typename TData>
		class PriorityQueue
		{
		public:
			PriorityQueue(_In_ int _ninitSize)
			{
				if (_ninitSize > 0)
				{
					m_pNodes	= (QueueHeap<TData>*)malloc(sizeof(QueueHeap<TData>) * _ninitSize);
					m_nCapactiy = _ninitSize;
					m_nUsedSize = 0;
				}
				else
				{
					m_pNodes	= nullptr;
					m_nCapactiy = 0;
					m_nUsedSize = 0;
				}
			}

			virtual ~PriorityQueue()
			{
				free(m_pNodes);
				m_pNodes = nullptr;
			}

		public:
			void Insert(_In_ TData _newData)
			{
				int nCurrIndex		= m_nUsedSize;
				int nParentIndex	= _GetParentIndex(nCurrIndex);

				if (m_nCapactiy <= 1)
				{
					m_nCapactiy = 3;
					m_pNodes	= (QueueHeap<TData>*)realloc(m_pNodes, sizeof(QueueHeap<TData>) * m_nCapactiy);
				}
				// if max Capactiy, m_nCapactiy * 2
				if (m_nUsedSize == m_nCapactiy)
				{
					m_nCapactiy *= 2;
					m_pNodes	= (QueueHeap<TData>*)realloc(m_pNodes, sizeof(QueueHeap<TData>) * m_nCapactiy);
				}

				// Add NewNode 
				m_pNodes[nCurrIndex].Data = _newData;

				// Refresh
				while (m_nUsedSize > 0 && m_pNodes[nCurrIndex].Data < m_pNodes[nParentIndex].Data)
				{
					_SwapNodes(nCurrIndex, nParentIndex);

					nCurrIndex		= nParentIndex;
					nParentIndex	= _GetParentIndex(nCurrIndex);
				}

				// offset
				++m_nUsedSize;
			}

			void DeleteMin()
			{
				int nDataSize		= sizeof(QueueHeap<TData>);
				int nParentIndex	= 0;
				int nLeftIndex		= 0;
				int nRightIndex		= 0;

				// offset
				--m_nUsedSize;

				_SwapNodes(0, m_nUsedSize);

				// Get Index ( LeftChild + 1 == RightChild )
				nLeftIndex	= _GetLeftChild(0);
				nRightIndex = nLeftIndex + 1;

				while (true)
				{
					int nSelectedChild = 0;

					if(nLeftIndex >= m_nUsedSize)
						break;

					if (nRightIndex >= m_nUsedSize)
					{
						nSelectedChild = nLeftIndex;
					}
					else
					{
						if (m_pNodes[nLeftIndex].Data > m_pNodes[nRightIndex].Data)
							nSelectedChild = nRightIndex;
						else
							nSelectedChild = nLeftIndex;
					}

					if (m_pNodes[nSelectedChild].Data < m_pNodes[nParentIndex].Data)
					{
						_SwapNodes(nParentIndex, nSelectedChild);
						nParentIndex = nSelectedChild;
					}
					else
						break;

					nLeftIndex	= _GetLeftChild(nParentIndex);
					nRightIndex = nLeftIndex + 1;
				}

				if (m_nUsedSize < (m_nCapactiy / 2))
				{
					m_nCapactiy /= 2;
					m_pNodes	= (QueueHeap<TData>*)realloc(m_pNodes, sizeof(QueueHeap<TData>) * m_nCapactiy);
				}
			}

			TData* GetMinData()
			{
				if (m_nUsedSize > 0)
					return &m_pNodes[0].Data;
				else
					return nullptr;
			}

			void PrintNode()
			{
				for (int i = 0; i < m_nUsedSize; ++i)
				{
					printf("%d ", m_pNodes[i].Data);
				}
				printf("\n");
			}

		private:
			QueueHeap<TData>* _CreateHeap(_In_ TData _newData)
			{
				QueueHeap<TData>* pNewNode = new QueueHeap<TData>();
				pNewNode->Data = _newData;

				return pNewNode;
			}

			void _DestroyNodes()
			{
				delete pNewNode;
				pNewNode = nullptr;
			}

			void _SwapNodes(_In_ int _nIndex1, _In_ int _nIndex2)
			{
				int nCopySize = sizeof(QueueHeap<TData>);
				QueueHeap<TData>* pTemp = (QueueHeap<TData>*)malloc(nCopySize);

				memcpy(pTemp,				&m_pNodes[_nIndex1],	nCopySize);
				memcpy(&m_pNodes[_nIndex1], &m_pNodes[_nIndex2],	nCopySize);
				memcpy(&m_pNodes[_nIndex2], pTemp,					nCopySize);

				free(pTemp);
			}

			int _GetParentIndex(_In_ int _nIndex)
			{
				return (int)((_nIndex - 1) / 2);
			}

			int _GetLeftChild(_In_ int _nIndex)
			{
				return (2 * _nIndex) + 1;
			}

			int _GetRightChild(_In_ int _nIndex)
			{
				return (2 * _nIndex) + 2;
			}

		private:
			QueueHeap<TData>* m_pNodes;
			int m_nCapactiy;
			int m_nUsedSize;
		};
	}
}