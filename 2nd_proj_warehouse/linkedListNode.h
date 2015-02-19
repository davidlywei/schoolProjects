/****************************************************************************************

	Class Name:		LinkedListNode
		
	Purpose:		A node that keeps track of it's id, how many instances of that item
					it stores, and the next node in the chain.

	Author:			David Wei
	Date:			11/24/14
	Last Modified:	
					11/27/14 - Moved definitions to linkedListNode.cpp

	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>
#include <iomanip>

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class LinkedListNode
{
	private:
		LinkedListNode *next;
		int id;
		int quantity;

	public:
		LinkedListNode(const int idNumber);
		friend ostream& operator<<(ostream& out, const LinkedListNode* l);

		friend class LinkedList;
};
#endif
