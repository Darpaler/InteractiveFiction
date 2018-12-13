#pragma once
#include "Room.h"

//Child class of Room, includes a boss monster.
class BossRoom :
	public Room
{
public:
	//Constructor
	//Runs once automatically when you create an object out of the class
	//Runs once per object but many times per class
	BossRoom();

	//Public Variables
	bool hasRisen = false;	//If the skeleton in the room has risen
	bool isAlive = false;	//If the skeleton is still alive

	//Deconstructor
	//This frees up memory
	~BossRoom();
};

