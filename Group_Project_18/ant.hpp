/***************************************************************************************************
* Program name:         Ant.hpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the header file for the Ant class for the
*                       Predator-Prey Game.
***************************************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "getRandomNumber.hpp"
#include "critter.hpp"

class Ant : public Critter
{
	private:

	public:
		Ant();
        // Ant takes x, y, number of steps, time steps, size of grid by row x col
		Ant(int, int, int, int, int, int);

		virtual void move(Critter ***,int,int,int);
        virtual void breed(Critter ***,int,int,int);

};
#endif
