/***************************************************************************
* Program name:		medusa.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Medusa class. 
***************************************************************************/

#include "medusa.hpp"
#include "character.hpp"
#include "barbarian.hpp"
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
Medusa::Medusa() : Barbarian()
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
Description:   
***************************************************************************/
int Medusa::attack()
{
	attackVal = 0;
	rollDiceAttack();
	if (roll == 12)
	{
		attackVal = 50;
		cout << "*Glare*" << endl;
		cout << "The defender has turned to stone!" << endl;
		cout << "Medusa winds!" << endl;
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
