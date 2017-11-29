#pragma once
#include "stdafx.h"
#include "Singletone.h"

class MouseInput : public Singletone<MouseInput>
{
private:
	bool cur_ClickState, prv_ClickState;
	SDL_Point mPosition;

public:
	void Init();
	void Update();
	inline void OnMove(int x, int y)
	{
		mPosition.x = x;
		mPosition.y = y;
	}

	inline void OnClick() { cur_ClickState = true; }
	void Destroy();

};

#define MOUSEINPUT MouseInput::GetInstance()