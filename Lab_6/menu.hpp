/******************************************************************************************
* Program name:         menu.hpp
* Author:               Kristin Schaefer
* Date:                 5-12-2019
* Description:          This file contains the header file for the menu function.
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "node.hpp"
#include "doubleLink.hpp"

bool mainMenu(DoubleLink *dllPtr);
void menuFunction1(DoubleLink *listPtr);
void menuFunction2(DoubleLink *listPtr);
void menuFunction3(DoubleLink *listPtr);
void menuFunction4(DoubleLink *listPtr);
void menuFunction5(DoubleLink *listPtr);
void menuFunction6(DoubleLink *listPtr);
int menuValidation(int min, int max);

#endif
