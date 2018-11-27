// InteractiveFiction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//Variables
string room1Description;	//Describes the first room
string room2Description;	//Describes the second room
string room3Description;	//Describes the third room
string room4Description;	//Describes the fourth room
int playerLocation = 1;		//The room number the player is in
int gold = 0;				//The amount of gold the player has
bool key = false;			//Whether or not the player has the key to escape the dungeon

//Pointer Functions
void giveGold(int* gold);
void giveKey(bool* key);

//Functions
string getTextFromUser(string prompt) //Recieves a string from the user 
{
	string text;		//The user's response
	cout << prompt;		//The prompt for the user to respond to
	cin >> text;		//The user's input
	return text;		//Return the response
}

int getNumbersFromUser(string prompt) //Recieves an int from the user 
{
	int number;			//The user's response
	cout << prompt;		//The prompt for the user to respond to
	cin >> number;		//The user's input
	return number;		//Return the response
}

void room1()	//The interactions for the first room
{
	cout << room1Description;	//Print out room description when player enters
	bool inRoom = true;			//Whether or not the player has left the room
	do
	{
		string action = getTextFromUser("What would you like to do?\n");	//Ask what they want to do
		
		if (action == "east")													//The player walks east
		{
			cout << "You walk through the East door.\n";						//Tell them they moved
			playerLocation = 2;													//Move them
			inRoom = false;														//Remove them from the room
		}
		else if (action == "south")												//The player walks south
		{
			cout << "You walk through the South door.\n";						//Tell them they moved
			playerLocation = 3;													//Move them
			inRoom = false;														//Remove them from the room
		}
		else if (action == "west" || action == "north")							//If they go a way withouth a door
		{
			cout << "You bump into a wall.\n";									//Tell them they can't go that way
		}
		else if (action == "look")												//If they look
		{			
			cout << room1Description;											//Describe the room again
		}
		else if (action == "help")												//If they ask for help
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\n\n";		//Give them a list of actions
		}
		else																	//If they give an unknown action
		{
			cout << action << " is not an action you can currently do.\n";		//Tell them they can't do that
		}

	} while (inRoom);
}

void room2()					//The interactions for the first room
{
	cout << room2Description;	//Print out room description when player enters
	bool inRoom = true;			//Whether or not the player has left the room
	bool unOpened = true;		//Whether the chest was opened or not

	do
	{
		string action = getTextFromUser("What would you like to do?\n");					//Ask what they want to do

		if (action == "west")																//The player walks west
		{
			cout << "You walk through the West door.\n";
			playerLocation = 1;
			inRoom = false;
		}
		else if (action == "south")															//The player walks south
		{
			cout << "You walk through the South door.\n";
			playerLocation = 4;
			inRoom = false;
		}
		else if (action == "east" || action == "north")										//The player walks east or north
		{
			cout << "You bump into a wall.\n";
		}
		else if (action == "look")															//If the player looks
		{
			cout << room2Description;
		}
		else if(action == "openchest")														//If the player opens the chest
		{
			if (unOpened)																	//If they haven't already opened it
			{
				room2Description = "There's an empty chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
				giveGold(&gold);
				cout << "You found 20 Gold!\n";
				unOpened = false;
			}
			else																			//If it was already opened
			{
				cout << "The chest is empty.\n";
			}
		}
		else if (action == "help")															//If they ask for help
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\nopenchest\n\n";
		}
		else																				//If they put in any other action 
		{
			cout << action << " is not an action you can currently do.\n";	
		}

	} while (inRoom);
}

void room3()
{
	cout << room3Description;
	bool inRoom = true;
	bool hasRisen = false;	//If the skeleton in the room has risen
	bool isAlive = false;	//If the skeleton is still alive

	do
	{
		string action = getTextFromUser("What would you like to do?\n");


		if (action == "north")
		{
			if (isAlive)	//If the skeleton has been encountered and is alive
			{
				//The player dies trying to flee
				cout << "The skeleton catches you trying to flee and gets you in the back.\nYou have been slain.\n";
				playerLocation = 0;	//Player exits the dungeon and games ends
				inRoom = false;
			}
			else if (!hasRisen)	//If the skeleton hasn't risen
			{
				//The skeleton rises, and then is alive for the player to deal with
				cout << "Before you can get to the door, a skeleton rises up and lunges at you.\n";
				room3Description = "There is a skeleton attacking you. You better deal with him first before trying to escape.\n";
				hasRisen = true;
				isAlive = true;
			}
			else
			{
				//The player can leave the room
				cout << "You walk through the North door.\n";
				playerLocation = 1;
				inRoom = false;
			}
		}

		else if (action == "east")
		{
			if (isAlive)	//If the skeleton has been encountered and is alive
			{
				//The player dies trying to flee
				cout << "The skeleton catches you trying to flee and gets you in the back.\nYou have been slain.\n";
				playerLocation = 0;	//Player exits the dungeon and games ends
				inRoom = false;
			}
			else if (!hasRisen)	//If the skeleton hasn't risen
			{
				//The skeleton rises, and then is alive for the player to deal with
				cout << "Before you can get to the door, a skeleton rises up and lunges at you.\n";
				room3Description = "There is a skeleton attacking you. You better deal with him first before trying to escape.\n";
				hasRisen = true;
				isAlive = true;
			}
			else
			{
				//The player can leave the room
				cout << "You walk through the East door.\n";
				playerLocation = 4;
				inRoom = false;
			}
		}

		else if (action == "west" || action == "south")
		{
			cout << "You bump into a wall.\n";
		}

		else if (action == "look")
		{
			cout << room3Description;
		}

		else if (action == "attack")	//Attacking the skeleton
		{
			if (isAlive) //If it's still alive
			{
				cout << "You swing you sword at the skeleton, and he falls toppling to the ground.\nHe drops a key and you pick it up.\n";
				key = true;	//Get the key
				isAlive = false;	//Kill it
				room3Description = "There is a pile of bones resting in the middle of the room that knows better to rise up in your presence. You can see large wooden doors on both the North and East sides of the room.\n";
			}
			else	//If the skeleton's not there
			{
				cout << "There is nothing for you to attack.\n";
			}
		}

		else if (action == "bribe" && gold == 20)	//If you have the gold
		{
			if (isAlive)	//If the skeleton's alive
			{
				cout << "You offer the skeleton all of your gold to avoid conflict.\nYou realize the skeleton wasn't really a bad guy, just a guy going through a rough time.\n";
				cout << "He hands you a key and leaves.\n";
				giveKey(&key);
				isAlive = false;	//The skeleton is gone
				room3Description = "There is no longer a pile of bones resting in the middle of the room, just the memory of a new friend. You can see large wooden doors on both the North and East sides of the room.\n";
			}
			else	//If the skeleton is not there
			{
				cout << "There is no one for you to bribe.\n";
			}
		}
		 else if (action == "help")
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\nattack\nbribe\n\n";
		}
		else
		{
			cout << action << " is not an action you can currently do.\n";
		}

	} while (inRoom);
}

void room4()
{
	cout << room4Description;
	bool inRoom = true;

	do
	{
		string action = getTextFromUser("What would you like to do?\n");

		if (action == "north")
		{
			cout << "You walk through the North door.\n";
			playerLocation = 2;
			inRoom = false;
		}
		else if (action == "west")
		{
			cout << "You walk through the West door.\n";
			playerLocation = 3;
			inRoom = false;
		}
		else if (action == "east")
		{
			if (key)	//If you have the key
			{
				cout << "You unlock the door and escape the dungeon.";
				playerLocation = 0;	//Leave and beat the game
				inRoom = false;
			}
			else	//No key
			{
				cout << "The East door is currently locked.\n";
			}
		}
		else if (action == "south")
		{
			cout << "You bump into a wall.\n";
		}
		else if (action == "look")
		{
			cout << room3Description;
		}
		else if (action == "help")
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\n\n";
		}
		else
		{
			cout << action << " is not and action you can currently do.\n";
		}
	} while (inRoom);
}

void setRoom(int roomNumber)	//Set the player's room
{
	if (roomNumber == 1) //If in room 1
	{
		room1();		 //Run room1 function
	}
	if (roomNumber == 2) //If in room 2
	{
		room2();		 //Run room2 function
	}
	if (roomNumber == 3) //If in room 3
	{
		room3();		 //Run room3 function
	}
	if (roomNumber == 4) //If in room 4
	{
		room4();		 //Run room4 function
	}
}

void giveGold(int* gold) //Give the player gold
{
	*gold = 20;
}

void giveKey(bool* key)	//Give the player a key
{
	*key = true;
}

void ResetRooms()
{
	//Default Rooms
	room1Description = "The room is dimly lit from candles hanging on the walls.\nYou can see large wooden doors on both the East and South sides of the room.\n";
	room2Description = "There's a small chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
	room3Description = "There is a pile of bones resting in the middle of the room. You can see large wooden doors on both the North and East sides of the room.\n";
	room4Description = "You enter a room of narrow halls and passage ways. You can see large wooden doors at the end of both the West and North passage ways.\nThe door at the end of the East passage way has a large steel lock on it.\n";
}

int main()
{
	//Instructions
	cout << "Type in your action to play, or type in \"help\" for a list of options.\n\n";

	//Set Default Rooms
	ResetRooms();
	
	//Start Game
	cout << "You appear to be lost in some sort of mysterious dungeon.\n";
	
	//Game Loop
	while (playerLocation != 0)		//While the player hasn't left the dungeon
	{
		setRoom(playerLocation);	//Set them to the current room they're in
	}

	return 0;
}
