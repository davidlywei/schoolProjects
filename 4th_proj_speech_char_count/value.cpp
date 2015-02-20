/****************************************************************************************

	Purpose:		Source file for value.h

	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include "value.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

// initialization of static variable totalChars 
int Value::totalChars = 0;

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

Value::Value()
{
	totalChars++;
}

Value::Value(char c)
:character(c), count(1)
{
	totalChars++;
}

Value::Value(const Value& v)
{
	character = v.getChar();
	count = v.getCount();
	totalChars++;
}

Value::~Value()
{
	totalChars--;
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

/*************************************************************************
	
	Function Name:	operator<<

	Purpose:		Overloaded operator for printing out values
	
	Parameters:		
	ostream& out:	The ostream object to return
	const Value& v:	The value object to print out

*************************************************************************/
ostream& operator<<(ostream& out, const Value& v)
{
	// print out character
	switch(static_cast<int>(v.getChar()))
	{
		// if character is unprintable, replace
		// with printable version

		case 10:				// replace newline
			out << "  \\n  |";
			break;

		case 13:				// replace carriage return
			out << "  \\r  |";
			break;

		case 32:				// replace space
			out << "  \\s  |";
			break;

		default:				// printable character
			out << setw(3) << v.getChar() << "   |";
	}

	// print out stats
	// --- print out count
	out << "  ";
	out << setw(4) << v.getCount();
	out << " | ";
	// --- print out frequency
	out << fixed << setprecision(5);
	out << setw(8) << v.getFreq() * 100 << " %";

	return out;
}


