#pragma once

namespace JF
{
	namespace JFStudy
	{
		template<typename TData>
		struct DLLNode
		{
			TData pData;
			DLLNode* pPrevNode = nullptr;
			DLLNode* pNextNode = nullptr;
		};

		template<typename TData>
		class JFLinkedList
		{
		private:
			DLLNode* CreateNode(TData p_Data);
			void Destroy(DLLNode* p_Node);

		public:
			void Push_Back(TData p_Data);
			void Remove(DLLNode* p_Node);

		private:
			DLLNode* m_pHead = nullptr;
			DLLNode* m_pTail = nullptr;
		};
	}
}

template<typename TData>
DLLNode<TData>* JF::JFStudy::JFLinkedList<TData>::CreateNode(TData p_Data)
{
	DLLNode<TData>* newNode = (DLLNode<TData>*)malloc(sizeof(DLLNode<T>));
	newNode->pData		= p_Data;
	newNode->pNextNode	= nullptr;

	return newNode;
};

template<typename TData>
void JF::JFStudy::JFLinkedList<TData>::Destroy(DLLNode* p_Node)
{
	free(p_Data);
}

template<typename TData>
void JF::JFStudy::JFLinkedList<TData>::Push_Back(TData p_Data)
{
	if (m_pHead == nullptr && m_pTail == nullptr)
	{
		m_pHead = CreateNode(p_Data);
		m_pTail = m_pHead;
	}
	else
	{
		m_pTail->pNextNode = CreateNode(p_Data);
		m_pTail->pNextNode->pPrevNode = m_pTail;
		m_pTail = m_pTail->pNextNode;
	}
}


template<typename TData>
void JF::JFStudy::JFLinkedList<TData>::Remove(DLLNode* p_Node)
{
	auto prevNode = p_Data->pPrevNode;
	auto nextNode = p_Data->pNextNode;

	if (prevNode == nullptr)
		m_pHead = nextNode;
	else
		prevNode->pNextNode = nextNode;

	if (nextNode == nullptr)
		m_pTail = prevNode;
	else
		nextNode->pPrevNode = prevNode;

	Destroy(p_Node);
}