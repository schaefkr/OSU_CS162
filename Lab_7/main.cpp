/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			5-17-2019
* Description:		This file contains the main function for Lab7. The main function
* 			declares a Queue object and then passes that object to the 
* 			mainMenu function. The mainMenu function is within a do-while 
* 			loop which ends when the user selects to exit the program. 
* Sources:		Textbook ch 17
*****************************************************************************************/

#include "menu.hpp"
#include "queue.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	bool quit;
	Queue userList;	
	Queue *userListPtr = &userList;

	do
	{
		quit = mainMenu(userListPtr);
	} while (!quit);

	return 0;
}
