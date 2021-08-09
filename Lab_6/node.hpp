/***************************************************************************
* Program name:         node.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the Node class.
***************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP
 
class Node
{
	protected:
		int val;
		Node *next = nullptr;
		Node *prev = nullptr;
	public:
		Node(int val);
		Node();
		~Node();
		void setNextPtr(Node *tempPtr);
		void setNextPtr(int num);
		void setPrevPtr(Node *tempPtr);
		void setPrevPtr(int num);
		Node * getNextPtr();
		Node * getPrevPtr();
		int getValue();		
};
#endif
