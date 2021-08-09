/***************************************************************************
* Program name:         doubleLink.cpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:		This is the source file for the DoubleLink class.
***************************************************************************/

#include "doubleLink.hpp"
#include "node.hpp"
#include <iostream>
using std::endl;
using std::cout;

/***************************************************************************
DoubleLink:DoubleLink() : Node()
Description: Constructor
***************************************************************************/
DoubleLink::DoubleLink() : Node()
{
}

/***************************************************************************
DoubleLink::~DoubleLink()
Description: Destructor
Source: textbook ch17 
***************************************************************************/
DoubleLink::~DoubleLink()
{
	Node *nodePtr = head;
	while(nodePtr != nullptr)
	{
		Node *garbage = nodePtr;
		nodePtr = nodePtr->getNextPtr();
		delete garbage;
	}
}

/***************************************************************************
void DoubleLink::addHead(int value)
Description: This function adds a user-specified value to the head of the 
doubly-linked list.
***************************************************************************/
void DoubleLink::addHead(int value)
{
	Node *addHeadPtr = new Node(value);

	if (head == nullptr)
	{
		head = addHeadPtr;
		tail = head;
	}
	else
	{
		addHeadPtr->setNextPtr(head);	
		head = addHeadPtr;
	}
}

/***************************************************************************
void DoubleLink::addTail(int value)
Description: This function adds a user-specified value to the tail of the 
doubly-linked list.
***************************************************************************/
void DoubleLink::addTail(int value)
{
	Node *addTailPtr = new Node(value);

	if (head == nullptr)
	{
		head = addTailPtr;
		tail = head;
	}
	else
	{
		addTailPtr->setPrevPtr(tail);
		tail->setNextPtr(addTailPtr);	
		tail = addTailPtr; 
	}
}

/***************************************************************************
void DoubleLink::removeFirst()
Description: This function removes the first value in a doubly-linked list.
***************************************************************************/
void DoubleLink::removeFirst()
{
	if (head)
	{
		Node *nodeDelete = head;
		head = head->getNextPtr();	

		if (head)
		{
			head->setPrevPtr(0); 
		}
		else
		{
			tail = nullptr;
		}
		delete nodeDelete;
	}
	else
	{
		cout << "Option can not be completed." << endl;
		cout << "There are no nodes to delete in the list." << endl;
	}
}

/***************************************************************************
void DoubleLink::removeLast()
Description: This function removes the last value in a doubly-linked list.
***************************************************************************/
void DoubleLink::removeLast()
{
	if (tail)
	{
		Node *nodeDelete = tail;
		tail = tail->getPrevPtr();	

		if (tail)
		{
			tail->setNextPtr(0);	
		}
		else 
		{
			head = nullptr;
		}
		delete nodeDelete;
	}
	else
	{
		cout << "Option can not be completed." << endl;
		cout << "There are no nodes to delete in the list." << endl;
	}
}

/***************************************************************************
void DoubleLink::printForward()
Description: This function traverses the doubly linked list in forward 
order and prints the values in the list. 
***************************************************************************/
void DoubleLink::printForward()
{
	Node *nodePrintPtr = head;
	if (head == nullptr)
	{
		cout << "There are no nodes to print." << endl;
		cout << "The list is empty." << endl;
	}
	else
	{
		while (nodePrintPtr != nullptr)
		{
			cout << nodePrintPtr->getValue() << "  ";
			nodePrintPtr = nodePrintPtr->getNextPtr();	
		}
	}
	cout << endl;
}

/***************************************************************************
void DoubleLink::printReverse()
Description: This function traverses the doubly linked list in reverse 
order and prints the values in the list. 
***************************************************************************/
void DoubleLink::printReverse()
{
	Node *nodePrintPtr = tail;
	if (head == nullptr)
	{
		cout << "There are no nodes to print." << endl;
		cout << "The list is empty." << endl;
	}
	else
	{
		while (nodePrintPtr != nullptr)
		{
			cout << nodePrintPtr->getValue() << "  ";
			nodePrintPtr = nodePrintPtr->getPrevPtr();
		}
	}
	cout << endl;
}
