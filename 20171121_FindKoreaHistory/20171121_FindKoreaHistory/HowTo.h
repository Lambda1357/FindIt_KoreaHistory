#pragma once
#include "Scene.h"

class Object;
class CHowTo :
	public Scene
{
private:
	int iCutCnt;
	Object* m_HowtoObj[3];
	Object* m_Button[3];
public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CHowTo();
	virtual ~CHowTo();
};

