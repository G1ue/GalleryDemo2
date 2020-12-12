#include "DateType.h"


//Get the date.
unsigned int DateType::GetDate() const {
	return Date;
}

//Get the total multimedia contents number.
int DateType::GetNum() const {
	return num;
}

//Set the date.
void DateType::SetDate(unsigned int inDate) {
	Date = inDate;
}


//Add the num
void DateType::AddNum() {
	num = num + 1;
}

// Subtract the num
void DateType::SubtractNum() {
	num = num - 1;
}