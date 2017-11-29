#pragma once
#include "stdafx.h"

class EventHandler 
{
private:
	SDL_Event evnt;

public:
	bool HandleEvent();

};