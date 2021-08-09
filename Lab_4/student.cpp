/***************************************************************************
* Program name:		student.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description:		This is the source file for the Student derived class. 
***************************************************************************/

#include "student.hpp"
#include "person.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;

/***************************************************************************
Student::Student()
Description: Constructor
***************************************************************************/
Student::Student() : Person()
{
}

/***************************************************************************
void Student::do_work()
Description: This function generates a random number of hours of work and
outputs a message specific to the Student class. 
***************************************************************************/
void Student::do_work()
{
	int seed = time(0);
	srand(seed);
	int hours = 72;
	int work = rand() % hours + 1;

	cout << name << " did " << work << " hours of homework." << endl;
}

/***************************************************************************
void Student::setGPA(float gpa)
Description: This function sets the student's gpa. 
***************************************************************************/
void Student::setGPA(float gpa)
{
	this->gpa = gpa; 
}

/***************************************************************************
float Student::getGPA()
Description: This function sets the student's gpa. 
***************************************************************************/
float Student::getGPA()
{
	return gpa; 
}

/***************************************************************************
void Student::setExtraInfo(float info)
Description: This function sets the student's gpa. 
***************************************************************************/
void Student::setExtraInfo(float info)
{
	gpa = info; 
}

/***************************************************************************
float Student::getExtraInfo()
Description: This function gets the student's gpa. 
***************************************************************************/
float Student::getExtraInfo()
{
	return gpa; 
}
