#pragma once

#include "Scene.h"

class StartScene : public Scene
{
private:


public:
	virtual void Init(char* ImgAdr);
	virtual void Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();

};