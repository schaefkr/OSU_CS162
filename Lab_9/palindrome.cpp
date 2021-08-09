/*****************************************************************************************
* Program name:         palindrome.cpp
* Author:               Kristin Schaefer
* Date:                 6-2-2019
* Description:          This file contains the the source file for the Palindrome class.
*			It defines a function which takes a string defined by the user
*                       and then outputs the concatenation of the string and its palindrome.
*****************************************************************************************/

#include "palindrome.hpp"
#include "menu.hpp"
#include <iostream>
#include <stack>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::stack;

/*****************************************************************************************
Palindrome::Palindrome()
Description: Constructor
*****************************************************************************************/
Palindrome::Palindrome()
{

}

/*****************************************************************************************
void Palindrome::makePalindrome()
Description: This function calls the Menu function menuPalindrome() to get a user-input
string. The function adds the values of the user's string sequentially to a stack and 
then pops off the characters one by one to print the concatenation of the original string
and it's palindrome.
Sources: https://www.geeksforgeeks.org/stack-in-cpp-stl/
http://www.cplusplus.com/reference/string/string/at/ 
*****************************************************************************************/
void Palindrome::makePalindrome()
{
	cout << "-------------------------------------------------------" << endl;
	cout << "* Palindrome *" << endl;

	stack <char> palStack;
	pal = menuPalindrome();
	cout << "Your string: " << pal << endl;
	
	// add values of string sequentially to the stack
	for(int i = 0; i < pal.length(); i++)
	{
		palStack.push(pal.at(i));
	}	

	// pop off characters one by one and print the character
	cout << "Your string + palindrome: " << pal;
	while (!palStack.empty())
	{
		cout << palStack.top();
		palStack.pop();
	}
	
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << endl;
}
