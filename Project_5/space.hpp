/*****************************************************************************************
* Program name:         space.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Space class.
			The Space class is an abstract class, with it's derived classes
			being Home, Work, Walk, Train, Bus and Shop. Each Space object is
			designed to act like a node in a linked list. It has Space 
			pointers to the Spaces up, right, down, and left on the map. It
			defines functions for setters and getters to the Space object 
			pointers. It also has two pure virtual functions spaceEvent() and 
			genRandomEvent(). 
*****************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include "player.hpp" 
#include <string>
using std::string;

class Space 
{
	protected:
		Space *up = nullptr;
		Space *right = nullptr;
		Space *down = nullptr;
		Space *left = nullptr;
		Player *player1 = nullptr;
		string spaceType;
		string printType;
	public:
		void setUp(Space *upSpace);
		void setUp(int val);
		Space * getUp();
		void setRight(Space *rightSpace);
		void setRight(int val);
		Space * getRight();
		void setDown(Space *downSpace);
		void setDown(int val);
		Space * getDown();
		void setLeft(Space *leftSpace);
		void setLeft(int val);
		Space * getLeft();
		string getSpaceType();
		string getPrintType();
		virtual bool spaceEvent(Space *playerPosPtr, Space *headPtr) = 0;
		virtual int genRandomEvent() = 0;
};
#endif

