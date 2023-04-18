#include "framework.h"
#include "World.h"


World::World()
{
	CreateActors();
}

World::~World()
{
}

void World::CreateActors()
{

	_boss = make_shared<Boss>(10000, 200, "Boss");

	_players.reserve(10);
	for (int i = 0; i < 10; i++)
	{

		string job;
		switch (rand() % 3)
		{
		case 0:
		{
			job = "Knight" + to_string(i + 1);
			shared_ptr<Player> player = make_shared<Player>(Random(900, 1100), Random(70, 120), job);
			_players.push_back(player);
			break;
		}
		case 1:
		{
			job = "Mage" + to_string(i + 1);
			shared_ptr<Player> player = make_shared<Player>(Random(600, 800), Random(150, 200), job);
			_players.push_back(player);
			break;
		}
		case 2:
		{
			job = "Archer" + to_string(i + 1);
			shared_ptr<Player> player = make_shared<Player>(Random(500, 700), Random(200, 250), job);
			_players.push_back(player);
			break;
		}
		}
		
	}

}

void World::Init()
{
}

void World::Update()
{
	for (auto player : _players)
		player->Attack(_boss, nullptr);

		dynamic_pointer_cast<Boss>(_boss)->MonsterAttack(_players);
}

bool World::End()
{
	if (_boss->IsDead())
		return true;

	bool check = true;

	for (auto player : _players)
	{
		if (player->IsDead() == false)
		{
			check = false;
			break;
		}
	}

	return check;
	
}
