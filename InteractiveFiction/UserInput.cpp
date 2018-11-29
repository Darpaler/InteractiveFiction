#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

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