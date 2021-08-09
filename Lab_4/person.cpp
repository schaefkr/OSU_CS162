/***************************************************************************
* Program name:		person.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description:		This is the source file for the Person class. 
***************************************************************************/

#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using std::string;
using std::cout;
using std::endl;

/***************************************************************************
* Person::Person()
* Description: Constructor
***************************************************************************/
Person::Person()
{
}

/***************************************************************************
* Person::~Person()
* Description: Destructor
***************************************************************************/
Person::~Person()
{
}

/***************************************************************************
* void Person::do_work()
* Description: Virtual Function. 
***************************************************************************/
void Person::do_work()
{
	int seed = time(0);
	srand(seed);
	int hours = 72;
	int work = rand() % hours + 1;
}

/***************************************************************************
* void Person::setAge(int age)
* Description: This function sets the person's age. 
***************************************************************************/
void Person::setAge(int age)
{
	this->age = age; 
}

/***************************************************************************
* int Person::getAge()
* Description: This function gets the person's age. 
***************************************************************************/
int Person::getAge()
{
	return age; 
}

/***************************************************************************
* void Person::setName(string name)
* Description: This function sets the person's name. 
***************************************************************************/
void Person::setName(string name)
{
	this->name = name; 
}

/***************************************************************************
* string Person::getName()
* Description: This function gets the person's name. 
***************************************************************************/
string Person::getName()
{
	return name; 
}

/***************************************************************************
* void Person::setExtraInfo(float info)
* Description: This function sets extra person information. 
***************************************************************************/
void Person::setExtraInfo(float info)
{
}

/***************************************************************************
* void Person::float getExtraInfo()
* Description: This function gets extra person information. 
***************************************************************************/
float Person::getExtraInfo()
{
}





