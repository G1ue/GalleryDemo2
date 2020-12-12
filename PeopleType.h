#pragma once
#include <string>

#include "SortedList.h"

using namespace std;

// people managing class
class PeopleType
{
private:
	string Person;					// the name of a person
	int num;						// multimedia contents number
	SortedList<string> FileNameList;// filename list, all filename in the list has the same person's name.

public:

	//default constuctor.
	PeopleType()
	{
		Person = "";
		num = 0;
		FileNameList.ResetList();
	}

	//destructor
	~PeopleType() {}

	/*
		@brief	Get the person's name.
		@pre	The person is set.
		@post	None.
		@return the person.
	*/
	string GetPerson() const;

	/*
		@brief	Get the total multimedia contents number.
		@pre	The number is set.
		@post	None.
		@return the total multimedia contents number in the filename list.
	*/
	int GetNum() const;

	/*
		@brief	Set the person's name.
		@pre	None.
		@post	The person is set.
		@param	inName	person
	*/
	void SetPerson(string inName);

	/*
		@brief	Add the content filename in the list.
		@pre	None.
		@post	The filename list is set.
		@param	inFN	being added to the filename list
	*/
	void AddContentFileNameintheList(string inFN);

	/*
		@brief	Add the num
		@pre	None.
		@post	num = num+1;
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
		@brief	Return the filenamelist of the people type.
		@pre	None.
		@post	Return the filename list.
		@return FileNameList.
	*/
	SortedList<string> getFileNameList() const;

	bool operator==(const PeopleType& A) {
		if (Person == A.GetPerson())
			return true;
		return false;
	}

	bool operator >(const PeopleType& A) {
		if (Person > A.GetPerson())
			return true;
		return false;
	}

	bool operator <(const PeopleType& A) {
		if (Person < A.GetPerson())
			return true;
		return false;
	}
};

