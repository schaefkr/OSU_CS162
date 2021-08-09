/***************************************************************************
* Program name:         harrypotter.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the HarryPotter class.
* It is a derived class of the abstract class Character. It overrides the
* functions defense(), attack(), rollDice() and has it's own constructor.
* It also has it's own private member variable life to hold HarryPotter's 
* current number of lives for the defense function.  
***************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "character.hpp"
#include <string>
using std::string;

class HarryPotter : public Character 
{
	protected:
		int life;	
	public:
		HarryPotter();
		~HarryPotter();
		void defense(int d) override;
		int attack() override;
		void rollDice() override;
};
#endif
