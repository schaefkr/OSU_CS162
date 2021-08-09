/***************************************************************************
* Program name:		medusa.cpp
* Author:		Kristin Schaefer
* Date:			05-26-2019
* Description:		This is the source file for the Medusa class.
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor.
* It also has additional function called rollDefenseAttack().  
***************************************************************************/

#include "medusa.hpp"
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
Medusa::Medusa()
Description: Constructor
***************************************************************************/
Medusa::Medusa() : Character()
{
	strength = 8;
	armor = 3;
	damage = 0;
	name = "Medusa";	
}

/***************************************************************************
Medusa::~Medusa()
Description: Destructor
***************************************************************************/
Medusa::~Medusa()
{
}

/***************************************************************************
int Medusa::attack()
Description: The attack function generates a dice roll and then passes that 
value to the defender's defense function to calculate their damage. It
has a special part called Glare which makes Medusa's attack value 20 
(higher than any of the character's total strength points), thus causing 
her to win the round. 
***************************************************************************/
int Medusa::attack()
{
	attackVal = 0;
	rollDiceAttack();
	if (roll == 12)
	{
		attackVal = 20;
		//cout << "*Glare*" << endl;
		//cout << "The defender has turned to stone!" << endl;
		//cout << "Medusa wins!" << endl;
	}  
	else
	{
		attackVal = roll;
	}	
	return attackVal;
}

/***************************************************************************
int Medusa::rollDice()
Description: This function generates the dice roll for Medusa's defense 
function. 
***************************************************************************/
void Medusa::rollDice()
{
	int roll1 = 0;
	roll = 0;
	
	// roll 1
	roll1 = rand() % 6 + 1;

	roll = roll1;
}

/***************************************************************************
int Medusa::rollDiceAttack()
Description: This function generates the dice roll for Medusa's attack
function. 
***************************************************************************/
void Medusa::rollDiceAttack()
{
	int roll1, roll2 = 0;
	roll = 0;
	
	// roll 1
	roll1 = rand() % 6 + 1;
	// roll 2
	roll2 = rand() % 6 + 1;

	roll = roll1 + roll2;
}

/***************************************************************************
void Medusa::defense(int d)
Description: The defense function takes the damage attacked, calculates 
the damage inflicted, and applies that damage to the defender's strength
points.
***************************************************************************/
void Medusa::defense(int d)
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
