/***************************************************************************
* Program name:         loser.hpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:          This is the header file for the Loser class.
* It is a doubly-linked list with contains nodes of Character objects 
* representing the loser pile of the tournament. The list functions
* according to a last-in-first-out (LIFO) method. The class has functions
* to add a Character object to the front of the list, addFront(), to check
* if the list is empty, isEmpty(), and to print the list, print(). It also
* has a destructor to delete the dynamically allocated memory once the 
* program has ended.
***************************************************************************/

#ifndef LOSER_HPP
#define LOSER_HPP
#include "character.hpp"

class Loser
{
	private:
		Character *head = nullptr;
		Character *tail = nullptr;
	public:
		Loser();
		~Loser();
		void deleteLoser();
		void addFront(Character *loserPlayer);	// adds a loser player to the front of the list	
		bool isEmpty();
		void print();	
};
#endif

