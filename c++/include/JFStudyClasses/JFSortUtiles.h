#pragma once

#include <queue>

namespace JF
{
	namespace JFSortUtiles
	{
		//----------------------------------------------------------------------------
		// Sort Utile 
		//----------------------------------------------------------------------------
		template<typename TData>
		void Swap(TData* p_pA, TData* p_pB)
		{
			TData temp = *p_pA;
			*p_pA = *p_pB;
			*p_pB = temp;
		}

		//----------------------------------------------------------------------------
		// BubbleSort
		//----------------------------------------------------------------------------
		template<typename TData>
		void BubbleSort(TData p_sortData[], int p_nLength)
		{
			bool isSwap = false;
			for (int i = 0; i < p_nLength - 1; ++i)
			{
				isSwap = false;
				for (int j = 0; j < p_nLength - (i+1); ++j)
				{
					if (p_sortData[j] > p_sortData[j+1])
					{
						Swap(&p_sortData[j], &p_sortData[j + 1]);

						isSwap = true;
					}
				}

				if (isSwap == false)
					return;
			}
		}

		//----------------------------------------------------------------------------
		// InsertionSort
		//----------------------------------------------------------------------------
		template<typename TData>
		void InsertionSort(TData p_sortData[], int p_nLength)
		{
			TData temp;
			for (int i = 1; i < p_nLength; ++i)
			{
				if(p_sortData[i-1] <= p_sortData[i])
					continue;

				temp = p_sortData[i];

				for (int j = 0; j < i; ++j)
				{
					if (p_sortData[j] > temp)
					{
						memmove(&p_sortData[j+1], &p_sortData[j], sizeof(p_sortData[0]) * (i-j));
						p_sortData[j] = temp;
						break;
					}
				}
			}
		}

		//----------------------------------------------------------------------------
		// QuickSort
		//----------------------------------------------------------------------------
		template<typename TData>
		void QuickSort(TData p_SortData[], int p_nLeft, int p_nRight)
		{
			struct PartitionData
			{
				PartitionData(int p_nPivot, int p_nLeft, int p_nRight)
					: nPivot(p_nPivot), nLeft(p_nLeft), nRight(p_nRight) {}

				int nPivot;
				int nLeft;
				int nRight;
			};

			// First partition calculation.
			int nIndex = Partition(p_SortData, p_nLeft, p_nRight);

			// partition calculation Loop.
			std::queue<PartitionData> pivotList;
			pivotList.push(PartitionData(nIndex, p_nLeft, p_nRight));
			while (pivotList.size() != 0)
			{
				PartitionData* data = &pivotList.front();

				int leftPivot = data->nPivot - 1;
				if (data->nLeft < leftPivot)
					pivotList.push(PartitionData(Partition(p_SortData, p_nLeft, leftPivot), data->nLeft, leftPivot));

				int rightPivot = data->nPivot + 1;
				if (data->nRight > rightPivot)
					pivotList.push(PartitionData(Partition(p_SortData, rightPivot, p_nRight), rightPivot, data->nRight));

				pivotList.pop();
			}

			//qsort((void*)p_SortData, p_nRight + 1, sizeof(p_SortData[0]), CompareScore);
		}

		template<typename TData>
		int Partition(TData p_SortData[], int p_nLeft, int p_nRight)
		{
			TData* pivot = nullptr;

			// Find 3 numbering middle value ( 3 numbering sort )
			if ((p_nLeft + 2) <= p_nRight)
			{
				bool isSwap = false;
				for (int i = 0; i < 2; ++i)
				{
					isSwap = false;
					for (int j = 0; j < 2-i; ++j)
					{
						if (p_SortData[p_nLeft+j] > p_SortData[p_nLeft+j+ 1])
						{
							Swap(&p_SortData[p_nLeft+j], &p_SortData[p_nLeft+j+1]);

							isSwap = true;
						}
					}

					if (isSwap == false)
						break;
				}

				pivot = &p_SortData[p_nLeft+1];
				p_nLeft += 2;
			}
			else
			{
				pivot = &p_SortData[p_nLeft];
				++p_nLeft;
			}

			// Sort
			while ( p_nLeft <= p_nRight )
			{
				while (p_SortData[p_nLeft] <= *pivot && p_nLeft < p_nRight)
					++p_nLeft;

				while (p_SortData[p_nRight] > *pivot && p_nLeft <= p_nRight)
					--p_nRight;

				if (p_nLeft < p_nRight)
					Swap(&p_SortData[p_nLeft], &p_SortData[p_nRight]);
				else
					break;
			}

			Swap(pivot, &p_SortData[p_nRight]);

			return p_nRight;
		}

		int CompareScore(const void* p_pA, const void* p_pB)
		{
			int* a = (int*)p_pA;
			int* b = (int*)p_pB;

			if (*a > *b)
				return 1;
			else if (*a < *b)
				return -1;
			else
				return 0;
		}
	}
}