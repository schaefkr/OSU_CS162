/***************************************************************************
* Program name:		character.cpp
* Author:		Kristin Schaefer
* Date:			05-12-2019
* Description:		This is the source file for the Character class. 
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
