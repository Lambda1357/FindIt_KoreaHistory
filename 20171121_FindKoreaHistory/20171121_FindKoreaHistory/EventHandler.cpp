#include "stdafx.h"
#include "EventHandler.h"
#include "MouseInput.h"
#include "KeyInput.h"


bool EventHandler::HandleEvent()
{
	SDL_PollEvent(&evnt);
	MOUSEINPUT->Update();
	KEYINPUT->Update();

	if (evnt.type == SDL_QUIT)	
		return false;

	else
	{
		if (evnt.type == SDL_MOUSEMOTION)
		{
			int x, y;
			SDL_GetMouseState(&x, &y);
			MOUSEINPUT->OnMove(x, y);
		}
		else if (evnt.type == SDL_MOUSEBUTTONDOWN) MOUSEINPUT->OnMouseDown();
		else if (evnt.type == SDL_MOUSEBUTTONUP) MOUSEINPUT->OnMouseUp();

		switch (evnt.key.keysym.sym)
		{
		case SDLK_h:
			KEYINPUT->OnKeyDown();
			break;
		default:
			KEYINPUT->OnKeyUp();
			break;
		}
	}

	return true;
}
