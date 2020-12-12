#include "ItemType.h"

// Get the name of the contents file.
string ItemType::GetFileName() const {
	return m_sFileName;
}


// Get the type of the file.
int ItemType::GetFileType() const {
	return m_sFileType;
}


// Get the contents file making date.
unsigned long ItemType::GetDate() const {
	return m_sDate;
}


// Get people included in contents.
string ItemType::GetPeople()const {
	return m_sPeople;
}


// Get the name of the event.
string ItemType::GetEventName() const {
	return m_sEventName;
}

// Get the place where the content is recorded.
string ItemType::GetPlace() const {
	return m_sPlace;
}

// Set the contents file name.
void ItemType::SetFileName(string inFileName) {
	m_sFileName = inFileName;
}


// Set the file type.
void ItemType::SetFileType(int inFileType) {
	m_sFileType = inFileType;
}


// Set the contents file making date
void ItemType::SetDate(unsigned long inDate) {
	m_sDate = inDate;
}


// Set people included in contents.
void ItemType::SetPeople(string inPeople) {
	m_sPeople = inPeople;
}


// Set the name of the event.
void ItemType::SetEventName(string inName) {
	m_sEventName = inName;
}

// Set the place where the content is recorded.
void ItemType::SetPlace(string inPlace) {
	m_sPlace = inPlace;
}

// Set the user record.
void ItemType::SetRecord(string inFileName, int inFileType, unsigned long inDate,
	string inPeople, string inEventName, string inPlace) {
	m_sFileName = inFileName;
	m_sFileType = inFileType;
	m_sDate = inDate;
	m_sPeople = inPeople;
	m_sEventName = inEventName;
	m_sPlace = inPlace;
}


// Display the file name on the screen.
void ItemType::DisplayFileNameOnScreen() const {
	cout << "\tThe FileName is " << m_sFileName << endl;
}


// Display the type on the screen.
void ItemType::DisplayFileTypeOnScreen()const {
	cout << "\tThe FileType is " << m_sFileType << endl;
}


// Display the date on the screen.
void ItemType::DisplayDateOnScreen()const {
	cout << "\tThe Date is " << m_sDate << endl;
}


// Display people on the screen.
void ItemType::DisplayPeopleOnScreen() const {
	cout << "\tPeople are " << m_sPeople << endl;
}


// Display the event name on the screen.
void ItemType::DisplayEventNameOnScreen() const {
	cout << "\tThe EventName is " << m_sEventName << endl;
}


// Display the place on the screen.
void ItemType::DisplayPlaceOnScreen()const {
	cout << "\tThe Place is " << m_sPlace << endl;
}

// Display a record(FilName, Type, etc) on the screen.
void ItemType::DisplayRecordOnScreen()const {
	DisplayFileNameOnScreen();
	DisplayFileTypeOnScreen();
	DisplayDateOnScreen();
	DisplayPeopleOnScreen();
	DisplayPlaceOnScreen();
	DisplayEventNameOnScreen();
	cout << endl;
}


// Set the file name from the keyboard.
void ItemType::SetFileNameFromKB() {
	cout << "\tFileName : ";
	cin >> m_sFileName;
}


// Set the filetype from the keyboard.
void ItemType::SetFileTypeFromKB() {
	cout << "\tFileType (1.image 2.video) : ";
	cin >> m_sFileType;
	while (m_sFileType != 1 and m_sFileType != 2) {
		cout << "\tFileType should be 1(for the image) or 2(for the video)." << endl;
		cout << "\t(1.image 2.video) : ";
		cin >> m_sFileType;
	}


}


// Set the date from the keyboard.
void ItemType::SetDateFromKB() {
	cout << "\tDate (YYYYMMDD) : ";
	cin >> m_sDate;
}


// Set people from the keyboard.
void ItemType::SetPeopleFromKB() {
	cout << "\tPeople : ";
	cin >> m_sPeople;
}


// Set the event name from the keyboard.
void ItemType::SetEventNameFromKB() {
	cout << "\tEventName : ";
	cin >> m_sEventName;
}

//Set the palce from the keyboard.
void ItemType::SetPlaceFromKB() {
	cout << "\tPlace : ";
	cin >> m_sPlace;
}

// Set the contents record from the keyboard.
void ItemType::SetRecordFromKB() {

	SetFileNameFromKB();
	SetFileTypeFromKB();
	SetDateFromKB();
	SetPeopleFromKB();
	SetPlaceFromKB();
	SetEventNameFromKB();
}

