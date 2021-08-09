/*****************************************************************************************
* Program name:         work.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Work class.
                        The Work class is a derived class of Space. Each Work object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Work object, spaceEvent(), 
			and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef WORK_HPP
#define WORK_HPP
#include "space.hpp"
#include "player.hpp"	

class Work : public Space  
{
	private:

	public:
		Work(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
};
#endif

