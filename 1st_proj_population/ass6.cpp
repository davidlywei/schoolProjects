/****************************************************************************************
	Description:	This program solves Assignment #6

					Simulate the world population
	
	Author:			David Wei
	Date:			11/11/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <iostream>

using namespace std;

//***************************************************************************************
// Classes
//***************************************************************************************

#include "population.h"

//***************************************************************************************
// Main Function
//***************************************************************************************

int main()
{
	const int OriginalPopulationSize = 36;
	
	srand(time(NULL));
	Population World(OriginalPopulationSize);
	World.display();
	
	// let time pass until half of the world's Population dies
	do
	{
		TODAY.letTimePass();
		World.examinePopulation();
	}
	while (World.getNumberLiving() > OriginalPopulationSize/2);
	
	World.display();
}
