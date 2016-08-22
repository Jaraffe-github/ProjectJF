#pragma once

namespace JF
{
	namespace JFSortUtiles
	{
		//----------------------------------------------------------------------------
		// BubbleSort
		//----------------------------------------------------------------------------
		template<typename TData>
		void BubbleSort(TData p_sortData[], int p_nLength)
		{
			int temp;
			bool isSwap = false;
			for (int i = 0; i < p_nLength - 1; ++i)
			{
				isSwap = false;
				for (int j = 0; j < p_nLength - (i+1); ++j)
				{
					if (p_sortData[j] > p_sortData[j+1])
					{
						temp = p_sortData[j+1];
						p_sortData[j+1] = p_sortData[j];
						p_sortData[j] = temp;

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
			int temp;
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
	}
}