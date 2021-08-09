/*****************************************************************************************
** Program name:        ant.cpp
** Author:              Kristin Schaefer
** Date:                04-14-2019
** Description:         This file contains the source file for the Ant class for the 
                        Langton's Ant Simulation.       
******************************************************************************************/

#include "ant.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>

#include <stdint.h>
#include <limits.h>

/*****************************************************************************************
	                       		Ant::Ant         
This is the default constructor for the class Ant. The function is empty, and serves 
the purpose of initializing an Ant object.
******************************************************************************************/
Ant::Ant()
{
}

/*****************************************************************************************
	                       		Ant::setAntOrientation      
This function sets the orientation values for the ant directions up, right, down and 
left. The function also sets the beginning ant orientation to up.
******************************************************************************************/
void Ant::setAntOrientation()
{
	antUp = 0;
	antRight = 1;
	antDown = 2;
	antLeft = 3;
	antOrientation = antUp;
}

/*****************************************************************************************
                                      Ant::setBoardSize        
This function gets the user's input for the size of rows and columns for the board
and then fills the accordingly sized board with blank spaces.
source: https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
******************************************************************************************/
void Ant::setBoardSize()
{
	// get rows for board
	cout << "Please enter the number of rows for the board (1 to 50)." << endl;
	do
	{
		cin >> std::setw(1) >> boardRows;
		if (std::cin.good())
		{
			if ((boardRows < 1) || (boardRows > 50))
			{
				cout << "Please enter a positive integer from 1 to 50." << endl;
			}
		}
		else 
		{
			cout << "Please enter a positive integer from 1 to 50." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');	
		}	
	} while (!std::cin.good() || (boardRows < 1) || (boardRows > 50));	      

 	// get columns for board
	cout << "Please enter the number of columns for the board (1 to 50)." << endl;
	do
	{
		cin >> std::setw(1) >> boardColumns;
		if (std::cin.good())
		{
			if ((boardColumns < 1) || (boardColumns > 50))
			{
				cout << "Please enter a positive integer from 1 to 50." << endl;
			}
		}
		else 
		{
			cout << "Please enter a positive integer from 1 to 50." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');	
		}	
	} while (!std::cin.good() || (boardColumns < 1) || (boardColumns > 50));	      
	
	// create board and fill with spaces 
	board = new char*[boardRows];
        
	for (int index = 0; index < boardRows; index++)
        {
                board[index] = new char[boardColumns];
        }

        for (int r = 0; r < boardRows; r++)
	{
		for (int c = 0; c < boardColumns; c++)
		{
			board[r][c] = ' ';
		}	
	}
}

/*****************************************************************************************
                                      Ant::setBoardSteps        
This function asks the user to input the the total number of steps the ant can take.
source: https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
******************************************************************************************/
void Ant::setBoardSteps()
{
	// get the number of total steps of the ant from the user
	cout << "Please enter the number of steps for the board (1 to 100)." << endl;
	do
	{
		cin >> std::setw(1) >> steps;
		if (std::cin.good())
		{
			if ((steps < 1) || (steps > 100))
			{
				cout << "Please enter a positive integer from 1 to 100." << endl;
			}
		}
		else 
		{
			cout << "Please enter a positive integer from 1 to 100." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');	
		}	
	} while (!std::cin.good() || (steps < 1) || (steps > 100));	      
}

/*****************************************************************************************
                                      Ant::setBoardLocation        
This function sets the value of the ant's location.
https://stackoverflow.com/questions/18567483/c-checking-for-an-integer#18567586
******************************************************************************************/
void Ant::setBoardLocation()
{
	// get the starting row of the ant from the user	
	cout << "Please enter the starting row of the ant." << endl;
	do
	{
		cin >> std::setw(1) >> antRow;
		if (std::cin.good())
		{
			antRow -= 1;
			if ((antRow < 0) || (antRow > (boardRows - 1)))
			{
				cout << "Please enter a positive integer." << endl;
			}
		}
		else 
		{
			cout << "Please enter a positive integer." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');	
		}	
	} while (!std::cin.good() || (antRow < 0) || (antRow > (boardRows - 1)));	      
	
	// get the starting column of the ant from the user
	cout << "Please enter the starting column of the ant." << endl;
	do
	{
		cin >> std::setw(1) >> antColumn;
		if (std::cin.good())
		{
			antColumn -= 1;
			if ((antColumn < 0) || (antColumn > (boardColumns - 1)))
			{
				cout << "Please enter a positive integer." << endl;
			}
		}
		else 
		{
			cout << "Please enter a positive integer." << endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');	
		}	
	} while (!std::cin.good() || (antColumn < 0) || (antColumn > (boardColumns - 1)));	      
}

/*****************************************************************************************
                                      Ant::startSim        
This function begins the Langton's Any simulation.
source: https://www.youtube.com/watch?v=G1EgjgMo48U  
******************************************************************************************/
void Ant::startSim()
{
	//start the simulation
	state = board[antRow][antColumn];
	board[antRow][antColumn] = '*'; 
	
	for (int index = 0; index < steps; index++)
	{
		if (state == ' ')
		{
			turnRight();
			printBoard();
			board[antRow][antColumn] = '#';
			moveForward();
		}
		
		else if (state == '#') 
		{
			turnLeft();
			printBoard();
			board[antRow][antColumn] = ' ';
			moveForward(); 
		} 
	}
}

/*****************************************************************************************
                                      Ant::turnLeft        
This function rotates the antOrientation 90 degrees to the left by decrementing the
antOrientation value. If the value is less than 0 (antUp), the variable is set to  
antLeft, thus wrapping the orientation to 3.
source: https://www.youtube.com/watch?v=G1EgjgMo48U 
******************************************************************************************/
void Ant::turnLeft()
{
	antOrientation--;
	if (antOrientation < antUp)
	{
		antOrientation = antLeft;
	} 
}

/*****************************************************************************************
                                      Ant::turnRight        
This function rotates antOrientation 90 degrees to the right by incrementing the 
antOrientation value. If the value is greater than 3 (antLeft), the variable is set to 
antUp, thus wrapping the orientation to 0. 
source: https://www.youtube.com/watch?v=G1EgjgMo48U
******************************************************************************************/
void Ant::turnRight()
{
	antOrientation++;
	if (antOrientation > antLeft)
	{
		antOrientation = antUp;
	}	 
}

/*****************************************************************************************
                                      Ant::moveForward        
This function moves the ant forward by incrementing or decrementing the row or column 
based on the antOrientation. If the ant reaches an edge, it is wrapped to the opposite
edge of the board. 
source: https://www.youtube.com/watch?v=G1EgjgMo48U  
******************************************************************************************/
void Ant::moveForward()
{
	if (antOrientation == antUp)
	{
		antRow--;
	}
	
	else if (antOrientation == antRight)
	{
		antColumn++;
	}

	else if (antOrientation == antDown)
	{
		antRow++;
	} 
	
	else if (antOrientation == antLeft)
	{
		antColumn--;
	}

	// wrap around edges
	if (antColumn > (boardColumns - 1))
	{
		antColumn = 0; 
	} 
	
	else if (antColumn < 0)
	{
		antColumn = boardColumns - 1;
	}

	if (antRow > (boardRows - 1))
	{
		antRow = 0;
	}

	else if (antRow < 0)
	{
		antRow = boardRows - 1;
	}
	state = board[antRow][antColumn];
	board[antRow][antColumn] = '*'; 	
}

/*****************************************************************************************
                                      Ant::printBoard        
This function prints the current board.  
******************************************************************************************/
void Ant::printBoard()
{
	for (int r = 0; r < boardRows; r++)
	{
        	for (int c = 0; c < boardColumns; c++)
		{
			cout << board[r][c];
		}
	cout << endl;
	}
	cout << endl;
}

/*****************************************************************************************
                                      Ant::deleteArray       
This is the destructor for the ant board. It deallocates the memory of the dynamic
2d array.
******************************************************************************************/
void Ant::deleteArray()
{
	for (int index = 0; index < boardRows; index++)
	{
		delete [] board[index];
	}
	delete [] board;	 
}

