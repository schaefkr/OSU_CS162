/***************************************************************************
* Program name:		harrypotter.cpp
* Author:		Kristin Schaefer
* Date:			05-26-2019
* Description:		This is the source file for the Harry Potter class.
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor. 
***************************************************************************/

#include "harrypotter.hpp"
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
HarryPotter::HarryPotter()
Description: Constructor
***************************************************************************/
HarryPotter::HarryPotter() : Character()
{
	strength = 10;
	armor = 0;
	damage = 0;	
	name = "Harry Potter";	
	life = 1;
}

/***************************************************************************
HarryPotter::~HarryPotter()
Description: Destructor
***************************************************************************/
HarryPotter::~HarryPotter()
{

}

/***************************************************************************
void HarryPotter::defense()
Description: The defense funtion takes the damage attacked, calculates 
the damage inflicted, and applies that damage to the defender's strength
points. Harry Potter gets an extra life, so if his strength points go to 
0 or below, then he come back to life and receives 20 strength points.
***************************************************************************/
void HarryPotter::defense(int d)
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
		damage -= defenseVal - armor; 
		strength -= damage; 
	}
	
	if ((strength <= 0) && (life == 1))
	{
		strength = 20;
		life--;
		//cout << "*Hogwarts*" << endl;
 		//cout << "Harry Potter has recovered!" << endl;
	}
}

/***************************************************************************
int HarryPotter::attack()
Description: The attack function generates a dice roll and then passes that 
value to the defender's defense function to calculate their damage.  
***************************************************************************/
int HarryPotter::attack()
{
	attackVal = 0;
	rollDice();
	attackVal = roll;
	return attackVal;
}

/***************************************************************************
int HarryPotter::rollDice()
Description: This function generates a dice roll for Barbarian's attack and
defense functions.
***************************************************************************/
void HarryPotter::rollDice()
{
	roll = 0;
	int roll1, roll2 = 0;
	
	// roll 1
 	roll1 = rand() % 6 + 1;	
	// roll2 
	roll2 = rand() % 6 + 1;	

	roll = roll1 + roll2;
}
