#include "stdafx.h"
#include "MouseInput.h"

void MouseInput::Init()
{
	mPosition.x = mPosition.y = 0;
	cur_ClickState = prv_ClickState = false;
}

void MouseInput::Update()
{
	prv_ClickState = cur_ClickState;
	cur_ClickState = false;
}

void MouseInput::Destroy()
{
	ReleaseInstance();
}
