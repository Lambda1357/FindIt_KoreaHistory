#pragma once

#include "Scene.h"
#include "Button.h"

class StartScene : public Scene
{
private:
	std::vector<Object*> v_ObjectList;

public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();

};