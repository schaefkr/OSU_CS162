/*****************************************************************************************
* Program name:         shop.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Shop class.
                        The Shop class is a derived class of Space. Each Shop object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Shop object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#ifndef SHOPE_HPP
#define SHOP_HPP
#include "space.hpp"
#include "player.hpp"	

class Shop : public Space  
{
	private:

	public:
		Shop(Player *playerPtr);
		bool spaceEvent(Space *playerPosPtr, Space *headPtr) override;
		int genRandomEvent() override;
};
#endif

