#pragma once
#ifndef _SpecialType_H
#define _SpecialType_H


#include <iostream>
#include <string>
using namespace std;

class SpecialType {


private:
	string filename;

public:

	SpecialType();		//default constructor.
	~SpecialType();		//default destructor.

	/*
		@brief	Get the file name.
		@pre	The file name is set.
		@post	None.
		@return the file name.
	*/
	string GetFileName() const;

	/*
		@brief	Display the file name of the image on the screen.
		@pre	The file name should be set.
		@post	None.
	*/
	void Display1() const;

	/*
		@brief	Display the file name of the video on the screen.
		@pre	The file name should be set.
		@post	None.
	*/
	void Display2() const;

	/*
		@brief	Set the file name.
		@pre	None.
		@post	The file name is set.
		@param	_FN	the file name
	*/
	void SetFileName(string _FN);

	/*
		@brief	Set the file name from the keyboard,
		@pre	None.
		@post	The file name is set.
		@param	_FN	the file name
	*/
	void SetFileNameFromKB();

	bool operator==(const SpecialType& _item) {
		if (filename == _item.GetFileName())
			return true;
		return false;
	}

	friend ostream& operator <<(ostream& ostrm, const SpecialType& item) {
		ostrm << "\t    File Name : " << item.GetFileName() << endl;
		return ostrm;
	}
};
#endif

