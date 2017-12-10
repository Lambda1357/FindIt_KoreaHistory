#pragma once
#include "stdafx.h"
#include "EventHandler.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;


class MainProc
{
private:
	SDL_Window* pWindow;
	SDL_Surface* pScreen;
	EventHandler evntHandler;

public:
	void Init();
	bool Update();
	void Render();
	void Destroy();

	MainProc();
	virtual ~MainProc();
};
