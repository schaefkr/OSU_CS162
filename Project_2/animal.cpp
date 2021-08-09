/***************************************************************************
* Program name:         animal.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:		This is the source file for the Animal parent class.
* 			It's derived classes are Tiger, Penguin and Turtle. 
***************************************************************************/

#include "animal.hpp"
#include <iostream> 

/***************************************************************************
				Animal::Animal()
Description: Constructor
***************************************************************************/
Animal::Animal()
{
	age = 0;
	numBabies = 0;
	cost = 0.00;
	baseFoodCost = 10.00;
	payoff = 0.00;
}

/***************************************************************************
	            	     int Animal::getAge()	
Description: This function returns the animal's age.
***************************************************************************/
int Animal::getAge()
{
	return age;
}

/***************************************************************************
	               void Animal::setAge(int addDays)	
Description: This function takes an int input of addDays and adds this 
value to the animal's age.
***************************************************************************/
void Animal::setAge(int addDays)
{
	age += addDays;
}

/***************************************************************************
	               void Animal::resetAge()	
Description: This function resets the animals's age to 0.
***************************************************************************/
void Animal::resetAge()
{
	age = 0;
}

/***************************************************************************
	            	    bool Animal::isAdult()	
Description: This functiion returns a bool value indicating if the animal
is an adult or not.
***************************************************************************/
bool Animal::isAdult()
{
	bool bAdult;
	if (age >= 3)
	{
		bAdult = true;
	}
	else 
	{
		bAdult = false;
	}
	return bAdult;
}

/***************************************************************************
	            	     double Animal::getCost()	
Description: This function returns the cost of the animal.
***************************************************************************/
double Animal::getCost()
{
	return cost;
}

/***************************************************************************
	            	    int Animal::getNumBabies()	
Description: This function returns the amount of babies the animal has. 
***************************************************************************/
int Animal::getNumBabies()
{
	return numBabies;
}

/***************************************************************************
	           	  double Animal::getBaseFoodCost()	
Description: This function gets the base food cost of the animal.
***************************************************************************/
double Animal::getBaseFoodCost()
{
	return baseFoodCost;
}

/***************************************************************************
	           	  double Animal::getPayoff()	
Description: This function gets the payoff of the animal.
***************************************************************************/
double Animal::getPayoff()
{
	return payoff;
}





