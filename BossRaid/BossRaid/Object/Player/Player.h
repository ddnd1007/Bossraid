#pragma once

class Monster;

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	virtual ~Player() override;
	virtual void PrintInfo() override;

private:
};

