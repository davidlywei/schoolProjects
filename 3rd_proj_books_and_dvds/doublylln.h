/****************************************************************************************

	Class Name:		DoublyLLN

	Purpose:		Defines a doubly linked list node for use with the linked list class.

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef DOUBLYLLN_H
#define DOUBLYLLN_H

#include <iostream>

#include "linkedlist.h"
#include "singlylln.h"

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename Type>
class DoublyLLN
{
	private:
		Type* data;
		DoublyLLN<Type>* prev;
		DoublyLLN<Type>* next;
		Counter* numLists;

	public:
		DoublyLLN(DoublyLLN<Type>* p, DoublyLLN<Type>* n, Type* value, Counter* nList);
		DoublyLLN(DoublyLLN<Type>* p, DoublyLLN<Type>* n, const Type& value);
		DoublyLLN(const SinglyLLN<Type>& node);
		~DoublyLLN();
		
		/***************************************************************
			
			Function Name:	removeNode
		
			Purpose:		Removes the linked list node.
			
			Parameters:		
			SinglyLLN<Type>* prev:	The node before the node to be 
									removed.
	
			SinglyLLN<Type>* node:	The node to be removed.
		
		***************************************************************/
		void removeNode(DoublyLLN<Type>* prev, DoublyLLN<Type>* node);
		
		/***************************************************************
			
			Function Name:	getData
		
			Purpose:		Returns a pointer to the data contained in
							a node.
			
			Parameters:		N/A
		
		***************************************************************/
		Type* getData();
		
		/***************************************************************
			
			Function Name:	getNumLists
		
			Purpose:		Returns a pointer to the Counter struct
							that holds how many linked lists reference
							the struct.
			
			Parameters:		N/A
		
		***************************************************************/
		Counter* getNumLists();
		
		/***************************************************************
			
			Function Name:	getNext
		
			Purpose:		Returns a pointer to the next linked list
							node.
			
			Parameters:		N/A
		
		***************************************************************/
		DoublyLLN<Type>* getNext();

	friend class LinkedList< Type, DoublyLLN>;
};

#include "doublylln.cpp"

#endif
