/***************************************************************************
* Program name:         Zoo.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the Header file for the Zoo class. 
***************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"

class Zoo
{
	private:
		Tiger *tigerPtr = nullptr;
		Turtle *turtlePtr = nullptr;
		Penguin *penguinPtr = nullptr; 
		int days;
		int numTigers, numPenguins, numTurtles;
		int tigerArraySize, turtleArraySize, penguinArraySize;
		double balance, dailyFeedingCost, profit, bonus;
		int validate1or2();
		int validate1or2or3();
		void purchaseNewAnimal();
		int randomEvent();
		int getRandomEvent();
		double getRandomBonus();
		int getRandomAnimal();
		void animalBorn(int type);	
	public: 
		Zoo(Tiger *tig, Turtle *turt, Penguin *pen, int size);
		~Zoo();
		bool startMenu();
		void startBusiness();
		double getBalance();
		bool outOfMoney();
		bool playAgain();
		void playGame();
		void deallocateMemory();	
};
#endif
