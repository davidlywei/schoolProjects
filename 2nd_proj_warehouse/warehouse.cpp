/****************************************************************************************
	Description:	Source file for Warehouse class
					
	Author:			David Wei
	Date:			11/27/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include "warehouse.h"

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

// Nothing to set, Compiler provided default constructor is sufficient

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************


/*************************************************************************
	
	Function Name:	Warehouse::execTransFile

	Purpose:		Reads through the transaction file and executes the
					commands. If an unknown command is given, will display
					and error to the user.
	
	Parameters:		
		const char* filename:	The name of the transaction file.

**************************************************************************/
void Warehouse::execTransFile(const char* filename)
{
	// Open file pointer
	ifstream infile(filename); 

	// Size of the char arrays
	const int SIZE = 20;

	// holds the line read in from the file
	char line[SIZE];

	// points to the input string after strtok has removed \r\n
	char *buffer;
	
	// store the command and the idNumber
	char command[SIZE];
	int idNumber;

	// keeps track of the line number
	int lineCount = 0;

	// check for successful open
	if(!infile)
	{
		cerr << "Error in opening input file: " << filename << endl;
		exit(1);
	}
	
	// loop through file
	while(infile.getline(line, SIZE))
	{
		lineCount++;

		// remove \r\n
		buffer = strtok(line, "\r\n");

		// check if line is blank
		if(buffer)
		{
			// get command
			strcpy(command, strtok(buffer, " "));

			// get idNumber
			idNumber = atoi(strtok(NULL," "));

			// add item
			if( !(strcmp(command, "add")))
			{
				inventory.add(idNumber);
			}

			// subtract item
			else if( !(strcmp(command, "subtract")))
			{
				inventory.subtract(idNumber);
			}
			
			// print list
			else if( !(strcmp(command, "print")))
			{
				inventory.print();
			}

			// misspelled command
			else
			{
				cout << "Bad transaction: " << command << " in line #" << lineCount << endl;
			}
		}
	}

	// close infile
	infile.close();
}

