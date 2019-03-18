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

	inline void OnMouseDown() { cur_ClickState = true; }
	inline void OnMouseUp() { cur_ClickState = false; }
	inline bool GetClick() { return cur_ClickState; }
	inline bool GetPrevClick() { return prv_ClickState; }
	inline SDL_Point GetPos() { return mPosition; }
	bool IsClick(SDL_Rect chkBox);
	void Destroy();

};

#define MOUSEINPUT MouseInput::GetInstance()