/******************************************************************************************
* Program name:         menu.cpp
* Author:               Kristin Schaefer
* Date:                 5-26-2019
* Description:          This file contains the header file for the menu functions. It has
* a function for the starting menu of the tournament, startMenu(), a function to get the 
* number of team players per team, menuTeamSize(), a function to get the name of each 
* Character, menuCharacter(), a function to ask the user if they would like to play the
* tournament again, playAgain(), and a function to ask the user if they would like to 
* print the loser pile. 
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPPP
#include <string>
using std::string;

bool startMenu();
int menuTeamSize();
int menuCharacter(int playerNum);
string menuPlayerName(int playerNum);
bool playAgain(); 
bool menuPrintLoserPile(); 

#endif
