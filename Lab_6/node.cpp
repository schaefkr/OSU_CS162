/***************************************************************************
* Program name:         node.cpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:		This is the source file for the Node class.
***************************************************************************/

#include "node.hpp"
#include <iostream>

/***************************************************************************
Node::Node()
Description: Default constructor
***************************************************************************/
Node::Node()
{

}

/***************************************************************************
Node::Node(int val)
Description: Constructor
***************************************************************************/
Node::Node(int val)
{
	this->val = val;
}

/***************************************************************************
Node::~Node()
Description: Destructor
***************************************************************************/
Node::~Node()
{

}

/***************************************************************************
void Node::setNextPtr(Node *tempPtr)
Description: This function sets the next pointer of the Node. 
***************************************************************************/
void Node::setNextPtr(Node *tempPtr)
{
	next = tempPtr;
}

/***************************************************************************
void Node::setNextPtr(int num)
Description: This function sets the next pointer of the Node to nullptr. 
***************************************************************************/
void Node::setNextPtr(int num)
{
	if (num == 0)
	{
		next = nullptr;
	}
}

/***************************************************************************
void Node::setPrevPtr(Node *tempPtr)
Description: This function sets the prev pointer of the Node. 
***************************************************************************/
void Node::setPrevPtr(Node *tempPtr)
{
	prev = tempPtr;
}

/***************************************************************************
void Node::setPrevPtr(int num)
Description: This function sets the prev pointer of the Node to nullptr. 
***************************************************************************/
void Node::setPrevPtr(int num)
{
	if (num == 0)
	{
		prev = nullptr;
	}
}

/***************************************************************************
Node * Node::getNextPtr()
Description: This function gets the next pointer of the Node. 
***************************************************************************/
Node * Node::getNextPtr()
{
	return next;
}

/***************************************************************************
Node * Node::getPrevPtr()
Description: This function gets the prev pointer of the Node. 
***************************************************************************/
Node * Node::getPrevPtr()
{
	return prev;
}

/***************************************************************************
int Node::getValue()
Description: This function gets the val member variable. 
***************************************************************************/
int Node::getValue()
{
	return val;
}
