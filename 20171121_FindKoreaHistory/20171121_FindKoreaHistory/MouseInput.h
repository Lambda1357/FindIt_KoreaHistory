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
	void Destroy();

};