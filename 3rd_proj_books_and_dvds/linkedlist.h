
/****************************************************************************************

	Class Name:		LinkedList

	Purpose:		This defines a linked list. Whether or not it's a singly
					or doubly linked list depends on the linked list nodes
					put into the list.

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef	LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>

#include "counter.h"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

template < typename Type, template <typename> class NodeType>
class LinkedList
{
	private:
		NodeType<Type>* head;		
		NodeType<Type>* tail;	
	
		/***************************************************************
			
			Function Name:	findPrev
		
			Purpose:		Finds the node in the linked list that 
							should be before the node to be inserted.
							
							Returns a pointer to the node.
			
			Parameters:		
			const Type& target:	The item that we want to insert into
								the linked list
		
		***************************************************************/
		NodeType<Type>* findPrev(const Type& target);
	
	public:
		LinkedList();
		~LinkedList();
	
		/***************************************************************
			
			Function Name:	insert
		
			Purpose:		Inserts a new linked list node after
							finding the place it belongs.
			
			Parameters:		
			const Type& target:	The item that will be inserted.
		
		***************************************************************/
		void insert(const Type& target);
		
		/***************************************************************
			
			Function Name:	insert
		
			Purpose:		Inserts a linked list node that has already
							been created.
			
			Parameters:		
			Type* Target:	The item to be inserted.
	
			Counter* count:	The counter that contains how many linked 
							lists point to the data.
		
		***************************************************************/
		void insert(Type* target, Counter* count);
		
		/***************************************************************
			
			Function Name:	remove
		
			Purpose:		Removes a linked list node
			
			Parameters:		
			const Type& target:	The value of the linked list node that 
								is to be removed.
		
		***************************************************************/
		void remove(const Type& target);
		
		/***************************************************************
			
			Function Name:	getHead
		
			Purpose:		Returns the head pointer of the linked list
			
			Parameters:		N/A
		
		***************************************************************/
		NodeType<Type>* getHead();
		
		/***************************************************************
			
			Function Name:	getTail
		
			Purpose:		Returns the tail pointer of the linked list
			
			Parameters:		N/A
		
		***************************************************************/
		NodeType<Type>* getTail();
		
		/***************************************************************
			
			Function Name:	
		
			Purpose:		
			
			Parameters:		
		
		***************************************************************/
		//void appendList(NodeType<Type>* c);
		
		/***************************************************************
			
			Function Name:	print
		
			Purpose:		Prints the linked list Iteratively
			
			Parameters:		N/A
		
		***************************************************************/
		void print();
		
		/***************************************************************
			
			Function Name:	printList
		
			Purpose:		Prints the linked list recursively, forwards
							backwards, or both.
			
			Parameters:		
			const NodeType<Type>* curr:	The current node to print.
	
			int direction:				The indicator of what direction
										to print:
	
										positive numbers: in order
										zero			: both
										negative numbers: reverse order
		
		***************************************************************/
		void printList(const NodeType<Type>* curr, int direction);
};

#include "linkedlist.cpp"

#endif
