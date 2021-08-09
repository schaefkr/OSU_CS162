/*****************************************************************************************
* Program name:         bus.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Bus class.
                        The Bus class is a derived class of Space. Each Bus object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Bus object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef BUS_HPP
#define BUS_HPP
#include "space.hpp"
#include "player.hpp"	

class Bus : public Space  
{
	private:

	public:
		Bus(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
		void takeBus();
};
#endif

