/***************************************************************************
* Program name:         loser.cpp
* Author:               Kristin Schaefer
* Date:                 05-26-2019
* Description:		This is the source file for the Loser class.
* It is a doubly-linked list with contains nodes of Character objects 
* representing the loser pile of the tournament. The list functions
* according to a last-in-first-out (LIFO) method. The class has functions
* to add a Character object to the front of the list, addFront(), to check
* if the list is empty, isEmpty(), and to print the list, print(). It also
* has a destructor to delete the dynamically allocated memory once the 
* program has ended.
***************************************************************************/

#include "loser.hpp"
#include "character.hpp"
#include <iostream>
using std::endl;
using std::cout;

/***************************************************************************
Loser::Loser();
Description: Constructor
***************************************************************************/
Loser::Loser()
{

}

/***************************************************************************
Loser::~Loser();
Description: Destructor. The destuctor goes through the DLL using a temp 
pointer and deletes each node, starting at the head node.  
***************************************************************************/
Loser::~Loser()
{

}

/***************************************************************************
void Loser::deleteLoser()
Description: This function goes through the DLL using a temp 
pointer and deletes each node, starting at the head node.  
***************************************************************************/
void Loser::deleteLoser()
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
void Loser::addFront(Character *loserPlayer)
Description: This function takes a pointer to a Character object (node) and
adds it to the front of the list. The function takes into account whether
the list is empty or has 1 or more nodes already. 
***************************************************************************/
void Loser::addFront(Character *loserPlayer)
{
	Character *newHead = loserPlayer;

	if (isEmpty())
	{
		head = newHead;
		tail = head;
		head->setPrev(0);		// nullptr
		head->setNext(0);		// nullptr
	}
	else
	{
		head->setPrev(newHead);
		newHead->setPrev(0);		//nullptr	 
		newHead->setNext(head);	
		head = newHead;
	}
}

/***************************************************************************
bool Loser::isEmpty()
Description: This function checks whether the list is empty by seeing if 
head is empty/assigned or not.
***************************************************************************/
bool Loser::isEmpty()
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

/***************************************************************************
void Loser::print()
Description: This function prints the list from front(head) to back (tail).
It also prints a small titleblock Loser Pile to show that it is printing the 
loser pile contents.
***************************************************************************/
void Loser::print()
{
	Character *tempPrintPtr = head;
	if (isEmpty())
	{
		cout << "There are no losers currently in the lineup." << endl;
	}
	else
	{
		int index = 1;
		cout << endl;
		cout << "------------------------------------------------" << endl;
		cout << "Loser Pile" << endl;
		cout << "------------------------------------------------" << endl;
		
		while (tempPrintPtr)
		{
			cout << index << ". " << tempPrintPtr->getPlayerName() << endl;
			tempPrintPtr = tempPrintPtr->getNext();
			index++;
		}
	}
}
