/***************************************************************************
* Program name:         team.cpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:		This is the source file for the Team class.
* It is a doubly-linked list with contains nodes of Character objects 
* representing the team lineups (2) of the tournament. The list functions
* according to a first-in-first-out (FIFO) method. The class has functions
* to add a Character object to the back of the list, addBack(), to check
* if the list is empty, isEmpty(), and to push a Character to the 
* back of the list, pushBack(). It also has a destrutor to delete the 
* dynamically allocated memory once the program has ended. 
***************************************************************************/

#include "team.hpp"
#include "character.hpp"
#include "loser.hpp"
#include <iostream>
using std::endl;
using std::cout;

/***************************************************************************
Team::Team()
Description: Constructor
***************************************************************************/
Team::Team()
{

}

/***************************************************************************
Team::~Team()
Description: Destructor. The destuctor goes through the DLL using a temp 
pointer and deletes each node, starting at the head node.  
***************************************************************************/
Team::~Team()
{

}


/***************************************************************************
void Team::deleteTeam()
Description: Destructor. This function goes through the DLL using a temp 
pointer and deletes each node, starting at the head node.  
***************************************************************************/
void Team::deleteTeam()
{
	Character *nodePtr = head;
	while (nodePtr)
	{
		Character *garbage = nodePtr;
		nodePtr = nodePtr->getNext();
		delete garbage;
	}
}

/***************************************************************************
Character * Team::getFront()
Description: This function returns a pointer to the head Character object
node in the DLL. 
***************************************************************************/
Character * Team::getFront()
{
	return head;	
}

/***************************************************************************
void Team::pushBack()
Description: This function reassigns the head and tail pointers in the DLL
so that the head Character object node is sent to the back of the list. 
This represents that a character has won a battle round. 
***************************************************************************/
void Team::pushBack()
{
	Character *winner = head;	
	Character *nextPlayer = head->getNext();	
	// 1 player
	if (head == tail)
	{
		// do nothing
	}
	// 2 or more players
	else
	{
		winner->setPrev(tail);	
		winner->setNext(0);
		tail->setNext(winner); 	
		nextPlayer->setPrev(0);
		head = nextPlayer;
		tail = winner;
	}		
}

/***************************************************************************
void Team::addBack()
Description: This function is used to create the team line-ups, which 
consist of doubly-linked lists. The list is organized in a first-in-last-out
method, thus each new Character that is added to the lineup is added to the 
back of the list.
***************************************************************************/
void Team::addBack(Character *player)
{
	Character *newPlayer = player;
	if (isEmpty())
	{
		tail = newPlayer; 
		tail->setNext(0);
		tail->setPrev(0);
		head = tail;
	}
	else
	{
		tail->setNext(newPlayer);
		newPlayer->setPrev(tail);
		newPlayer->setNext(0);
		tail = newPlayer; 
	}	
}

/***************************************************************************
Character * Team::removeFront()
Description: This function removes the loser Character object node from the
front of the list and returns that Character pointer to the Loser class so 
that that Character can be added to the loser pile or DLL. To remove the 
head object the head and tail pointers are reassigned. 
***************************************************************************/
void Team::removeFront()
{
	Character *newHead = head->getNext(); 
	// 1 item in list
	if (head == tail)
	{
		head = nullptr;
	}
	// 2 or more items in list
	else
	{
		newHead->setPrev(0);
		head = newHead;
	}	
}

/***************************************************************************
bool Team::isEmpty()
Description: This function checks whether the list is empty by seeing if 
head is empty/assigned or not. It returns a boolean value indicating if the 
list is empty or not. 
***************************************************************************/
bool Team::isEmpty()
{
	if (head)
	{
		return false;
	}
	else 
	{
		return true;
	}
}



