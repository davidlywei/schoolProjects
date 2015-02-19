/****************************************************************************************

	Purpose:		Source file for linkedlist.h

	Author:			David Wei
	Date:			Jan 26, 2015
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

template < typename Type, template <typename> class NodeType>
LinkedList<Type, NodeType>::LinkedList()
:head(NULL), tail(NULL)
{}

template < typename Type, template <typename> class NodeType>
LinkedList<Type, NodeType>::~LinkedList()
{
	NodeType<Type>* curr = head;
	NodeType<Type>* prev = NULL;

	// loop through all the nodes.
	while(curr)
	{
		prev = curr;
		curr = curr->next;

		// delete it
		delete prev;
	}
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/***************************************************************
	
	Function Name:	findPrev
	
	Purpose:		Finds the node in the linked list that 
					should be before the node to be inserted.
					
					Returns a pointer to the node.
	
	Parameters:		
	const Type& target:	The item that we want to insert into
						the linked list
	
***************************************************************/
template < typename Type, template <typename> class NodeType>
NodeType<Type>* LinkedList<Type, NodeType>::findPrev(const Type& target)
{
	NodeType<Type>* curr = head;
	NodeType<Type>* prev = NULL;

	// (curr) checks if we can dereference curr
	// (*(curr->data) < target) checks to see the data comes before the target
	while( (curr) && (*(curr->data) < target))
	{
		prev = curr;
		curr = curr->next;
	}
	
	return prev;
}

/***************************************************************
	
	Function Name:	insert

	Purpose:		Inserts a new linked list node after
					finding the place it belongs.
	
	Parameters:		
	const Type& target:	The item that will be inserted.

***************************************************************/
template < typename Type, template <typename> class NodeType>
void LinkedList<Type, NodeType>::insert(const Type& target)
{
	// find previous linked list node
	NodeType<Type>* prev = findPrev(target);

	// if prev does not exist, then 
	if(!prev)
	{
		// set head to the newly created node
		head = new NodeType<Type>(NULL, head, target);

		// if the tail doesn't exist 
		if(!tail)
		{
			// list is empty, set tail equal to head
			tail = head;
		}
	}
	else if (prev == tail)
	{
		// inserting at the end
		tail = new NodeType<Type>(tail, NULL, target);
	}
	else
	{
		// inserting in the middle
		new NodeType<Type>(prev, prev->next, target);
	}
}

/***************************************************************
	
	Function Name:	insert

	Purpose:		Inserts a linked list node that has already
					been created.
	
	Parameters:		
	Type* Target:	The item to be inserted.

	Counter* count:	The counter that contains how many linked 
					lists point to the data.

***************************************************************/
template < typename Type, template <typename> class NodeType>
void LinkedList<Type, NodeType>::insert(Type* target, Counter* count)
{
	NodeType<Type>* prev = findPrev(*(target));

	// if prev does not exist, then 
	if(!prev)
	{
		// set head to the newly created node
		head = new NodeType<Type>(NULL, head, target, count);

		// if tail does not exist, then this is a new node
		if(!tail)
		{
			tail = head;
		}
	}
	else if (prev == tail)
	{
		// inserting at the end of the list
		tail = new NodeType<Type>(tail, NULL, target, count);
	}
	else
	{
		// inserting in the middle.
		new NodeType<Type>(prev, prev->next, target, count);
	}
}

/***************************************************************
	
	Function Name:	remove

	Purpose:		Removes a linked list node
	
	Parameters:		
	const Type& target:	The value of the linked list node that 
						is to be removed.

***************************************************************/
template < typename Type, template <typename> class NodeType>
void LinkedList<Type, NodeType>::remove(const Type& target)
{
	// Create curr and prev pointers
	NodeType<Type>* curr = head;
	NodeType<Type>* prev = NULL;

	// (curr) checks if we can dereference curr
	// (curr->data < target) checks to see the data comes before the target
	while( (curr) && (*(curr->data) != target) )
	{
		prev = curr;
		curr = curr->next;
	}

	// if the node exists.
	if(curr)
	{
		// Set head pointer if it's head
		if(curr == head)
		{
			head = curr->next;
		}

		// Set tail pointer if it's tail
		if(curr == tail)
		{
			tail = prev;
		}

		// remove the node
		curr->removeNode(prev, curr);
	}
}

/***************************************************************
	
	Function Name:	getHead

	Purpose:		Returns the head pointer of the linked list
	
	Parameters:		N/A

***************************************************************/
template < typename Type, template <typename> class NodeType>
NodeType<Type>* LinkedList<Type, NodeType>::getHead()
{
	return head;
}

/***************************************************************
	
	Function Name:	getTail

	Purpose:		Returns the tail pointer of the linked list
	
	Parameters:		N/A

***************************************************************/
template < typename Type, template <typename> class NodeType>
NodeType<Type>* LinkedList<Type, NodeType>::getTail()
{
	return tail;
}

/***************************************************************
	
	Function Name:	print

	Purpose:		Prints the linked list Iteratively
	
	Parameters:		N/A

***************************************************************/
template < typename Type, template <typename> class NodeType>
void LinkedList<Type, NodeType>::print()
{
	NodeType<Type>* curr = head;

	// loop through nodes
	while(curr)
	{
		// print nodes
		cout << *(curr->data) << endl;

		curr = curr->next;
	}
}

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
template < typename Type, template <typename> class NodeType>
void LinkedList<Type, NodeType>::printList( 
				const NodeType<Type>* curr, int direction)
{
	// check if the node is valid (exit condition)
	if(curr)
	{
		// if we want to print in the forward direction
		if(direction >= 0)
		{
			cout << curr->data->print() << endl;
		}

		// preform recursion
		printList(curr->next, direction);

		// if we want to print in the reverse direction
		if(direction <= 0)
		{
			cout << curr->data->print() << endl;
		}
	}
}
