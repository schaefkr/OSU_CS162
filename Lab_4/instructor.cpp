/***************************************************************************
* Program name:		instructor.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description:		This is the source file for the Instrucor derived class. 
***************************************************************************/

#include "instructor.hpp"
#include "person.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::string;
using std::cout;
using std::endl;

/***************************************************************************
Instructor::Instructor()
Description: Constructor
***************************************************************************/
Instructor::Instructor() : Person()
{
}

/***************************************************************************
void Instructor::do_work()
Description: This function generates a random number of hours of work and
outputs a message specific to the Instructor class. 
***************************************************************************/
void Instructor::do_work()
{
	int seed = time(0);
	srand(seed);
	int hours = 72;
	int work = rand() % hours + 1;

	cout << name << " graded papers for " << work << " hours." << endl;
}

/***************************************************************************
void Instructor::setRating(float rating)
Description: This function sets the instructor's rating. 
***************************************************************************/
void Instructor::setRating(float rating)
{
	this->rating = rating;
}

/***************************************************************************
float Instructor::getRating()
Description: This function gets the instructor's rating. 
***************************************************************************/
float Instructor::getRating()
{
	return rating;
}

/***************************************************************************
void Instructor::setExtraInfo(float info)
Description: This function sets the instructor's rating. 
***************************************************************************/
void Instructor::setExtraInfo(float info)
{
	rating = info;
}

/***************************************************************************
float Instructor::getExtraInfo()
Description: This function gets the instructor's rating. 
***************************************************************************/
float Instructor::getExtraInfo()
{
	return rating;
}
