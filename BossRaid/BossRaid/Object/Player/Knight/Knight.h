#pragma once
class Knight : public Creature
{
public:
	Knight(int hp, int atk, string name);
	virtual ~Knight() override;
	virtual void PrintInfo() override;


private:
};

