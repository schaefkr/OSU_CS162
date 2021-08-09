/*****************************************************************************************
* Program name:         player.cpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the source file for the Player class.
                        It defines functions for the getters and setters for the money, 
                        transitMoney, stress and stopwatch variables. It also defines 
                        functions for controlling the items in the player's bag (queue
                        structure).	
*****************************************************************************************/

#include "player.hpp"
#include "menu.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::string;
using std::queue;

//1 = wallet
//2 = phone
//3 = transit pass
//4 = work ID
//5 = donuts
//6 = coffee

/*****************************************************************************************
Player::Player()
Description: Constructor. It initializes the values for money, transitMoney, stress, 
stopwatch and limit (for the bag). It also calls the fillBag() function to fill the 
player's bag with starting items. 
*****************************************************************************************/
Player::Player()
{
	money = 20;
	transitMoney = 10;
	stress = 0;
	stopwatch = 0;
	limit = 10;
	fillBag();
}

/*****************************************************************************************
void Player::fillBag()
Description: This function fills the player's bag with starting items wallet, phone, 
transit pass and work ID. Each item is a string.
*****************************************************************************************/
void Player::fillBag()
{
	addBack(1);
	addBack(2);
	addBack(3);
	addBack(4);
}

/*****************************************************************************************
void Player::addBack(int val)
Description: This function checks that the bag limit of 10 items is not exceeded and then 
adds the item to the back of the queue based on the int value passed as a parameter.
*****************************************************************************************/
void Player::addBack(int val)
{
	if (getItemCount() >= limit)	
	{	
		cout << "Your bag cannot hold any more items!" << endl;
	}
	else
	{
		string item;
		if (val == 1)
		{
			item = "wallet";
		}
		else if (val == 2)
		{
			item = "phone";
		}
		else if (val == 3)
		{
			item = "transit pass";
		}
		else if (val == 4)
		{
			item = "work ID";
		}
		else if (val == 5)
		{
			item = "donuts";
		}
		else 
		{
			item = "coffee";
		}
		bag.push(item);
	}
}

/*****************************************************************************************
int Player::getItemCount()
Description: This function checks the total number of items in the bag by checking the 
size of the queue. It then returns the item count as an integer.
*****************************************************************************************/
int Player::getItemCount()
{
	return bag.size();
}

/*****************************************************************************************
void Player::removeFront()
Description: This function checks if the bag is empty, and if it is not, then it removes
the front item in the bag.
*****************************************************************************************/
void Player::removeFront()
{
	if (!bag.empty())
	{
		bag.pop();
	}
}

/*****************************************************************************************
void Player::printBag()
Description: This function prints the bag's contents by creating a temp queue and then 
printing each item and then popping it off the queue until the queue is empty. 
*****************************************************************************************/
void Player::printBag()
{
	queue <string> tempBuffer = bag;
	while (!tempBuffer.empty())	
	{
		if (tempBuffer.size() > 1)
		{
			cout << tempBuffer.front() << ", ";
		}
		else 
		{
			cout << tempBuffer.front();
		}
		tempBuffer.pop();
	}
}

/*****************************************************************************************
bool Player::checkBag(int val)
Description: This function checks the bag for an item specified in the parameter as an 
integer. If the item is found, a true boolean value is returned. If it is not found, a 
false boolean value is returned.
*****************************************************************************************/
bool Player::checkBag(int val)
{
	queue <string> tempBuffer = bag;
	string item;

	if (val == 1)
	{
		item = "wallet";
	}
	else if (val == 2)
	{
		item = "phone";
	}
	else if (val == 3)
	{
		item = "transit pass";
	}
	else if (val == 4)
	{
		item = "work ID";
	}
	else if (val == 5)
	{
		item = "donuts";
	}
	else 
	{
		item = "coffee";
	}

	while (!tempBuffer.empty())	
	{
		if (tempBuffer.front() == item)
		{
			return true;	
		}	
		tempBuffer.pop();
	}
}

/*****************************************************************************************
string Player::getFront()
Description: This function gets the front value of the player's bag and then returns that
item as a string. 
*****************************************************************************************/
string Player::getFront()
{
	if (!bag.empty())
	{
		return bag.front();
	} 
}

/*****************************************************************************************
void Player::setMoney(int val)
Description: This function takes an integer value (neg. or pos.) and adds it to the 
player's money variable.
*****************************************************************************************/
void Player::setMoney(int val)
{
	money += val;
}

/*****************************************************************************************
int Player::getMoney()
Description: This function returns the money variable as an integer value.
*****************************************************************************************/
int Player::getMoney()
{
	return money;
}

/*****************************************************************************************
void Player::setTransitMoney(int val)
Description: This function takes an integer value (neg. or pos.) and adds it to the 
player's transitMoney variable.
*****************************************************************************************/
void Player::setTransitMoney(int val)
{
	transitMoney += val;
}

/*****************************************************************************************
int Player::getTransitMoney()
Description: This function returns the transitMoney variable as an integer value.
*****************************************************************************************/
int Player::getTransitMoney()
{
	return transitMoney;
}

/*****************************************************************************************
void Player::setStress(int val)
Description: This function takes an integer value (neg. or pos.) and adds it to the 
player's stress variable.
*****************************************************************************************/
void Player::setStress(int val)
{
	stress += val;
	if (stress < 0)
	{
		stress = 0;
	} 
}

/*****************************************************************************************
int Player::getStress()
Description: This function returns the stress variable as an integer value.
*****************************************************************************************/
int Player::getStress()
{
	return stress;
}

/*****************************************************************************************
void Player::setStopwatch(int val)
Description: This function takes an integer value (neg. or pos.) and adds it to the 
player's stopwatch variable.
*****************************************************************************************/
void Player::setStopwatch(int val)
{
	stopwatch += val;
	if (stopwatch < 0)
	{
		stopwatch = 0;
	} 
}

/*****************************************************************************************
int Player::getStopwatch()
Description: This function returns the stopwatch variable as an integer value.
*****************************************************************************************/
int Player::getStopwatch()
{
	return stopwatch;
}


