#pragma once

class JFFileHandle
{
//-----------------------------------------------------------------------------
// Basic Funtions
//-----------------------------------------------------------------------------
public:
	/** ������ �������� �Ҹ��ڸ� ����Ѵ�. **/
	virtual ~JFFileHandle() {}

//-----------------------------------------------------------------------------
// Basic Funtions
//-----------------------------------------------------------------------------
public:
	/** ���� ����Ű���ִ� ��ġ�� ��ȯ **/
	virtual int64		Tell() = 0;

	/**
	* ���� ����Ű�� �ִ� ��ġ�� �ٲ۴�.
	* @param NewPosition	���ο� ��ġ.
	* @return				true = ����
	**/
	virtual bool		Seek(int64 NewPosition) = 0;

	/**
	* ������ ���� �������� ���� ����Ű���ִ� ��ġ�� �ٲ۴�.
	* @param NewPositionRelativeToEnd	������ ���° �κ��� ����ų��.
	* @return							true = ����
	**/
	virtual bool		SeekFromEnd(int64 NewPositionRelativeToEnd = 0) = 0;

	/**
	* ������ ���� Byte ��ŭ �д´�.
	* @param Destination	���� ������ ����. �ּ� BytesToRead ��ŭ�� ũ�Ⱑ �־���Ѵ�.
	* @param BytesToRead	Destination ���� Byte ��ŭ �д´�.
	* @return				true = ����
	**/
	virtual bool		Read(uint8* Destination, int64 BytesToRead) = 0;

	/**
	* ���� Bytea��ŭ�� ���Ͽ� ����.
	* @param Source			���� ���۸� ���Ͽ� ����. �ּ� BytesToWrite ��ŭ�� ũ�Ⱑ �־���Ѵ�.
	* @param BytesToWrite	���� ũ�⸸ŭ ���Ͽ� ����.
	* @return				true = ����
	**/
	virtual bool		Write(const uint8* Source, int64 BytesToWrite) = 0;

//-----------------------------------------------------------------------------
// Utility Functions. Only Vitual Function
//-----------------------------------------------------------------------------
public:
	/** ������ ũ�⸦ ��ȯ�Ѵ�. **/
	virtual int64		Size();
};