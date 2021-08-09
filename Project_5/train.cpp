/*****************************************************************************************
* Program name:         train.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Train class.
                        The Train class is a derived class of Space. Each Train object is 
                        designed to act like a node in a linked list. It has Space 
                        pointers to the Spaces up, right, down, and left on the map. It
                        defines functions for the actions of the Train object, spaceEvent(), 
                        and a function to generate in int for a random function.
*****************************************************************************************/

#include "train.hpp"
#include "space.hpp"
#include "player.hpp" 
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::endl;

/*****************************************************************************************
Train::Train(Player *playerPtr) : Space()
Description: Constructor. Takes a pointer to a Player object and sets the pointer
accordingly. Also sets the spaceType and printType. 
*****************************************************************************************/
Train::Train(Player *playerPtr) : Space()
{
	spaceType = "Train";
	printType = "    Train   ";
	player1 = playerPtr;
}

/*****************************************************************************************
bool Train::spaceEvent(Space *playerPosPtr, Space *headPtr)
Description: This function takes two Space pointers as parameters. This first, a pointer
to the player's current position on the map, the second a pointer to the head pointer of
the map, or the home position. The function gets a random event int from the
genRandomEvent() function and then executes the random event accordingly. 
*****************************************************************************************/
bool Train::spaceEvent(Space *playerPosPtr, Space *headPtr)
{
	int num = 0;
	
	// generate random event
	num = genRandomEvent();
	// train is late 
	if (num == 1)
	{
		cout << "Baaa. The train is running late." << endl;  
		cout << "Time: +10 minutes" << endl;
		cout << "Stress Level: +3 pts" << endl;
		player1->setStopwatch(10);
		player1->setStress(3);
	}
	// someone is playing guitar 
	else if ((num == 2)  && (player1->getMoney() >= 5))
	{
		cout << "Someone is playing guitar at the station. You give $5." << endl;
		cout << "Wallet: -$5" << endl;
		player1->setMoney(-5); 
		if (player1->getStress() >= 2)
		{
			player1->setStress(-2);
			cout << "Stress Level: -2 pts" << endl;
		}
	}
	// else no random event occurs
	
	takeTrain();

	return false;
}

/*****************************************************************************************
int Train::genRandomEvent()
Description: This function generates a random integer, and returns that integer so a 
random event can be executed in the spaceEvent() function.
*****************************************************************************************/
int Train::genRandomEvent()
{
	int num = 0;
	num = rand() % 3 + 1;
}

/*****************************************************************************************
void Train::takeTrain()
Description: This function checks if the user has enough money on their transit card to 
take the train. If they do not have enough money on their transit card, the user must add
$10 from their wallet to their transit card. If the user does not have enough money to 
top up their transit card a message is printed that they must first visit an atm.
*****************************************************************************************/
void Train::takeTrain()
{
	if (player1->getTransitMoney() >= 5)
	{
		player1->setTransitMoney(-5);
		cout << "The train is busy, but you got a seat." << endl;	
		cout << "Transit Card: -$5" << endl; 
		cout << "Time: +5 minutes" << endl; 
		player1->setTransitMoney(-5);
		player1->setStopwatch(5);
	}
	if ((player1->getTransitMoney() < 5) && (player1->getMoney() >= 10))
	{
		cout << "You need $5 on your transit card to take the train." << endl;
		cout << "You topped up your transit card with $10." << endl;
		cout << "Wallet: -$10" << endl; 
		cout << "Transit Card: +$10" << endl; 
		player1->setMoney(-10);
		player1->setTransitMoney(10);
		cout << "You can now take the train." << endl;
		cout << "Transit Card: -$5" << endl; 
		cout << "Time: +5 minutes" << endl; 
		player1->setTransitMoney(-5);
		player1->setStopwatch(5);
	} 		
	if ((player1->getTransitMoney() < 5) && (player1->getMoney() < 10))
	{
		cout << "You need $5 on your transit card to take the train." << endl;
		cout << "You need $10 in your wallet to top up your transit card." << endl;
		cout << "Please visit an ATM at 7-11 to withdraw cash." << endl;
	}
}
