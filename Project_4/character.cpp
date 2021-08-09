/***************************************************************************
* Program name:		character.cpp
* Author:		Kristin Schaefer
* Date:			05-26-2019
* Description:		This is the source file for the Character class. 
* It is an abstract class. Its derived classes are Barbarian, Vampire, 
* HarryPotter, Medusa and Bluemen. The class is treated as a node object, 
* with next and prev pointers to Character objects for the doubly-linked 
* list objects Team and Loser.
***************************************************************************/

#include "character.hpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/***************************************************************************
string Character::getAttack()
Description: This function returns the character's attack value.  
***************************************************************************/
int Character::getAttack()
{
	return attackVal;
}

/***************************************************************************
string Character::getDefense()
Description: This function returns the character's defense value.  
***************************************************************************/
int Character::getDefense()
{
	return defenseVal;
}

/***************************************************************************
int Character::getStrength()
Description: This function returns the character's strength value.  
***************************************************************************/
int Character::getStrength()
{
	return strength;
}

/***************************************************************************
int Character::getArmor()
Description: This function returns the character's armor value.  
***************************************************************************/
int Character::getArmor()
{
	return armor;
}

/***************************************************************************
int Character::getDamage()
Description: This function returns the character's damage value.  
***************************************************************************/
int Character::getDamage()
{
	return damage;
}

/***************************************************************************
int Character::getRoll()
Description: This function returns the character's dice roll.  
***************************************************************************/
int Character::getRoll()
{
	return roll;
}

/***************************************************************************
string Character::getName()
Description: This function returns the character's name.  
***************************************************************************/
string Character::getName()
{
	return name;
}

// New functions for Project 4

/***************************************************************************
string Character::getPlayerName()
Description: This function returns the player's name.  
***************************************************************************/
string Character::getPlayerName()
{
	return playerName;
}

/***************************************************************************
void Character::setPlayerName(string playerName)
Description: This function sets the player's name. Which is to be defeined
by the user. 
***************************************************************************/
void Character::setPlayerName(string playerName)
{
	 this->playerName = playerName;
}

/***************************************************************************
void Character::setPrev(Character *prevPlayer)
Description: This function sets the previous pointer of the Character node
to a pointer to a Character object passed as a parameter. 
***************************************************************************/
void Character::setPrev(Character *prevPlayer)
{
	prev = prevPlayer;
}

/***************************************************************************
void Character::setPrev(int val)
Description: This function sets the previous pointer of the Character node
to a pointer to nullptr if 0 is passed as a parameter. It is an overloaded
function. 
***************************************************************************/
void Character::setPrev(int val)
{
	if (val == 0)
	{
		prev = nullptr;
	}
}

/***************************************************************************
Character * Character::getPrev()
Description: This function returns a pointer to a Character object
indicating the previous Character of the node.
***************************************************************************/
Character * Character::getPrev()
{
	return prev;	
}

/***************************************************************************
void Character::setNext(Character *nextPlayer)
Description: This function sets the next pointer of the Character node
to a pointer to a Character object passed as a parameter. 
***************************************************************************/
void Character::setNext(Character *nextPlayer)
{
	next = nextPlayer;
}

/***************************************************************************
void Character::setPrev(int val)
Description: This function sets the next pointer of the Character node
to a pointer to nullptr if 0 is passed as a parameter. It is an overloaded
function. 
***************************************************************************/
void Character::setNext(int val)
{
	if (val == 0)
	{
		next = nullptr;
	}
}

/***************************************************************************
Character * Character::getNext()
Description: This function returns a pointer to a Character object
indicating the next Character for the node.
***************************************************************************/
Character * Character::getNext()
{
	return next;	
}

/***************************************************************************
void Character::recovery()
Description: This function reduces 25, 50 or 75% of the damage taken by the 
Character during a battle round based on the value of their dice roll. 
***************************************************************************/
void Character::recovery()
{
	recov = 0;

	if (roll < 7)
	{
		recov = (damage + 2);	
		strength += recov;
	}
	else 
	{
		recov = (damage + 4);	
		strength += recov;
	}
}

/***************************************************************************
int Character::getRecovery()
Description: This function returns the recovery value.
***************************************************************************/
int Character::getRecovery()
{
	return recov;
} 
