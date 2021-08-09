/***************************************************************************
* Program name:         harrypotter.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Harry Potter class. 
***************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "character.hpp"
#include "barbarian.hpp"
#include <string>
using std::string;

class HarryPotter : public Barbarian 
{
	protected:
		int life;	
	public:
		HarryPotter();
		~HarryPotter();
		void defense(int d) override;
};
#endif
