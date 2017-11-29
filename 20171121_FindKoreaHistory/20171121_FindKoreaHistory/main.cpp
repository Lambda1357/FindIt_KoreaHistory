#include "stdafx.h"

int main(int argc, char* argv[])
{
	MainProc Game;
	Game.Init();

	while (Game.Update())
	{
		Game.Render();
	}

	Game.Destroy();

    return 0;
}

