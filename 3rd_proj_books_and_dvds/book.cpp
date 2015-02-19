/****************************************************************************************

	Purpose:		Source file for book.h 

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "book.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

Book::Book(	string id, string bc, string tt, string pd, string pr, string ar,
			string ct, string np)
:Item(id, bc, tt, pd, pr), author(ar), coverType(ct), numPages(np)
{}

Book::~Book() {}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/***************************************************************
	
	Function Name:	print

	Purpose:		Returns a string with Book's description
	
	Parameters:		N/A

***************************************************************/
string Book::print() const
{
	string out = "\n";

	out += "Book:\n";

	out += "ID Number: "		+ idNumber	+ "\n";
	out += "Bar Code: "			+ barCode	+ "\n";
	out += "Title: "			+ title		+ "\n";
	out += "Publication Date: " + pubDate	+ "\n";
	out += "Price: $"			+ price		+ "\n";
	out += "Author: "			+ author	+ "\n";
	out += "Cover Type: "		+ coverType	+ "\n";
	out += "# of Pages: "		+ numPages	+ "\n";

	return out;
}

/***************************************************************
	
	Function Name:	operator=

	Purpose:		Assigns a Book object to this book object.
	
	Parameters:		
	const Book& b:	The book that will be assigned to this 
					object

***************************************************************/
Book Book::operator=(const Book& b)
{

	idNumber	=	b.idNumber;	
	barCode		=	b.barCode;	
	title		=	b.title;		
	pubDate		=	b.pubDate;		
	price		=	b.price;		
	author		=	b.author;		
	coverType	=	b.coverType;
	numPages	=	b.numPages;

	return *this;
}

/***************************************************************
	
	Function Name:	operator<

	Purpose:		Overloads the less than operator to compare
					Book to Book
	
	Parameters:		
	const Book& b:	The book to be compared.

***************************************************************/
bool Book::operator<(const Book& b)
{
	return (title < b.title);
}

/***************************************************************
	
	Function Name:	operator<

	Purpose:		Overloads the less than operator to compare
					Book to Dvd.
	
	Parameters:		
	const Dvd& d:	The Dvd to be compared to

***************************************************************/
bool Book::operator<(const Dvd& d)
{
	// Added the '|| &d' to shut the compiler up about unused
	// vairables
	return true || &d;
}


