/****************************************************************************************
	Description:	Source file for Linked List 
					
	Author:			David Wei
	Date:			11/27/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include "linkedList.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************


/*************************************************************************
	
	Purpose:		Sets head to Null
	
	Parameters:		N/A

**************************************************************************/
LinkedList::LinkedList()
:head(NULL)
{}


/*************************************************************************
	
	Purpose:		Destroys each node in the list
	
	Parameters:		N/A

**************************************************************************/
LinkedList::~LinkedList()
{
	LinkedListNode *currNode = head;
	LinkedListNode *nextNode = NULL;

	// loop through list
	while(currNode)
	{
		// save curr's next
		nextNode = currNode->next;

		// delete the currNode
		delete currNode;

		// progress in the list.
		currNode = nextNode;
	}
}


//***************************************************************************************
// Member Function Definitions
//***************************************************************************************


/*************************************************************************
	
	Function Name:	LinkedList::add

	Purpose:		Adds 1 to the quantity of a node. If the node doesn't
					exist, create and insert the node.
	
	Parameters:		
		const int idNumber:	The idNumber of item who's quantity will be 
							increased.

**************************************************************************/
void LinkedList::add(const int idNumber)
{
	LinkedListNode *target = NULL;

	// check if item is not in the list already
	if ( !(target = this->find(idNumber)) )
	{
		// create node for idNumber
		target = new LinkedListNode(idNumber);

		this->insert(target);
	}
	
	// if so, increment quantity
	target->quantity++;
}

/*************************************************************************
	
	Function Name:	LinkedList::insert

	Purpose:		Inserts a linked list node into the list, from lowest
					ID number to greatest ID number
	
	Parameters:		
		LinkedListNode *node:	The node to be inserted

**************************************************************************/
void LinkedList::insert(LinkedListNode* node)
{
	LinkedListNode *curr = head;
	LinkedListNode *prev = NULL;

	// find where the new node should go
	while( (curr && (curr->id < node->id)) )
	{
		prev = curr;
		curr = curr->next;
	}

	if(prev)
	{
		// If prev exists, then we are inserting into the middle or end of the list.
		// Assogm the previous node's next to node
		prev->next = node;
	}
	else
	{
		// If prev doesnt exist, we are either inserting into an empty list, or 
		// inserting at the beginning of the list either case head must be changed
		head = node;
	}

	// node's next is always curr. If curr points to a NULL then the item is 
	// inserted at the end of the list, and of course it's next is NULL.
	node->next = curr;
}

/*************************************************************************
	
	Function Name:	LinkedList::subtract

	Purpose:		Subtracts 1 from the quantity of a node. If that 
					node's quantity becomes 0, remove the node
	
	Parameters:		
		const int idNumber:	The ID number of the item who's quantity will
							be increased

**************************************************************************/
void LinkedList::subtract(const int idNumber)
{
	LinkedListNode* target = NULL;

	// check if the item is in the list
	if( (target = this->find(idNumber)) )
	{
		// if after subtracting 1, the quantity of target
		// is equal to 0,
		if( !(--(target->quantity)) )
		{
			this->remove(target->id);
		}

	}
}

/*************************************************************************
	
	Function Name:	LinkedList::remove

	Purpose:		Removes a node from the linked list.
	
	Parameters:		
		const int idNumber:	Removes the node with this ID Number

**************************************************************************/
void LinkedList::remove(const int idNumber)
{
	LinkedListNode *curr = head;
	LinkedListNode *prev = NULL;

	// find where the new node should go
	while( (curr && (curr->id != idNumber)) )
	{
		prev = curr;
		curr = curr->next;
	}

	// Check if prev exists
	if(prev)
	{
		// if prev exists, set prev's next to curr's next	
		prev->next = curr->next;
	}
	else
	{
		// if prev doesn't exist, then we are removing the 
		// first node from the list, so head node is 
		// reassigned. 
		head = curr->next;
	}

	// free curr
	delete curr;
}

/*************************************************************************
	
	Function Name:	LinkedList::print

	Purpose:		Prints out the Linked List
	
	Parameters:		N/A

**************************************************************************/
void LinkedList::print() const
{
	LinkedListNode *curr = head;

	// print out header
	cout << endl;
	cout << "Item  Quantity" << endl;

	// loop though list
	while(curr)
	{
		cout << curr;
		
		// advance to next item in the list
		curr = curr->next;
	}

	cout << endl;
}

/*************************************************************************
	
	Function Name:	LinkedList::find

	Purpose:		Looks through the linked list to see if the node
					exists. Returns a pointer to the node if it does, 
					and NULL otherwise
	
	Parameters:		
		const int idNumber:	The id number of the node we are looking for

**************************************************************************/
LinkedListNode* LinkedList::find(const int idNumber) const
{
	LinkedListNode *curr = head;

	// loop to find the target item
	while( (curr && (curr->id != idNumber)) )
	{
		curr = curr->next;
	}

	return curr;
}

