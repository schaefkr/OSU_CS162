/***************************************************************************
* Program name:		bluemen.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Blue Men class. 
***************************************************************************/

#include "bluemen.hpp"
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
BlueMen::BlueMen()
Description: Constructor
***************************************************************************/
BlueMen::BlueMen() : Barbarian()
{
	strength = 12;
	armor = 3;
	damage = 0;	
	name = "Blue Men";
	numDefenseDie = 3;	
}

/***************************************************************************
BlueMen::~BlueMen()
Description: Destructor
***************************************************************************/
BlueMen::~BlueMen()
{

}

/***************************************************************************
void BlueMen::defense()
Description: The defense funtion takes the damage attacked, calculates 
the damage inflicted, and applies that damage to the defender's strength
points. If the bluemeen lose 4 pts of strength, then the number of dice is 
reduced by one.
***************************************************************************/
void BlueMen::defense(int d)
{
	damage = d; 

	defenseVal = 0;
	rollDiceDefense();
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
	
	if (damage > 0)
	{
		if (strength == 8 || strength == 4)
		{
			numDefenseDie--;
			cout << "*Mob*" << endl;
			cout << "The Blue Men have lost a die!" << endl;
		}
	}
}

/***************************************************************************
void rollDiceDefense()
Description: This function generates a dice roll for the blue men's defense
function. If the bluemen lose 4 pts of strength, then the number of dice is
reduced by one.  
***************************************************************************/
void BlueMen::rollDiceDefense()
{
	roll = 0;
	int roll1, roll2, roll3 = 0; 
	if (numDefenseDie == 3)
	{
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;
		roll3 = rand() % 6 + 1;
		roll = roll1 + roll2 + roll3;	
	}
	else if (numDefenseDie == 2) 
	{
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;
		roll = roll1 + roll2;
	}
	else
	{
		roll1 = rand() % 6 + 1;
		roll = roll1;
	}
}

/***************************************************************************
void rollDice()
Description: This function generatea a dice roll for the blue men's attack
function. 
***************************************************************************/
void BlueMen::rollDice()
{
	roll = 0;
	int roll1, roll2 = 0;
	
	// roll 1
	roll1 = rand() % 10 + 1;	
	
	// roll 2
	roll1 = rand() % 10 + 1;	

	roll = roll1 + roll2;
} 
