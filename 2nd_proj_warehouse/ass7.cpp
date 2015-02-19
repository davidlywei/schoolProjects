/****************************************************************************************
	Description:	This program solves Assignment #6

					Write a program that uses a linked list to store the results of 
					several transactions given in a transaction file.
					
	Author:			David Wei
	Date:			11/24/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <iostream>

using namespace std;

//***************************************************************************************
// Classes
//***************************************************************************************

#include "warehouse.h"

//***************************************************************************************
// Main Function
//***************************************************************************************

int main()
{
	// create warehouse
	Warehouse store;

	// The transaction file
	const char TRANSACTION_FILE[] = "ass7data.txt";

	// execute the transaction file
	store.execTransFile(TRANSACTION_FILE);

	return 0;
}
