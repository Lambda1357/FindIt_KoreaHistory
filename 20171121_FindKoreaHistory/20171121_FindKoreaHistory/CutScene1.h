#pragma once
#include "Scene.h"

class Object;
class CCutScene1 :
	public Scene
{
private:
	Object* m_Button;
public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CCutScene1();
	virtual ~CCutScene1();
};

