/****************************************************************************************
	Description:	This program solves lab 5.

					Read characters from a file into a tree. 

					Print out the characters with the frequency.

					Display how balanced the tree is.
					
	Author:			David Wei
	Date:			2/19/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 8.1)

****************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//***************************************************************************************
// Classes
//***************************************************************************************

#include "value.h"
#include "valueFunctor.h"
#include "tree.h"
#include "treeNode.h"

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

// Constant for file to analyze
const char SPEECH_FILE[]	= "c:/Users/david/Desktop/cis22c_testfiles/Speech.txt";

//***************************************************************************************
// Prototypes
//***************************************************************************************

void processFile(const char* FILENAME);

//***************************************************************************************
// Main Function
//***************************************************************************************

int main()
{
	processFile(SPEECH_FILE);

	return 0;
}

//***************************************************************************************
// Function Definitions
//***************************************************************************************

/*************************************************************************
	
	Function Name:	processFile

	Purpose:		Reads the file, freqs each character, and prints out
					each character in order of most used to least used.
	
	Parameters:		
	const char* FILENAME:	The file processFile will read.

*************************************************************************/
void processFile(const char* FILENAME)
{
	Tree< Value, ValueFunctor > tree;

	// var to hold read in character
	char buffer;

	// Open file pointer
	ifstream infile(FILENAME); 
	
	// check for successful open
	if(!infile)
	{
		cerr << "Error in opening input file: " << FILENAME << endl;
		exit(1);
	}
	
	// read each char in file
	while(infile.get(buffer))
	{
		Value temp(buffer);

		Value* vRef = tree.search(temp);

		if( !vRef )
		{
			tree.insert(temp);
		}
		else
		{
			vRef->incCount();
		}
	}

	// print out header
	cout << "Total number of characters: " 
		 << tree.getRoot()->getTotalChars() << endl;

	cout << "\n Char | Count | Frequency" << endl;
	cout << "---------------------------" << endl;

	tree.printInOrder();
	cout << endl;

	tree.checkBalance();
	cout << endl;

	// close infile
	infile.close();
}

