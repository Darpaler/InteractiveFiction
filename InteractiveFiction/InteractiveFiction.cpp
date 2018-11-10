// InteractiveFiction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//Variables
string room1Description;
string room2Description;
string room3Description;
string room4Description;
int playerLocation = 1;
int gold = 0;
bool key = false;

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

void room1()
{
	cout << room1Description;
	bool inRoom = true;
	do
	{
		string action = getTextFromUser("What would you like to do?\n");
		if (action == "east")
		{
			cout << "You walk through the East door.\n";
			playerLocation = 2;
			inRoom = false;
		}

		if (action == "south")
		{
			cout << "You walk through the South door.\n";
			playerLocation = 3;
			inRoom = false;
		}

		if (action == "west" || action == "north")
		{
			cout << "You bump into a wall.\n";
		}

		if (action == "look") 
		{
			cout << room1Description;
		}
		
		if (action == "help")
		{
			cout << "List Of Actions:\neast\nsouth\nnorth\nwest\nlook\n";
		}

	} while (inRoom);
}

void room2()
{
	cout << room2Description;
	bool inRoom = true;
	bool unOpened = true;

	do
	{
		string action = getTextFromUser("What would you like to do?\n");

		if (action == "west")
		{
			cout << "You walk through the West door.\n";
			playerLocation = 1;
			inRoom = false;
		}

		if (action == "south")
		{
			cout << "You walk through the South door.\n";
			playerLocation = 4;
			inRoom = false;
		}

		if (action == "east" || action == "north")
		{
			cout << "You bump into a wall.\n";
		}

		if (action == "look")
		{
			cout << room2Description;
		}

		if(action == "openchest")
		{
			if (unOpened)
			{
				room2Description = "There's an empty chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
				gold += 20;
				cout << "You found 20 Gold!\n";
				unOpened = false;
			}
			else
			{
				cout << "The chest is empty.\n";
			}
		}

	} while (inRoom);
}

void room3()
{
	cout << room3Description;
	bool inRoom = true;
	bool hasRisen = false;
	bool isAlive = false;

	do
	{
		string action = getTextFromUser("What would you like to do?\n");


		if (action == "north")
		{
			if (isAlive)
			{
				cout << "The skeleton catches you trying to flee and gets you in the back.\nYou have been slain.\n";
				playerLocation = 0;
				inRoom = false;
			}
			else if (!hasRisen)
			{
				cout << "Before you can get to the door, a skeleton rises up and lunges at you.\n";
				room3Description = "There is a skeleton attacking you. You better deal with him first before trying to escape.\n";
				hasRisen = true;
				isAlive = true;
			}
			else
			{
				cout << "You walk through the North door.\n";
				playerLocation = 1;
				inRoom = false;
			}
		}

		if (action == "east")
		{
			if (isAlive)
			{
				cout << "The skeleton catches you trying to flee and gets you in the back.\nYou have been slain.\n";
				playerLocation = 0;
				inRoom = false;
			}
			else if (!hasRisen)
			{
				cout << "Before you can get to the door, a skeleton rises up and lunges at you.\n";
				room3Description = "There is a skeleton attacking you. You better deal with him first before trying to escape.\n";
				hasRisen = true;
				isAlive = true;
			}
			else
			{
				cout << "You walk through the East door.\n";
				playerLocation = 4;
				inRoom = false;
			}
		}

		if (action == "west" || action == "south")
		{
			cout << "You bump into a wall.\n";
		}

		if (action == "look")
		{
			cout << room3Description;
		}

		if (action == "attack")
		{
			if (isAlive) 
			{
				cout << "You swing you sword at the skeleton, and he falls toppling to the ground.\nHe drops a key and you pick it up.\n";
				bool key = true;
				isAlive = false;
				room3Description = "There is a pile of bones resting in the middle of the room that knows better to rise up in your presence. You can see large wooden doors on both the North and East sides of the room.\n";
			}
			else
			{
				cout << "There is nothing for you to attack.\n";
			}
		}

		if (action == "bribe" && gold == 20)
		{
			if (isAlive)
			{
				cout << "You off the skeleton all of your gold to avoid conflict.\nYou realize the skeleton wasn't really a bad guy, just a guy going through a rough time.\n";
				cout << "He hands you a key and leaves.\n";
				bool key = true;
				isAlive = false;
				room3Description = "There is no longer a pile of bones resting in the middle of the room, just the memory of a new friend. You can see large wooden doors on both the North and East sides of the room.\n";
			}
			else
			{
				cout << "There is no one for you to bribe.\n";
			}
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

		if (action == "west")
		{
			cout << "You walk through the West door.\n";
			playerLocation = 3;
			inRoom = false;
		}
		
		if (action == "east")
		{
			if (key)
			{
				cout << "You unlock the door and escape the dungeon.";
				playerLocation = 0;
			}
			else
			{
				cout << "The East door is currently locked.\n";
			}
		}

		if (action == "south")
		{
			cout << "You bump into a wall.\n";
		}

		if (action == "look")
		{
			cout << room3Description;
		}

	} while (inRoom);
}

void setRoom(int roomNumber)
{
	if (roomNumber == 1)
	{
		room1();
	}
	if (roomNumber == 2)
	{
		room2();
	}
	if (roomNumber == 3)
	{
		room3();
	}
	if (roomNumber == 4)
	{
		room4();
	}
}

int main()
{
	room1Description = "The room is dimly lit from candles hanging on the walls.\nYou can see large wooden doors on both the East and South sides of the room.\n";
	room2Description = "There's a small chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
	room3Description = "There is a pile of bones resting in the middle of the room. You can see large wooden doors on both the North and East sides of the room.\n";
	room4Description = "You enter a room of narrow halls and passage ways. You can see large wooden doors at the end of both the West and North passage ways.\nThe door at the end of the East passage way has a large steel lock on it.\n";
	
	cout << "You appear to be lost in some sort of mysterious dungeon.\n";
	while (playerLocation != 0) 
	{
		setRoom(playerLocation);
	}

	return 0;
}
