#include "stdafx.h"
#include "MainProc.h"
#include "MouseInput.h"

void MainProc::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL video init Failed! SDL_Error : %s\n", SDL_GetError());
	}
	pWindow = SDL_CreateWindow("Find it! Reversed Korea History", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (pWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s", SDL_GetError());
	}
	else
	{
		pScreen = SDL_GetWindowSurface(pWindow);
		pTestSurface = SDL_LoadBMP("./HerosCat.bmp");
		testBox = { 100, 100, 100, 70 };
	}
}

bool MainProc::Update()
{
	if (!evntHandler.HandleEvent()) return false;
	
	if (MOUSEINPUT->IsClick(testBox)) return false;

	return true;
}

void MainProc::Render()
{
	SDL_BlitSurface(pTestSurface, NULL, pScreen, &testBox);

	SDL_UpdateWindowSurface(pWindow);
}

void MainProc::Destroy()
{
	SDL_FreeSurface(pTestSurface);
	SDL_FreeSurface(pScreen);
	SDL_DestroyWindow(pWindow);

	SDL_Quit();
}

MainProc::MainProc()
{
	pWindow = NULL;
	pScreen = NULL;
}

MainProc::~MainProc()
{
}
