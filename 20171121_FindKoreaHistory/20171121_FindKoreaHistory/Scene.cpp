#include "stdafx.h"
#include "Scene.h"

void Scene::BackgroundInit(char* imgAdr)
{
	background = SDL_LoadBMP(imgAdr);
}

void Scene::BackgroundFree()
{
	SDL_FreeSurface(background);
}
