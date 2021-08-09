/***************************************************************************
* Program name:         person.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the header file for the Person parent class.
*                       It's derived classes are Student and Instructor. 
***************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person 
{
	protected:
		string name;
		int age;
	public:
		Person();
		~Person();
		virtual void do_work();
		void setAge(int age);
		int getAge();
		void setName(string name);
		string getName();
		virtual void setExtraInfo(float);
		virtual float getExtraInfo();
};
#endif
