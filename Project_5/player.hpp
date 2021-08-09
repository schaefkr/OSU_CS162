/*****************************************************************************************
* Program name:         player.hpp
* Author:               Kristin Schaefer
* Date:                 6-11-2019
* Description:          This file contains the the header file for the Player class.
			The Player class contains a queue structure of strings 
			representing the player's bag and the items in it. It also 
			contains the variables representing the player's money, transit
			money, stress level and time.
			It defines functions for the getters and setters for the money, 
			transitMoney, stress and stopwatch variables. It also defines 
			functions for controlling the items in the player's bag (queue
			structure).
*****************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <queue>
#include <string>
using std::string;
using std::queue;

class Player
{
	private:
		queue <string> bag;
		int money;
		int transitMoney;
		int stress;
		int stopwatch;	
		int limit;	
	public:
		Player();
	
		void fillBag();
		void addBack(int val);
		int getItemCount();
		void removeFront();
		bool checkBag(int val);
		void printBag();	
		string getFront();
	
		void setMoney(int val);
		int getMoney();
		void setTransitMoney(int val);
		int getTransitMoney();
		void setStress(int val);
		int getStress();
		void setStopwatch(int val);
		int getStopwatch();
};
#endif

