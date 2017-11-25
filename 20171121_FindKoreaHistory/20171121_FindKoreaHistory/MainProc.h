#pragma once
#include "stdafx.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;


class MainProc
{
private:
	SDL_Window* pWindow;
	SDL_Surface* pScreen;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();

	MainProc();
	virtual ~MainProc();
};
