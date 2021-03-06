// InteractiveFiction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Rooms.h"
#include "Movement.h"
#include <iostream>
#include <string>
#include "UserInput.h"

using namespace std;

//Variables
string room2Description;	//Describes the second room
string room3Description;	//Describes the third room
string room4Description;	//Describes the fourth room
int playerLocation = 1;		//The room number the player is in
int myGold = 0;				//The amount of gold the player has
bool key = false;			//Whether or not the player has the key to escape the dungeon

int main()
{
	//Welcome
	cout << "Hello " << getTextFromUser("Please Enter Your Name: ") << "! Welcome to The Dungeon!\n";

	//Instructions
	cout << "Type in your action to play, or type in \"help\" for a list of options.\n\n";

	//Set Default Rooms
	resetRooms();
	
	//Start Game
	cout << "You appear to be lost in some sort of mysterious dungeon.\n";
	
	//Game Loop
	while (playerLocation != 0)		//While the player hasn't left the dungeon
	{
		setRoom(playerLocation);	//Set them to the current room they're in
	}

	return 0;
}
