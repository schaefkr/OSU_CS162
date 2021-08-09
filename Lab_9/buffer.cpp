/*****************************************************************************************
* Program name:		buffer.cpp
* Author:		Kristin Schaefer
* Date:			6-2-2019
* Description:		This file contains the the source file for the Buffer class.
*			The file contains declarations of functions such as startSim()
*			which controls the Buffer simulation. It also declares functions
*			to generate random value integer values, genRandomNum(), functions
*			to append and remove a value to the queue, a function to print 
*			the current Buffer, printBuffer(), a function to get the length 
*			of the current Buffer, getLength(), and the average length of 
*			the Buffer, getAvgLength(), and a function to clear the Buffer in
*			case the user wants to run the Buffer simulation again. 
*****************************************************************************************/

#include "buffer.hpp"
#include "menu.hpp"
#include <iostream>
#include <queue>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::endl;
using std::queue;

/*****************************************************************************************
Buffer::Buffer()
Description: Constructor. This function initializes the round, appendEnd, removeFront, 
userAppendEnd and userRemoveFront values.
*****************************************************************************************/
Buffer::Buffer()
{
	appendEnd = 0;
	removeFront = 0;
	userAppendEnd = 0;
	userRemoveFront = 0;
}

/*****************************************************************************************
void Buffer::startSim()
Description: This function controls the Buffer simulation. It calls Menu functions to 
get the user-input number of simulation rounds and the numbers representing the chance
to add or remove a value from the queue. Then a for-loop controls the round of the 
simulation by generating two random numbers to determine if a randomly generated number
is appended or removed from the queue. After the comparison, the current Buffer is 
printed, as well as the current Buffer length and the average Buffer length. After the 
for-loop is exited, the Buffer is cleared in case the user wants to run the simulation 
again. 
*****************************************************************************************/
void Buffer::startSim()
{
	round = 1;	 
	
	// menu functions 
	round = menuNumRounds();
	userAppendEnd = menuNumEnd();
	userRemoveFront = menuNumFront();

	for (int i = 0; i < round; i++)
	{
		cout << "-------------------------------------------------------" << endl;
		cout << "* Buffer * | Round " << i+1 << endl;
	
		cout << "\n";
		// generate N
		N = genRandomNum(1000);
		cout << "Random number N: " << N << endl;
	
		// generate append number
		appendEnd = genRandomNum(100);
		cout << "Random append val: " << appendEnd << endl;
		cout << "User append val: " << userAppendEnd << endl;
		if (appendEnd <= userAppendEnd)
		{
			append();
			cout << "Random number N appended to end of queue." << endl;
		}	
		else 
		{
			cout << "Random number N not appended to end of queue." << endl;
		}	
	
		cout << "\n";
		// generate remove number
		removeFront = genRandomNum(100);
		cout << "Random remove value: " << removeFront << endl;
		cout << "User remove value: " << userRemoveFront << endl;	
		if (removeFront <= userRemoveFront)
		{
			remove();
			cout << "Front value removed from queue." << endl;
		}
		else 
		{
			cout << "Front value not removed from queue." << endl;
		}
	
		cout << "\n";
		// print buffer
		cout << "Current buffer: ";	
		printBuffer();
		cout << endl;
		// print buffer length
		cout << "Buffer length: " << getLength() << endl; 
		// print avg buffer length
		cout << std::fixed << std::showpoint;
		cout << std::setprecision(2); 
		cout << "Average buffer length: " << getAvgLength() << endl; 
		
		cout << "-------------------------------------------------------" << endl;
		cout << endl;
	}
	clearBuffer();
	ALi = 0.00;
	ALiPrev= 0.00;	
}

/*****************************************************************************************
int Buffer::genRandomNum(int max)
Description: This function generates a random integer from 1 to the value passed as a
parameter. It then returns the randomly generated integer.
*****************************************************************************************/
int Buffer::genRandomNum(int max)
{
	int randNum = 0;
	randNum = rand() % max + 1;
	if (randNum == 0)
	{
		randNum++;
	}	
	return randNum;
}

/*****************************************************************************************
void Buffer::append()
Description: This function appends the randomly generated integer N to the end of the 
queue.
*****************************************************************************************/
void Buffer::append()
{
	userBuffer.push(N);
}

/*****************************************************************************************
void Buffer::remove()
Description: This function removes the randomly generated integer at the front of the 
queue.
*****************************************************************************************/
void Buffer::remove()
{
	if (!userBuffer.empty())
	{
		userBuffer.pop();
	}	
}

/*****************************************************************************************
void Buffer::printBuffer()
Description: This function prints the current queue. A temporary queue is 
declared and the userBuffer is assigned to the temporary queue. Then a while-loop prints
the front value of the queue and removes the front value until the queue is empty.  
*****************************************************************************************/
void Buffer::printBuffer()
{
	queue <int> tempBuffer = userBuffer;
	while (!tempBuffer.empty())
	{
		cout << tempBuffer.front() << " ";
		tempBuffer.pop();	
	}
}

/*****************************************************************************************
int Buffer::getLength()
Description: This function gets the number of randomly generated integer values 
currently in the queue.
*****************************************************************************************/
int Buffer::getLength()
{
	return userBuffer.size();
}

/*****************************************************************************************
double Buffer::getAvgLength()
Description: This function calculates the average Buffer length with the formula:
ALi = (ALi-1 * (i-1) + Li)/i. It then returns the double value representing the average
Buffer length. 
Sources: https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c
*****************************************************************************************/
double Buffer::getAvgLength()
{
	// ALi = (ALi-1 * (i-1) + Li)/i 
	double i = round;
	// set ALi-1
	if (round == 1)
	{
		ALiPrev = 0.00;
	}
	else 
	{
		ALiPrev = ALi;	
	}

	// set ALi
	ALi = (ALiPrev * (i-1) + getLength()) / i; 	
	return ALi; 
}

/*****************************************************************************************
void Buffer::clearBuffer()
Description: This function clears the Buffer in case the user wants to run the 
simulation again. It clears the Buffer by using a while loop to pop/delete the values
from the queue until the queue is empty. 
*****************************************************************************************/
void Buffer::clearBuffer()
{
	while (!userBuffer.empty())
	{
		userBuffer.pop();	
	}
}







