#pragma once
#include "Scene.h"

class CHiddenObject;
class CCh1Stage1 :
	public Scene
{
private:
	std::vector<CHiddenObject*> vecHiddenObj;

	void RandomSetting();
	void Hint();
public:
	virtual void Init(char* ImgAdr);
	virtual int Update();
	virtual void Render(SDL_Surface* scrSurface);
	virtual void Destroy();
public:
	CCh1Stage1();
	virtual ~CCh1Stage1();
};

