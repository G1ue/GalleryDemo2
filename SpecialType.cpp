#include "SpecialType.h"

// default constructor
SpecialType::SpecialType()
{
	filename = "";
}

// default destructor
SpecialType::~SpecialType() {}

// Get the file name.
string SpecialType::GetFileName() const {
	return filename;
}

// Display the file name of the image on the screen.
void SpecialType::Display1() const
{
	cout << "[ " << filename << ".jpg ]\n";
}

// Display the file name of the video on the screen.
void SpecialType::Display2() const {
	cout << "[ " << filename << ".mp4 ]\n";
}


// Set the file name.
void SpecialType::SetFileName(string _FN) {
	filename = _FN;
}

// Set the file name from the keyboard.
void SpecialType::SetFileNameFromKB() {
	cout << "\n\tEnter the file name -->";
	cin >> filename;
}