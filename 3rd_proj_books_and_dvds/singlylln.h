/****************************************************************************************

	Class Name:		SinglyLLN
		
	Purpose:		Defines a singly linked list node for use with the linked list class.

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef SINGLYLLN_H
#define SINGLYLLN_H

#include <iostream>
#include "linkedlist.h"

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename Type>
class SinglyLLN
{
	private:
		Type* data;
		SinglyLLN<Type>* next;
		Counter* numLists;

	public:
		SinglyLLN(SinglyLLN<Type>* p, SinglyLLN<Type>* n, Type* value, Counter* nList);
		SinglyLLN(SinglyLLN<Type>* p, SinglyLLN<Type>* n, const Type& value);
		~SinglyLLN();
		
		/***************************************************************
			
			Function Name:	removeNode
		
			Purpose:		Removes the linked list node.
			
			Parameters:		
			SinglyLLN<Type>* prev:	The node before the node to be 
									removed.

			SinglyLLN<Type>* node:	The node to be removed.
		
		***************************************************************/
		void removeNode(SinglyLLN<Type>* prev, SinglyLLN<Type>* node);
		
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
		SinglyLLN<Type>* getNext();

	friend class LinkedList< Type, SinglyLLN>;
};

#include "singlylln.cpp"

#endif
