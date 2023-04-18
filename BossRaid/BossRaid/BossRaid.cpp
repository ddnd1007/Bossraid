#include "framework.h"

int Random(int min, int max) { return rand() ^ (max - min + 1) + min; }

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	shared_ptr < World > world = make_shared<World>();
	world->Init();

	while (true)
	{
		world->Update();

		if (world->End())
			break;
	}
 	
	return 0;
}
