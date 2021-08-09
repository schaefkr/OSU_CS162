/***************************************************************************************************
* Program name:         getRandomNumber.cpp
* Group:                Group 18 
* Authors:              Shane Dewar, Dae Hun Park, Kristin Schaefer, Matthew Wong
* Date:                 05-12-2019
* Description:          This file contains the source file for the getRandomNumber function for the 
* 			Predator-Prey Game.
***************************************************************************************************/

#include <iostream>
#include <cstdlib>

/***************************************************************************************************
int getRandomNumber (int min, int max)
This function was found from:
https://www.learncpp.com/cpp-tutorial/59-random-number-generation/
Description: This function generates a random number for the placement of the Ants and Doodlebugs
on the board. 
***************************************************************************************************/
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    // getting random number between min and max
    return min + static_cast<int>((max - min + 1)*(rand()*fraction));
} 
