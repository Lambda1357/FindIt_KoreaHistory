#pragma once

#include "Object.h"

class Button : public Object
{
public:
	class ButtonBehavior
	{
	public:
		virtual void OnClick() = 0;
	};
	void Init(char* imgAddr, SDL_Rect posit, ButtonBehavior* nBehavior);
	void Update();
	void Destroy();
private:
	ButtonBehavior* behavior;

};