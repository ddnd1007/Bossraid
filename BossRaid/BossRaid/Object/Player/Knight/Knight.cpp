#include "framework.h"
#include "Knight.h"

Knight::Knight(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
}

Knight::~Knight()
{
}

void Knight::PrintInfo()
{
	Creature::PrintInfo();
}

