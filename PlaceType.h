#pragma once
#include <string>
#include "SortedList.h"

using namespace std;

// place management class
class PlaceType
{
private:
	string PlaceName;				// the name of a place
	int num;						// multimedia contents number
	SortedList<string> FileNameList;// filename list, all filename in the list has the same name of the place. 

public:

	//default constuctor
	PlaceType()
	{
		PlaceName = "";
		num = 0;
		FileNameList.ResetList();
	}

	//destructor
	~PlaceType() {}

	/*
		@brief	Get the name of the place.
		@pre	The name of the place is set.
		@post	None.
		@return PlaceName.
	*/
	string GetPlaceName() const;

	/*
		@brief	Get the total multimedia contents number.
		@pre	The number is set.
		@post	None.
		@return the total multimedia contents number in the filename list.
	*/
	int GetNum() const;

	/*
		@brief	Set the name of the place.
		@pre	None.
		@post	The name of the place is set.
		@param	inName	PlaceName
	*/
	void SetPlaceName(string inName);


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
		@brief	Return the filenamelist of the place type.
		@pre	None.
		@post	Return the filename list.
		@return FileNameList.
	*/
	SortedList<string> getFileNameList() const;

	bool operator==(const PlaceType& A) {
		if (PlaceName == A.GetPlaceName())
			return true;
		return false;
	}

	bool operator >(const PlaceType& A) {
		if (PlaceName > A.GetPlaceName())
			return true;
		return false;
	}

	bool operator <(const PlaceType& A) {
		if (PlaceName < A.GetPlaceName())
			return true;
		return false;
	}

};
