/***********************************************************************
 * Program name:        letters.hpp
 * Author:              Kristin Schaefer
 * Date:                04-14-2019
 * Description:         This is the header file for lab 2. It provides
 *                      the function prototypes for the functions
 *                      count_letters() and output_letters().	
***********************************************************************/

#ifndef LETTERS_HPP
#define LETTERS_HPP
#include <fstream>
using std::ifstream;
using std::ofstream;

void count_letters(ifstream&, int*);
void output_letters(ofstream&, int*);
void clear_array(int*);

#endif 
