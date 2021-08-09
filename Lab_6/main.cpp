/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-12-2019
* Description:		This file contains the main function for Lab6.
* Sources:
* Textbook ch 17
*****************************************************************************************/

#include "menu.hpp"
#include "node.hpp"
#include "doubleLink.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	bool quit;
	DoubleLink userList;	
	DoubleLink *userListPtr = &userList;

	do
	{
		quit = mainMenu(userListPtr);
	} while (!quit);

	return 0;
}
