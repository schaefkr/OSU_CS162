/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			6-9-2019
* Description:		This file contains the Main function for Lab10. The Main function
* is used to call the starting menu function, menuStart(). If the user chooses to start
* the Fibonacci Number Calculation, then a true boolean value is returned and the 
* fibonacciStart() function is called. If the user selects to exit the program, then a
* false boolean value is returned and and the program is exited.
*****************************************************************************************/

#include "menu.hpp"
#include "fibonacci.hpp"
#include <iostream>	

int main()
{
	if (menuStart())	
	{
		fibonacciStart();
	}

	return 0;
} 
