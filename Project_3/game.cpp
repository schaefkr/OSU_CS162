/******************************************************************************************
* Program name:		game.cpp
* Author:		Kristin Schaefer
* Date:			5-12-2019
* Description:		This file contains the source file for the game function.
******************************************************************************************/

#include "game.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

/******************************************************************************************
Game::Game()
Description: Game constructor.
******************************************************************************************/
Game::Game()
{
	round = 1; 
}

/******************************************************************************************
Game::~Game()
Description: Game destructor.
******************************************************************************************/
Game::~Game()
{

}

/******************************************************************************************
void Game::setPlayers()
Description: This function sets the game players based on the user's selection.
******************************************************************************************/
void Game::setPlayers(int player1, int player2)
{
	if (player1 == 1)
	{
		p1 = new Vampire;
	}
	if (player1 == 2)
	{
		p1 = new Barbarian;
	}
	if (player1 == 3)
	{
		p1 = new BlueMen;
	}
	if (player1 == 4)
	{
		p1 = new Medusa;
	}
	if (player1 == 5)
	{
		p1 = new HarryPotter;
	}

	if (player2 == 1)
	{
		p2 = new Vampire;
	}
	if (player2 == 2)
	{
		p2 = new Barbarian;
	}
	if (player2 == 3)
	{
		p2 = new BlueMen;
	}
	if (player2 == 4)
	{
		p2 = new Medusa;
	}
	if (player2 == 5)
	{
		p2 = new HarryPotter;
	}
}

/******************************************************************************************
bool Game::combatRound()
Description: 
******************************************************************************************/
bool Game::combatRound()
{
	// each round consists of two attacks 
	// keeps playing until one of the characters strenth is <= 0.
	
	// Round 1
	int p1Damage = 0;
	p1Damage = p1->attack(); 
	p2->defense(p1Damage);
	printRound(1);	

	// Round 2
	int p2Damage = 0;
	p2Damage = p2->attack();
	p1->defense(p2Damage);
	printRound(2);	

	// Check player death
	bool playerDeath = false;
	if ((p1->getStrength() <= 0) && (p2->getStrength() > 0))
	{ 
		cout << "Player 1 " << p1->getName() << " has died" << endl; 	
		cout << "The combat is now over." << endl;
		playerDeath = true;
		round = 0;
	}
	else if ((p2->getStrength() <= 0) && (p1->getStrength() > 0))
	{ 
		cout << "Player 2 " << p2->getName() << " has died" << endl; 	
		cout << "The combat is now over." << endl;
		playerDeath = true;
		round = 0;
	}
	else if ((p1->getStrength() <= 0) && (p2->getStrength() <= 0))
	{ 
		cout << "Player 1 " << p1->getName() << " has died" << endl; 	
		cout << "Player 2 " << p2->getName() << " has died" << endl; 	
		cout << "The combat is now over." << endl;
		round = 0;
	}
	if (playerDeath)
	{
		delete p1;
		delete p2;
		p1 = nullptr;
		p2 = nullptr; 
	}
	return playerDeath;
}

/******************************************************************************************
void Game::printRound()
Description: This function prints the results of each attack round of the game. 
******************************************************************************************/
void Game::printRound(int attack)
{
	if (attack == 1)
	{
		cout << endl;
		cout << "---------------------------------" << endl;
		cout << "Round " << round << endl; 
		cout << "Attack 1" << endl;
		cout << "---------------------------------" << endl;
		cout << "Attacker: " << p1->getName() << endl;
		cout << "Defender: " << p2->getName() << endl;
		cout << "Attacker's roll: " << p1->getRoll() << endl;
		cout << "Defender's roll: " << p2->getRoll() << endl;
		cout << "Damage inflicted: " << p2->getDamage() << endl;
		cout << "Defender's strength after attack: " << p2->getStrength() << endl;
		cout << "---------------------------------" << endl;
		cout << endl;	
	}
	else
	{
		cout << endl;
		cout << "---------------------------------" << endl;
		cout << "Round " << round << endl; 
		cout << "Attack 2" << endl;
		cout << "---------------------------------" << endl;
		cout << "Attacker: " << p2->getName() << endl;
		cout << "Defender: " << p1->getName() << endl;
		cout << "Attacker's roll: " << p2->getRoll() << endl;
		cout << "Defender's roll: " << p1->getRoll() << endl;
		cout << "Damage inflicted: " << p1->getDamage() << endl;
		cout << "Defender's strength after attack: " << p1->getStrength() << endl;
		cout << "---------------------------------" << endl;
		cout << endl;	
		round++;
	}
}

