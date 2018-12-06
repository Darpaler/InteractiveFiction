#include "pch.h"
#include "Room.h"


Room::Room()
{
}

void Room::setDescription(string roomDescription)
{
	description = roomDescription;
}

string Room::getDescription()
{
	return description;
}

Room::~Room()
{
}
