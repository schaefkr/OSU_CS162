/***************************************************************************
* Program name:		barbarian.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Barbarian class. 
***************************************************************************/

#include "barbarian.hpp"
#include "character.hpp"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/***************************************************************************
Barbarian::Barbarian()
Description: Constructor
***************************************************************************/
Barbarian::Barbarian() : Character()
{
	strength = 12;
	armor = 0;
	damage = 0;
	name = "Barbarian";
}

/***************************************************************************
Barbarian::~Barbarian()
Description: Destructor
***************************************************************************/
Barbarian::~Barbarian()
{
}

/***************************************************************************
void Barbarian::defense()
Description: The defense function takes the damage attacked, calculates 
the damage inflicted, and applies that damage to the defender's strength
points.
***************************************************************************/
void Barbarian::defense(int d)
{
	damage = d; 

	defenseVal = 0;
	rollDice();
	defenseVal = roll;	

	if (damage <= (defenseVal + armor))
	{
		damage = 0;
	}
	else
	{
		damage -= defenseVal; 
		damage -= armor; 
		strength -= damage; 
	}
}

/***************************************************************************
int Barbarian::attack()
Description: The attack function generates a dice roll and then passes that 
value to the defender's defense function to calculate their damage.  
***************************************************************************/
int Barbarian::attack()
{
	attackVal = 0;
	rollDice();
	attackVal = roll;
	return attackVal;
}

/***************************************************************************
int Barbarian::rollDice()
Description: This function generates a dice roll for Barbarian's attack and
defense functions.
***************************************************************************/
void Barbarian::rollDice()
{
	roll = 0;
	int roll1, roll2 = 0;
	
	// roll 1
	roll1 = rand() % 6 + 1;	
	// roll2 
	roll2 = rand() % 6 + 1;	

	roll = roll1 + roll2;
}
