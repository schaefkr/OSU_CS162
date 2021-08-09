/***************************************************************************
* Program name:		die.hpp
* Author:		Kristin Schaefer
* Date:			04-21-2019
* Description:		This is the source file for the Die class.
* Sources:		https://stackoverflow.com/questions/7690580/
* 			how-to-write-c-inheritance-constructors
***************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP
#include <string>
using std::string;

class Die 
{
	protected:
		int N;	
		int currentSide;
		string dieType;		
	public:
		Die(int N);	
		virtual int getDieRoll(int r);
		string getDieType();
		int getCurrentSide();
		void setNumSides(int N);
		~Die();
}; 
#endif
