/****************************************************************************************

	class:			ValueFunctor

	Purpose:		The functor used for Value comparisons

	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef VALUEFUNCTOR_H
#define VALUEFUNCTOR_H

#include "value.h"

#include "functorOutput.inc"

//***************************************************************************************
// Class Definition
//***************************************************************************************

template <typename DataType>
class ValueFunctor
{
	public:
		int operator()(	const DataType& d1, 
						const DataType& d2)
		{
			if(d1.getChar() > d2.getChar())
				return GREATER_THAN;
	
			if(d1.getChar() < d2.getChar())
				return LESS_THAN;
	
			return EQUALS;
		}
};

#endif
