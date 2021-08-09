/*****************************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			6-2-2019
* Description:		This file contains the main function for Lab9. It creates a 
* 			Palindrome and Buffer object to pass to the startMenu() function.
* 			While the user does not select to exit the program, the user can 
* 			continue to do the buffer simulation or to make a  palindrome.
*****************************************************************************************/

#include "palindrome.hpp"
#include "buffer.hpp"
#include "menu.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));
	Buffer buffer1;					// create buffer object
	Buffer *bufferPtr = &buffer1;			// ptr for buffer object
	Palindrome palindrome1;				// create palindrome object
	Palindrome *palindromePtr = &palindrome1;	// ptr for palindrome object
	bool again = false;

	do
	{
		again = menuStart(bufferPtr, palindromePtr);	
	} while(again);

	return 0;
} 
