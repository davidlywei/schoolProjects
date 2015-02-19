/****************************************************************************************

	Class Name:		Book

	Purpose:		Defines a book

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef BOOK_H
#define BOOK_H

class Dvd;

#include <iostream>
#include <string>

#include "item.h"
#include "dvd.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Book : public Item
{
	private:
		string author;
		string coverType;
		string numPages;

	public:
		Book(string id = "undef", string bc = "undef", string tt = "undef", 
			 string pd = "undef", string pr = "undef", string ar = "undef",
			 string ct = "undef", string np = "undef");
		~Book();
	
		/***************************************************************
			
			Function Name:	print
		
			Purpose:		Returns a string with Book's description
			
			Parameters:		N/A
		
		***************************************************************/
		string print() const;
		
		/***************************************************************
			
			Function Name:	operator=
		
			Purpose:		Assigns a Book object to this book object.
			
			Parameters:		
			const Book& b:	The book that will be assigned to this 
							object
		
		***************************************************************/
		Book operator=(const Book& b);
		
		/***************************************************************
			
			Function Name:	operator<
		
			Purpose:		Overloads the less than operator to compare
							Book to Book
			
			Parameters:		
			const Book& b:	The book to be compared.
		
		***************************************************************/
		bool operator<(const Book& b);
		
		/***************************************************************
			
			Function Name:	operator<
		
			Purpose:		Overloads the less than operator to compare
							Book to Dvd.
			
			Parameters:		
			const Dvd& d:	The Dvd to be compared to
		
		***************************************************************/
		bool operator<(const Dvd& d);
};

#endif
