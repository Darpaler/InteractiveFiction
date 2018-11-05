// InteractiveFiction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//Variables
string room1;
string room2;
string room3;
string room4;
int playerLocation = 1;

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

int main()
{
	room1 = "The room is dimly lit from candles hanging on the walls.\nYou can see large wooden doors on both the East and South sides of the room.\n";
	room2 = "There's a small chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
	room3 = "There is a pile of bones resting in the middle of the room. You can see large wooden doors on both the North and East sides of the room.\n";
	room4 = "You enter a room of narrow halls and passage ways. You can see large wooden doors at the end of both the West and North passage ways.\nThe door at the end of the East passage way has a large steel lock on it.\n";
	
	cout << "You appear to be lost in some sort of mysterious dungeon.\n";
	cout << room1;
	
	if (getTextFromUser("Where would you like to go?\n") == "east")
	{
		playerLocation = 2;
	}
	
	if (getTextFromUser("Where would you like to go?\n") == "south")
	{
		playerLocation = 3;
	}
}
