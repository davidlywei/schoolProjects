/****************************************************************************************

	class:			TreeNode
	
	Purpose:		The nodes of the BST.

	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename DataType, template <typename> class Functor>
class Tree;

template <typename DataType>
class TreeNode
{
	private:
		DataType data;
		unique_ptr< TreeNode<DataType> > left;
		unique_ptr< TreeNode<DataType> > right;
	
	public:
		TreeNode(const DataType& d)
		:data(d)
		{}
		TreeNode();
	
		~TreeNode()
		{
			//delete left;
			//delete right;
		}
	
	template <typename, template <typename> class> friend class Tree;
};

#endif
