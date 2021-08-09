/***************************************************************************
* Program name:         queue.hpp
* Author:               Kristin Schaefer
* Date:                 05-19-2019
* Description:          This is the header file for the Queue class. It 
* defines a struct for QueueNode containing a value for the Node to hold, 
* and a previous and next pointer. It also defines the Queue class which 
* holds a pointer to the head QueueNode in the linked list as well as
* functions to check if the list is empty, add a Node to the back of the 
* list, get the first value in the list, remove the first value in the list, 
* and to print the queue. 
***************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueNode
{
	// variables for QueueNode
	int val;
	QueueNode *prev = nullptr; 
	QueueNode *next = nullptr;
	
	// constructor for QueueNode
	QueueNode(int value)
	{  
		val = value;
	};	
}; 

class Queue
{
	private:
		QueueNode *head = nullptr;	// pointer to the first QueueNode object in the queue
	public:
		Queue();
		~Queue();			// free all the memory of nodes in the queue
		bool isEmpty();
		void addBack(int val);
		int getFront();
		void removeFront();
		void printQueue();
};
#endif
