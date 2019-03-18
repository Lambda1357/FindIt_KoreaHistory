#pragma once
#include "Scene.h"
class Object;
class CEndScene :
	public Scene
{
private:
	Object* pFailBar; 
	Object* pSuccessBar;
	Object* pNextBar;
	Object* pFailChar;
	Object* pSuccessChar;
public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CEndScene();
	virtual ~CEndScene();
};

