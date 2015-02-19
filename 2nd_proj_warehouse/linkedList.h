/****************************************************************************************

	Class Name:		LinkedList

	Purpose:		Creates a linked list that supports adding, removing and printing 
					of the linked list.

	Author:			David Wei
	Date:			11/24/14
	Last Modified:	
					11/27/14 - Moved definitions to linkedList.cpp file

	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>

#include "linkedListNode.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class LinkedList
{
	private:
		LinkedListNode *head;
		void insert(LinkedListNode* node);
		void remove(const int idNumber);
		LinkedListNode* find(const int idNumber) const;

	public:
		LinkedList();
		~LinkedList();
		void add(const int idNumber);
		void subtract(const int idNumber);
		void print() const;
};

#endif
