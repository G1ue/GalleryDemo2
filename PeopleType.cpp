#include "PeopleType.h"

// Get the person's name.
string PeopleType::GetPerson() const {
	return Person;
}

// Get the total multimedia contents number.
int PeopleType::GetNum() const {
	return num;
}

// Set the person's name.
void PeopleType::SetPerson(string inName) {
	Person = inName;
}


// Add the content filename in the list.
void PeopleType::AddContentFileNameintheList(string inFN) {
	FileNameList.Add(inFN);
	AddNum();
}

// Add the num.
void PeopleType::AddNum() {
	num = num + 1;
}

// Subtract the num
void PeopleType::SubtractNum() {
	num = num - 1;
}

// Delete the content filename in the list.
void PeopleType::DeleteContentFileNameintheList(string inFN) {
	FileNameList.Delete(inFN);
	SubtractNum();
}

// Return the filenamelist.
SortedList<string> PeopleType::getFileNameList() const {
	return FileNameList;
}