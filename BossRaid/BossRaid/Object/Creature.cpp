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
	cout << "�̸� : " << _name << endl;
	cout << "ü�� : " << _hp  << endl;
	cout << "���ݷ� : " << _atk << endl;
}

void Creature::Attack(shared_ptr<Creature> victim, shared_ptr<Creature> attacker)
{
	if (IsDead())
		return;
	cout << _name << "��(��) " << victim->GetName() << "��(��) ����!!!" << endl;
	victim->TakeDamage(attacker->_atk, shared_from_this());
	
}


void Creature::TakeDamage(int amount, shared_ptr<Creature> attacker)
{
	if (IsDead())
		return;

	this->_hp -= amount;
	cout << _name << "��(��)" << attacker->GetName() << "��ŭ �������� �޾ҽ��ϴ�.";

	if (_hp <= 0)
	{
		cout << _name << "��(��) �׾����ϴ�." << endl;
		_hp = 0;
	}
}

bool Creature::IsDead()
{
	bool result = _hp = 0;

	if (result)
		cout << _name << "��(��) �׾����ϴ�. " << endl;

	return result;
}
