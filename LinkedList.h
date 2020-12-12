#pragma once

using namespace std;

/*
	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;				// A data for each node.
	NodeType* next;		// A node pointer to point succeeding node.
};

// Simple sorted list class for managing items.
template <typename T>
class LinkedList
{
public:
	LinkedList();	//default constructor
	~LinkedList();	//destructor

	/*
		@brief	Initialize list to empty state.
		@pre	None
		@post	List is empty.
	*/
	void MakeEmpty();

	/*
		@brief	Get number of elements in the list.
		@pre	None.
		@post	Function value = number of elements in list.
		@return	Number of elements in this list.
	*/
	int GetLength() const;

	/*
		@brief	Add item into appropriate spot of this sorted list
		@pre	List is not full. item is not in the list.
		@post	Item is inserted in this list.
		@return	1 if this function works well, otherwise 0.
	*/
	int Add(T item);

	/*
		@brief	Delete item from this list.
		@pre	List is not empty. the item exists in list.
		@post	Item is deleted from this list.
		@return	1 if this function works well, otherwise 0.
	*/
	int Delete(T item);

	/*
		@brief	Change value of item which is in this list.
		@pre	List is not empty. the item exists in list.
		@post	Item's value is changed.
		@return	1 if this function works well, otherwise 0.
	*/
	int Replace(T item);

	/*
		@brief	Retrieve list element whose key matches item's key (if present).
		@pre	Key member of item is initialized.
		@post	If there is an element whose key matches with item's key then the element's record is copied to the item.
		@param	item	being copied with the matched item
		@return	1 if any element's primary key matches with item's, otherwise 0.
	*/
	int Get(T& item);

	/*
		@brief	Initialize current pointer for an iteration through the list.
		@pre	None.
		@post	current pointer is prior to list. current pointer has been initialized.
	*/
	void ResetList();

	/*
		@brief	Get the next element in list.
		@pre	current pointer is defined. Element at current pointer is not last in list.
		@post	current pointer is updated to next position. item is a copy of element at current pointer.
		@param	item	a copy of the next element in the list.
	*/
	void GetNextItem(T& item);

private:
	NodeType<T>* m_pList; // Pointer for pointing the first node.
	NodeType<T>* m_pCurPointer; // Node pointer for poining current node to use iteration.
	int m_nLength; // Number of node in the list.
};

// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = nullptr;
	m_pCurPointer = nullptr;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	MakeEmpty(); // Erase all nodes in the list.
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
{
	NodeType<T>* tempPtr;

	while (m_pList != nullptr)
	{
		tempPtr = m_pList;   // Make 'tempPtr' that points to the first node.
		m_pList = m_pList->next; // Move the first node to the next.
		delete tempPtr; // Delete the 'tempPtr'.
	}

	m_nLength = 0; // Initialize the length of the list.
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// Add item into this list.
template <typename T>
int LinkedList<T>::Add(T item)
{
	ResetList(); // Initialize the first pointer.


	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	T dummy;
	bool bFound = false;

	node->data = item;
	node->next = nullptr;

	if (!m_nLength) // There is no node in the list.
	{
		m_pList = node;
	}

	else
	{
		while (1)
		{
			pre = m_pCurPointer;

			GetNextItem(dummy);

			if (m_pCurPointer->data > node->data)
			{
				if (pre == nullptr)
				{
					node->next = m_pCurPointer;
					m_pList = node;
					break;
				}
				node->next = m_pCurPointer;
				pre->next = node;
				break;
			}

			if (m_pCurPointer->next == nullptr)
			{
				m_pCurPointer->next = node; // Combine the last node with the first node.
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}

//Delete item from this list.
template <typename T>
int LinkedList<T>::Delete(T item)
{
	bool moreToSearch, found;
	NodeType<T>* pre = nullptr;

	m_pCurPointer = m_pList;
	found = false;
	moreToSearch = (m_pCurPointer != nullptr);

	while (moreToSearch && !found)
	{
		if (item == m_pCurPointer->data)
		{
			found = true;
			if (pre == nullptr)
				m_pList = m_pCurPointer->next;
			else
			{
				pre->next = m_pCurPointer->next;
				delete m_pCurPointer;
			}
			m_nLength--;
		}
		else
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != nullptr);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

//Change value of item which is in this list.
template <typename T>
int LinkedList<T>::Replace(T item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			location->data = item;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != nullptr);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != nullptr);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}

// Initializes current pointer for an iteration through the list.
template <typename T>
void LinkedList<T>::ResetList()
{
	m_pCurPointer = nullptr;
}


// Gets the next element in list.
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{

	if (m_pCurPointer == nullptr)
	{
		m_pCurPointer = m_pList;
	}
	else

		m_pCurPointer = m_pCurPointer->next;

	item = m_pCurPointer->data;
}

