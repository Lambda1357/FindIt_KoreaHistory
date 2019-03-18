#pragma once
#include "Scene.h"

class CHiddenObject;
class CCh1Stage2 :
	public Scene
{
private:
	std::vector<CHiddenObject*> vecHiddenObj;

	void Hint();
	void RandomSetting();
public:

	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CCh1Stage2();
	virtual ~CCh1Stage2();
};

