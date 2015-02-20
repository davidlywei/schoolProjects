/****************************************************************************************

	class:			Value
	
	Purpose:		Holds each character read in from the file.


	Author:			David Wei
	Date:			2/19/15
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#ifndef VALUE_H
#define VALUE_H

#include <iostream>
#include <iomanip>
#include <memory>

using namespace std;

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Value
{
	private:
		char character;
		int count;
		static int totalChars;
	
	public:
		Value();
		Value(char c);
		Value(const Value& v);
		~Value();
		
		char getChar() const {return character;}
		int getCount() const {return count;}
		int getTotalChars() const {return totalChars;}
		double getFreq() const 
		{
			return (count / static_cast<double>(totalChars));
		}
	
		void incCount() 
		{
			totalChars++;
			count++;
		}
	
	friend ostream& operator<<(ostream& out, const Value& v);
};
#endif
