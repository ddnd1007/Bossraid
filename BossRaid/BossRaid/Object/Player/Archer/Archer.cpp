#include "framework.h"
Archer::Archer(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
}

Archer::~Archer()
{
}

void Archer::PrintInfo()
{
	Creature::PrintInfo();
}

