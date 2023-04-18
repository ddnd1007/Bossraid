#pragma once
class Monster : public Creature
{
public:
	Monster(int hp, int atk, string name);
	virtual ~Monster() override;
	virtual void PrintInfo() override;


private:
};