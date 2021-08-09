/***************************************************************************
* Program name:         instructor.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the header file for the Instructor derived class.
***************************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"
#include <string>
using std::string;

class Instructor : public Person
{
	private:
		float rating;
	public:
		Instructor();
		virtual void do_work();
		void setRating(float rating);
		float getRating(); 	
		virtual void setExtraInfo(float info);
		virtual float getExtraInfo();
};
#endif
