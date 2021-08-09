/***************************************************************************
* Program name:         doubleLink.hpp
* Author:               Kristin Schaefer
* Date:                 05-12-2019
* Description:          This is the header file for the DoubleLink class.
***************************************************************************/

#ifndef DOUBLELINK_HPP
#define DOUBLELINK_HPP
#include "node.hpp" 
 
class DoubleLink : public Node
{
	private:
		Node *head = nullptr;
		Node *tail = nullptr;
	public:
		DoubleLink();
		~DoubleLink();
		void addHead(int value);
		void addTail(int value);
		void removeFirst();	
		void removeLast();
		void printForward();	
		void printReverse();			
};
#endif
