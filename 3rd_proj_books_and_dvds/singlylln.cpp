/****************************************************************************************

	Purpose:		Source file for singlylln.h

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

template <typename Type>
SinglyLLN<Type>::SinglyLLN(SinglyLLN<Type>* p, 
							SinglyLLN<Type>* n, const Type& value)
:data(new Type()), next(n), numLists(new Counter)
{
	// copy value from item to this.
	*(data) = value;
	
	// set previous pointer's next 
	if(p)
	{
		p->next = this;
	}

	// initialise and set the number of pointers pointing at this data to 1
	numLists->count = 1;
}

template <typename Type>
SinglyLLN<Type>::SinglyLLN(SinglyLLN<Type>* p, SinglyLLN<Type>* n, 
							Type* value, Counter* nLists)
:data(value), next(n), numLists(nLists)
{
	// Set previous pointer's next to this
	if(p)
	{
		p->next = this;
	}

	// Increment the number of pointers pointing at this data by 1
	numLists->count++;
}

template <typename Type>
SinglyLLN<Type>::~SinglyLLN()
{
	// if there are no pointers pointing at the data
	if( !(--numLists->count) )
	{
		// then delete the data and the numLists associated
		// with it.
		delete numLists;
		delete data;
	}

	// otherwise, just delete the node
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
void SinglyLLN<Type>::removeNode(SinglyLLN<Type>* prev, SinglyLLN<Type>* node)
{
	if(prev)
	{
		prev->next = node->next;
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
Type* SinglyLLN<Type>::getData()
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
Counter* SinglyLLN<Type>::getNumLists()
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
SinglyLLN<Type>* SinglyLLN<Type>::getNext()
{
	return next;
}

