/****************************************************************************************************
* Name:                fibonacci.cpp
* Author:              Kristin Schaefer
* Date:                6-9-2019
* Description:         This is the source file for the Fibonacci functions. It defines a function to 
* control the implementation of the Fibonacci functions and to calculate their running times, 
* fibonacciStart(). It also defines a function to recursively calculate the nth value in a 
* Fibonacci sequence, fibonacciRecursive(), as well as a function to iteratively calculate the nth
* value in a Fibonacci sequence, fibonacciIterative().
****************************************************************************************************/

#include "fibonacci.hpp"
#include "menu.hpp"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
using std::cout;
using std::endl;

/****************************************************************************************************
void fibonacciStart()
Description: This function calls the recursive and iterative Fibonacci functions and outputs their
values. It also checks the running time of each Fibonacci function and prints the running time.
Sources:
https://www.geeksforgeeks.org/measure-execution-time-function-cpp/ 
****************************************************************************************************/
void fibonacciStart()
{
	// Get n 
	int n = 0;
	n = menuN();

	cout << endl;
	// Recursive Fibonacci Function
	cout << "Fibonacci Recursive: " << endl;
	// get start timepoint
	auto start = high_resolution_clock::now();
	cout << "number: " << fibonacciRecursive(n) << endl;
	// get end timepoint
	auto stop = high_resolution_clock::now();
	cout << "function run time: " << endl;
	auto duration = duration_cast<microseconds>(stop-start);
	cout << duration.count() << " microseconds" << endl;

	cout << endl;
	// Iterative Fibonacci Function
	cout << "Fibonacci Iterative: " << endl;
	// get start timepoint
	start = high_resolution_clock::now();
	cout << "number: " << fibonacciIterative(n) << endl;
	// get end timepoint
	stop = high_resolution_clock::now();
	cout << "function run time: " << endl;
	duration = duration_cast<microseconds>(stop-start);
	cout << duration.count() << " microseconds" << endl;

}

/****************************************************************************************************
int fibonacciRecursive(int n)
Description: This function takes an integer n as input and then calculates recursively the nth 
number in the Fibonacci sequence and returns that value as an integer. It checks for base cases of 
0 and 1. 
Sources:
https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
C++ Early Objects, page 925-926
****************************************************************************************************/
int fibonacciRecursive(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else 
	{
		return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
	} 
}

/****************************************************************************************************
int fibonacciIterative(int n) 
Description: This function takes an integer n as input and then calculates iteratively the nth
number in the Fibonacci sequence and retruns that value as an integer. 
Sources:
https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
****************************************************************************************************/
int fibonacciIterative(int n) 
{
	int first = 0;
	int second = 1;
	int counter = 2;
	
	while (counter < n)
	{
		int temp = second;
		second += first;
		first = temp;
		++counter;
	}
	
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return first + second;
	}
}
