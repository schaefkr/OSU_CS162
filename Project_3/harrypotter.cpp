/***************************************************************************
* Program name:		harrypotter.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Harry Potter class. 
***************************************************************************/

#include "harrypotter.hpp"
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
HarryPotter::HarryPotter()
Description: Constructor
***************************************************************************/
HarryPotter::HarryPotter() : Barbarian()
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
	
	if ((strength <= 0) && (life = 1))
	{
		strength = 20;
		life--;
		cout << "*Hogwarts*" << endl;
 		cout << "Harry Potter has recovered!" << endl;
	}
}
