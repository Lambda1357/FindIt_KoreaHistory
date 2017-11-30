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

bool MouseInput::IsClick(SDL_Rect chkBox)
{
	if (cur_ClickState == true && prv_ClickState == false)
	{
		if ((mPosition.x > chkBox.x) && (mPosition.x < (chkBox.x + chkBox.w)) && (mPosition.y > chkBox.y) && (mPosition.y < (chkBox.y + chkBox.w)))
		{
			return true;
		}
	}
	return false;
}

void MouseInput::Destroy()
{
	ReleaseInstance();
}
