#pragma once

#define MAXSIZE 30

template <typename T>
class UnsortedList
{
private:
	T* m_Array;			// list array.
	int m_Length;		// number of elements in list.
	int m_CurPointer;	// iterator pointer.
	int m_MaxSize;		// max size.

public:
	UnsortedList();		//default constructor
	~UnsortedList();	//default destructor

	/*
		@brief	Make the list empty.
		@pre	None.
		@post	None.
	*/
	void MakeEmpty();

	/*
		@brief	Get the length of the list.
		@pre	None.
		@post	None.
		@return m_Length
	*/
	int GetLength();

	/*
		@brief	Check if the list is full or not.
		@pre	None.
		@post	None.
		@return	true if the list is full, otherwise return 0.
	*/
	bool IsFull();

	/*
		@brief  Initialize the pointer.
		@pre	None.
		@post	None.
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
		@brief	Add a new data into the list.
		@pre	The list should be initialized.
		@post	Add the new record into the list.
		@param	inData	new data.
		@return	1 if this function works well, otherwise 0.
	*/

	int Add(const T& inData);

	/*
		@brief	Get the index of the parameter 'data' in the list.
		@pre	The list should not be initialized.
		@post	From the beginning, the iterator's item will be checked
				until that item becomes the same with the paramter 'data'.
		@param	data	will be used during checking process.
		@return	the index of the param 'data' if the list has it, otherwise return -1.
	*/
	int Get(T& data);

	/*
		@brief	Delete a specific record in the list.
		@pre	The list should not be initialized.
		@post	If the parameter 'data' is found in the list, that record will be deleted.
				Otherwise, the last record will be deleted.
		@param	data	will be used to find out if the list has the data or not.
		@return 1 if the parameter 'data' is found in the list, otherwise return -1.
	*/
	int Delete(T data);

	/*
		@brief	If a record of the list has the same id with the parameter 'data',
				replace the name and the address of that record
				with the name and the address of the parameter 'data'.
		@param	data	will be used to figure out if the list has the record
						that has the same id with the parameter 'data' or not.
		@return	1 if a record of the list has the same id with the parameter 'data',
				otherwise return 0.
	*/
	int Replace(const T& data);
};

// default constructor
template<typename T>
inline UnsortedList<T>::UnsortedList()
{
	m_MaxSize = MAXSIZE;
	m_Length = 0;
	ResetList();
	m_Array = new T[m_MaxSize];
}

//default destructor
template<typename T>
inline UnsortedList<T>::~UnsortedList()
{
	delete[] m_Array;
}

// Make the list empty.
template<typename T>
inline void UnsortedList<T>::MakeEmpty()
{
	m_Length = 0;
}

// Get the length of the list.
template<typename T>
inline int UnsortedList<T>::GetLength()
{
	return m_Length;
}

// Check if the list is full or not.
template<typename T>
inline bool UnsortedList<T>::IsFull()
{
	if (m_Length > m_MaxSize - 1)
		return true;
	else
		return false;
}

// Initialize the pointer.
template<typename T>
inline void UnsortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

// Move the list iterator to the next item in the list and copy that item in the parameter 'data'.
template<typename T>
inline int UnsortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;
	if (m_CurPointer == m_Length)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

// Add a new data into the list.
template<typename T>
inline int UnsortedList<T>::Add(const T& inData)
{
	if (!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}

// Get the index of the parameter 'data' in the list.
template<typename T>
inline int UnsortedList<T>::Get(T& data)
{
	for (m_CurPointer = 0; m_CurPointer < m_Length; m_CurPointer++)
	{
		if (data == m_Array[m_CurPointer])
		{

			return m_CurPointer;
		}
	}
	return -1;
}

// Delete a specific record in the list.
template<typename T>
inline int UnsortedList<T>::Delete(T data)
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

// If a record of the list has the same id with the parameter 'data',
// replace the nameand the address of that record
// with the nameand the address of the parameter 'data'.
template<typename T>
inline int UnsortedList<T>::Replace(const T& data)
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
