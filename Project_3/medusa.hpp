/***************************************************************************
* Program name:         medusa.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Medusa class. 
***************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "character.hpp"
#include "barbarian.hpp"
#include <string>
using std::string;

class Medusa : public Barbarian
{
	protected:
	
	public:
		Medusa();
		~Medusa();
		int attack() override;
		void rollDice() override;
		void rollDiceAttack(); 	//added function
};
#endif
