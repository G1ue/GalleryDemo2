#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// The item information class
class ItemType
{

protected:

	string m_sFileName;		// the name of the contents file (Date_Num ex. 20201025_9)
	int m_sFileType;		// the type of the contents (1.image or 2.video) 
	unsigned long m_sDate;	// the date when the content file is made (YYYYMMDD)
	string m_sPeople;		// people included in contents
	string m_sEventName;	// the name of the event
	string m_sPlace;		// the place where the content is recorded. 

public:

	//	default constructor.
	ItemType()
	{
		m_sFileName = "";
		m_sFileType = 0;
		m_sDate = 0;
		m_sPeople = "";
		m_sEventName = "";
		m_sPlace = "";
	}

	//	destructor.

	~ItemType() {}


	/*
		@brief	Get the name of the contents file
		@pre	The file name is set.
		@post	None.
		@return the file name.
	*/
	string GetFileName() const;


	/*
		@brief	Get the type of the file.
		@pre	The type is set.
		@post	None.
		@return the type of the file.
	*/
	int GetFileType() const;


	/*
		@brief	Get the contents file making date
		@pre	The date is set.
		@post	None.
		@return the contents file making date.
	*/
	unsigned long GetDate() const;


	/*
		@brief	Get people included in contents.
		@pre	People are set.
		@post	None.
		@return the people included in contents.
	*/
	string GetPeople()const;


	/*
		@brief	Get the name of the event.
		@pre	The event name is set.
		@post	None.
		@return the event name,
	*/
	string GetEventName() const;

	/*
		@brief	Get the place where the content is recorded.
		@pre	The place is set.
		@post	None.
		@return the place.
	*/
	string GetPlace() const;


	/*
		@brief	Set the contents file name.
		@pre	None.
		@post	The file name is set.
		@param	inFileName	the file name
	*/
	void SetFileName(string inFileName);


	/*
		@brief	Set the file type.
		@pre	None.
		@post	The file type is set.
		@param	inFileType	File type
	*/
	void SetFileType(int inFileType);

	/*
		@brief	Set the contents file making date
		@pre	None.
		@post	The date is set.
		@param  inDate	contents date.
	*/
	void SetDate(unsigned long inDate);

	/*
		@brief	Set the place where the content is recorded.
		@pre	None.
		@post	The place is set.
		@param	inPlace	place
	*/
	void SetPlace(string inPlace);


	/*
		@brief	Set people included in contents.
		@pre	None.
		@post	People are set.
		@param	inPeople	contents people.
	*/
	void SetPeople(string inPeople);


	/*
		@brief	Set the name of the event.
		@pre	None.
		@post	The event name is set.
		@param	inName	event name
	*/
	void SetEventName(string inName);


	/*
		@brief	Set the contents record.
		@pre	None.
		@post	The user record is set.
		@param	inFileName	contents file name
		@param	inFileType	the file type
		@param	inDate		contents file making date
		@param	inPeople	contents people
		@param  inEventName	the event name
		@param	inPlace		place
	*/
	void SetRecord(string inFileName, int inFileType, unsigned long inDate,
		string inPeople, string inEventName, string inPlace);

	/*
		@brief	Display the file name on the screen.
		@pre	The file name is set.
		@post	The file name is on the screen.
	*/
	void DisplayFileNameOnScreen()const;


	/*
		@brief	Display the file type on the screen.
		@pre	The file type is set.
		@post	The file type is on the screen.
	*/
	void DisplayFileTypeOnScreen()const;


	/*
		@brief	Display the date on the screen.
		@pre	The date is set.
		@post	The date is on the screen.
	*/
	void DisplayDateOnScreen()const;


	/*
		@brief	Display people on the screen.
		@pre	People are set.
		@post	People are on the screen.
	*/
	void DisplayPeopleOnScreen()const;


	/*
		@brief	Display the event name on the screen.
		@pre	The event name is set.
		@post	The event name is on the screen.
	*/
	void DisplayEventNameOnScreen()const;

	/*
		@brief	Display the place on the screen.
		@pre	The place is set.
		@post	The place is on the screen.
	*/
	void DisplayPlaceOnScreen()const;


	/*
		@brief	Display a record(FilName, FileType, etc) on the screen.
		@pre	The content record is set.
		@post	The content record is on the screen.
	*/
	void DisplayRecordOnScreen()const;


	/*
		@brief	Set the file name from the keyboard.
		@pre	None.
		@post	The file name is set.
	*/
	void SetFileNameFromKB();


	/*
		@brief	Set the file type from the keyboard.
		@pre	None.
		@post	The filetype is set.
	*/
	void SetFileTypeFromKB();


	/*
		@brief	Set the date from the keyboard.
		@pre	None.
		@post	The date is set.
	*/
	void SetDateFromKB();


	/*
		@brief	Set people from the keyboard.
		@pre	None.
		@post	People are set.
	*/
	void SetPeopleFromKB();


	/*
		@brief	Set the event name from the keyboard.
		@pre	None.
		@post	The event name is set.
	*/
	void SetEventNameFromKB();

	/*
		@brief	Set the palce from the keyboard.
		@pre	None.
		@post	The place is set.
	*/
	void SetPlaceFromKB();

	/*
		@brief	Set the contents record from the keyboard.
		@pre	None.
		@post	The record is set.
	*/
	void SetRecordFromKB();

	bool operator >(const ItemType& A) {
		if (m_sFileName > A.GetFileName())
			return true;
		return false;
	}

	bool operator <(const ItemType& A) {
		if (m_sFileName < A.GetFileName())
			return true;
		return false;
	}

	bool operator==(const ItemType& A) {
		if (m_sFileName == A.GetFileName())
			return true;
		return false;
	}
};

