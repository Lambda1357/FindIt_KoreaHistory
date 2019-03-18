#pragma once
#include "Scene.h"

class Object;
class CCutScene2 :
	public Scene
{
private:
	int iCutScene;
	Object* m_ChatBubble[7];
	Object* m_Button[3];
public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CCutScene2();
	virtual ~CCutScene2();
};

