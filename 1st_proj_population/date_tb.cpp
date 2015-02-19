/****************************************************************************************
	Description:	
					
	Author:			David Wei
	Date:			
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

//***************************************************************************************
// Prototypes
//***************************************************************************************
#include "date.h"

//***************************************************************************************
// Definition
//***************************************************************************************

int main()
{
	Date d(5, 10, 1000);

	srand(time(NULL));

	d.display();
	cout << endl;
	
	for(int i = 0; i < 3 ; i++)
	{
		d.increment();
		
		d.display();
		cout << endl;
	}

	cout << "\nTotal age: " << d.determineAge() << endl;
	
	d.letTimePass();
	d.letTimePass();
	d.letTimePass();
	d.display();
	
	cout << "\nTotal age: " << d.determineAge() << endl;
	
	return 0;
}

