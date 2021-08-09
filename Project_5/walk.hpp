/*****************************************************************************************
* Program name:         walk.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Walk class.
                        The Walk class is a derived class of Space. Each Walk object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Walk object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef WALK_HPP
#define WALK_HPP
#include "space.hpp"
#include "player.hpp"	

class Walk : public Space  
{
	private:

	public:
		Walk(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
};
#endif

