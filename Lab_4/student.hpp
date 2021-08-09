/***************************************************************************
* Program name:         student.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the header file for the Student derived class.
***************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"
#include <string>
using std::string;

class Student : public Person
{
	private:
		float gpa;
	public:
		Student();
		virtual void do_work();
		void setGPA(float gpa);
		float getGPA(); 
		virtual void setExtraInfo(float info);	
		virtual float getExtraInfo();	
};
#endif
