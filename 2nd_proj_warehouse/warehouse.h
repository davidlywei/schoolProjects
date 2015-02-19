/****************************************************************************************

	Class Name:		Warehouse
		

	Purpose:		Reads a transaction file, and executes those transactions on an
					internally stored inventory

	Author:			David Wei
	Date:			11/24/14
	Last Modified:	
					11/27/14 - Moved function definitions to warehouse.cpp

	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <cstring>
#include <cstdlib>
#include <fstream>
#include "linkedList.h"

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Warehouse
{
	private:
		LinkedList inventory;

	public:
		void execTransFile(const char* filename);
};

#endif
