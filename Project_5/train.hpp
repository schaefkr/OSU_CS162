/*****************************************************************************************
* Program name:         train.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Train class.
                        The Train class is a derived class of Space. Each Train object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Train object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef TRAIN_HPP
#define TRAIN_HPP
#include "space.hpp"
#include "player.hpp"	

class Train : public Space  
{
	private:

	public:
		Train(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
		void takeTrain(); 
};
#endif

