/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description:		This file contains the source file for the Menu class.
******************************************************************************************/

#include "menu.hpp"
#include "university.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*****************************************************************************************
*              			    Menu::Menu()    	 
* Description: Constructor 
******************************************************************************************/
Menu::Menu()
{
}

/*****************************************************************************************
*              			    Menu::~Menu()    	 
* Description: Destructor 
******************************************************************************************/
Menu::~Menu()
{
}

/*****************************************************************************************
*       			    int Menu::menuDisplay()    	 
* This function displays the start menu options to the user and then asks the user to
* input an int option. The function completes input validation and displays the menu 
* again if the user does not enter a valid input.
******************************************************************************************/
int Menu::menuDisplay()
{
	string choice;
	int c = 0;

	cout << endl;
	cout << "1. Print all building information" << endl; 
	cout << "2. Print all student and instructor information" << endl; 
	cout << "3. Choose a person to do work" << endl;
	cout << "4. Exit program" << endl;

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("1234") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2, 3 or 4." << endl;
			if (choice.find_first_not_of("1234") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 4))
		{
			cout << "Error. Please enter 1, 2, 3 or 4." << endl;
		}
	} while ((c < 1) || (c > 4));
	return c;
}

/*****************************************************************************************
* void Menu::menu_do_work(University *uniPtr)    	 
* This function displays the names of the people in the information system and asks the 
* user to select one of the people listed to do_work() 
******************************************************************************************/
void Menu::menu_do_work(University *uniPtr)
{
	string choice;
	int c = 0;
	menuUniPtr = uniPtr;	

	cout << endl;
	cout << "Please choose a person to do work." << endl;
	uniPtr->printPplNames();
 
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

	uniPtr->uni_do_work(c);
}
