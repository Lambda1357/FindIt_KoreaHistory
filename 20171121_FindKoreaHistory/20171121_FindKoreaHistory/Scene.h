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
};