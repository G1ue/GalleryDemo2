#include "PlaceType.h"

//Get the name of the place.
string PlaceType::GetPlaceName() const {
	return PlaceName;
}

//Get the total multimedia contents number.
int PlaceType::GetNum() const {
	return num;
}

//Set the name of the place.
void PlaceType::SetPlaceName(string inName) {
	PlaceName = inName;
}


//Add the content filename in the list.
void PlaceType::AddContentFileNameintheList(string inFN) {
	FileNameList.Add(inFN);
	AddNum();
}

//Add the num
void PlaceType::AddNum() {
	num = num + 1;
}

// Subtract the num
void PlaceType::SubtractNum() {
	num = num - 1;
}

// Delete the content filename in the list.
void PlaceType::DeleteContentFileNameintheList(string inFN) {
	FileNameList.Delete(inFN);
	SubtractNum();
}

//Return the filenamelist of the place type.
SortedList<string> PlaceType::getFileNameList() const {
	return FileNameList;
}