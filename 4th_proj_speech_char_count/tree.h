/****************************************************************************************

	class:			Tree
	
	Purpose:		Defines a BST with functions:
						- insert
						- print (in-order, pre-order, post-order)
						- search
						- balance checking
			
	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef TREE_H
#define TREE_H

#include <iomanip>
#include <memory>

#include "treeNode.h"

#include "functorOutput.inc"

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename DataType, template <typename> class Functor>
class Tree
{
	private:
		unique_ptr< TreeNode<DataType> > root;
		Functor<DataType> compare;
	
		DataType* findTreeNode(unique_ptr< TreeNode<DataType> >& node, const DataType& d);
		void insertTreeNode(unique_ptr< TreeNode<DataType> >& node, const DataType& d);
	
		void inOrder(unique_ptr< TreeNode<DataType> >& node);
		void preOrder(unique_ptr< TreeNode<DataType> >& node);
		void postOrder(unique_ptr< TreeNode<DataType> >& node);
		int checkSize(unique_ptr< TreeNode<DataType> >& node);
	
	public:
		Tree()
		{}
	
		~Tree()
		{
			//delete root;
		}
	
		void insert(const DataType& d);
		DataType* search(const DataType& d);
		void checkBalance();
		DataType* getRoot() {return &(root->data);}
	
		void printInOrder();
		void printPreOrder();
		void printPostOrder();
};

#include "tree.cpp"

#endif
