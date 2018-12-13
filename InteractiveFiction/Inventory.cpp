#include "pch.h"
#include <iostream>
#include <string>


void giveGold(int* gold) //Give the player gold using Pointers
{
	*gold = 20;
}

void giveKey(bool* key)	//Give the player a key using Pointers
{
	*key = true;
}