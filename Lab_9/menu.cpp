/******************************************************************************************
* Program name:		menu.cpp
* Author:		Kristin Schaefer
* Date:			6-2-2019
* Description:		This file contains the source file for the menu function. It
* 			defines functions for the starting menu, startMenu(), a function
*			to get the number of buffer sim rounds, menuNumRounds, a function
*			to get two % values from the user for the buffer sim rounds, 
* 			menuNumEnd() and menuNumFront(), and a function to get the string
*			to make the palindrome form the user.  
******************************************************************************************/

#include "menu.hpp"
#include "buffer.hpp"
#include "palindrome.hpp"
#include <iostream>
#include <cctype>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
bool menuStart()
Description: This function prints a start menu asking the user if they would like to
1. Buffer 2. Palindrome 3. Exit (the program). The function gets the user's choice and
validates the input. If the user's input is invalid an error message is printed and the user
must enter another value until they enter a valid choice of 1, 2 or 3. After the user enters a 
valid choice, the function assigns a boolean value to the user's choice and then returns
that value.
******************************************************************************************/
bool menuStart(Buffer *bufferPtr, Palindrome *palindromePtr)
{
	string choice;
	int c;

	cout << "1. Buffer" << endl; 
	cout << "2. Palindrome" << endl; 
	cout << "3. Exit" << endl; 
	
	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("123") !=std::string::npos)
		{
			cout << "Error. Please enter 1, 2 or 3." << endl;
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
			cout << "Error. Please enter 1, 2 or 3." << endl;
		}
	} while ((c < 1) || (c > 3));

	if (c == 1)
	{
		// start buffer
		bufferPtr->startSim();	
		return true; 	
	} 
	else if (c == 2)
	{
		// start palindrome
		palindromePtr->makePalindrome();	
		return true; 	
	}
	else 
	{
		return false;
	}
}

/******************************************************************************************
string menuPalindrome()
Description: This function gets a string from the user to make a palindrome of for the 
makePalindrome() function in the Palindrome class.
******************************************************************************************/
string menuPalindrome()
{
	string choice;

	cout << "Please enter a word to make a palindrome" << endl;
	std::getline(cin, choice);
	return choice; 
}

/******************************************************************************************
int menuNumRounds()
Description: This function gets the number of rounds to run the Buffer simulation from 
the user. It returns the number of rounds as an integer for the startSim() function in 
the Buffer class.
******************************************************************************************/
int menuNumRounds()
{
	string choice;	
	int c = 0;

	cout << endl;
	cout << "How many rounds would you like to simulate?" << endl;	

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a number from 1 to 1000." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 1000))
		{
			cout << "Error. Please enter a number from 1 to 1000." << endl;
		}
	} while ((c < 1) || (c > 1000));

	return c;	
}

/******************************************************************************************
int menuNumEnd()
Description: This function gets an integer from the user representing the chance to put a 
randomly generated number at the end of the buffer. It returns the integer for the 
startSim() function in the Buffer class. 
******************************************************************************************/
int menuNumEnd()
{
	string choice;	
	int c = 0;

	cout << endl;
	cout << "Please enter a percentage representing the chance to put a " 
     	     <<	"randomly generated number at the end of the buffer." << endl;	

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a number from 1 to 99." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 99))
		{
			cout << "Error. Please enter a number from 1 to 99." << endl;
		}
	} while ((c < 1) || (c > 99));

	return c;	
}

/******************************************************************************************
int menuNumFront()
Description: This function gets an integer from the user representing the chance to remove 
a randomly generated number from the front of the buffer. It returns the integer for the 
startSim() function in the Buffer class. 
******************************************************************************************/
int menuNumFront()
{
	string choice;	
	int c = 0;

	cout << endl;
	cout << "Please enter a percentage representing the chance to remove a " 
     	     <<	"randomly generated number from the front of the buffer." << endl;	

	do
	{
		std::getline(cin, choice);
		while (std::cin.fail() || choice.find_first_not_of("0123456789") !=std::string::npos)
		{
			cout << "Error. Please enter a number from 1 to 99." << endl;
			if (choice.find_first_not_of("0123456789") == std::string::npos)
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
			} 
			std::getline(cin, choice);
		}
		c = std::stoi(choice);
		if ((c < 1) || (c > 99))
		{
			cout << "Error. Please enter a number from 1 to 99." << endl;
		}
	} while ((c < 1) || (c > 99));

	return c;	
}
