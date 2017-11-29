#include "stdafx.h"
#include "EventHandler.h"



bool EventHandler::HandleEvent()
{
	SDL_PollEvent(&evnt);

	if (evnt.type == SDL_QUIT)	return false;

	return true;
}
