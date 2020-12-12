#pragma once
#include "sortedList.h"
#include "UnsortedList.h"
#include "LinkedList.h"

#include "ItemType.h"
#include "SpecialType.h"

#include "DateType.h"

#include "EventType.h"
#include "PeopleType.h"
#include "PlaceType.h"


using namespace std;

class Application
{
private:

	int m_Command;								//current command number

	SortedList<ItemType> m_ContentsList;		// multimedia contents list.

	UnsortedList<SpecialType> m_FavoriteList1;	// favorite contents list (image)
	UnsortedList<SpecialType> m_FavoriteList2;	// favorite contents list (video)

	LinkedList<DateType> m_DateList;			// Date grouping list.

	LinkedList<EventType> m_EventList;			// Events grouping list.
	LinkedList<PeopleType> m_PersonList;		// Person grouping list.
	LinkedList<PlaceType> m_PlaceList;			// Place grouping list.

public:


	Application();		//	default constructor.
	~Application();		//	destructor.


	/*
		@brief	The program driver.
		@pre	The program is started.
		@post	The program is finished.
	*/
	void Run();


	/*
		@brief	Display commands on the screen and get a input from keyboard.
		@pre	None.
		@post	None.
		@return	user's command.
	*/
	int GetCommand();


	/*
		@brief	Add a new record into the contents list and the event list.
		@pre	The list should be initialized.
		@post	New record is added into the list.
		@return	1 if the function works well, otherwise return 0.
	*/
	int AddContents();

	/*
		@brief	Display all records in the list on the screen.
		@pre	None.
		@post	None.
	*/
	void DisplayAllContents();


	/*
		@brief	Get the file name from the keyboard, and delete that contents' record in the list.
		@pre	The file name from the keyboard should be in the list.
		@post	Delete the certain item.
	*/
	void DeleteContents();

	/*
		@brief	Delete all items.
		@pre	None.
		@post	All lists become empty.
	*/
	void DeleteAllContents();


	/*
		@brief	Find the item that has the specific filename in the list, through the binary search.
		@pre	None.
		@post	Display the found item.
		@return	1 for success, otherwise return 0.
	*/
	int SearchByFileName_BinaryS();


	/*
		@brief	Add a record of the the contents list into the favorite list.
		@pre	Input item from the keyboard should be in the contents list.
		@post	Show the input item from the keyboard.
	*/
	void AddFavoriteItem();


	/*
		@brief	Delete a record in the favorite list.
		@pre	The filename from the keyboard should be in the favorite list.
		@Post	The record is deleted.
	*/
	void DeleteFavoriteItem();

	/*
		@brief	Delete all records in the favorite list.
		@pre	None.
		@post	m_FavoriteList1 and m_FavoriteList2 become empty.
	*/
	void DeleteAllFavoriteItems();

	/*
		@brief	Print all items in the favorite list.
		@pre	None.
		@post	None.
	*/
	void PrintAllFavoriteItems();

	/*
		@brief	Add the content in the date list.
		@pre	the date is set.
		@post	the file is added in the date list.
		@param	inD	date
		@return the file name -> YYYYMMDD_i   ex) "20201024_1"
	*/
	string AddContentInDateList(unsigned long inD);

	/*
		@brief	Add the content in the event list.
		@pre	the event name and the file name are set.
		@post	the file is added in the event list.
		@param	inEN	eventname
				inFN	filename
	*/
	void AddContentInEventList(string inEN, string inFN);

	/*
		@brief	Get the event name from the keyboard and show the detail information of the filename list.
		@pre	None.
		@post	Display the contents information if the event name is in the eventlist.
	*/
	void FindNDisplayEvent();

	/*
		@brief	Add the content in the person list.
		@pre	the person and the file name are set.
		@post	the file is added in the person list.
		@param	inPN	person(name)
				inFN	filename
	*/
	void AddContentInPersonList(string inPN, string inFN);

	/*
		@brief	Get the person's name from the keyboard and show the detail information of the filename list.
		@pre	None.
		@post	Display the contents information if the person name is in the personlist.
	*/
	void FindNDisplayPerson();

	/*
		@brief	Add the content in the place list.
		@pre	the name of the place and the file name are set.
		@post	the file is added in the place list.
		@param	inPN	placename
				inFN	filename
	*/
	void AddContentInPlaceList(string inPN, string inFN);

	/*
		@brief	Get the name of the place from the keyboard and show the detail information of the filename list.
		@pre	None.
		@post	Display the contents information if the name of the place is in the placelist.
	*/
	void FindNDisplayPlace();

	/*
		@brief	Get the event name and the person's name from the keyboard and show all contents that match both.
		@pre	None.
		@post	Display the information of contents that match both input-event name and input-person's name
				in the m_ContentsList.
	*/
	void FindNDisplayByEventAndPerson();

	/*
		@brief	Delete the content in the event list.
		@pre	The input parameter 'inFN' should exist in the m_ContentsList.
		@post	The file is deleted in the event list.
		@param	inEN	eventname
				inFN	filename
	*/
	void DeleteContentInEventList(string inEN, string inFN);

	/*
		@brief	Delete the content in the person list.
		@pre	The input parameter 'inFN' should exist in the m_ContentsList.
		@post	The file is deleted in the person list.
		@param	inPN	person(name)
				inFN	filename
	*/
	void DeleteContentInPersonList(string inPN, string inFN);

	/*
		@brief	Delete the content in the place list.
		@pre	The input parameter 'inFN' should exist in the m_ContentsList.
		@post	The file is deleted in the place list.
		@param	inPN	placename
				inFN	filename
	*/
	void DeleteContentInPlaceList(string inPN, string inFN);
};


