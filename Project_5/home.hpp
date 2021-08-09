/*****************************************************************************************
* Program name:         home.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Home class.
                        The Home class is a derived class of Space. Each Home object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Home object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef HOME_HPP
#define HOME_HPP
#include "space.hpp"
#include "player.hpp"	

class Home : public Space  
{
	private:

	public:
		Home(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
};
#endif

