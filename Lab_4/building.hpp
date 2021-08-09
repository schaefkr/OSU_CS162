/***************************************************************************
* Program name:         building.hpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the Header file for the Building class. 
***************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using std::string;

class Building
{
	private:
		string bldgName;
		double bldgSize;
		string bldgAddress;
	public:
		Building();
		~Building();
		void setBldgName(string bldgName);
		string getBldgName();
		void setBldgSize(double bldgSize);
		double getBldgSize();
		void setBldgAddress(string bldgAddress);
		string getBldgAddress();
};
#endif
