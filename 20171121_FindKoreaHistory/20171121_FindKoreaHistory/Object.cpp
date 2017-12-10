#include "stdafx.h"
#include "Object.h"

void Object::Init(char* imgAddr, SDL_Rect posit)
{
	ObjectImage = SDL_LoadBMP(imgAddr);

	scrPosit = posit;
}

void Object::Render(SDL_Surface* scrSurface)
{
	Uint32 colorKey = SDL_MapRGB(ObjectImage->format, 255, 0, 255);
	SDL_SetColorKey(ObjectImage, 1, colorKey);

	SDL_BlitSurface(ObjectImage, NULL, scrSurface, &scrPosit);
}

void Object::Destroy()
{
	SDL_FreeSurface(ObjectImage);
}