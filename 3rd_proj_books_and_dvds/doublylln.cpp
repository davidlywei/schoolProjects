/****************************************************************************************

	Purpose:		Source file for doublylln.h

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

template <typename Type>
DoublyLLN<Type>::DoublyLLN(DoublyLLN<Type>* p, 
							DoublyLLN<Type>* n, const Type& value)
:data(new Type()), prev(p), next(n), numLists(new Counter) 
{
	// copy value from item to this.
	*(data) = value;

	// set previous' and next's pointers
	if(n)
	{
		n->prev = this;
	}

	if(p)
	{
		p->next = this;
	}

	// Initialize, and set number of pointers pointing to this data to 1
	numLists->count = 1;
}

template <typename Type>
DoublyLLN<Type>::DoublyLLN(DoublyLLN<Type>* p, DoublyLLN<Type>* n, 
							Type* value, Counter* nLists)
:data(value), prev(p), next(n), numLists(nLists)
{
	// set previous' and next's pointers
	if(n)
	{
		n->prev = this;
	}

	if(p)
	{
		p->next = this;
	}

	// Increment the count of pointers pointing to the data.
	numLists->count++;
}
		
template <typename Type>
DoublyLLN<Type>::DoublyLLN(const SinglyLLN<Type>& node)
:data(node->data), prev(NULL), next(node->next), numLists(node->numLists)
{
	// Increment the count of pointers pointing to the data.
	numLists++;
}
		
template <typename Type>
DoublyLLN<Type>::~DoublyLLN()
{
	// when deleting, check if anyone else is pointing to the data.
	if( !(--numLists->count) )
	{
		// if not, delete it, and the numLists struct
		delete numLists;
		delete data;
	}

	// otherwise, just ignore it.
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/***************************************************************
	
	Function Name:	removeNode

	Purpose:		Removes the linked list node.
	
	Parameters:		
	SinglyLLN<Type>* prev:	The node before the node to be 
							removed.

	SinglyLLN<Type>* node:	The node to be removed.

***************************************************************/
template <typename Type>
void DoublyLLN<Type>::removeNode(DoublyLLN<Type>* prev, DoublyLLN<Type>* node)
{
	if(prev)
	{
		prev->next = node->next;
		node->next->prev = node->prev;
	}
	
	delete node;
}

/***************************************************************
	
	Function Name:	getData

	Purpose:		Returns a pointer to the data contained in
					a node.
	
	Parameters:		N/A

***************************************************************/
template <typename Type>
Type* DoublyLLN<Type>::getData()
{
	return data;
}

/***************************************************************
	
	Function Name:	getNumLists

	Purpose:		Returns a pointer to the Counter struct
					that holds how many linked lists reference
					the struct.
	
	Parameters:		N/A

***************************************************************/
template <typename Type>
Counter* DoublyLLN<Type>::getNumLists()
{
	return numLists;
}

/***************************************************************
	
	Function Name:	getNext

	Purpose:		Returns a pointer to the next linked list
					node.
	
	Parameters:		N/A

***************************************************************/
template <typename Type>
DoublyLLN<Type>* DoublyLLN<Type>::getNext()
{
	return next;
}


