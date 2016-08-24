#pragma once

namespace JF
{
	namespace JFSearchUtiles
	{
		//----------------------------------------------------------------------------
		// BinarySearch
		//----------------------------------------------------------------------------
		template<typename TData, typename TTarget>
		TData* BinarySearch(_Inout_ TData _SourceList[], _In_ int _nSize, _In_ TTarget _Target)
		{
			int nLeft	= 0;
			int nRight	= _nSize - 1;
			int nMid	= 0;

			while (nLeft <= nRight)
			{
				nMid = (nLeft + nRight) / 2;

				if (_SourceList[nMid] == _Target )
					return &_SourceList[nMid];
				else if (_SourceList[nMid] < _Target)
					nLeft = nMid + 1;
				else
					nRight = nMid - 1;
			}

			return nullptr;

			// bsearch();
		}
	}
}