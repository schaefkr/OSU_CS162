/***************************************************************************
* Program name:         university.cpp
* Author:               Kristin Schaefer
* Date:                 04-29-2019
* Description:		This is the source file for the University class.
 * ***************************************************************************/

#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"

#include <iostream> 
#include <string>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::string;

/***************************************************************************
University::University()
Description: Constructor
***************************************************************************/
University::University()
{
	name = "Oregon State University";
	m = 2;
	n = 2;
	
	bldgPtr = new Building[n];
	bldgPtr[0].setBldgName("Memorial Union");
	bldgPtr[0].setBldgSize(5000.00);
	bldgPtr[0].setBldgAddress("2501 SW Jefferson Way");
	bldgPtr[1].setBldgName("Valley Library");
	bldgPtr[1].setBldgSize(8000.00);
	bldgPtr[1].setBldgAddress("201 SW Waldo Place");

	personPtrs.push_back(new Student);
	personPtrs.push_back(new Instructor);
	personPtrs[0]->setName("Screech Powers");
	personPtrs[0]->setAge(20);
	personPtrs[0]->setExtraInfo(2.5);
	personPtrs[1]->setName("Miss Bliss");	
	personPtrs[1]->setAge(35);
	personPtrs[1]->setExtraInfo(5.0);
}

/***************************************************************************
University::i~University()
Description: Destructor
***************************************************************************/
University::~University()
{
	delete [] bldgPtr;
	while (!personPtrs.empty())
	{
		delete personPtrs.back();
		personPtrs.pop_back(); 
	}
}

/***************************************************************************
void University::printBldgInfo()
Description: This function prints the information of all of the buildings
in its information system, such as name, address and building size. 
***************************************************************************/
void University::printBldgInfo()
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << "Building " << i+1 << endl;
		cout << "Name: " << bldgPtr[i].getBldgName() << endl;
		cout << "Size: " << bldgPtr[i].getBldgSize() << " sq. ft." << endl;
		cout << "Address: " << bldgPtr[i].getBldgAddress() << endl;
	}
}

/***************************************************************************
void University::printPplInfo()
Description: This function prints the information of all of the people 
in its information system, such as name, age, gpa and rating. 
***************************************************************************/
void University::printPplInfo()
{
		cout << endl;
		cout << "Person 1"<< endl;
		cout << "Name: " << personPtrs[0]->getName() << endl;	
		cout << "Age: " << personPtrs[0]->getAge() << endl;	
		cout << "GPA: " << personPtrs[0]->getExtraInfo() << endl;
		
		cout << endl;
		cout << "Person 2" << endl;
		cout << "Name: " << personPtrs[1]->getName() << endl;	
		cout << "Age: " << personPtrs[1]->getAge() << endl;	
		cout << "Rating: " << personPtrs[1]->getExtraInfo() << endl;
}

/***************************************************************************
string University::getName()
Description: This function gets the name of the University.
***************************************************************************/
string University::getUniName()
{
	return name;
}

/***************************************************************************
void University::uni_do_work(int choice)
Description: This function calls the person to do_work(). 
***************************************************************************/
void University::uni_do_work(int choice)
{
	if ((choice >= 1) && (choice <= m))
	{
		personPtrs[choice-1]->do_work();
	}
}

/***************************************************************************
void University::printPplNames()
Description: This function prints the names of all of the people 
***************************************************************************/
void University::printPplNames()
{
	for (int i = 0; i < m; i++)
	{
		cout << i+1 << ".";
		cout << personPtrs[i]->getName() << endl;	
	}
}
