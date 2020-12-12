#include "Application.h"

Application::Application()
{
	m_Command = 0;
}


Application::~Application()
{
}


// The program driver.
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:
			AddContents();
			break;
		case 2:
			DeleteContents();
			break;
		case 3:
			DeleteAllContents();
			break;
		case 4:
			DisplayAllContents();
			break;
		case 5:
			SearchByFileName_BinaryS();
			break;
		case 6:
			FindNDisplayEvent();
			break;
		case 7:
			FindNDisplayPerson();
			break;
		case 8:
			FindNDisplayPlace();
			break;
		case 9:
			FindNDisplayByEventAndPerson();
			break;
		case 10:
			AddFavoriteItem();
			break;
		case 11:
			DeleteFavoriteItem();
			break;
		case 12:
			DeleteAllFavoriteItems();
			break;
		case 13:
			PrintAllFavoriteItems();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display commands on the screen and get an input from keyboard.
int Application::GetCommand() {
	int command;
	cout << endl << endl;


	cout << "\t*************My Gallery*************" << endl;
	cout << "\t   1 : Add an item" << endl;
	cout << "\t   2 : Delete an item" << endl;
	cout << "\t   3 : Delete \"all\" items" << endl;
	cout << "\t   4 : Print all on the screen" << endl;
	cout << "\t   5 : Search an item by FileName" << endl;  // using binary search.

	cout << endl;
	cout << "\t**********Gallery Grouping**********" << endl;
	cout << "\t   6 : Find and display the event" << endl;
	cout << "\t   7 : Find and display the person" << endl;
	cout << "\t   8 : Find and display the place" << endl;
	cout << "\t   9 : Find the item by Event&Person" << endl; // 'Event' with 'Person'

	cout << endl;
	cout << "\t**********Favorite Gallery**********" << endl;
	cout << "\t   10 : Add a favorite item" << endl;
	cout << "\t   11 : Delete a favorite item" << endl;
	cout << "\t   12 : Delete \"all\" favorite items" << endl;
	cout << "\t   13 : Display all favorite items" << endl;

	cout << endl;
	cout << "\t************************************" << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl;
	cout << "\t************************************" << endl;
	cout << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;

}

// Add a new record into the contents list and the event list. (to the favorite list is also possible)
int Application::AddContents() {

	if (m_ContentsList.IsFull()) // If the list is full, don't add a new record, 
	{							 // and return 0.	
		cout << "\tList is full." << endl;
		return 0;
	}

	ItemType item;

	item.SetDateFromKB();
	item.SetEventNameFromKB();
	item.SetPeopleFromKB();
	item.SetPlaceFromKB();
	item.SetFileTypeFromKB();

	string item_FN = AddContentInDateList(item.GetDate()); // Set the file name of the 'item'.
	item.SetFileName(item_FN);


	m_ContentsList.Add(item);

	// Add content into the eventlist.
	AddContentInEventList(item.GetEventName(), item.GetFileName());

	// Add content into the personlist.
	AddContentInPersonList(item.GetPeople(), item.GetFileName());

	//Add content into the placelist.
	AddContentInPlaceList(item.GetPlace(), item.GetFileName());

	//DisplayAllContents();
	return 1;
}

// Display all records in the list on the screen.
void Application::DisplayAllContents() {
	ItemType data;

	cout << "\n\t<Current Contents list>" << endl;
	cout << endl;
	m_ContentsList.ResetList(); //Initialize the list iterator into -1.
	int length = m_ContentsList.GetLength();
	int curIndex = m_ContentsList.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_ContentsList.GetNextItem(data);
	}
}

//	Get the file name from the keyboard, and delete that contents' record in the list.
void Application::DeleteContents() {
	ItemType data;
	string input_name;
	cout << "\t Filename you want to delete : " << endl;
	cin >> input_name;

	m_ContentsList.ResetList(); //Initialize the iterator.
	int length = m_ContentsList.GetLength();
	int num = 0;
	int curIndex = m_ContentsList.GetNextItem(data); // If curIndex == 0, data has the first record of the list.
	while (data.GetFileName() != input_name) {
		curIndex = m_ContentsList.GetNextItem(data);
		num++;
		if (num == length) {
			break;
		}
	}

	if (data.GetFileName() == input_name)
	{
		m_ContentsList.Delete(data);

		DeleteContentInEventList(data.GetEventName(), input_name);
		DeleteContentInPersonList(data.GetPeople(), input_name);
		DeleteContentInPlaceList(data.GetPlace(), input_name);

		// Deletion in m_FavoriteLists.
		SpecialType SType;
		SType.SetFileName(input_name);
		if (data.GetFileType() == 1) {
			m_FavoriteList1.Delete(SType);
		}
		else {
			m_FavoriteList2.Delete(SType);
		}

		cout << "<========DELETE SUCCESS !===========>" << endl;
	}
	else
	{
		cout << '\t' << input_name << "is not in the list." << endl;
		cout << "<========DELETE FAIL !=======>" << endl;
	}
}

// Delete all items.
void Application::DeleteAllContents() {
	m_ContentsList.MakeEmpty();

	m_FavoriteList1.MakeEmpty();
	m_FavoriteList2.MakeEmpty();

	m_DateList.MakeEmpty();

	m_EventList.MakeEmpty();
	m_PersonList.MakeEmpty();
	m_PlaceList.MakeEmpty();
}

//  Find the item that has the specific name in the list, through the binary search.
int Application::SearchByFileName_BinaryS() {
	ItemType item;

	item.SetFileNameFromKB();
	if (m_ContentsList.GetByBinarySearch(item))
	{
		cout << "<============I FOUND ITEM !==========>" << endl;
		item.DisplayRecordOnScreen();
		cout << "<====================================>" << endl;
		return 1;	// Success
	}
	else {
		cout << "<========I CAN'T FIND ITEM !==========>" << endl;
		return 0;	// Fail 
	}
}


// Add a record of the the contents list into the favorite list.
void Application::AddFavoriteItem()
{
	SpecialType item;
	ItemType tmpItem;

	item.SetFileNameFromKB();
	tmpItem.SetFileName(item.GetFileName());
	if (m_ContentsList.GetByBinarySearch(tmpItem)) {
		
		if (tmpItem.GetFileType() == 1) //image type
		{
			m_FavoriteList1.Add(item);
			cout << item;
			cout << "\t   This content is IMAGE" << endl;
		}
		else
		{
			m_FavoriteList2.Add(item);
			cout << item;
			cout << "\t   This content is VIDEO" << endl;
		}
	}
	else
	{
		cout << "<============I NOT FOUND ITEM !==========>" << endl;
	}
}


// Delete a record in the favorite list.
void Application::DeleteFavoriteItem() {
	SpecialType item;
	ItemType tmpItem;

	item.SetFileNameFromKB();
	tmpItem.SetFileName(item.GetFileName());
	if (m_ContentsList.GetByBinarySearch(tmpItem) == 0) {
		cout << "<============I NOT FOUND ITEM !==========>" << endl;
	}
	else
	{
		if (tmpItem.GetFileType() == 1) {
			m_FavoriteList1.Delete(item);
		}
		else {
			m_FavoriteList2.Delete(item);
		}
	}
}

// Delete all records in the favorite list.
void Application::DeleteAllFavoriteItems() {
	m_FavoriteList1.MakeEmpty();
	m_FavoriteList2.MakeEmpty();
}


// Print all items in the favorite list.
void Application::PrintAllFavoriteItems() {
	SpecialType data1;
	cout << "\n\t<Current IMAGE List>" << endl;
	cout << endl;
	m_FavoriteList1.ResetList(); //Initialize the list iterator into -1.
	int length1 = m_FavoriteList1.GetLength();
	int curIndex1 = m_FavoriteList1.GetNextItem(data1);
	while (curIndex1 < length1 && curIndex1 != -1)
	{
		data1.Display1();
		curIndex1 = m_FavoriteList1.GetNextItem(data1);
	}

	cout << endl;

	SpecialType data2;
	cout << "\n\t<Current VIDEO List>" << endl;
	cout << endl;
	m_FavoriteList2.ResetList(); //Initialize the list iterator into -1.
	int length2 = m_FavoriteList2.GetLength();
	int curIndex2 = m_FavoriteList2.GetNextItem(data2);
	while (curIndex2 < length2 && curIndex2 != -1)
	{
		data2.Display2();
		curIndex2 = m_FavoriteList2.GetNextItem(data2);
	}

}


// Add the content in the date list.
string Application::AddContentInDateList(unsigned long inD) {
	DateType inDate;
	inDate.SetDate(inD);

	if (m_DateList.Get(inDate)) {		//the same date is already in the datelist. 
		inDate.AddNum();
		int _num = inDate.GetNum();
		string _date = to_string(inDate.GetDate());
		string _filename = _date + '_' + to_string(_num); // Make the file name ex) 20201024_3
		m_DateList.Replace(inDate);
		return _filename;
	}

	else { //This is the case for a new date.
		inDate.AddNum(); //num = 1;
		string _date = to_string(inDate.GetDate());
		string _filename = _date + "_1"; //ex)20201024_1
		m_DateList.Add(inDate);
		return _filename;
	}
}

// Add the content in the event list.	
void Application::AddContentInEventList(string inEN, string inFN) {

	EventType inevent; // Make an 'inevent' to access into m_EventList.
	inevent.SetEventName(inEN);

	if (m_EventList.Get(inevent)) {		// the same event name is already in the eventlist.
		inevent.AddContentFileNameintheList(inFN);		// Add the filename in the filenamelist.
		m_EventList.Replace(inevent);
	}
	else {		// This is the case for a new event name.
		ItemType a;
		a.SetFileName(inFN);
		m_ContentsList.GetByBinarySearch(a);

		EventType b;		// Create EventType 'b' to add in the eventlist.
		b.SetEventName(a.GetEventName());
		b.AddContentFileNameintheList(inFN);
		m_EventList.Add(b);
	}
}

// Get the event name from the keyboard and show the detail information of the filename list.
void Application::FindNDisplayEvent() {

	//Get the event name from the keyboard.
	string input_name;
	cout << "Event name : " << endl;
	cin >> input_name;

	//Make the EventType have the event name of the input_name;
	EventType temp;
	temp.SetEventName(input_name);

	if (!m_EventList.Get(temp)) { //There is no item
		cout << "<======== ITEM Not Found!==========>" << endl;
	}
	else { //The item is found.
		string tempFileName;

		SortedList<string> tempList = temp.getFileNameList();
		tempList.ResetList(); // Initialize the list iterator into -1.

		for (int i = 0; i < temp.getFileNameList().GetLength(); i++)
		{
			tempList.GetNextItem(tempFileName);				// move to the next item in the filenamelist.
			ItemType tempItemType;
			tempItemType.SetFileName(tempFileName);			// Set the filename of the tempitemtype into FileNameList[currrentindex] 
			m_ContentsList.GetByBinarySearch(tempItemType);	// Copy the detail information
			tempItemType.DisplayRecordOnScreen();			//Display the information
		}
	}
}

// Add the content in the person list.
void Application::AddContentInPersonList(string inPN, string inFN) {
	PeopleType inperson; // Make an 'inperson' to access into m_PersonList.
	inperson.SetPerson(inPN);

	if (m_PersonList.Get(inperson)) {		// the same person is already in the personlist.
		inperson.AddContentFileNameintheList(inFN);		// Add the filename in the filenamelist.
		m_PersonList.Replace(inperson);		// Copy the information.
	}
	else {		// This is the case for a new person.
		ItemType a;
		a.SetFileName(inFN);
		m_ContentsList.GetByBinarySearch(a);

		PeopleType b;		// Create PeopleType 'b' to add in the person list.
		b.SetPerson(a.GetPeople());
		b.AddContentFileNameintheList(inFN);
		m_PersonList.Add(b);
	}
}

// Get the person's name from the keyboard and show the detail information of the filename list.
void Application::FindNDisplayPerson() {

	//Get the person's name from the keyboard.
	string input_name;
	cout << "Name of the Person : " << endl;
	cin >> input_name;

	//Make the PeopleType have the name of the input_name;
	PeopleType temp;
	temp.SetPerson(input_name);

	if (!m_PersonList.Get(temp)) {
		cout << "<======== ITEM Not Found!==========>" << endl;
	}
	else { //The item is found.
		string tempFileName;

		SortedList<string> tempList = temp.getFileNameList();
		tempList.ResetList();

		for (int i = 0; i < temp.getFileNameList().GetLength(); i++)
		{
			tempList.GetNextItem(tempFileName);
			ItemType tempItemType;
			tempItemType.SetFileName(tempFileName);
			m_ContentsList.GetByBinarySearch(tempItemType);
			tempItemType.DisplayRecordOnScreen();
		}
	}
}

// Add the content in the place list.
void Application::AddContentInPlaceList(string inPN, string inFN) {
	PlaceType inplace;
	inplace.SetPlaceName(inPN);



	if (m_PlaceList.Get(inplace)) {
		inplace.AddContentFileNameintheList(inFN);
		m_PlaceList.Replace(inplace);
	}
	else {
		ItemType a;
		a.SetFileName(inFN);
		m_ContentsList.GetByBinarySearch(a);

		PlaceType b;
		b.SetPlaceName(a.GetPlace());
		b.AddContentFileNameintheList(inFN);
		m_PlaceList.Add(b);
	}
}

// Get the name of the place from the keyboard and show the detail information of the filename list.
void Application::FindNDisplayPlace() {

	string input_name;
	cout << "Name of the Place : " << endl;
	cin >> input_name;

	PlaceType temp;
	temp.SetPlaceName(input_name);

	if (!m_PlaceList.Get(temp)) {
		cout << "<======== ITEM Not Found!==========>" << endl;
	}
	else {
		string tempFileName;

		SortedList<string> tempList = temp.getFileNameList();
		tempList.ResetList();

		for (int i = 0; i < temp.getFileNameList().GetLength(); i++)
		{
			tempList.GetNextItem(tempFileName);
			ItemType tempItemType;
			tempItemType.SetFileName(tempFileName);
			m_ContentsList.GetByBinarySearch(tempItemType);
			tempItemType.DisplayRecordOnScreen();
		}
	}
}

// Get the event name and the person's name from the keyboard and show all contents that match both.
void Application::FindNDisplayByEventAndPerson() {
	string in_event;
	string in_person;
	cout << " Event Name : " << endl;
	cin >> in_event;
	cout << " The Person's Name : " << endl;
	cin >> in_person;
	EventType tempE;
	tempE.SetEventName(in_event);
	PeopleType tempP;
	tempP.SetPerson(in_person);

	if (m_EventList.Get(tempE) && m_PersonList.Get(tempP)) {

		string tempFileName;

		SortedList<string> tempList = tempE.getFileNameList();
		tempList.ResetList(); // Initialize the list iterator into -1.
		SortedList<ItemType> BothList;

		int tempELength = tempE.getFileNameList().GetLength();

		for (int i = 0; i < tempELength; i++)
		{
			tempList.GetNextItem(tempFileName);				// move to the next item in the filenamelist.

			ItemType tempItemType;
			tempItemType.SetFileName(tempFileName);			// Set the filename of the tempitemtype into FileNameList[currrentindex] 
			m_ContentsList.GetByBinarySearch(tempItemType);	// Copy the detail information

			if (tempItemType.GetPeople() == in_person) {	// The item that matches both input exists in the m_ContentsList.
				BothList.Add(tempItemType);
			}
		}

		int BothLength = BothList.GetLength();

		if (BothLength == 0) {
			cout << "<======== ITEM Not Found!==========>" << endl;
		}
		else { // More than one record exist in the BothList.
			string tempfilename;
			BothList.ResetList();
			cout << "\t   <<" << in_event << " with " << in_person << ">>" << endl;
			cout << endl;


			for (int i = 0; i < BothLength; i++) {
				ItemType tempItemType;
				BothList.GetNextItem(tempItemType);
				tempItemType.DisplayRecordOnScreen();
			}
		}
	}
	else {
		cout << "<======== ITEM Not Found!==========>" << endl;
	}
}

// Delete the content in the event list.
void Application::DeleteContentInEventList(string inEN, string inFN) {
	EventType inevent; // Make an 'inevent' to access into m_EventList.
	inevent.SetEventName(inEN);
	if (m_EventList.Get(inevent)) {		// The same event name is in the eventlist.
		if (inevent.GetNum() == 1) {
			m_EventList.Delete(inevent);
		}
		else { // Current FileNameList has more than two elements.
			inevent.DeleteContentFileNameintheList(inFN);
		}
	}
}

// Delete the content in the person list.
void Application::DeleteContentInPersonList(string inPN, string inFN) {
	PeopleType inperson; // Make an 'inperson' to access into m_PersonList.
	inperson.SetPerson(inPN);
	if (m_PersonList.Get(inperson)) {
		if (inperson.GetNum() == 1) {
			m_PersonList.Delete(inperson);
		}
		else {
			inperson.DeleteContentFileNameintheList(inFN);
		}
	}
}

// Delete the content in the place list.
void Application::DeleteContentInPlaceList(string inPN, string inFN) {
	PlaceType inplace;
	inplace.SetPlaceName(inPN);
	if (m_PlaceList.Get(inplace)) {
		if (inplace.GetNum() == 1) {
			m_PlaceList.Delete(inplace);
		}
		else {
			inplace.DeleteContentFileNameintheList(inFN);
		}
	}
}