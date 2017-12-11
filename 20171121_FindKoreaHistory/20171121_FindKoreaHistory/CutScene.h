#pragma once

#include "Scene.h"
#include "Button.h"

class CutScene : public Scene
{
private:
	std::list<Object*> scrList;
	Object indexPrev;
	Object indexNext;
	Object sceneChangeButton;
	int currentScr;

public:
	void Init(char* imgAdr);
	void Update();
	void Render(SDL_Surface scrSurface);
	void Destroy();

	void PutScreenObject(Object* nObj);
	void PutScreenObject(char* imgAdr);
	void PutScreenObject(char* imgAdr, SDL_Rect rct);
};