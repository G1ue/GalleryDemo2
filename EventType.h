#pragma once
#include <string>
#include "SortedList.h"

using namespace std;

// The event management class
class EventType
{
private:
	string EventName;					// the name of the event.
	int num;							// multimedia contents number in the event.
	SortedList<string> FileNameList;	// filename list, all filename in the list has the same event name.

public:

	//default constuctor.
	EventType()
	{
		EventName = "";
		num = 0;
		FileNameList.ResetList();
	}

	//destructor
	~EventType() {}

	/*
		@brief	Get the event name.
		@pre	The event name is set.
		@post	None.
		@return the event name.
	*/
	string GetEventName() const;

	/*
		@brief	Get the total multimedia contents number.
		@pre	The number is set.
		@post	None.
		@return the total multimedia contents number in the filenamelist.
	*/
	int GetNum() const;

	/*
		@brief	Set the event name.
		@pre	None.
		@post	The event name is set.
		@param	inName	the event name
	*/
	void SetEventName(string inName);

	/*
		@brief	Add the content filename in the list.
		@pre	None.
		@post	The filename list is set.
		@param	inFD	being added to the filename list
	*/
	void AddContentFileNameintheList(string inFN);

	/*
		@brief	Add the num
		@pre	None.
		@post	num = num+1
	*/
	void AddNum();

	/*
	@brief	Subtract the num
	@pre	None.
	@post	num = num-1
	*/
	void SubtractNum();

	/*
		@brief	Delete the content filename in the list.
		@pre	None.
		@post	The filename list is set.
		@param	inFD	being deleted in the filename list
	*/
	void DeleteContentFileNameintheList(string inFN);

	/*
		@brief	Return the filenamelist.
		@pre	None.
		@post	Return the filename list.
		@return FileNameList.
	*/
	SortedList<string> getFileNameList() const;

	bool operator==(const EventType& A) {
		if (EventName == A.GetEventName()) //primary key in the eventlist is the eventname.
			return true;
		return false;
	}

	bool operator >(const EventType& A) {
		if (EventName > A.GetEventName())
			return true;
		return false;
	}

	bool operator <(const EventType& A) {
		if (EventName < A.GetEventName())
			return true;
		return false;
	}
};


