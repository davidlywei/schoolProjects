/****************************************************************************************

	Class Name:		Dvd
		
	Purpose:		Defines a DVD

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef DVD_H
#define DVD_H

class Book;

#include <iostream>
#include <string>

#include "item.h"
#include "book.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Dvd : public Item
{
	private:
		string director;
	
	public:
		Dvd(string id = "undef", string bc = "undef", string tt = "undef", 
			 string pd = "undef", string pr = "undef", string dr = "undef");
		~Dvd();
		
		/***************************************************************
			
			Function Name:	print
		
			Purpose:		Returns a string with Dvd's description
			
			Parameters:		N/A
		
		***************************************************************/
		string print() const;
		
		/***************************************************************
			
			Function Name:	operator=
		
			Purpose:		Assigns one Dvd to another. 
							Returns the Dvd Object.
			
			Parameters:		
			const Dvd& d:	The Dvd which will be assigned to the 
							implied Dvd object.
		
		***************************************************************/
		Dvd operator=(const Dvd& d);
		
		/***************************************************************
			
			Function Name:	operator<
		
			Purpose:		Overloads the less than operator to compare
							Dvds to Dvds.
			
			Parameters:		
			const Dvd& d:	The Dvd to be compared to.
		
		***************************************************************/
		bool operator<(const Dvd& d);
		
		/***************************************************************
			
			Function Name:	operator <
		
			Purpose:		Overloads the less than operator to compare
							Dvds to books.
			
			Parameters:		
			const Book& b:	The Book to be compared to.
		
		***************************************************************/
		bool operator<(const Book& b);
};

#endif
