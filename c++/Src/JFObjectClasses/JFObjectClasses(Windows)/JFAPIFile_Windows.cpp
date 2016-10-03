#include "pch.h"

FILE_HANDLE JFAPI::FILE::Open(const wchar_t* _FileName, eFILE_OPERATION _Operation, eFILE_LOCATION _FileLocation)
{
	// Check)
	assert(_FileName != nullptr);

	// Check) _FileName�� nullptr�̸� �ȉ´�.
	RETURN_IF(_FileName == nullptr, INVALID_FILE_HANDLE);

	// Declare) 
	DWORD dwDesiredAccess;
	DWORD dwShareMode;
	DWORD dwCreationDisposition;
	DWORD dwFlagsAndAttributes;

	switch (_Operation)
	{
	case	eFILE_OPERATION::READ:
	{
		dwDesiredAccess			= GENERIC_READ;
		dwShareMode				= FILE_SHARE_READ;
		dwCreationDisposition	= OPEN_EXISTING;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL;
	}
	break;

	case	eFILE_OPERATION::WRITE:
	{
		dwDesiredAccess			= GENERIC_WRITE;
		dwShareMode				= FILE_SHARE_WRITE;
		dwCreationDisposition	= CREATE_NEW;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL;
	}
	break;

	case	eFILE_OPERATION::APPEND:
	{
		dwDesiredAccess			= GENERIC_WRITE | GENERIC_READ;
		dwShareMode				= FILE_SHARE_WRITE;
		dwCreationDisposition	= CREATE_ALWAYS;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL;
	}
	break;

	case	eFILE_OPERATION::READ_ASYNC:
	{
		dwDesiredAccess			= GENERIC_READ;
		dwShareMode				= FILE_SHARE_READ;
		dwCreationDisposition	= OPEN_EXISTING;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED;
	}
	break;

	case	eFILE_OPERATION::WRITE_ASYNC:
	{
		dwDesiredAccess			= GENERIC_WRITE;
		dwShareMode				= FILE_SHARE_WRITE;
		dwCreationDisposition	= CREATE_NEW;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED;
	}
	break;

	case	eFILE_OPERATION::APPEND_ASYNC:
	{
		dwDesiredAccess			= GENERIC_WRITE | GENERIC_READ;
		dwShareMode				= FILE_SHARE_WRITE;
		dwCreationDisposition	= CREATE_ALWAYS;
		dwFlagsAndAttributes	= FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED;
	}
	break;

	default:
		assert(false);
		throw;
		break;
	}

	// Declare) 
	FILE_HANDLE	hFile = INVALID_FILE_HANDLE;

	// 2) ���� Directory���� ã�´�.
	if ((_FileLocation & eFILE_LOCATION::NOW) != eFILE_LOCATION::NONE)
	{
		hFile = CreateFileW(_FileName, dwDesiredAccess, dwShareMode, nullptr, dwCreationDisposition, dwFlagsAndAttributes, 0);
	}

	// Return) ��� ����~
	return	hFile;
}

FILE_HANDLE JFAPI::FILE::Open(const char* _FileName, eFILE_OPERATION _Operation, eFILE_LOCATION _FileLocation)
{
	// Declare) 
	wchar_t temp[1024];

	// 1) ���ڿ��� Converting�Ѵ�.
	CONVERT_STRING(_FileName, temp);

	// 2) Open
	return	JFAPI::FILE::Open(temp, _Operation, _FileLocation);
}

//// 2) Executor�� ���δ�.
//CGPTR<CGExecutor::CCompletionPort>	pExecutor	 = CGExecutor::Default::GetInstance()->Executor();
//
//// 3) Executor�� �����Ѵ�.(�����ϸ� �⺻ Executor�� �����Ѵ�.)
//bResult	 = pExecutor->Attach(hFile);
//
//// Check) File Time�� ���� ���ϸ� �ǵ�����.
//RETURN_IF(bResult==false, false);

void JFAPI::FILE::Close(FILE_HANDLE _hFile)
{
	// Check) FileHandle�� INVALID_FILE_HANDLE�̸� �ȉ´�.
	RETURN_IF(_hFile == INVALID_FILE_HANDLE, );

	// 1) Close�Ѵ�.
	CloseHandle(_hFile);
}

size_t JFAPI::FILE::Read(FILE_HANDLE _hFile, size_t _size, void* _Data)
{
	// Check) Debug�� ���� �߸��� ���� �˻�.
	assert(_hFile != INVALID_FILE_HANDLE);

	// Check)
	RETURN_IF(_hFile == INVALID_FILE_HANDLE, 0);

	// Declare) 
	size_t	dwData = 0;

	// 1) Read�Ѵ�.
	auto	result = ::ReadFile(_hFile, _Data, static_cast<DWORD>(_size), (LPDWORD)&dwData, NULL);

	// Check) �б⿡ ���������� 0�� �����Ѵ�.
	RETURN_IF(result == FALSE, 0);

	// Return) ���� Byte���� return�Ѵ�.
	return	dwData;
}

size_t JFAPI::FILE::Write(FILE_HANDLE _hFile, size_t _size, const void* _Data)
{
	// Check) Debug�� ���� �߸��� ���� �˻�.
	assert(_hFile != INVALID_FILE_HANDLE);

	// Check)
	RETURN_IF(_hFile == INVALID_FILE_HANDLE, 0);

	// Declare) 
	size_t	dwData = 0;

	// 1) Read�Ѵ�.
	auto	result = ::WriteFile(_hFile, _Data, static_cast<DWORD>(_size), (LPDWORD)&dwData, NULL);

	// Check) �б⿡ ���������� 0�� �����Ѵ�.
	RETURN_IF(result == FALSE, 0);

	// Return) ���� Byte���� return�Ѵ�.
	return	dwData;
}

size_t JFAPI::FILE::Seek(FILE_HANDLE _hFile, size_t _Offset, eFILE_ORIGIN _Origin)
{
	// Check) 
	RETURN_IF(_hFile == INVALID_FILE_HANDLE, 0);

	// 1) File Pointer�� �����Ѵ�.
	auto	result = SetFilePointer(_hFile, static_cast<long>(_Offset), nullptr, (DWORD)_Origin);

	// Return) 
	return	result;
}

size_t JFAPI::FILE::GetLength(FILE_HANDLE _hFile)
{
	// Check) 
	RETURN_IF(_hFile == INVALID_FILE_HANDLE, 0);

	// Return)
	return	GetFileSize(_hFile, nullptr);
}