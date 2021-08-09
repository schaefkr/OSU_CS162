/*****************************************************************************************
* Program name:		buffer.hpp
* Author:		Kristin Schaefer
* Date:			6-2-2019
* Description:		This file contains the header file the Buffer class. It declares 
* 			private member variables holding the number of rounds of the 
* 			buffer simulation, as well as the values to hold the random and 
* 			user removeFront and appendEnd values. It also declares two double 
* 			values representing the average buffer length and the previous 
* 			round's average Buffer length. The Buffer itself is a queue 
* 			container of integers called userBuffer.
* 			The file contains declarations of functions such as startSim()
* 			which controls the Buffer simulation. It also declares functions
* 			to generate random value integer values, genRandomNum(), functions
* 			to append and remove a value to the queue, a function to print 
* 			the current Buffer, printBuffer(), a function to get the length 
* 			of the current Buffer, getLength(), and the average length of 
* 			the Buffer, getAvgLength(), and a function to clear the Buffer in
* 			case the user wants to run the Buffer simulation again. 
*****************************************************************************************/

#ifndef BUFFER_HPP
#define BUFFER_HPP
#include <queue>
using std::queue;

class Buffer
{
	private:
		int round;
		int appendEnd;
		int removeFront;
		int userAppendEnd;
		int userRemoveFront;
		int N;	
		double ALi;
		double ALiPrev;
		queue <int> userBuffer;
	public:
		Buffer();
		void startSim();
		int genRandomNum(int max);
		void append();
		void remove();
		void printBuffer();
		int getLength();
		double getAvgLength();
		void clearBuffer();
};
#endif 

