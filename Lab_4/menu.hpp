/******************************************************************************************
* Program name:        menu.hpp
* Author:              Kristin Schaefer
* Date:                04-29-2019
* Description:         This file contains the header file for the Menu class.
******************************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP
#include "university.hpp"

class Menu
{
	private:
		University *menuUniPtr = nullptr;
	public:
		Menu();
		~Menu();
		int menuDisplay(); 
		void menu_do_work(University *uniPtr);
};
#endif
