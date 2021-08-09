




#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "zoo.hpp"
	
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int arraySize = 10;
	Tiger tigerArray[arraySize];
	Turtle turtleArray[arraySize];
	Penguin penguinArray[arraySize];	
	Zoo zooTycoon(tigerArray, turtleArray, penguinArray, arraySize);
	bool playGame, keepPlaying, balancePositive; 
	
	playGame = zooTycoon.startMenu();
	if (playGame)
	{
		zooTycoon.startBusiness();
		zooTycoon.playGame();
		keepPlaying = zooTycoon.playAgain();
		balancePositive = zooTycoon.outOfMoney();
	}	

	while (keepPlaying && balancePositive)	
	{
		zooTycoon.playGame();
		keepPlaying = zooTycoon.playAgain();
		balancePositive = zooTycoon.outOfMoney();
	}
		
	return 0;
}

