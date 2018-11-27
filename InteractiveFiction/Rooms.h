#pragma once
#include<iostream>
#include <string>
using namespace std;

//Functions
void ResetRooms();
void room1();
void room2();
void room3();
void room4();

void ResetRooms(string room1, string room2, string room3, string room4)
{
	//Default Rooms
	room1 = "The room is dimly lit from candles hanging on the walls.\nYou can see large wooden doors on both the East and South sides of the room.\n";
	room2 = "There's a small chest in the center of the room. You can see large wooden doors on both the West and South sides of the room.\n";
	room3 = "There is a pile of bones resting in the middle of the room. You can see large wooden doors on both the North and East sides of the room.\n";
	room4 = "You enter a room of narrow halls and passage ways. You can see large wooden doors at the end of both the West and North passage ways.\nThe door at the end of the East passage way has a large steel lock on it.\n";
}