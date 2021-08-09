/***************************************************************************
* Program name:         team.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Team class.
* It is a doubly-linked list with contains nodes of Character objects 
* representing the team lineups (2) of the tournament. The list functions
* according to a first-in-first-out (FIFO) method. The class has functions
* to add a Character object to the back of the list, addBack(), to check
* if the list is empty, isEmpty(), and to push a Character to the 
* back of the list, pushBack(). It also has a destrutor to delete the 
* dynamically allocated memory once the program has ended. 
***************************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP
#include "character.hpp"
 
class Team
{
	private:
		Character *head = nullptr;
		Character *tail = nullptr;
	public:
		Team();
		~Team();
		void deleteTeam();
		Character * getFront();			// get fighter to battle at front of list
		void pushBack();			// put winner at back of list
		void addBack(Character *player);	// add player to back of list
		void removeFront();			// remove fighter who lost battle and pass to loser list
		bool isEmpty();
};
#endif 
