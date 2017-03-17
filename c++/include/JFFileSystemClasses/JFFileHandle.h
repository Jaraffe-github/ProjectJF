#pragma once

class JFFileHandle
{
//-----------------------------------------------------------------------------
// Basic Funtions
//-----------------------------------------------------------------------------
public:
	/** 파일을 닫을때는 소멸자를 사용한다. **/
	virtual ~JFFileHandle() {}

//-----------------------------------------------------------------------------
// Basic Funtions
//-----------------------------------------------------------------------------
public:
	/** 현재 가리키고있는 위치를 반환 **/
	virtual int64		Tell() = 0;

	/**
	* 현재 가리키고 있는 위치를 바꾼다.
	* @param NewPosition	새로운 위치.
	* @return				true = 성공
	**/
	virtual bool		Seek(int64 NewPosition) = 0;

	/**
	* 파일의 끝을 기준으로 현재 가리키고있는 위치를 바꾼다.
	* @param NewPositionRelativeToEnd	끝에서 몇번째 부분을 가리킬지.
	* @return							true = 성공
	**/
	virtual bool		SeekFromEnd(int64 NewPositionRelativeToEnd = 0) = 0;

	/**
	* 파일을 지정 Byte 만큼 읽는다.
	* @param Destination	읽을 파일의 버퍼. 최소 BytesToRead 만큼의 크기가 있어야한다.
	* @param BytesToRead	Destination 에서 Byte 만큼 읽는다.
	* @return				true = 성공
	**/
	virtual bool		Read(uint8* Destination, int64 BytesToRead) = 0;

	/**
	* 지정 Bytea만큼을 파일에 쓴다.
	* @param Source			지정 버퍼를 파일에 쓴다. 최소 BytesToWrite 만큼의 크기가 있어야한다.
	* @param BytesToWrite	지정 크기만큼 파일에 쓴다.
	* @return				true = 성공
	**/
	virtual bool		Write(const uint8* Source, int64 BytesToWrite) = 0;

//-----------------------------------------------------------------------------
// Utility Functions. Only Vitual Function
//-----------------------------------------------------------------------------
public:
	/** 파일의 크기를 반환한다. **/
	virtual int64		Size();
};