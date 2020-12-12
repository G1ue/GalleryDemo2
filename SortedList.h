#pragma once
#include <iostream>
using namespace std;
#define MAXSIZE 30

template <typename T>
class SortedList
{
private:
	T* m_Array;			// The list array.
	int m_Length;		// number of elements in list.
	int m_CurPointer;	// iterator pointer.
	int m_MaxSize;		// max size.

public:
	SortedList();	// default constructor.
	~SortedList();	// default destructor.

	/*
		@brief	Make the list empty.
		@pre	None.
		@post	Clear list.
	*/
	void MakeEmpty();

	/*
		@brief	Get a number of records in current list. cf) A record is a similar notion with a row.
		@pre	None.
		@post	None.
		@return	number of records in current list.
	*/
	int GetLength() const;

	/*
		@brief	Check if the capcity of the list is full or not.
		@pre	None.
		@post	None.
		@return	true if the list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull() const;

	/*
		@brief	Check if the list is empty or not.
		@pre	None.
		@post	None.
		@return true if the list is empty, otherwise return false.
	*/
	bool IsEmpty() const;

	/*
		@brief	Initialize the list iterator.
		@pre	The list should be initialized.
		@post	The iterator is reset.
	*/
	void ResetList();

	/*
		@brief	Move the list iterator to the next item in the list and copy that item in the parameter 'data'.
		@pre	The list and the list iterator should not be initialized.
		@post	The iterator is moved to the next item.
		@param	data	get current iterator's item. It does not need to be initialized.
		@return	the index of the current iterator's item if it is not the end of the list, otherwise return -1
	*/
	int GetNextItem(T& data);

	/*
		@brief	Add new record into the list in a sorted way.
		@pre	The list should be initialized.
		@post	Add the new record into the list.
		@param	indata	new data.
		@return	1 if this function works well, otherwise 0.
	*/
	int Add(const T& inData);

	/*
		@brief	Find a specific item in the list using sequential search.
		@pre	The file name of the parameter 'data' should exist in the list.
		@post	The found item in the list is inputted in the parameter 'data'.
		@param	data	ItemType value which has a filename that is found, copy the item.
		@return	1 if the function works well, otherwise return 0.
	*/
	int GetBySeqSearch(T& data);

	/*
		@brief	Delete a specific record in the list.
		@pre	The filename of the parameter 'data' should be in the list.
		@post	If the parameter 'data' is found in the list, that record will be deleted.
		@param	data	will be used to find out if the list has the data or not.
		@return 1 if the parameter 'data' is found in the list, otherwise return 0.
	*/
	int Delete(T data);

	/*
		@brief	If a record of the list has the same name with the parameter 'data',
				replace that record with the parameter 'data'.
		@pre	The filename of the parameter 'data' should be in the list.
		@post	If the parameter 'data' is found in the list, that record will be replaced.
		@param	data	will be used to figure out if the list has the record
						that has the same name with the parameter 'data' or not.
		@return	1 if a record of the list has the same name with the parameter 'data',
				otherwise return 0.
	*/
	int Replace(const T& data);


	/*
		@brief	Find a specific item in the list using binary search.
		@pre	None.
		@post	The found item in the list is inputted in the parameter 'indata'.
		@param	indata	ItemType value which has a filename that is found, copy the item.
		@return	1 if the function works well, otherwise return 0.
	*/
	int GetByBinarySearch(T& indata);
};

template<typename T>
SortedList<T>::SortedList()
{
	m_MaxSize = MAXSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

template<typename T>
SortedList<T>::~SortedList()
{
	// delete[] m_Array; 

	/**********************************************************************************************
	***************************This part should be reviewed again.*********************************
	**********************************************************************************************/
}

// Make the list empty.
template<typename T>
void SortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

// Get a number of records in current list. cf) A record is a similar notion with a row.
template<typename T>
int SortedList<T>::GetLength() const
{
	return m_Length;
}

// Check if the capcity of the list is full or not.
template<typename T>
bool SortedList<T>::IsFull() const
{
	if (m_Length > m_MaxSize - 1)
		return true;
	else
		return false;
}

// Check if the list is empty or not.
template<typename T>
bool SortedList<T>::IsEmpty() const
{
	if (m_Length == 0)
		return true;
	else
		return false;
}

// Initialize the list iterator.
template<typename T>
void SortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

// Move the list iterator to the next item in the list and copy that item in the parameter 'data'.
template<typename T>
int SortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

// Add new record into the list in a sorted way.
template<typename T>
int SortedList<T>::Add(const T& inData)
{
	if (IsFull()) return 0;		// return 0 if the list is full.

	if (IsEmpty()) {			// add in the first place of the list,
		m_Array[m_Length++] = inData;	// increment the length
		return 1;
	}

	bool found = false;
	int iPos = 0; // iPos is inData-inserting position 
	// Detect the place to insert inData (iPos)

	for (int i = 0; i < m_Length; i++) {
		if (m_Array[i] == inData) {
			return 0;	// fail to add
		}

		else if (m_Array[i] < inData) {
			continue;
		}
		// m_Array[i] > inData
		else {

			for (int j = m_Length; j > i; j--) {
				m_Array[j] = m_Array[j - 1];
			}
			m_Array[i] = inData;
			m_Length++;
			return 1;
		}
	}

	m_Array[m_Length] = inData;
	m_Length++;
	return 1;	// Success to add
}

// Find a specific item in the list using sequential search.
template<typename T>
int SortedList<T>::GetBySeqSearch(T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			data = m_Array[i];
			return 1;
		}
	}
	return 0;
}

// Delete a specific record in the list.
template<typename T>
int SortedList<T>::Delete(T data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			for (int j = i; j < m_Length - 1; j++)
			{
				m_Array[j] = m_Array[j + 1];
			}
			m_Length--;
			return 1;
		}
	}
	return 0;
}

// If a record of the list has the same name with the parameter 'data',
// replace that record with the parameter 'data'.
template<typename T>
int SortedList<T>::Replace(const T& data)
{
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i] == data)
		{
			m_Array[i] = data;
			return 1;
		}
	}
	return 0;
}

// Find a specific item in the list using binary search.
template<typename T>
int SortedList<T>::GetByBinarySearch(T& indata)
{
	if (m_Length == 0)	// If the array is  empty, 
		return 0;		// return 0.

	int currentPos = m_Length / 2;	// Start searching from the middle record in the list.
	while (1)
	{
		if (m_Array[currentPos] == indata) { // The item for searching is in the middle of the list.
			indata = m_Array[currentPos];
			return 1;
			break;
		}

		else if (m_Array[currentPos] > indata) {
			if (currentPos == 0) return 0; // The item for searching is not in the list.

			currentPos /= 2;	// Move the searching index.
			continue;
		}

		else if (m_Array[currentPos] < indata) {
			if (currentPos == m_Length - 1) return 0; //The item for searching is not in the list.

			currentPos = (currentPos + m_Length) / 2;
			continue;
		}

		return 0;
	}
}

