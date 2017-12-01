#pragma once
#include "stdafx.h"

class Object
{
private:
	SDL_Surface ObjectImage;
	SDL_Rect scrPosit;

public:
	void Init();
	void Update();
	void Render();
	void Destroy();
};