#include "stdafx.h"
#include "Button.h"
#include "MouseInput.h"

void Button::Init(char* imgAddr, SDL_Rect posit, ButtonBehavior* nBehavior)
{
	Object::Init(imgAddr, posit);
	behavior = nBehavior;
}

void Button::Update()
{
	if (MOUSEINPUT->IsClick(scrPosit)) behavior->OnClick();
}

void Button::Destroy()
{
	if (behavior) delete behavior;
	Object::Destroy();
}
