#include "stdafx.h"
#include "CutScene1.h"
#include "Object.h"
#include "MouseInput.h"


CCutScene1::CCutScene1()
{
}


CCutScene1::~CCutScene1()
{
	Destroy();
}

void CCutScene1::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	SDL_Rect m_Pos = { 1200, 0, 70, 70 };

	m_Button = new Object;
	m_Button->Init("./img/Clear/Close.bmp", m_Pos);
}
int CCutScene1::Update()
{
	SDL_Rect m_Pos = { 1200, 0, 70, 70 };

	if (MOUSEINPUT->IsClick(m_Pos))
	{
		return 1;
	}
}
void CCutScene1::Render(SDL_Surface* scrSurface)
{
	SDL_BlitSurface(background, NULL, scrSurface, NULL);

	m_Button->Render(scrSurface);
}
void CCutScene1::Destroy()
{
	BackgroundFree();

	delete m_Button;
	m_Button = NULL;
}
