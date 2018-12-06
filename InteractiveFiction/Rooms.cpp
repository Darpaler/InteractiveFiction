#include "pch.h"
#include "UserInput.h"
#include "Inventory.h"
#include<iostream>
#include <string>
#include "Room.h"
using namespace std;

//Global Variables
extern int playerLocation;
extern string room2Description;
extern string room3Description;
extern string room4Description;
extern int gold;
extern bool key;

//Creating Objects
Room room1O;

void resetRooms()
{
	//Default Rooms
	room1O.setDescription("The room is dimly lit from candles hanging on the walls.\nYou can see large wooden doors on both the East and South sides of the room.\n");
	room2Description = "There's a small chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
	room3Description = "There is a pile of bones resting in the middle of the room. You can see large wooden doors on both the North and East sides of the room.\n";
	room4Description = "You enter a room of narrow halls and passage ways. You can see large wooden doors at the end of both the West and North passage ways.\nThe door at the end of the East passage way has a large steel lock on it.\n";
}

void room1()	//The interactions for the first room
{
	cout << room1O.getDescription();	//Print out room description when player enters
	bool inRoom = true;			//Whether or not the player has left the room
	do
	{
		room1O.action = getTextFromUser("What would you like to do?\n");	//Ask what they want to do

		if (room1O.action == "east")													//The player walks east
		{
			cout << "You walk through the East door.\n";						//Tell them they moved
			playerLocation = 2;													//Move them
			inRoom = false;														//Remove them from the room
		}
		else if (room1O.action == "south")												//The player walks south
		{
			cout << "You walk through the South door.\n";						//Tell them they moved
			playerLocation = 3;													//Move them
			inRoom = false;														//Remove them from the room
		}
		else if (room1O.action == "west" || room1O.action == "north")							//If they go a way withouth a door
		{
			cout << "You bump into a wall.\n";									//Tell them they can't go that way
		}
		else if (room1O.action == "look")												//If they look
		{
			cout << room1O.getDescription();											//Describe the room again
		}
		else if (room1O.action == "help")												//If they ask for help
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\n\n";		//Give them a list of actions
		}
		else																	//If they give an unknown action
		{
			cout << room1O.action << " is not an action you can currently do.\n";		//Tell them they can't do that
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
		else if (action == "openchest")														//If the player opens the chest
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
