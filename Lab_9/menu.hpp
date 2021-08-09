/******************************************************************************************
* Program name:         menu.cpp
* Author:               Kristin Schaefer
* Date:                 6-2-2019
* Description:          This file contains the header file for the menu functions. It 
* 			defines functions for the starting menu, startMenu(), a function
* 			to get the number of buffer sim rounds, menuNumRounds, a function
* 			to get two % values from the user for the buffer sim rounds, 
* 			menuNumEnd() and menuNumFront(), and a function to get the string
* 			to make the palindrome form the user. 
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include "buffer.hpp"
#include "palindrome.hpp" 
using std::string;

bool menuStart(Buffer *bufferPtr, Palindrome *palindromePtr);
int menuNumRounds();
int menuNumEnd();
int menuNumFront();
string menuPalindrome();

#endif
