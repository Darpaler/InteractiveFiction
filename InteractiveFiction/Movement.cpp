#include "pch.h"
#include "Rooms.h"
#include <iostream>
#include <string>


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