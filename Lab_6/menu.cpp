/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			5-12-2019
* Description:		This file contains the source file for the menu function for lab 6.
******************************************************************************************/

#include "menu.hpp"
#include "node.hpp"
#include "doubleLink.hpp"
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
bool mainMenu(DoubleLink *ddlPtr)
{
	string choice;
	int c;
	bool quit = false;

	// display menu
	cout << "1. Add a new node to the head" << endl; 
	cout << "2. Add a new node to the tail" << endl; 
	cout << "3. Delete from from head" << endl;
	cout << "4. Delete from from tail" << endl;
	cout << "5. Traverse the list in reverse" << endl;
	cout << "6. Exit program" << endl;

	// input validation
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("123456") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2, 3, 4, 5 or 6" << endl;
			if (choice.find_first_not_of("123456") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 6))
		{
			cout << "Error. Please enter 1, 2, 3, 4, 5 or 6." << endl;
		}
	} while ((c < 1) || (c > 6));

	// call menu function number
	if (c == 1)
	{
		// add new node to head
		menuFunction1(ddlPtr);
	}
	else if (c == 2)
	{
		// add new node to tail 
		menuFunction2(ddlPtr);
	}
	else if (c == 3)
	{
		// delete node from head
		menuFunction3(ddlPtr); 	
	}
	else if (c == 4)
	{
		// delete node from tail 
		menuFunction4(ddlPtr); 	
	}
	else if (c == 5)
	{
		// traverse lise in reverse 
		menuFunction5(ddlPtr); 	
	} 
	else if (c == 6)
	{
		quit = true;
	} 
	return quit;
}

/******************************************************************************************
void menuFunction1(DoubleLink *listPtr)
Description: This function adds a new node to the head of the doubly-linked list.
******************************************************************************************/
void menuFunction1(DoubleLink *listPtr)
{
	int value = 0;
	value = menuValidation(0, 10000);
	listPtr->addHead(value);	
	menuFunction6(listPtr); 	
}

/******************************************************************************************
void menuFunction2(DoubleLink *listPtr)
Description: This function adds a new node to the tail of the doubly-linked list.
******************************************************************************************/
void menuFunction2(DoubleLink *listPtr)
{
	int value = 0;
	value = menuValidation(0, 10000);
	listPtr->addTail(value);	
	menuFunction6(listPtr); 	
}

/******************************************************************************************
void menuFunction3(DoubleLink *listPtr)
Description: This function deletes the first node of the doubly-linked list.
******************************************************************************************/
void menuFunction3(DoubleLink *listPtr)
{
	listPtr->removeFirst();	
	menuFunction6(listPtr); 	
}

/******************************************************************************************
void menuFunction4(DoubleLink *listPtr)
Description: This function deletes the last node of the doubly-linked list.
******************************************************************************************/
void menuFunction4(DoubleLink *listPtr)
{
	listPtr->removeLast();	
	menuFunction6(listPtr); 	
}

/******************************************************************************************
void menuFunction5(DoubleLink *listPtr)
Description: This function traverses the doubly-linked list in reverse.
******************************************************************************************/
void menuFunction5(DoubleLink *listPtr)
{
	listPtr->printReverse();
}

/******************************************************************************************
void menuFunction6(DoubleLink *listPtr)
Description: This function traverses the doubly-linked list.
******************************************************************************************/
void menuFunction6(DoubleLink *listPtr)
{
	listPtr->printForward();
}

/******************************************************************************************
int menuValidation(int min, int max)
Description: This function checks the user input for the DLL for validity. 
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
