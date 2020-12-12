#include <string>
#include "SortedList.h"

using namespace std;

class DateType
{
private:
	unsigned int Date;		// the date when contents are created.
	int num;				// multimedia contents number that have the same date

public:

	//default constuctor.
	DateType()
	{
		Date = 0;
		num = 0;
	}

	//destructor
	~DateType() {}

	/*
		@brief	Get the date.
		@pre	The date is set.
		@post	None.
		@return the date.
	*/
	unsigned int GetDate() const;

	/*
		@brief	Get the total multimedia contents number.
		@pre	The number is set.
		@post	None.
		@return the total multimedia contents number in the filenamelist.
	*/
	int GetNum() const;

	/*
		@brief	Set the date.
		@pre	None.
		@post	The event name is set.
		@param	inDate	the date
	*/
	void SetDate(unsigned int inDate);

	/*
		@brief	Add the num
		@pre	None.
		@post	num = num+1
	*/
	void AddNum();

	/*
	@brief	Subtract the num
	@pre	None.
	@post	num = num-1
	*/
	void SubtractNum();

	bool operator==(const DateType& A) {
		if (Date == A.GetDate())
			return true;
		return false;
	}

	bool operator >(const DateType& A) {
		if (Date > A.GetDate())
			return true;
		return false;
	}

	bool operator <(const DateType& A) {
		if (Date < A.GetDate())
			return true;
		return false;
	}
};