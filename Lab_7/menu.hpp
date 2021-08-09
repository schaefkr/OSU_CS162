/******************************************************************************************
* Program name:         menu.hpp
* Author:               Kristin Schaefer
* Date:                 5-19-2019
* Description:          This file contains the header file for the Menu function for lab 7.
* It defines functions for a start menu which asks the user to select a menu option to 
* execute a queue-related function such as add a value to the back of the queue or print 
* the queue. The functions also validate all of the user input.
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "queue.hpp"

bool mainMenu(Queue *cllPtr);
void menuFunction1(Queue *listPtr);
void menuFunction2(Queue *listPtr);
void menuFunction3(Queue *listPtr);
void menuFunction4(Queue *listPtr);
int menuValidation(int min, int max);

#endif
