/******************************************************************************************
* Program name:		game.cpp
* Author:		Kristin Schaefer
* Date:			5-26-2019
* Description:		This file contains the source file for the game function.
* Game class contains all of the functions controlling the simulation of the tournament.
* The class contains two Team objects representing the lineup of each team as a doubly-
* linked list of nodes of Character objects. The class also has one Loser (also DLL)
* containing the Character object nodes that have lost a battle round. The class has 
* member functions to control the game setup, gameSetup(), the creation of new players 
* for the team lineups, createPlayer(), the simulation of the tournament, 
* playTournament(), as well as support functions combatRound(), printGame(), and
* printRound() for the playTournament() function.
******************************************************************************************/

#include "game.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "team.hpp"
#include "loser.hpp"
#include "menu.hpp"
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
	team1Score = 0; 
	team2Score = 0; 
}

/******************************************************************************************
Game::~Game()
Description: Game destructor.
******************************************************************************************/
Game::~Game()
{

}

/******************************************************************************************
void Game::gameSetup()
Description: This function calls menu functions to set the team size for both teams. After
that, the function uses a loop to call a menu function to get the Character type for each
Character. A new object of that type is then created and another menu function is called
to get the users Character name for that Character. Finally, a pointer to the newly
created Character is passed to the doubly-linked Team list with the addBack function.
******************************************************************************************/
void Game::gameSetup()
{
	int i, type = 0;	
	Character *tempPlayer = nullptr;
	team1 = new Team;
	team2 = new Team;
	loserPile = new Loser;	

	// team size for team 1 and 2
	teamSize = menuTeamSize();

	// choose character type and name for each player on team 1 
	for (i = 0; i < teamSize; i++)
	{
		type = menuCharacter(i+1);
		tempPlayer = createPlayer(type);
		tempPlayer->setPlayerName(menuPlayerName(i+1)); 
		team1->addBack(tempPlayer);
	}	
	// choose character type and name for each player on team 2 
	for (i = 0; i < teamSize; i++)
	{
		type = menuCharacter(i+1);
		tempPlayer = createPlayer(type);
		tempPlayer->setPlayerName(menuPlayerName(i+1)); 
		team2->addBack(tempPlayer);
	}	
}

/******************************************************************************************
void Game::playTournament()
Description: This function controls the simulation of the tournament for the fantasy combat
game. The main body of the game is controlled within a do-while loop. The loop stops when 
one team runs out of characters who have been transferred to the loser pile. After the 
loops exits, function are called to print the Game result and to optionally print the loser  
pile.
******************************************************************************************/
void Game::playTournament()
{
	bool playAgain = true;
	bool printPile = false;
	round = 1;
	team1Score = 0; 
	team2Score = 0; 

	do 
	{
		p1 = team1->getFront();	
		p2 = team2->getFront();
		combatRound();	
		// compare damage, find loser, and implement recovery for winner
		if (p1->getDamage() < p2->getDamage())
		{
			team1->pushBack();
			p1->recovery();
			team2->removeFront();
			loserPile->addFront(p2);
			team1Score++;
		}	
		else if (p1->getDamage() > p2->getDamage())
		{
			team2->pushBack();
			p2->recovery();
			team1->removeFront();
			loserPile->addFront(p1);
			team2Score++;
		}	
		// print Battle result
		printRound();	
		round ++;

		if (team1->isEmpty() || team2->isEmpty())
		{
			playAgain = false;	
		}
	
	} while (playAgain);
	// print the Game result
	printGame();
	// allow user to print the loser pile
	printPile = menuPrintLoserPile();
	if (printPile)
	{
		loserPile->print();
	}
	// delete extra members in order to play again
	team1->deleteTeam();	
	team2->deleteTeam();	
	loserPile->deleteLoser();
	delete team1;	
	delete team2;	
	delete loserPile;	
}

/******************************************************************************************
Character * Game::createPlayer(int player)
Description: This function creates a new type of derived Character object based on the
user's selection.
******************************************************************************************/
Character * Game::createPlayer(int player)
{
	if (player == 1)
	{
		Character *newPlayer = new Vampire;
		return newPlayer;
	}
	else if (player == 2)
	{
		Character *newPlayer = new Barbarian;
		return newPlayer;
	}
	else if (player == 3)
	{
		Character *newPlayer = new BlueMen;
		return newPlayer;
	}
	else if (player == 4)
	{
		Character *newPlayer = new Medusa;
		return newPlayer;
	}
	else
	{
		Character *newPlayer = new HarryPotter;
		return newPlayer;
	}
}

/******************************************************************************************
void Game::combatRound()
Description: This function calls the attack and defense function of two Characters who
are battling in the current round.  
******************************************************************************************/
void Game::combatRound()
{
	// each battle consists of two rounds 
	// round 1
	int p1Damage = 0;
	p1Damage = p1->attack(); 
	p2->defense(p1Damage);

	// round 2
	int p2Damage = 0;
	p2Damage = p2->attack();
	p1->defense(p2Damage);
}

/******************************************************************************************
void Game::printRound()
Description: This function prints the results of each game round, consisting of an 
attack and defense by each Character. It prints the name of each player who is battling, 
as well as their damage and strength values. It also prints the name of the player who
won the battle round or if it was a tie. 
******************************************************************************************/
void Game::printRound()
{
	cout << "------------------------------------------------" << endl;	
	cout << "Round " << round << ":" << endl;		
	cout << "------------------------------------------------" << endl;	
	cout << "Team 1 Player: " << p1->getPlayerName() << endl;
	cout << "Team 2 Player: " << p2->getPlayerName() << endl;
	cout << p1->getPlayerName() << " damage to opponent: " << p2->getDamage() << endl; 
	cout << p2->getPlayerName() << " damage to opponent: " << p1->getDamage() << endl; 
	if (p1->getDamage() < p2->getDamage())
	{
		cout << p1->getPlayerName() << " has won the battle." << endl;
		cout << p1->getPlayerName() << " has recovered " << p1->getRecovery() << " points." << endl; 
		cout << p1->getPlayerName() << " strength remaining: " << p1->getStrength() << endl; 
	}
	else if (p1->getDamage() > p2->getDamage())
	{
		cout << p2->getPlayerName() << " has won the battle." << endl;
		cout << p2->getPlayerName() << " has recovered " << p2->getRecovery() << " points." << endl; 
		cout << p2->getPlayerName() << " strength remaining: " << p2->getStrength() << endl; 
	}
	else
	{
		cout <<	"The battle was a tie. The players will have a rematch." << endl;
	}
	cout << "Team 1 Total Score: " << team1Score << endl;
	cout << "Team 2 Total Score: " << team2Score << endl;
}

/******************************************************************************************
void Game::printGame()
Description: This function prints the final game results. It prints the total team scores, 
as well as which team won or if there was a tie game.  
******************************************************************************************/
void Game::printGame()
{
	cout << "------------------------------------------------" << endl;	
	cout << "Game Results: " << endl; 
	cout << "------------------------------------------------" << endl;	
	cout << "Team 1 Total Score: " << team1Score << endl;
	cout << "Team 2 Total Score: " << team2Score << endl;
	if (team1Score > team2Score)
	{
		cout << "Team 1 has won the game." << endl;
	}
	else if (team1Score < team2Score)
	{
		cout << "Team 2 has won the game." << endl;
	}
	else
	{
		cout << "Tie game." << endl;
	}
}
