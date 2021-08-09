/***************************************************************************
* Program name:         loadedDie.hpp
* Author:               Kristin Schaefer
* Date:                 04-21-2019
* Description:          This is the source file for the LoadedDie class.
* 			It is a derived class of the class Die.
* Sources:              https://stackoverflow.com/questions/7690580/
*                       how-to-write-c-inheritance-constructors
***************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"
#include "game.hpp"

class LoadedDie : public Die
{
	public:
		LoadedDie(int N);
		int getDieRoll(int r);	
};
#endif 
