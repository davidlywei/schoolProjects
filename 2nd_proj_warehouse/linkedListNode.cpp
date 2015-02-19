/****************************************************************************************
	Description:	
					
	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/
#include "linkedListNode.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************


/*************************************************************************
	
	Purpose:		Creates a linked list node. The idNumber is 
					initialized but it expects the insert and add 
					functions of the LinkedList class to set those
					values
	
	Parameters:		
		const int idNumber:	The id number given to the linked list node

**************************************************************************/
LinkedListNode::LinkedListNode(const int idNumber)
{
	next = NULL;
	id = idNumber;
	quantity = 0;
}

ostream& operator<<(ostream& out, const LinkedListNode* l)
{
	// Print out the ID number
	out << setfill('0');
	out << setw(4) << l->id;
	
	// print out the quantity
	out << setfill(' ');
	out << setw(7) << l->quantity;
	
	out << endl;

	return out;	
}

