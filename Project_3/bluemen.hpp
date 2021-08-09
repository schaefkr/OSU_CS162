/***************************************************************************
* Program name:         bluemen.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Blue Men class. 
***************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "character.hpp"
#include "barbarian.hpp"
#include <string>
using std::string;

class BlueMen : public Barbarian 
{
	protected:
		int numDefenseDie;
	public:
		BlueMen();
		~BlueMen();
		void defense(int d) override;
		void rollDiceDefense();	// added function
		void rollDice() override; 
};
#endif
