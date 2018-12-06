#pragma once
#include <iostream>
#include <string>

using namespace std;

class Room
{
public:
	//Constructor
	//Runs once automatically when you create an object out of the class
	//Runs once per object but many times per class
	Room();
	
	//Public Variables
	string action;

	void setDescription(string roomDescription);
	string getDescription();


	//Deconstructor
	//This frees up memory
	~Room();
	
	//Private Variables
	private:
		string description;

};

