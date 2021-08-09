/***************************************************************************
* Program name:         vampire.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Vampire class.
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor.
* It also has additional function called rollDefenseDice().  
***************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "character.hpp"
#include <string>
using std::string;

class Vampire : public Character 
{
	protected:
		
	public:
		Vampire();
		~Vampire();
		void defense(int d) override;
		void rollDice() override;
		void rollDefenseDice();	// added function  
		int attack() override;
};
#endif
