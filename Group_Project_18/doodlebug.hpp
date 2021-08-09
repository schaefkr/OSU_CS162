/***************************************************************************************************
* Program name:         doodlebug.hpp
* Group:                Group 18
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the header file for the Doodlebug class for the
*                       Predator-Prey Game.
***************************************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "getRandomNumber.hpp"
#include "critter.hpp"

class Doodlebug : public Critter
{
	private:
		int sp; // starving point

	public:
		Doodlebug();
		Doodlebug(int, int, int, int, int, int, int);

	    virtual void move(Critter***, int, int, int);
		virtual void breed(Critter***, int, int, int);

		int starve(Critter***, int, int, int); // extra function specific to doodlebug
		void setSP(int);
		int getSP();

};
#endif
