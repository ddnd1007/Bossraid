#include "framework.h"
#include "Creature.h"

Creature::Creature(int hp, int atk, string name)
	: _hp(hp)
	, _atk(atk)
	,_name(name)
{
}

void Creature::PrintInfo()
{
	cout << "이름 : " << _name << endl;
	cout << "체력 : " << _hp  << endl;
	cout << "공격력 : " << _atk << endl;
}

void Creature::Attack(shared_ptr<Creature> victim, shared_ptr<Creature> attacker)
{
	if (IsDead())
		return;
	cout << _name << "이(가) " << victim->GetName() << "을(를) 공격!!!" << endl;
	victim->TakeDamage(attacker->_atk, shared_from_this());
	
}


void Creature::TakeDamage(int amount, shared_ptr<Creature> attacker)
{
	if (IsDead())
		return;

	this->_hp -= amount;
	cout << _name << "이(가)" << attacker->GetName() << "만큼 데미지를 받았습니다.";

	if (_hp <= 0)
	{
		cout << _name << "이(가) 죽었습니다." << endl;
		_hp = 0;
	}
}

bool Creature::IsDead()
{
	bool result = _hp = 0;

	if (result)
		cout << _name << "이(가) 죽었습니다. " << endl;

	return result;
}
