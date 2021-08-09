/***************************************************************************
* Program name:         medusa.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Medusa class.
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor.
* It also has additional function called rollDefenseAttack().   
***************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"
#include <string>
using std::string;

class Medusa : public Character 
{
	protected:
	
	public:
		Medusa();
		~Medusa();
		int attack() override;
		void rollDice() override;
		void rollDiceAttack(); 	//added function
		void defense(int d) override;
};
#endif
