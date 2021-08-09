/***************************************************************************
* Program name:         queue.cpp
* Author:               Kristin Schaefer
* Date:                 05-19-2019
* Description:          This is the source file for the Queue class. It 
* defines a struct for QueueNode containing a value for the Node to hold, 
* and a previous and next pointer. It also defines the Queue class which 
* holds a pointer to the head QueueNode in the linked list as well as
* functions to check if the list is empty, add a Node to the back of the 
* list, get the first value in the list, remove the first value in the list, 
* and to print the queue. 
***************************************************************************/

#include "queue.hpp"
#include <iostream>
using std::cout;
using std::endl;

/***************************************************************************
Queue::Queue()
Description: Constructor
***************************************************************************/
Queue::Queue()
{

}

/***************************************************************************
Queue::~Queue()
Description: Destructor. This function uses a while loop to check if the 
queue is empty. If the list is not empty, the loop continues to delete the 
QueueNodes in the queue by using a current ptr and then setting the current
ptr to the next QueueNode in the queue.  
***************************************************************************/
Queue::~Queue()
{
	while (head)
	{
		removeFront();
	}
}

/***************************************************************************
bool Queue::isEmpty()
Description: This function checks whether the queue is empty by testing 
if the head ptr is set to nullptr. 
***************************************************************************/
bool Queue::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/***************************************************************************
void Queue::addBack(int val)
Description: This function adds a QueueNode to the back of the queue. The 
value to be stored in the QueueNode is input and validated in the menu
function. The addBack function checks whether the queue contains 0, 1 or 2 
QueueNode's in the queue. If there are 0 QueueNodes, the head next and prev
are both set to head. If there is 1 QueueNode in the queue, a temp ptr to 
a new QueueNode is declared. The next and prev ptr for the tail and new head
are reassigned. If there are 2 or more QueueNodes in the queue, a temp ptr
for the new head and a tailPtr are both declared. The next and prev ptrs
for the tempPtr(new head) and the old head's prev ptr is reassigned to the 
new tail.
***************************************************************************/
void Queue::addBack(int val)
{
	// 0 items currently in the queue
	if (isEmpty())
	{
		head = new QueueNode(val);
		head->next = head; 
		head->prev = head;	 
	}
	// 1 item currently in the queue
	else if (head->next == head)
	{
		QueueNode *tempPtr = new QueueNode(val);
		tempPtr->prev = head;
		tempPtr->next = head;
		head->prev = tempPtr;
		head->next = tempPtr;
		head = tempPtr;
	}	
	// 2 or more items currently in the queue 
	else 
	{
		QueueNode *tempPtr = new QueueNode(val);
		QueueNode *tailPtr = head->prev;
		tempPtr->prev = tailPtr;		
		tempPtr->next = head;
		head->prev = tailPtr;
		head = tempPtr;
	}
}

/***************************************************************************
int Queue::getFront()
Description: This function returns the value stored in the front QueueNode
in the queue. 
***************************************************************************/
int Queue::getFront()
{
	return head->val;	
}

/***************************************************************************
void Queue::removeFront()
Description: This function removes the front value of the queue. First, 
both a temp ptr(head to be removed) and temp tail ptr are declared. Then 
the function checks whether the list has 1, 2 or 3 or more items in the
queue. If the queue has 1 QueueNode, a boolean value is set to true so that 
the head ptr can be set to nullptr at the end of the function. If the queue 
has 2 items, then the head ptr is reassigned to the next QueueNode and the 
head next and head prev ptrs are both assigned to the head. If the queue
has 3 or more items, then the head ptr is reassigned, the head prev ptr 
is reassigned, and the tail QueueNode's next ptr is reassigned to the new
head. 
***************************************************************************/
void Queue::removeFront()
{
	bool lastNode = false;
	QueueNode *tempPtr = head;
	QueueNode *tailPtr = head->prev;
	// 1 item in the queue
	if (head == head->next)
	{	
		lastNode = true;	
	}
	// 2 items in the queue
	else if (head->next == head->prev)
	{	
		head = tempPtr->next;
		head->next = head;
		head->prev = head;
	}
	// 3 or more items in th queue 
	else
	{
		head = tempPtr->next;
		head->prev = tempPtr->prev;
		tailPtr->next = head;	
	}
	delete tempPtr;

	if (lastNode)
	{
		head = nullptr;
	}
}

/***************************************************************************
void Queue::printQueue()
Description: This function prints the current queue. It is called from the 
menu function, so it does not need to check for an empty queue. First, a 
temp print(head) and tail ptr are declared. Next a while loop prints the current 
value of the QueueNode and then the print ptr is set to the next QueueNode.
Once the print ptr reaches the tail ptr, the loop stops and then the final 
tail QueueNode is printed.
***************************************************************************/
void Queue::printQueue()
{
	QueueNode *printPtr = head;
	QueueNode *tailPtr = head->prev;
		
	cout << "Queue: " << endl;	
	while (printPtr != head->prev)
	{
		cout << printPtr->val << "  ";
		printPtr = printPtr->next;
	} 
	cout << tailPtr->val << endl;
}
