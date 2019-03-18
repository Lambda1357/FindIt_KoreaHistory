#include "stdafx.h"
#include "HowTo.h"
#include "Object.h"
#include "MouseInput.h"

CHowTo::CHowTo()
{
}


CHowTo::~CHowTo()
{
	Destroy();
}


void CHowTo::Init(char* ImgAdr)
{
	for (int i = 0; i < 3; i++)
	{
		m_HowtoObj[i] = new Object;
	}

	for (int i = 0; i < 3; i++)
	{
		m_Button[i] = new Object;
	}

	SDL_Rect m_Pos;
	m_Pos = { 0,0,1280,720 };
	m_HowtoObj[0]->Init("./img/HowTo/HowTo1.bmp", m_Pos);
	m_HowtoObj[1]->Init("./img/HowTo/HowTo2.bmp", m_Pos);
	m_HowtoObj[2]->Init("./img/HowTo/HowTo3.bmp", m_Pos);
	m_Pos = { 25,550,70,70 };
	m_Button[0]->Init("./img/Interface/LeftButton.bmp",m_Pos);
	m_Pos = { 1180,550,70,70 };
	m_Button[1]->Init("./img/Interface/RightButton.bmp", m_Pos);
	m_Pos = { 1200,0,70,70 };
	m_Button[2]->Init("./img/Clear/Close.bmp", m_Pos);
	iCutCnt = 0;
}
int CHowTo::Update()
{
	SDL_Rect m_Pos;
	m_Pos = { 25,550,70,70 };

	if (MOUSEINPUT->IsClick(m_Pos))
	{
		if (iCutCnt > 0)
			--iCutCnt;
	}

	if (iCutCnt < 2)
	{
		m_Pos = { 1180,550,70,70 };

		if (MOUSEINPUT->IsClick(m_Pos))
		{
			++iCutCnt;
		}
	}

	else if (iCutCnt == 2)
	{
		m_Pos = { 1200,0,70,70 };

		if (MOUSEINPUT->IsClick(m_Pos))
		{
			return -3;
		}
	}
	return 0;
}
void CHowTo::Render(SDL_Surface* scrSurface)
{
	m_HowtoObj[iCutCnt]->Render(scrSurface);
	
	m_Button[0]->Render(scrSurface);

	if (iCutCnt < 2)
	{
		m_Button[1]->Render(scrSurface);
	}

	else if (iCutCnt == 2)
	{
		m_Button[2]->Render(scrSurface);
	}
}
void CHowTo::Destroy()
{
	for (int i = 0; i < 3; i++)
	{
		delete m_HowtoObj[i];
		m_HowtoObj[i] = NULL;
	}

	for (int i = 0; i < 2; i++)
	{
		delete m_Button[i];
		m_Button[i] = NULL;
	}
}