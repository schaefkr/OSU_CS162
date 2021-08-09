/***************************************************************************************************
* Program name:        fibonacci.hpp
* Author:              Kristin Schaefer
* Date:                6-9-2019
* Description:         This is the header file for the Fibonacci functions. It defines a function to 
* control the implementation of the Fibonacci functions and to calculate their running times, 
* fibonacciStart(). It also defines a function to recursively calculate the nth value in a 
* Fibonacci sequence, fibonacciRecursive(), as well as a function to iteratively calculate the nth
* value in a Fibonacci sequence, fibonacciIterative().
****************************************************************************************************/

#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

void fibonacciStart();
int fibonacciRecursive(int n);
int fibonacciIterative(int n);

#endif
