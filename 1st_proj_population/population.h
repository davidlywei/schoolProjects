/****************************************************************************************

	Class Name:		Population
		
	Purpose:		Emulates a population of people

	Author:			David Wei
	Date:			11/11/14
	Last Modified:	Initial Revision
	IDE USED:		gcc version 4.8.3 (cygwin64 on Windows 7)

*****************************************************************************************/

#include <cstdlib>
#include <ctime>

//***************************************************************************************
// Classes
//***************************************************************************************

#include "human.h"

//***************************************************************************************
// Class Definition
//***************************************************************************************

class Population
{
	private:
		Human **people;
		unsigned original_size;
		unsigned living;

	public:
		Population(unsigned populationSize);
		~Population();

		void display() const;
		void examinePopulation();
		unsigned getNumberLiving() const;
};

//***************************************************************************************
// Global Variable Declarations
//***************************************************************************************

// array of names that can be assigned to humans
const char* NAMES[] =
	{
	"Negar","Ron","Wayne","Justin","Stephen","Michael","David","Zian","Christopher",
	"Rodney", "Zhaozhen","Tatiana","Sam","Yan","Paul","Romualdo","Dalia",
	"Wee Chong Alex","Richard", "Brandon","Pramodh","Thomas","Bahman","Asim","Yijie",
	"Maya","Bhavya","Erik","Huy","Tiffany", "Xiaolin","Fangyuan","William","Adam","Di",
	"Joe"
	};

// The maximum number of names in the name array
const unsigned NUM_NAMES = 36;

// Sets the maximum age the person can be.
const unsigned MAX_STARTING_AGE = 100;

// Sets the earliest year that a person can be born on.
const unsigned STARTING_YEAR = 1914;

//***************************************************************************************
// Constructors and Destructors
//***************************************************************************************

/*************************************************************************
	
	Purpose:		Creates and populates a human array.
	
	Parameters:		
		unsigned populationSize:	The starting population size of the 
									world

**************************************************************************/
Population::Population(unsigned populationSize)
{
	// set original_size
	original_size = populationSize;
	
	// Sets the number of people who are still alive
	living = populationSize;

	// create people array
	people = new Human*[original_size];

	// generate humans
	for(unsigned i = 0; i < original_size; i++)
	{
		// create temp date for storing a birthday
		Date temp(
					(rand() % 12) + 1,
					(rand() % 31) + 1,
					(rand() % MAX_STARTING_AGE) + STARTING_YEAR
				 );

		// create new human
		people[i] = new Human(NAMES[i % NUM_NAMES], temp);
	}
}

/*************************************************************************

	Purpose:		Robot Uprisi... err Population Destructor		
	
	Parameters:		N/A

**************************************************************************/
Population::~Population()
{
	// Kill All Humans
	for(unsigned i = 0; i < original_size; i++)
	{
		delete people[i];
	}

	// Destroy all cities
	delete [] people;
}

//***************************************************************************************
// Member Function Definitions
//***************************************************************************************

// predeclaration of rollTheDice
float rollTheDice(const unsigned short age);

/*************************************************************************
	
	Function Name:	Population::getNumberLiving

	Purpose:		Returns the number of people who are still alive
	
	Parameters:		N/A

**************************************************************************/
unsigned Population::getNumberLiving() const
{
	return living;
}

/*************************************************************************
	
	Function Name:	Population::display

	Purpose:		Displays the current condition of the population
	
	Parameters:		N/A

**************************************************************************/
void Population::display() const
{
	// print out heading
	cout << "\n-------------------------------------------------\n" << endl;
	cout << "Today is ";
	TODAY.display();
	cout << endl;

	// Print out people
	for(unsigned i = 0; i < original_size; i++)
	{
		if(people[i]->getStatus())
		{
			people[i]->display();
		}
	}

	// print out ending
	cout << "\n-------------------------------------------------\n" << endl;
}

/*************************************************************************
	
	Function Name:	Population::examinePopulation

	Purpose:		Checks to see how many people are still alive
	
	Parameters:		N/A

**************************************************************************/
void Population::examinePopulation()
{
	// loop through Population 
	for(unsigned i = 0; i < original_size; i++)
	{
		// If they are alive
		if(people[i]->getStatus())
		{
			// Determine if they should continue to live
			if(rollTheDice(people[i]->age()) > 0.5)
			{
				// Kill the person
				people[i]->die();

				// reduce the living count
				living--;
			}
		}
	}
}

/*************************************************************************
	
	Function Name:	rollTheDice()

	Purpose:		Determines whether or not someone dies. Statistically
					The older you are, the more likely you are to die.
	
	Parameters:		
		const unsigned short age:	The age of the person in question

**************************************************************************/
float rollTheDice(const unsigned short age)
{
	return static_cast<float>( age * ( rand() % 100 ) / 10000.);
}
