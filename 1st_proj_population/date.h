/****************************************************************************************

	Class Name:		Date
					
	Purpose:		Keep track of dates

	Author:			David Wei
	Date:			11/11/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <iomanip>

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Date
{
	private:
		unsigned month;
		unsigned day;
		unsigned year;

	public:
		Date();
		Date(unsigned m, unsigned d, unsigned y);
		
		unsigned getMonth() const;
		unsigned getDay() const;
		unsigned getYear() const;
		int checkLeapYear() const;
		void increment();
		unsigned determineAge() const;
		void display() const;
		void letTimePass();
};

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

// array to keep track of number of days per month
unsigned DaysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Date TODAY;        // Make sure you define this after your define the Date class

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

/*************************************************************************
	
	Purpose:															
		By default sets the date to Today's date
	
	Parameters:															
		N/A

**************************************************************************/
Date::Date()
{
	// get current time
	time_t currTime = time(0);
	tm* now = localtime(&currTime);

	// set month, day and year.
	month = now->tm_mon + 1;
	day = now->tm_mday;
	year = now->tm_year + 1900;
}

/*************************************************************************

	Purpose:															
		Sets the month, day, and year. Both month and day inputs are
		modded with their maximum values to prevent overflows.
	
	Parameters:															
		unsigned m: Value to store into month (Value sanitized)
		unsigned d: Value to store into day (Value sanitized)
		unsigned y: Value to store into year.

**************************************************************************/
Date::Date(unsigned m, unsigned d, unsigned y)
{
	const int NUM_OF_MONTHS = 12;

	// check that the month is a valid month
	if( !(month = (m % (NUM_OF_MONTHS + 1) )) )
		month++; // if result of mod operation is 0, change to 1

	// check that the day is a valid day
	if( !(day = (d % DaysPerMonth[month]) ) )
		day++;	// if result of mod operation is 0, change to 1
	
	year = y;
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/*************************************************************************
	
	Function Name:	Date::getMonth()

	Purpose: 		Return the value of the member month.
	
	Parameters:		N/A

**************************************************************************/
unsigned Date::getMonth() const
{
	return month;
}

/*************************************************************************
	
	Function Name:	Date::getDay()

	Purpose: 		Return the value of the member day.
	
	Parameters:		N/A

**************************************************************************/
unsigned Date::getDay() const
{
	return day;
}

/*************************************************************************
	
	Function Name:	Date::getYear()

	Purpose: 		Return the value of the member year.
	
	Parameters:		N/A

**************************************************************************/
unsigned Date::getYear() const
{
	return year;
}


/*************************************************************************
	
	Function Name:	Date::checkLeapYear

	Purpose:		Returns 1 if the month is Feb, the year is divisible
					by 4 , and the year is not a multiple of 100 unless
					except ofcourse for multiples of 400

	Parameters:		N/A

**************************************************************************/
int Date::checkLeapYear() const
{
	return (
					(month == 2) && // check if the month is Feb.
				(	
				 	!(year % 4) &&	// check if the year is divisible
									// by 4

									// check if the year is divisible
									// by 100 but not 400
					((year % 100) || !(year % 400))
				)
		   );
}



/*************************************************************************
	
	Function Name:	Date::increment

	Purpose:		Increment the date by 1 day
	
	Parameters:		N/A

**************************************************************************/
void Date::increment()
{
		// assign day and check if days rolls over
		if( !(day %= (DaysPerMonth[month] + this->checkLeapYear())) )
		{
			// assign month and check if months rolls over
			if( !(month %= 12) )
			{
				// increment year
				year++;
			}

			// increment month
			month++;
		}

		// increment days
		day++;
}

/*************************************************************************
	
	Function Name:	Date::determineAge()

	Purpose:		Calculates the difference between the date and the
					value of today's date (stored in TODAY) If the age is
					negative, return the age as 0, and display an error.
	
	Parameters:		N/A

**************************************************************************/
unsigned Date::determineAge() const
{
	const double AVG_DAYS_PER_YEAR = 365.25;
	
	// initialize age to 0
	int age = 0;

	// number of this objects days + (months converted into days)
	int thisDays = day + (year * AVG_DAYS_PER_YEAR);

	// number of TODAY's days + (months converted into days)
	int todayDays = TODAY.day + (TODAY.year * AVG_DAYS_PER_YEAR);

	// convert the months to days
	for(unsigned i = 1; i <= month - 1; i++)
	{
		thisDays += (DaysPerMonth[i] + checkLeapYear());
	}

	// convert TODAY's months to days
	for(unsigned i = 1; i <= TODAY.month - 1; i++)
	{
		todayDays += (DaysPerMonth[i] + checkLeapYear());
	}

	if(todayDays < thisDays)
	{
		// borrow 1 year's worth of days
		// 0.25 from year ommitted because my age calculation
		// would ignore it regardless.
		todayDays += 365;

		// borrow one year from TODAY, resulting
		// resulting in TODAY.year - 1 which means
		age--;
	}

	// add the day converted month + days part to age
	// assuming that they add up to more than a year's worth.
	age += ((todayDays - thisDays) / 365);

	// if a negative age is encountered, set age to 0, 
	// and return an error.
	if(age < 0)
	{
		age = 0;
		cerr << "Error: Encountered Negative age" << endl;
	}

	return static_cast<unsigned>(age);
}

/*************************************************************************
	
	Function Name:	Date::display()

	Purpose:		Displays the date in the mm/dd/yy format
	
	Parameters:		N/A

**************************************************************************/
void Date::display() const
{
	// fill the empty spaces witn 0s
	cout << setfill('0');

	// print out month
	cout << setw(2) << month << "/"; 

	// days
	cout << setw(2) << day << "/";

	// years
	cout << setw(2) << year % 100;
	
	// return setfill to blanks
	cout << setfill(' ');
}

/*************************************************************************
	
	Function Name:	Date::letTimePass()

	Purpose:		Increments the date by n number of days, where n is 
					an integer between 1 and 365
	
	Parameters:		N/A

**************************************************************************/
void Date::letTimePass()
{
	// generate random number of days to increment
	// date by
	int daysToPass = (rand() % 365)	+ 1;

	// increment this date
	for(int i = 0; i < daysToPass; i++)
	{
		this->increment();
	}
}

