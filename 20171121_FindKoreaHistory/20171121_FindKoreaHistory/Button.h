#pragma once

#include "Object.h"

class ButtonBehavior
{
public:
	virtual void OnClick() = 0;
};

class Button : public Object
{
public:
	void Init(char* imgAddr, SDL_Rect posit, ButtonBehavior* nBehavior);
	void Update();
	void Destroy();

private:
	ButtonBehavior* behavior;

};