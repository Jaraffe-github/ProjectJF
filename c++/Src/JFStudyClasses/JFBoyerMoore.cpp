#include "JFBoyerMoore.h"
#include "malloc.h"

int JF::JFStudy::BoyerMoore( char* _pText,  int _nTextSize,  int _nStart,  char* _pPattern,  int _nPatternSize)
{
	int nBCT[128];
	int* pSuffix = (int*)calloc(_nPatternSize + 1, sizeof(int));
	int* pGST = (int*)calloc(_nPatternSize + 1, sizeof(int));
	int i = _nStart;
	int j = 0;

	int nPosition = -1;

	BuildBCT(_pPattern, _nPatternSize, nBCT);
	BuildGST(_pPattern, _nPatternSize, pSuffix, pGST);

	while (i <= _nTextSize - _nPatternSize)
	{
		j = _nPatternSize -1;

		while (j >= 0 && _pPattern[j] == _pText[i + j])
			--j;

		if (j < 0)
		{
			nPosition = i;
			break;
		}
		else
		{
			i += Max(pGST[j + i], j - nBCT[_pText[i + j]]);
		}
	}

	free(pSuffix);
	free(pGST);

	return nPosition;
}

void JF::JFStudy::BuildBCT( char* _pPattern,  int _nPatternSize,  int* _pBCT)
{
	for (int i = 0; i < 128; ++i)
		_pBCT[i] = -1;

	for (int j = 0; j < _nPatternSize; ++j)
		_pBCT[_pPattern[j]] = j;
}

void JF::JFStudy::BuildGST( char* _pPattern,  int _nPatternSize,  int* _pSuffix,  int* _pGST)
{
	// Case 1
	int i = _nPatternSize;
	int j = _nPatternSize + 1;

	_pSuffix[i] = j;

	while (i > 0)
	{
		while (j <= _nPatternSize && _pPattern[i - 1] != _pPattern[j - 1])
		{
			if (_pGST[j] == 0)
				_pGST[j] = j - i;

			j = _pSuffix[j];
		}

		--i;
		--j;

		_pSuffix[i] = j;
	}

	// case 2
	j = _pSuffix[0];

	for (int i = 0; i <= _nPatternSize; ++i)
	{
		if (_pGST[i] == 0)
			_pGST[i] = j;

		if (i == j)
			j = _pSuffix[j];
	}
}

int JF::JFStudy::Max( int _nA,  int _nB)
{
	if (_nA > _nB)
		return _nA;
	else
		return _nB;
}