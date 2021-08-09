/***************************************************************************
* Program name:		main.cpp
* Author:		Kristin Schaefer
* Date:			04-29-2019
* Description: 		This is the main function for the OSU information
* 			system program.
* Sources:
* Textbook chapter 7, 15
* https://stackoverflow.com/questions/21941539/c-vector-dynamic-memory-deallocation-delete
***************************************************************************/

#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "menu.hpp"

#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	University osu;
	University *universityPtr = &osu; 	
	int c = 0;

	// menu function 
	Menu mainMenu;
	cout << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << osu.getUniName() << " Information System" << endl;
	cout << "---------------------------------------------------------" << endl;
	do 
	{
		c = mainMenu.menuDisplay();

		if (c == 1)
		{
			// prints information about all of the buildings
			cout << "You have seleced option " << c << endl;	
			osu.printBldgInfo(); 
		}
		else if (c == 2)
		{
			// prints information of everybody at the university
			cout << "You have seleced option " << c << endl;	
			osu.printPplInfo(); 
		}
		else if (c == 3)
		{	
			// print another menu that prints all the people's names and
			// lets the user input the choice of the person the user would like to do work  
			cout << "You have seleced option " << c << endl;
			mainMenu.menu_do_work(universityPtr);
		}
	} while ((c == 1) || (c == 2) || (c == 3));

	return 0;
}
