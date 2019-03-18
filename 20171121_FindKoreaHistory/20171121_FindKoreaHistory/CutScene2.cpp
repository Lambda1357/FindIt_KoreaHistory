#include "stdafx.h"
#include "CutScene2.h"
#include "Object.h"
#include "MouseInput.h"


CCutScene2::CCutScene2()
{
}


CCutScene2::~CCutScene2()
{
	Destroy();
}

void CCutScene2::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	for (int i = 0; i < 7; i++)
	{
		m_ChatBubble[i] = new Object;
	}

	for (int i = 0; i < 3; i++)
	{
		m_Button[i] = new Object;
	}

	SDL_Rect m_Pos;
	m_Pos = { 287,196,260,183 };
	m_ChatBubble[0]->Init("./img/CutScenes/CutScene2/Dialog1.bmp", m_Pos);
	m_ChatBubble[4]->Init("./img/CutScenes/CutScene2/Dialog5.bmp", m_Pos);
	m_Pos = { 753,196,260,183 };
	m_ChatBubble[1]->Init("./img/CutScenes/CutScene2/Dialog2.bmp", m_Pos);
	m_ChatBubble[2]->Init("./img/CutScenes/CutScene2/Dialog3.bmp", m_Pos);
	m_ChatBubble[3]->Init("./img/CutScenes/CutScene2/Dialog4.bmp", m_Pos);
	m_ChatBubble[5]->Init("./img/CutScenes/CutScene2/Dialog6.bmp", m_Pos);
	m_ChatBubble[6]->Init("./img/CutScenes/CutScene2/Dialog7.bmp", m_Pos);

	m_Pos = { 25,550,70,70 };
	m_Button[0]->Init("./img/Interface/LeftButton.bmp", m_Pos);
	m_Pos = { 1180,550,70,70 };
	m_Button[1]->Init("./img/Interface/RightButton.bmp", m_Pos);
	m_Pos = { 1200,0,70,70 };
	m_Button[2]->Init("./img/Clear/Close.bmp", m_Pos);

	iCutScene = 0;
}

int CCutScene2::Update()
{
	SDL_Rect m_Pos;
	m_Pos = { 25,550,70,70 };

	if (MOUSEINPUT->IsClick(m_Pos))
	{
		if (iCutScene > 0)
			--iCutScene;
	}

	if (iCutScene < 6)
	{
		m_Pos = { 1180,550,70,70 };

		if (MOUSEINPUT->IsClick(m_Pos))
		{
			++iCutScene;
		}
	}

	else if (iCutScene == 6)
	{
		m_Pos = { 1200,0,70,70 };

		if (MOUSEINPUT->IsClick(m_Pos))
		{
			return 1;
		}
	}

	return 0;
}

void CCutScene2::Render(SDL_Surface* scrSurface)
{
	SDL_BlitSurface(background, NULL, scrSurface, NULL);

	m_ChatBubble[iCutScene]->Render(scrSurface);

	m_Button[0]->Render(scrSurface);
	
	if (iCutScene < 6)
	{
		m_Button[1]->Render(scrSurface);
	}

	else if (iCutScene == 6)
	{
		m_Button[2]->Render(scrSurface);
	}
} 

void CCutScene2::Destroy()
{
	BackgroundFree();

	for (int i = 0; i < 7; i++)
	{
		delete m_ChatBubble[i];
		m_ChatBubble[i] = NULL;
	}

	for (int i = 0; i < 3; i++)
	{
		delete m_Button[i];
		m_Button[i] = NULL;
	}

}
