#include "framework.h"
#include "Boss.h"


Boss::Boss(int hp, int atk, string name)
	:Monster(hp, atk, name)
{
}

void Boss::PrintInfo()
{
	Monster::PrintInfo();
}


void Boss::MonsterAttack(vector<shared_ptr<Creature>>& players)
{
	auto iter = std::remove_if(_aggroListTable.begin(), _aggroListTable.end(),
		[](const AggroList& list)-> bool
		{
			if (list.creature->IsDead())
				return true;
			return false;
		});

	_aggroListTable.erase(iter, _aggroListTable.end());

	std::sort(_aggroListTable.begin(), _aggroListTable.end(),
		[](const AggroList& a, const AggroList& b)-> bool
		{
			if (a.totalDamage > b.totalDamage)
				return true;
			return false;
		});

	int count = 0;
	for (auto list : _aggroListTable)
	{
		if (count >= _attackRange)
			break;
		Creature::Attack(list.creature, shared_from_this());
		count++;
	}

}

void Boss::TakeDamage(int amount, shared_ptr<Creature> attacker)
{
	Creature::TakeDamage(amount, attacker);

	auto iter = std::find_if(_aggroListTable.begin(), _aggroListTable.end(),
		[attacker](const AggroList& list)-> bool
		{
			if (list.creature->GetName() == attacker->GetName())
				return true;
			return false;
		});

	if (iter == _aggroListTable.end())
	{
		AggroList list;
		list.creature = attacker;
		list.totalDamage = amount;
		_aggroListTable.push_back(list);
	}
	else
	{
		iter->totalDamage += amount;
	}
}


