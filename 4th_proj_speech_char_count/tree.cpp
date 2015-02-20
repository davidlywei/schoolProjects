/****************************************************************************************

	Purpose:		Source file for tree.h

	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "tree.h"

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/*************************************************************************
	
	Function Name:	insert
	
	Purpose:		Wrapper for the function insertTreeNode function.
	
	Parameters:		
	const DataType& d:	The data to be inserted.

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::insert(const DataType& d)
{
	if (root)
	{
		insertTreeNode(root, d);
	}
	else
	{
		root = unique_ptr< TreeNode<DataType> >( new TreeNode<DataType>(d) );
	}
}

/*************************************************************************

	Function Name:	insertTreeNode
	
	Purpose:		Inserts a TreeNode into the tree recursively
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on
	
	const DataType& d:						The data to be inserted

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::insertTreeNode(
			unique_ptr< TreeNode<DataType> >& node, 
			const DataType& d
										)
{
	// check left
	if (compare(d, node->data) == LESS_THAN )
	{
		if (node->left)
		{
			// recurse from left node
			insertTreeNode(node->left, d);
		}
		else
		{
			// create new node on left
			node->left = unique_ptr< TreeNode<DataType> >( new TreeNode<DataType>(d) );
		}
	}
	else // check right
	{
		if (node->right)
		{
			// recurse from right node
			insertTreeNode(node->right, d);
		}
		else
		{
			// create new node on right
			node->right = unique_ptr< TreeNode<DataType> >( new TreeNode<DataType>(d) );
		}
	}
}

/*************************************************************************

	Function Name:	search
	
	Purpose:		searches for the node in question
	
	Parameters:		
	const DataType& d:	The data we are looking for

*************************************************************************/
template <typename DataType, template <typename> class Functor>
DataType* Tree<DataType, Functor>::search(const DataType& d)
{
	if (root) // check if root exists
	{
		return findTreeNode(root, d);
	}
	else
	{
		return NULL;
	}
}

/*************************************************************************

	Function Name:	findTreeNode	
	
	Purpose:		Searches recursively for the tree node
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on
	
	const DataType& d:						The data we are loooking for

*************************************************************************/
template <typename DataType, template <typename> class Functor>
DataType* Tree<DataType, Functor>::findTreeNode	(
			unique_ptr< TreeNode<DataType> >& node, 
			const DataType& d
											)
{
	if (node) // check if the node exists
	{
		// check for equality
		if (compare(node->data, d) == EQUALS)
		{
			return &(node->data);
		}
		else
		{
			// check left
			if (compare(d, node->data) == LESS_THAN)
			{
				if (node->left)
				{
					// recurse left
					return findTreeNode(node->left, d);
				}
			}
			else // check right
			{
				if (node->right)
				{
					// recurse right
					return findTreeNode(node->right, d);
				}
			}
		}
	}
	
	// if no node is returned	
	return NULL;
}

/*************************************************************************

	Function Name:	printInOrder
	
	Purpose:		Wrapper for inOrder function
	
	Parameters:		N/A
	
*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::printInOrder()
{
	// call inOrder with tree root
	inOrder(root);
}

/*************************************************************************

	Function Name:	inOrder
	
	Purpose:		Prints the data in order
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::inOrder(
			unique_ptr< TreeNode<DataType> >& node)
{
	// check for node's existance
	if (node)
	{
		// recurse left
		inOrder(node->left);
	
		// print data
		cout << node->data << endl;
	
		// recurse right
		inOrder(node->right);
	}
}

/*************************************************************************

	Function Name:	printPreOrder
	
	Purpose:		Wrapper for function preOrder
	
	Parameters:		N/A
	
*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::printPreOrder()
{
	// calls preOrder with tree root.
	preOrder(root);
}

/*************************************************************************

	Function Name:	preOrder
	
	Purpose:		prints the tree in pre-order
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::preOrder(
			unique_ptr< TreeNode<DataType> >& node)
{
	// checks for node
	if (node)
	{
		// prints out node
		cout << node->data << endl;
	
		// recurse left
		preOrder(node->left);
	
		// recurse right
		preOrder(node->right);
	}
}

/*************************************************************************

	Function Name:	printPostOrder
	
	Purpose:		wrapper for post order
	
	Parameters:		N/A

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::printPostOrder()
{
	// calls postOrder with tree root
	postOrder(root);
}

/*************************************************************************

	Function Name:	postOrder
	
	Purpose:		prints the tree in postOrder
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::postOrder(unique_ptr< TreeNode<DataType> >& node)
{
	// check node
	if (node)
	{
		// recurse left
		postOrder(node->left);
	
		// recurse right
		postOrder(node->right);
	
		// print out data
		cout << node->data << endl;
	}
}

/*************************************************************************

	Function Name:	checkBalance	
	
	Purpose:		checks how large the tree is on either side of the root.
	
	Parameters:		N/A

*************************************************************************/
template <typename DataType, template <typename> class Functor>
void Tree<DataType, Functor>::checkBalance()
{
	cout << "Left side has " << checkSize(root->left) << " nodes.\n";
	cout << "Right side has " << checkSize(root->right) << " nodes.\n";
}

/*************************************************************************

	Function Name:	checkSize
	
	Purpose:		recursively checks the size of the tree below itself
	
	Parameters:		
	unique_ptr<TreeNode<DataType> >& node:	The parent node to recurse
											on

*************************************************************************/
template <typename DataType, template <typename> class Functor>
int Tree<DataType, Functor>::checkSize(
			unique_ptr< TreeNode<DataType> >& node)
{
	if(!node)
		return 0;
	
	return 1 + checkSize(node->left) + checkSize(node->right);
}


