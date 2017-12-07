#pragma once
#include "stdafx.h"

class Object
{
protected:
	SDL_Surface* ObjectImage;
	SDL_Rect scrPosit;
	
public:
	virtual void Init(char* imgAddr, SDL_Rect posit);
	virtual void Update() {};
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();

};
