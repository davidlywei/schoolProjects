/****************************************************************************************

	Purpose:		Source file for dvd.h 

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "dvd.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

Dvd::Dvd(	string id, string bc, string tt, string pd, string pr, string dr)
:Item(id, bc, tt, pd, pr), director(dr) 
{}

Dvd::~Dvd() {}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/***************************************************************
	
	Function Name:	print

	Purpose:		Returns a string with Dvd's description
	
	Parameters:		N/A

***************************************************************/
string Dvd::print() const
{
	string out = "\n";

	out += "Dvd:\n";

	out += "ID Number: "		+ idNumber	+ "\n";
	out += "Bar Code: "			+ barCode	+ "\n";
	out += "Title: "			+ title		+ "\n";
	out += "Publication Date: "	+ pubDate	+ "\n";
	out += "Price: $"			+ price		+ "\n";
	out += "Director: "			+ director	+ "\n";

	return out;
}

/***************************************************************
	
	Function Name:	operator=

	Purpose:		Assigns one Dvd to another. 
					Returns the Dvd Object.
	
	Parameters:		
	const Dvd& d:	The Dvd which will be assigned to the 
					implied Dvd object.

***************************************************************/
Dvd Dvd::operator=(const Dvd& d)
{
	idNumber	= 	d.idNumber;
	barCode 	=   d.barCode;
	title	  	=   d.title;
	pubDate		=   d.pubDate;
	price		=   d.price;
	director	=   d.director;

	return *this;
}

/***************************************************************
	
	Function Name:	operator<

	Purpose:		Overloads the less than operator to compare
					Dvds to Dvds.
	
	Parameters:		
	const Dvd& d:	The Dvd to be compared to.

***************************************************************/
bool Dvd::operator<(const Dvd& d)
{
	return (title < d.title);
}

/***************************************************************
	
	Function Name:	operator <

	Purpose:		Overloads the less than operator to compare
					Dvds to books.
	
	Parameters:		
	const Book& b:	The Book to be compared to.

***************************************************************/
bool Dvd::operator<(const Book& b)
{
	// added the '&& &b' mostly to shut the compiler up about
	// unused variables
	return false && &b;
}


