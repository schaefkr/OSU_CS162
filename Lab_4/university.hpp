/***************************************************************************
* Program name:         university.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the header file for the University class.
***************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

class University 
{
	private:
		string name;
		Building *bldgPtr = nullptr;
		vector<Person*> personPtrs;
		int n;
		int m;
	public:
		University();
		~University();
		void printBldgInfo();
		void printPplInfo();
		string getUniName();
		void uni_do_work(int choice);	
		void printPplNames();
};
#endif
