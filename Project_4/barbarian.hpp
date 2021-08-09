/***************************************************************************
* Program name:         Barbarian.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Barbarian class. 
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor.
***************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "character.hpp"
#include <string>
using std::string;

class Barbarian : public Character
{
	protected:
	
	public:
		Barbarian();
		~Barbarian();
		virtual int attack() override;
		virtual void defense(int d) override;
		virtual void rollDice() override;
};
#endif
