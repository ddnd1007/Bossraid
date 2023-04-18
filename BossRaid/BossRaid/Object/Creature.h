#pragma once
class Creature : public enable_shared_from_this<Creature>
{
public:
	Creature();
	Creature(int hp, int atk, string name);
	virtual ~Creature() {}

	virtual void PrintInfo();
	virtual void Attack(shared_ptr<Creature> victim, shared_ptr<Creature> attacker );
	virtual void TakeDamage(int amount, shared_ptr<Creature> attacker);
	bool IsDead();

	const string& GetName() const { return _name; }
	const int& GetHP() const { return _hp; }
	const int& GetAtk() const { return _atk; }

	  

private:
	int _hp = 0;
	int _atk = 0;
	string _name;

};

