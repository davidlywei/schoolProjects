/****************************************************************************************

	Class Name:		Item

	Purpose:		Describes and item.
					
					The base class for both DVD and Book.

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

#ifndef ITEM_H
#define ITEM_H

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Item
{
	protected:
		string idNumber;
		string barCode;
		string title;
		string pubDate;
		string price;

	public:
		Item(string id = "undef", string bc = "undef", string tt = "undef", 
			 string pd = "undef", string pr = "undef");
		virtual ~Item() = 0;
	
		/***************************************************************
			
			Function Name:	operator<
		
			Purpose:		overloads the less than operator to work 
							with comparing Items to Items
			
			Parameters:		
			const Item& i:	The item we're comparing with.
		
		***************************************************************/
		bool operator<(const Item& i);
		
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
		//bool operator<(const Dvd& d);
		//
		///***************************************************************
		//	
		//	Function Name:	operator<
		//
		//	Purpose:		overloads the less than operator to work 
		//					with comparing Items to Books
		//	Parameters:		
		//	const Book& b:	The book we're comparing with.
		//
		//***************************************************************/
		//bool operator<(const Book& b);
		
		/***************************************************************
			
			Function Name:	print
		
			Purpose:		Returns a string with Item's description
			
			Parameters:		N/A
		
		***************************************************************/
		virtual string print() const = 0;	
	
	friend ostream& operator<<(ostream& out, const Item& i);
};

#endif
