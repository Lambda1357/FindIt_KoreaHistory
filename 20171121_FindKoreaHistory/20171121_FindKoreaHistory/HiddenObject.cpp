#include "stdafx.h"
#include "HiddenObject.h"


CHiddenObject::CHiddenObject() : bClicked(false), bChecked(false), bHinted(false)
{
	SDL_Rect _scrPosit = { 0,0,0,0 };
	m_Hint = new Object;
	m_Hint->Init("./img/Interface/HintTarget.bmp", _scrPosit);
}


CHiddenObject::~CHiddenObject()
{
	delete m_Hint;
	m_Hint = NULL;
}

void CHiddenObject::Update()
{
	SDL_Rect rc = { scrPosit.x - 30, scrPosit.y - 30, 95,95 };
	m_Hint->SetPos(rc);
}

void CHiddenObject::Render(SDL_Surface* scrSurface)
{
	Uint32 colorKey = SDL_MapRGB(ObjectImage->format, 255, 0, 255);
	SDL_SetColorKey(ObjectImage, 1, colorKey);

	SDL_BlitSurface(ObjectImage, NULL, scrSurface, &scrPosit);

	if (bHinted && !bClicked)
	{
		m_Hint->Render(scrSurface);
	}
}
