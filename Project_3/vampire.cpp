/***************************************************************************
* Program name:		vampire.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Vampire class. 
***************************************************************************/

#include "vampire.hpp"
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
Vampire::Vampire()
Description: Constructor
***************************************************************************/
Vampire::Vampire() : Barbarian()
{
	strength = 18;
	armor = 1;
	damage = 0;	
	name = "Vampire";	
}

/***************************************************************************
Vampire::~Vampire()
Description: Destructor
***************************************************************************/
Vampire::~Vampire()
{

}

/***************************************************************************
void Vampire::defense()
Description: The defense funtion takes the damage attacked, calculates 
the damage inflicted, and applies that damage to the defender's strength
points. If charm is activated, then the damage is 0.
***************************************************************************/
void Vampire::defense(int d)
{
	damage = d; 

	defenseVal = 0;
	rollDefenseDice();
	defenseVal = roll;	

	int charm = 0;
	charm = rand() % 2 + 1;
	
	// charm
	if (charm == 1)
	{
		if (damage <= (defenseVal + armor))
		{
			damage = 0;
		}
		else
		{
			damage -= defenseVal - armor; 
			strength -= damage; 
		}
	}
	else
	{
		damage = 0;
		cout << "*Charm*" << endl;
	 	cout << "Vampire has charmed their opponent. Attack is 0!" << endl;
	} 
}

/***************************************************************************
int Vampire::rollDice()
Description: This function generates a dice roll for the Vampire's attack
function.
***************************************************************************/
void Vampire::rollDice()
{
	roll = 0;
	int roll1 = 0;
	
	// roll 1
	roll1 = rand() % 12 + 1;	

	roll = roll1;
}

/***************************************************************************
int Vampire::rollDefenseDice()
Description: This function generates a dice roll for the Vampire's defense
function.
***************************************************************************/
void Vampire::rollDefenseDice()
{
	roll = 0;
	int roll1 = 0;
	
	// roll 1
	roll1 = rand() % 6 + 1;	

	roll = roll1;
}
