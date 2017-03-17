#include "pch.h"

/**
* Windows file handle implementation
**/
class JFFileHandleWindows : public JFFileHandle
{
	enum { READWRITE_SIZE = 1024 * 1024 };
	HANDLE FileHandle;

	FORCEINLINE int64 FileSeek(int64 Distance, uint32 MoveMethod)
	{
		LARGE_INTEGER li;
		li.QuadPart = Distance;
		li.LowPart = SetFilePointer(FileHandle, li.LowPart, &li.HighPart, MoveMethod);
		if (li.LowPart == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
		{
			li.QuadPart = -1;
		}
		return li.QuadPart;
	}
	FORCEINLINE bool IsValid()
	{
		return FileHandle != NULL && FileHandle != INVALID_HANDLE_VALUE;
	}

public:
	JFFileHandleWindows(HANDLE InFileHandle = NULL)
		: FileHandle(InFileHandle)
	{
	}
	virtual ~JFFileHandleWindows()
	{
		CloseHandle(FileHandle);
		FileHandle = NULL;
	}
	virtual int64 Tell() override
	{
		check(IsValid());
		return FileSeek(0, FILE_CURRENT);
	}
	virtual bool Seek(int64 NewPosition) override
	{
		check(IsValid());
		check(NewPosition >= 0);
		return FileSeek(NewPosition, FILE_BEGIN) != -1;
	}
	virtual bool SeekFromEnd(int64 NewPositionRelativeToEnd = 0) override
	{
		check(IsValid());
		check(NewPositionRelativeToEnd <= 0);
		return FileSeek(NewPositionRelativeToEnd, FILE_END) != -1;
	}
	virtual bool Read(uint8* Destination, int64 BytesToRead) override
	{
		check(IsValid());
		while (BytesToRead)
		{
			check(BytesToRead >= 0);
			int64 ThisSize = JFMath::Min<int64>(READWRITE_SIZE, BytesToRead);
			check(Destination);
			uint32 Result = 0;
			if (!ReadFile(FileHandle, Destination, uint32(ThisSize), (::DWORD *)&Result, NULL) || Result != uint32(ThisSize))
			{
				return false;
			}
			Destination += ThisSize;
			BytesToRead -= ThisSize;
		}
		return true;
	}
	virtual bool Write(const uint8* Source, int64 BytesToWrite) override
	{
		check(IsValid());
		while (BytesToWrite)
		{
			check(BytesToWrite >= 0);
			int64 ThisSize = JFMath::Min<int64>(READWRITE_SIZE, BytesToWrite);
			check(Source);
			uint32 Result = 0;
			if (!WriteFile(FileHandle, Source, uint32(ThisSize), (::DWORD *)&Result, NULL) || Result != uint32(ThisSize))
			{
				return false;
			}
			Source += ThisSize;
			BytesToWrite -= ThisSize;
		}
		return true;
	}
};