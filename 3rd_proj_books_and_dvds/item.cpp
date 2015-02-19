/****************************************************************************************

	Purpose:		Source file for item.h

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "item.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

Item::Item(	string id, string bc, string tt, string pd, string pr)
: idNumber(id), barCode(bc), title(tt), pubDate(pd), price(pr)
{}

Item::~Item() {}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/***************************************************************
	
	Function Name:	operator<

	Purpose:		overloads the less than operator to work 
					with comparing Items to Items
	
	Parameters:		
	const Item& i:	The item we're comparing with.

***************************************************************/
bool Item::operator<(const Item& i)
{
	return (title < i.title);
}

///***************************************************************
//	
//	Function Name:	operator<
//
//	Purpose:		overloads the less than operator to work 
//					with comparing Items to Dvd
//	Parameters:		
//	const Dvd& d:	The Dvd we're comparing with.
//
//***************************************************************/
//bool Item::operator<(const Dvd& d)
//{
//	return (title < d.title);
//}
//
///***************************************************************
//	
//	Function Name:	operator<
//
//	Purpose:		overloads the less than operator to work 
//					with comparing Items to Books
//	Parameters:		
//	const Book& b:	The book we're compairing with.
//
//***************************************************************/
//bool Item::operator<(const Book& b)
//{
//	return (title < b.title);
//}

/*************************************************************************
	
	Function Name:	operator<<

	Purpose:		Overloaded insertion operator so we can print out
					Items.
	
	Parameters:		
	ostream& out:	The ostream object we will be inserting into.
	
	const Item& i:	The item to be inserted.

*************************************************************************/
ostream& operator<<(ostream& out, const Item& i)
{
	out << i.print();
	
	return out;
}


