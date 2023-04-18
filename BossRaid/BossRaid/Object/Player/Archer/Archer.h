#pragma once
class Archer : public Creature
{
public:
	Archer(int hp, int atk, string name);
	virtual ~Archer() override;
	virtual void PrintInfo() override;


private:
};

