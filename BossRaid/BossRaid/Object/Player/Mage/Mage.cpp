#include "framework.h"
#include "Mage.h"

Mage::Mage(int hp, int atk, string name)
	:Creature(hp, atk, name)
{
}

Mage::~Mage()
{
}

void Mage::PrintInfo()
{
	Creature::PrintInfo();
}
