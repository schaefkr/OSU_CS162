/***************************************************************************
* Program name:         character.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Character class. 
***************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
using std::string;

class Character
{
	protected:
		int attackVal, defenseVal;
		int armor;
		int strength;
		int damage; 
		int roll;
		string name;
	public:
		int getAttack();
		int getDefense();
		int getArmor();
		int getStrength();
		int getDamage();
		int getRoll();
		string getName();
		virtual int attack() = 0;
		virtual void defense(int d) = 0;
		virtual void rollDice() = 0;
};
#endif
