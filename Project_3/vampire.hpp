/***************************************************************************
* Program name:         vampire.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Vampire class. 
***************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "character.hpp"
#include "barbarian.hpp"
#include <string>
using std::string;

class Vampire : public Barbarian 
{
	protected:
		
	public:
		Vampire();
		~Vampire();
		void defense(int d) override;
		void rollDice() override;
		void rollDefenseDice();	// added function  
};
#endif
