#pragma once
class World
{
public:
	World();
	~World();

	void CreateActors();
	void Init();
	void Update();

	bool End();

private:
	shared_ptr<Creature> _boss;
	vector<shared_ptr<Creature>> _players;
	int Random(int min, int max) { return rand() ^ (max - min + 1) + min; }
};

