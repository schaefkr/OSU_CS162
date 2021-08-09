/*****************************************************************************************
* Program name:         palindrome.hpp
* Author:               Kristin Schaefer
* Date:                 6-2-2019
* Description:          This file contains the the header file for the Palindrome class.
* 			It defines a function which takes a string defined by the user
* 			and then outputs the concatenation of the string and its palindrome. 
*****************************************************************************************/

#ifndef PALINDROME_HPP
#define PALINDROME_HPP
#include <string>
using std::string;

class Palindrome
{
	private:
		string pal;
	public:
		Palindrome();
		void makePalindrome();
};
#endif

