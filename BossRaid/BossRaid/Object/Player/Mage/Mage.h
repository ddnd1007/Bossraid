#pragma once
class Mage : public Creature
{
public:
	Mage(int hp, int atk, string name);
	virtual ~Mage() override;
	virtual void PrintInfo() override;


private:
};

