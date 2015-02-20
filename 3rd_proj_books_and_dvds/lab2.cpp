/****************************************************************************************
	Description:	This program solves lab 2.

					Create two singly linked lists, and insert Dvds and Books objects
					(both derived from the Item class) into separate singly linked lists

					Afterwards, combine the singly linked lists into a doubly linked 
					list of items.

					Then print out the lists forwards, backwards, and both recursively.
					
	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

#include <cstdlib>
#include <cstring>

using namespace std;

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

const int BUFFER_LEN = 1000;

const char INVENTORY_LIST[] = "Inventory.csv";

//***************************************************************************************
// Classes
//***************************************************************************************

#include "linkedlist.h"
#include "singlylln.h"
#include "doublylln.h"

#include "item.h"
#include "dvd.h"
#include "book.h"

//***************************************************************************************
// Prototypes
//***************************************************************************************

void buildList(	LinkedList<Book, SinglyLLN>& bookList, 
				LinkedList<Dvd,  SinglyLLN>& dvdList,
				const char* inventory);

//***************************************************************************************
// Main Function
//***************************************************************************************

int main()
{
	// Create two Singly Linked Lists for Books and Dvds
	LinkedList<Book, SinglyLLN> bookList;
	LinkedList<Dvd,  SinglyLLN> dvdList;
	
	// Creates a doubly linked list for Items
	LinkedList<Item, DoublyLLN> itemList;

	// Populate the Singly Linked Lists
	buildList(bookList, dvdList, INVENTORY_LIST);

	// Grab the head nodes for the book and Dvd Lists
	SinglyLLN<Book>* bookPtr = bookList.getHead();
	SinglyLLN<Dvd>* dvdPtr = dvdList.getHead();
	

	// Insert the Book and Dvd lists into the item list
	// --- Loop through Book List and insert.
	while(bookPtr)
	{
		itemList.insert(bookPtr->getData(), bookPtr->getNumLists());
		bookPtr = bookPtr->getNext();
	}

	// --- Loop through Dvd list and insert.
	while(dvdPtr)
	{
		itemList.insert(dvdPtr->getData(), dvdPtr->getNumLists());
		dvdPtr = dvdPtr->getNext();
	}
	
	// Print out itemList
	// --- print it out Forward
	itemList.printList(itemList.getHead(), 1);
	cout << "-----------------------------------------------------------" << endl;

	// --- print it out Backwards
	itemList.printList(itemList.getHead(), -1);
	cout << "-----------------------------------------------------------" << endl;
	
	// --- print it out both ways.
	itemList.printList(itemList.getHead(), 0);
	
	return 0;
}

//***************************************************************************************
// Function Definitions
//***************************************************************************************

/*************************************************************************
	
	Function Name:	buildList

	Purpose:		Populates the Book and Dvd Linked Lists
	
	Parameters:		
	LinkedList<Book, SinglyLLN>& bookList:	The Book Linked List
	LinkedList<Dvd,  SinglyLLN>& dvdList:	The Dvd Linked List
	const char* inventory:					The list of items to insert.

*************************************************************************/
void buildList(	LinkedList<Book, SinglyLLN>& bookList, 
				LinkedList<Dvd,  SinglyLLN>& dvdList,
				const char* inventory)
{
	string idNumber;
	string barCode;
	string title;
	string pubDate;
	string price;
	string author;
	string coverType;
	string numPages;
	string director;

	char buffer[BUFFER_LEN];

	// Open file pointer
	ifstream infile(inventory); 
	
	// check for successful open
	if(!infile)
	{
		cerr << "Error in opening input file: " << inventory << endl;
		exit(1);
	}
	
	while(infile.getline(buffer, BUFFER_LEN))
	{
		// read in the common items
		idNumber	= strtok(buffer, ",\r\n");
		barCode		= strtok(NULL, ",\r\n");
		title		= strtok(NULL, ",\r\n");

		// if item is a Book,
		if(idNumber[0] == '4')
		{
			author		= strtok(NULL, ",\r\n");
			pubDate		= strtok(NULL, ",\r\n");
			coverType	= strtok(NULL, ",\r\n");
			numPages	= strtok(NULL, ",\r\n");
			price		= strtok(NULL, ",\r\n");
			
			bookList.insert(Book(	idNumber, 	
    								barCode,
    								title,
    								pubDate,
    								price,
									author,   								
									coverType,								
									numPages 								
								));
		
		}
		
		// if item is a Dvd
		if(idNumber[0] == '7')
		{
			pubDate		= strtok(NULL, ",\r\n");
			director	= strtok(NULL, ",\r\n");
			director	+= ", ";
			director	+= strtok(NULL, ",\r\n");
			
			price		= strtok(NULL, ",\r\n");
			
			dvdList.insert(Dvd(	idNumber,
									barCode,
									title,
									pubDate,
									price,
									director
								));
		}
	}

	// close infile
	infile.close();
}

