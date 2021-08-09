/***************************************************************************
* Program name:         bluemen.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Blue Men class.
* * It is a derived class of the abstract class Character. It overrides the
* * functions defense(), attack(), rollDice() and has it's own constructor.
* * It also has additional function called rollDiceDefense(), and an 
* additional private member variable numDefenseDie.  
***************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "character.hpp"
#include <string>
using std::string;

class BlueMen : public Character 
{
	protected:
		int numDefenseDie;
	public:
		BlueMen();
		~BlueMen();
		void defense(int d) override;
		void rollDiceDefense();	// added function
		void rollDice() override; 
		int attack() override; 
};
#endif
