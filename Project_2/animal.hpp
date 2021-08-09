/***************************************************************************
* Program name:         animal.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the header file for the Animal parent class.
*                       It's derived classes are Tiger, Penguin and Turtle. 
***************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
	protected:
		int age;
		int numBabies;
		double cost;
		double baseFoodCost;
		double payoff;	
	public:
		Animal();	
		int getAge();
		void setAge(int addDays);
		void resetAge();
		bool isAdult();
		double getCost();
		int getNumBabies();
		double getBaseFoodCost();
		double getPayoff();
};
#endif
