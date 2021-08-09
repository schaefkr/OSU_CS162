/***************************************************************************
* Program name:         character.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Character class.
* It is an abstract class. Its derived classes are Barbarian, Vampire, 
* HarryPotter, Medusa and Bluemen. The class is treated as a node object, 
* with next and prev pointers to Character objects for the doubly-linked 
* list objects Team and Loser. 
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

		// project 4 new member variables
		string playerName;
		Character *next = nullptr;	// next ptr for doubly-linked list node	
		Character *prev = nullptr;	// prev ptr for doubly-linked list node	
		int recov;
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

		// project 4 new member functions
		string getPlayerName();
		void setPlayerName(string playerName);
		void setPrev(Character *prevPlayer);
		void setPrev(int val);
		Character * getPrev();
		void setNext(Character *nextPlayer);
		void setNext(int val);
		Character * getNext();
		void recovery();	
		int getRecovery();	
};
#endif
