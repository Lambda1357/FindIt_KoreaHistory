#include "stdafx.h"
#include "MainProc.h"

void MainProc::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL video init Failed! SDL_Error : %s\n", SDL_GetError());
	}
	pWindow = SDL_CreateWindow("찾아라! 뒤틀린 한국사", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (pWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s", SDL_GetError());
	}
	else
	{
		pScreen = SDL_GetWindowSurface(pWindow);
	}
}

MainProc::MainProc()
{
	pWindow = NULL;
	pScreen = NULL;
}
