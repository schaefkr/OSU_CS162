/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			5-19-2019
* Description:		This file contains the source file for the Menu function for lab 7.
* It defines functions for a start menu which asks the user to select a menu option to 
* execute a queue-related function such as add a value to the back of the queue or print 
* the queue. The functions also validate all of the user input.
******************************************************************************************/

#include "menu.hpp"
#include "queue.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
int mainMenu();	
Description: This function displays the start menu options to the user and then asks the 
user to input an option. The function completes input validation and displays the menu 
again if the user does not enter a valid input.		
******************************************************************************************/
bool mainMenu(Queue *cllPtr)
{
	string choice;
	int c;
	bool quit = false;

	// display menu
	cout << "1. Add a value to the back of the queue" << endl; 
	cout << "2. Display the front value" << endl; 
	cout << "3. Remove the front node" << endl;
	cout << "4. Display the queue content" << endl;
	cout << "5. Exit program" << endl;

	// input validation
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("12345") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2, 3, 4, or 5" << endl;
			if (choice.find_first_not_of("12345") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 5))
		{
			cout << "Error. Please enter 1, 2, 3, 4, or 5." << endl;
		}
	} while ((c < 1) || (c > 5));

	// call the menu function number
	if (c == 1)
	{
		// add a value to the back of the queue
		menuFunction1(cllPtr);
	}
	else if (c == 2)
	{
		// display the front value	 
		menuFunction2(cllPtr);
	}
	else if (c == 3)
	{
		// remove the front node 
		menuFunction3(cllPtr); 	
	}
	else if (c == 4)
	{
		// display the queue content 
		menuFunction4(cllPtr); 	
	}
	else if (c == 5)
	{
		// quit the program set to true
		quit = true;
	} 
	return quit;
}

/******************************************************************************************
void menuFunction1(Queue *listPtr)
Description: This function prompts the user to enter an integer to the back of the queue.
The input is validated and then passes the the Queue addBack() function.
******************************************************************************************/
void menuFunction1(Queue *listPtr)
{
	int value = 0;
	value = menuValidation(0, 10000);
	listPtr->addBack(value);
}

/******************************************************************************************
void menuFunction2(Queue *listPtr)
Description: This function calls Queue's getFront() function to print the front value
of the queue if the list is not empty. The function checks the if the queue is empty before
calling the getFront() function, and if the queue is empty an error message is printed 
and the getFront() function is not called. 
******************************************************************************************/
void menuFunction2(Queue *listPtr)
{
	// check if list is empty first
	if (listPtr->isEmpty())
	{
		cout << "Error. The queue is currently empty." << endl;
	}
	else
	{
		cout << "The front value of the queue is: "; 
		cout << listPtr->getFront() << "." << endl;
	}
}

/******************************************************************************************
void menuFunction3(Queue *listPtr)
Description: This function calls Queue's removeFront() function to remove the front value
of the queue if the list is not empty. The function checks the if the queue is empty before
calling the removeFront() function, and if the queue is empty an error message is printed 
and the removeFront() function is not called. 
******************************************************************************************/
void menuFunction3(Queue *listPtr)
{
	// check if list is empty first
	if (listPtr->isEmpty())
	{
		cout << "Error. The queue is currently empty." << endl;
	}
	else
	{
		listPtr->removeFront();
	}
}

/******************************************************************************************
void menuFunction4(Queue *listPtr)
Description: This function calls Queue's function printQueue() to print the current queue. 
First the function checks if the queue is empty. If the queue is empty the function outputs
an error message abd the printQueue() function is not called.
******************************************************************************************/
void menuFunction4(Queue *listPtr)
{
	// check if list is empty first
	if (listPtr->isEmpty())
	{
		cout << "Error. The queue is currently empty." << endl;
	}
	else
	{
		listPtr->printQueue();
	}
}

/******************************************************************************************
int menuValidation(int min, int max)
Description: This function checks if the user input is an integer within an acceptable 
range defined in the menuFunction1() function. It is necessary the input be validated 
because the Queue is designed to only work with integers.
******************************************************************************************/
int menuValidation(int min, int max)
{
	string choice;
	int c;

	cout << "Please enter an integer from " << min << " to " << max << "." << endl;

	// input validation
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Please enter an integer from " << min << " to " << max << "." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < min) || (c > max))
		{
			cout << "Please enter an integer from " << min << " to " << max << "." << endl;
		}
	} while ((c < min) || (c > max));
	return c;
}
