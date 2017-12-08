#pragma once
#include "stdafx.h"

class Scene
{

protected:
	SDL_Surface* background;
	void BackgroundInit(char* imgAdr);
	void BackgroundFree();

public:
	virtual void Init(char* ImgAdr) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Surface* scrSurface) = 0;
	virtual void Destroy() = 0;

};