/***************************************************************************
* Program name:         building.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:          This is the source file for the building class.
***************************************************************************/

#include "building.hpp"
#include <iostream>
#include <string>
using std::string;

/***************************************************************************
* Building::Building() 
* Description: Constructor
***************************************************************************/
Building::Building()
{
}

/***************************************************************************
* Building::~Building() 
* Description: Destructor
***************************************************************************/
Building::~Building()
{
}

/***************************************************************************
* string Building::getBldgName() 
* Description: This function returns the name of the building. 
***************************************************************************/
string Building::getBldgName()
{
	return bldgName;
}

/***************************************************************************
* void Building::setBldgName(string bldgName) 
* Description: This function sets the name of the building. 
***************************************************************************/
void Building::setBldgName(string bldgName)
{
	this->bldgName = bldgName;
}

/***************************************************************************
* double Building::getBldgSize() 
* Description: This function returns the size of the building. 
***************************************************************************/
double Building::getBldgSize()
{
	return bldgSize;
}

/***************************************************************************
* void Building::setBldgSize(double bldgSize) 
* Description: This function sets the size of the building. 
***************************************************************************/
void Building::setBldgSize(double bldgSize)
{
	this->bldgSize = bldgSize;
}

/***************************************************************************
* string Building::getBldgAddress() 
* Description: This function returns the address of the building. 
***************************************************************************/
string Building::getBldgAddress()
{
	return bldgAddress;
}

/***************************************************************************
* void Building::setBldgAddress(string bldgAddress) 
* Description: This function sets the address of the building. 
***************************************************************************/
void Building::setBldgAddress(string bldgAddress)
{
	this->bldgAddress = bldgAddress;
}
