
/***************************************************************************
* Program name:		Zoo.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description:		This is the Source file for the Zoo class. 
***************************************************************************/

#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <cctype> 

using std::cin;
using std::cout;
using std::endl;
using std::string;

/***************************************************************************
* 				Zoo::Zoo( )
* Description: Constructor
***************************************************************************/
Zoo::Zoo(Tiger *tig, Turtle *turt, Penguin *pen, int size)
{
	tigerPtr = tig;
	turtlePtr = turt;
	penguinPtr = pen;	
	tigerArraySize = size;
	turtleArraySize = size; 
	penguinArraySize = size;
	numTigers = 0;
	numTurtles = 0; 
	numPenguins = 0;
	balance = 100000.00;
	days = 0;	
} 

/***************************************************************************
* 				Zoo::~Zoo( )
* Description: Destructor
***************************************************************************/
Zoo::~Zoo()
{
	delete [] tigerPtr;
	delete [] turtlePtr;
	delete [] penguinPtr;
} 

/***************************************************************************
* 		            bool Zoo::startMenu( )
* Description: This function displays the start menu to the user by asking 
* the user either to input 1 to play the game or 2 to quit.
***************************************************************************/
bool Zoo::startMenu()
{
	int ch;
	bool play;
	
	cout << "1. Play Zoo Tycoon" << endl; 
	cout << "2. Exit" << endl; 

	ch = validate1or2();	
	
	if (ch == 1)
	{
		play = true;
	}	
	else 
	{	
		play = false;
	}
	return play;
}

/***************************************************************************
* 		            void Zoo::startBusiness()
* Description: This function asks the user to buy 1 or 2 of each animal to 
* start their zoo.
***************************************************************************/
void Zoo::startBusiness()
{
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Zoo Tycoon: Start Zoo" << endl; 	
	cout << "--------------------------------------------------" << endl;
	cout << "Your starting balance is: $" << balance << endl;

	// Purchase tigers
	cout << endl;
	cout << "How many tigers would you like to purchase?" << endl; 
	cout << "1. 1 Tiger - $10000" << endl;
	cout << "2. 2 Tigers - $20000" << endl; 
	int ch = validate1or2();
	numTigers += ch;
	for (int i = 0; i < ch+1 ; i++)
	{
		tigerPtr[i].setAge(1);
	}
	balance -= (numTigers * tigerPtr[0].getCost()); 

	// Purchase turtles
	cout << endl;
	cout << "How many turtles would you like to purchase?" << endl; 
	cout << "1. 1 Turtle - $100" << endl;
	cout << "2. 2 Turtles - $200" << endl; 
	ch = validate1or2();
	numTurtles += ch;
	for (int i = 0; i < numTurtles ; i++)
	{
		turtlePtr[i].setAge(1);
	}
	balance -= (numTurtles * turtlePtr[0].getCost());
	
	// Purchase penguins
	cout << endl;
	cout << "How many penguins would you like to purchase?" << endl; 
	cout << "1. 1 Penguin - $1000" << endl;
	cout << "2. 2 Penguin - $2000" << endl; 
	ch = validate1or2();
	numPenguins += ch;
	for (int i = 0; i < numPenguins ; i++)
	{
		penguinPtr[i].setAge(1);
	}
	balance -= (numPenguins * penguinPtr[0].getCost());
}

/***************************************************************************
* 		            int Zoo::validate1or2()
* Description: This function performs input validation for input options of 
* 1 or 2. 
***************************************************************************/
int Zoo::validate1or2()
{
	string choice;
	int c = 0;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("12") !=std::string::npos)
		{
			cout << "Error. Please enter 1 or 2." << endl;
			if (choice.find_first_not_of("12") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 2))
		{
			cout << "Error. Please enter 1 or 2." << endl;
		}
	} while ((c < 1) || (c > 2));
	return c;
}

/***************************************************************************
* 		            int Zoo::validate1or2or3()
* Description: This function performs input validation for input options of 
* 1, 2 or 3.
***************************************************************************/
int Zoo::validate1or2or3()
{
	string choice;
	int c = 0;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("123") !=std::string::npos)
		{
			cout << "Error. Please enter 1 or 2 or 3." << endl;
			if (choice.find_first_not_of("123") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 3))
		{
			cout << "Error. Please enter 1 or 2 or 3." << endl;
		}
	} while ((c < 1) || (c > 3));
	return c;
}

/***************************************************************************
* 		            double Zoo::getBalance()
* Description: This function returnts the user's balance. 
***************************************************************************/
double Zoo::getBalance()
{
	return balance;
} 

/***************************************************************************
* 		            bool Zoo::outOfMoney()
* Description: This function returns a bool value if the user's balance is 
* less than 0.
***************************************************************************/
bool Zoo::outOfMoney()
{
	bool notBroke;

	if (balance > 0)
	{
		notBroke = true;	
	}
	else
	{
		notBroke = false;
		cout << "You are bankrupt. The game will now end." << endl; 
	}
	return notBroke;
}

/***************************************************************************
* 		            bool Zoo::playAgain()
* Description: This function asks the user if they would like to play the 
* zoo game another day.
***************************************************************************/
bool Zoo::playAgain()
{
	int ch;
	bool playAgain;

	cout << endl;
	cout << "Would you like to keep playing Zoo Tycoon?" << endl;	
	cout << "1. Play another day of Zoo Tycoon." << endl; 
	cout << "2. Exit" << endl; 

	ch = validate1or2();	
	
	if (ch == 1)
	{
		playAgain = true;
	}	
	else 
	{	
		playAgain = false;
	}
	return playAgain;
}

/***************************************************************************
* 		            void Zoo::playGame()
* Description: This function contains all of the operations to take place
* at the user's zoo for one day.  
***************************************************************************/
void Zoo::playGame()
{
	// days increment
	days++;
	
	cout << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Day " << days << endl; 	
	cout << "--------------------------------------------------" << endl;

	// increase animal age by 1 day
	if (numTigers > 0)
	{
		for (int i = 0; i < numTigers ; i++)
		{
			tigerPtr[i].setAge(1);
		}
	}
	if (numTurtles > 0)
	{
		for (int i = 0; i < numTurtles ; i++)
		{
			turtlePtr[i].setAge(1);
		}
	}
	if (numPenguins > 0)
	{
		for (int i = 0; i < numPenguins ; i++)
		{
			penguinPtr[i].setAge(1);
		}
	}

	// pay feeding costs for all animals
	dailyFeedingCost = ( numTigers * tigerPtr[0].getBaseFoodCost()
			   + numTurtles * turtlePtr[0].getBaseFoodCost()
			   + numPenguins * penguinPtr[0].getBaseFoodCost()
			   );
	balance -= dailyFeedingCost;	

	// random event takes place
	int event = 1; 
	event = randomEvent();
	
	// calculate profit for the day
	profit = (  numTigers * tigerPtr[0].getPayoff() * tigerPtr[0].getCost()
		  + numTurtles * turtlePtr[0].getPayoff() * turtlePtr[0].getCost()
		  + numPenguins * penguinPtr[0].getPayoff() * penguinPtr[0].getCost()
		 );
	balance += profit;
	// if random event == 2 add to profit
	if (event == 2)
	{
		balance += bonus;
	}
	
	// purchase new animal
	purchaseNewAnimal();
	
	// day summary output
	cout << endl;	
	cout << "--------------------------------------------------" << endl;
	cout << "Day " << days << " summary:" << endl; 	
	cout << "Your profit for day " << days << " is : $" << profit << "." << endl;
	cout << "Your current balance is : $" << balance << "." << endl;
	cout <<	"You have " << numTigers << " tigers." << endl;
	cout << "You have " << numTurtles << " turtles." << endl;
	cout << "You have " << numPenguins << " penguins." << endl; 
	cout << "--------------------------------------------------" << endl;
}

/***************************************************************************
* 		            int Zoo::getRandomEvent()
* Description: This function produces a random integer of 1, 2, 3 or 4
* indicating the type of random even to take place in the function 
* randomEvent(). 
***************************************************************************/
int Zoo::getRandomEvent()
{
	int seed = time(0);
	srand(seed);
	int event = 1;
	event = rand() % 4 + 1;
	return event;  
}

/***************************************************************************
* 		            int Zoo::getRandomAnimal()
* Description: This function produces a random integer of 1, 2 or 3
* indicating the type of animal to perform the function on. 
***************************************************************************/
int Zoo::getRandomAnimal()
{
	int seed = time(0);
	srand(seed);
	int animal = 1;	
	animal = rand() % 3 + 1;
	return animal;  
}

/***************************************************************************
* 		            int Zoo::getRandomBonus()
* Description: This function produces a random bonus for the random event 
* zoo attendance boom in the randomEvent function.
***************************************************************************/
double Zoo::getRandomBonus()
{
	int seed = time(0);
	srand(seed);
	double randomBonus;
	randomBonus = rand() % 250 + 250;
	return randomBonus;  
}

/***************************************************************************
* 		            void Zoo::randomEvent()
* Description: This function contains the 4 different random events which 
* can take place at the zoo. 
***************************************************************************/
int Zoo::randomEvent()
{
	int e = 1;
	e = getRandomEvent(); 

	// zoo sickness
	if (e == 1)
	{
		int a = getRandomAnimal();
		if ((a == 1) && (numTigers > 0))
		{
			tigerPtr[numTigers-1].resetAge();	
			numTigers--;
			cout << "Oh no! One tiger has died." << endl; 
			cout << "You now have " << numTigers << " tigers." << endl;
		}			
		else if ((a == 2) && (numTurtles > 0))
		{
			turtlePtr[numTurtles-1].resetAge();	
			numTurtles--;
			cout << "Oh no! One turtle has died." << endl;
			cout << "You now have " << numTurtles << " turtles." << endl;
		}			
		else if ((a == 3) && (numPenguins > 0))
		{
			penguinPtr[numPenguins-1].resetAge();	
			numPenguins--; 
			cout << "Oh no! One penguin has died." << endl;
			cout << "You now have " << numPenguins << "penguins." << endl;
		}			
	}

	// zoo attendance boom
	else if (e == 2)
	{
		int b = getRandomBonus();
		bonus = numTigers * b;
		cout << "Good news! You have received a bonus of $" << bonus << 
			" for " << numTigers << " tigers." << endl; 
	}

	// zoo baby animal born
	else if (e == 3)
	{
		int a = getRandomAnimal();
		bool tigerAdult, turtleAdult, penguinAdult = false;	
	
		// check for adults
		int i = 0;	
		while ((i < numTigers) && (!tigerAdult))
		{
			if (tigerPtr[i].getAge() >= 3)
			{
				tigerAdult = true;
			}
			i++;
		}
		i = 0;	
		while ((i < numTurtles) && (!turtleAdult))
		{
			if (turtlePtr[i].getAge() >= 3)
			{
				turtleAdult = true;
			}
			i++;
		}
		i = 0;	
		while ((i < numPenguins) && (!penguinAdult))
		{
			if (penguinPtr[i].getAge() >= 3)
			{
				penguinAdult = true;
			}
			i++;
		}
		
		if (a == 1)
		{
			if (tigerAdult)
			{
				// tiger has baby
				animalBorn(1);	
			}	
			else if (!tigerAdult && turtleAdult)
			{
				// turtle has babies
				animalBorn(2);	
			}
			else if (!tigerAdult && !turtleAdult && penguinAdult)
			{
				// penguin has a babies
				animalBorn(3);	
			}
		}
		else if (a == 2)
		{
			if (turtleAdult)
			{
				// turtle has a baby
				animalBorn(2); 	
			}
			else if (!turtleAdult && penguinAdult)
			{
				// penguin has a baby
				animalBorn(3);	
			} 
			else if (!turtleAdult && !penguinAdult && tigerAdult)
			{
				// tiger has a baby
				animalBorn(1);	
			} 
		}
		else if (a == 3)
		{
			if (penguinAdult)
			{
				// penguin has a baby
				animalBorn(3);	
			}
			else if (!penguinAdult && tigerAdult)
			{
				// tiger has a baby
				animalBorn(1);	
			}  
			else if (!penguinAdult && !tigerAdult && turtleAdult)
			{
				// turtle has a baby
				animalBorn(2);	
			}
		}
	}
	return e;
}

/***************************************************************************
* 		            void Zoo::animalBorn(int type)
* Description: This function takes a random integer specifying the type of
* animal that has babies.  
***************************************************************************/
void Zoo::animalBorn(int type)
{
	if (type == 1)
	{
		int tigers = numTigers + tigerPtr[0].getNumBabies(); 
		if (tigers >= tigerArraySize)
		{
			Tiger *tempTigerPtr = new Tiger[tigerArraySize*2];
			for (int i = 0; i < numTigers; i++)	
			{
				tempTigerPtr[i] = tigerPtr[i];
			}
			//delete [] tigerPtr;
			tigerPtr = tempTigerPtr;
			tempTigerPtr = nullptr; 
			tigerArraySize *= 2;
		}
		numTigers += tigerPtr[0].getNumBabies(); 
		cout << "Congratulations! A tiger at your zoo has had " 
	             << tigerPtr[0].getNumBabies() << " baby tiger." << endl;
	}
	else if (type == 2)
	{
		int turtles = numTurtles + turtlePtr[0].getNumBabies(); 
		if (turtles >= turtleArraySize)
		{
			Turtle *tempTurtlePtr = new Turtle[turtleArraySize*2];
			for (int i = 0; i < numTurtles; i++)	
			{
				tempTurtlePtr[i] = turtlePtr[i];
			}	
			//delete [] turtlePtr;
			turtlePtr = tempTurtlePtr;
			tempTurtlePtr = nullptr; 
			turtleArraySize *= 2;
		}
		numTurtles += turtlePtr[0].getNumBabies(); 
		cout << "Congratulations! A turtle at your zoo has had " 
	             << turtlePtr[0].getNumBabies() << " baby turtles." << endl;
	}
	else if (type == 3)
	{
		int penguins = numPenguins + penguinPtr[0].getNumBabies(); 
		if (penguins >= penguinArraySize)
		{
			Penguin *tempPenguinPtr = new Penguin[penguinArraySize*2];
			for (int i = 0; i < penguinArraySize; i++)	
			{
				tempPenguinPtr[i] = penguinPtr[i];
			}	
			//delete [] penguinPtr;
			penguinPtr = tempPenguinPtr;
			tempPenguinPtr = nullptr; 
			penguinArraySize *= 2;
		}
		numPenguins += penguinPtr[0].getNumBabies(); 
		cout << "Congratulations! A penguin at your zoo has had " 
	             << penguinPtr[0].getNumBabies() << " baby penguins." << endl;
	}
}

/***************************************************************************
* 		            void Zoo::purchaseNewAnimal()
* Description: This function asks the user if they would like to purchase
* a new animal for their zoo. If yes, then they can choose which type of 
* animal they would like to purchase.
***************************************************************************/
void Zoo::purchaseNewAnimal()
{ 
	// ask user if they would like to buy another animal
	int ch;
	bool purchaseAnimal;

	cout << endl;
	cout << "Would you like to purchase another animal?" << endl; 
	cout << "1. Yes purchase another animal." << endl; 
	cout << "2. No, don't purchase another animal." << endl; 
	ch = validate1or2();	

	if (ch == 1)
	{
		int choice; 
		cout << "Which type of animal would you like to purchase?" << endl;
		cout << "1. Tiger" << endl;
		cout << "2. Turtle" << endl;
		cout << "3. Penguin" << endl;
		choice = validate1or2or3();
		
		if (choice == 1)
		{
			cout << "You have purchased 1 tiger." << endl;
			numTigers++; 
			if (numTigers == tigerArraySize)
			{
				cout << "updating array size." << endl;
				Tiger *tempTigerPtr = new Tiger[tigerArraySize*2];
				for (int i = 0; i < tigerArraySize; i++)	
				{
					tempTigerPtr[i] = tigerPtr[i];
				}	
				tigerPtr = tempTigerPtr;
				tempTigerPtr = nullptr; 
				tigerArraySize *= 2;
			}
			balance -= tigerPtr[0].getCost();
			tigerPtr[numTigers-1].setAge(3);
		}  
		else if (choice == 2)
		{
			cout << "You have purchased 1 turtle." << endl;
			numTurtles++; 
			if (numTurtles == turtleArraySize)
			{
				cout << "updating array size." << endl;
				Turtle *tempTurtlePtr = new Turtle[turtleArraySize*2];
				for (int i = 0; i < turtleArraySize; i++)	
				{
					tempTurtlePtr[i] = turtlePtr[i];
				}	
				turtlePtr = tempTurtlePtr;
				tempTurtlePtr = nullptr; 
				turtleArraySize *= 2;
			}
			balance -= turtlePtr[0].getCost();
			turtlePtr[numTurtles-1].setAge(3);
		}
		else
		{
			cout << "You have purchased 1 penguin." << endl;
			numPenguins++; 
			if (numPenguins == penguinArraySize)
			{
				cout << "updating array size." << endl;
				Penguin *tempPenguinPtr = new Penguin[penguinArraySize*2];
				for (int i = 0; i < penguinArraySize; i++)	
				{
					tempPenguinPtr[i] = penguinPtr[i];
				}	
				penguinPtr = tempPenguinPtr;
				tempPenguinPtr = nullptr; 
				penguinArraySize *= 2;
			}
			balance -= penguinPtr[0].getCost();
			penguinPtr[numPenguins-1].setAge(3);
		} 
	}	
}
