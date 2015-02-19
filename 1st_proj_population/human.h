/****************************************************************************************

	Class Name:		Human

	Purpose:		Emulates a human's birthday, and whether or not they are alive

	Author:			David Wei
	Date:			11/11/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <cstring>

//***************************************************************************************
// Classes
//***************************************************************************************

#include "date.h"

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Human
{
	private:
		char *name;
		Date birthday;
		bool alive;

	public:
		Human(const char *n, const Date& b);
		~Human();

		bool getStatus() const;
		unsigned age() const;
		void die();
		void display();
		void readEulogy();
};

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************


/*************************************************************************

	Purpose:	Assigns the name and date
	
	Parameters:		
		const char *n:	The name that will be assigned to the human
		const Date& b:	The date object that set the birthday

**************************************************************************/
Human::Human(const char *n, const Date& b)
{
	// allocate memory for name
	name = new char[strlen(n) + 1];

	// copy the name into name
	strcpy(name, n);

	// copy date into the birthday
	birthday = b;

	// set person to alive
	alive = true;
}

/*************************************************************************

	Purpose:		Destructor
	
	Parameters:		N/A

**************************************************************************/
Human::~Human()
{
	delete name;
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************


/*************************************************************************
	
	Function Name:	Human::getStatus

	Purpose:		Returns whether or not the human is alive
	
	Parameters:		N/A

**************************************************************************/
bool Human::getStatus() const
{
	return alive;
}

/*************************************************************************
	
	Function Name:	Human::age

	Purpose:		Returns the age of the human
	
	Parameters:		N/A

**************************************************************************/
unsigned Human::age() const
{
	return birthday.determineAge();
}

/*************************************************************************
	
	Function Name:	Human::die

	Purpose:		Sets the human's alive status to false, and displays
					a notification that they have died.
	
	Parameters:		N/A

**************************************************************************/
void Human::die()
{
	// Kill person
	alive = false;

	// report that person is dead
	readEulogy();
}

/*************************************************************************
	
	Function Name:	Human::readEulogy

	Purpose:		Displays the date that the person has died, their 
					name, and their age at the time of death.
	
	Parameters:		N/A

**************************************************************************/
void Human::readEulogy()
{
	// Display date
	TODAY.display();

	cout << " " << name << " has died at the age of " << this->age() << endl;
}

/*************************************************************************
	
	Function Name:	Human::display()

	Purpose:		Displays the name and birthday of the the human
	
	Parameters:		N/A

**************************************************************************/
void Human::display()
{
	// display information about person
	cout << name << " was born on ";
	birthday.display(); 
	cout << " is " << this->age();
	cout << endl;
}
