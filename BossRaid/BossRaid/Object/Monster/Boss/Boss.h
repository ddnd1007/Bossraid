#pragma once

class Boss : public Monster
{
public:
	Boss(int hp, int atk, string name);
	virtual void PrintInfo() override;
	void MonsterAttack(vector<shared_ptr<Creature>>& players);
	virtual void TakeDamage(int amount, shared_ptr<Creature> attacker) override;


	struct AggroList
	{
		shared_ptr<class Creature> creature;
		int totalDamage;
	};




private:
	vector<AggroList> _aggroListTable;
	int _attackRange = 4;

};

