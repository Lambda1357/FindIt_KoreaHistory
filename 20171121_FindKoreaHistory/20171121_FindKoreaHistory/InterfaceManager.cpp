#include "stdafx.h"
#include "InterfaceManager.h"
#include "SceneManager.h"
#include "MouseInput.h"
#include "KeyInput.h"
#include "Object.h"

#include "han2unicode.h"


CInterfaceManager::CInterfaceManager()
{
}


CInterfaceManager::~CInterfaceManager()
{
	Release();
}

void CInterfaceManager::Initialize()
{
	iHP = 3;
	iHint = 3;
	iCorrectCnt = 0;
	
	HPBarPos[0] = { 35,97,60,60 };
	HPBarPos[1] = { 35,169,60,60 };
	HPBarPos[2] = { 35,241,60,60 };

	HintBarPos[0] = { 1183, 97, 60, 60 };
	HintBarPos[1] = { 1183, 169, 60, 60 };
	HintBarPos[2] = { 1183, 241, 60, 60 };

	CorrectBarPos[0] = { 35,656,60,60 };
	CorrectBarPos[1] = { 102,656,60,60 };
	CorrectBarPos[2] = { 169,656,60,60 };
	CorrectBarPos[3] = { 236,656,60,60 };
	CorrectBarPos[4] = { 305,656,60,60 };

	ExitBarPos = { 1178,630,70,70 };

	m_Pos = { 0,0, 1280, 720 };
	m_InGameEdge = new Object;
	m_InGameEdge->Init("./img/Interface/InGameEdge.bmp", m_Pos);

	m_Pos = { 500,5,300,60 };
	m_StageBar = new Object;
	m_StageBar->Init("./img/Interface/Stage.bmp", m_Pos);

	for (int i = 0; i < 3; i++)
	{
		m_HPBar[i] = new Object;
		m_HPBar[i]->Init("./img/Interface/Heart.bmp", HPBarPos[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		m_HintBar[i] = new Object;
		m_HintBar[i]->Init("./img/Interface/Hint.bmp", HintBarPos[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		m_CorrectBar[i] = new Object;
		m_CorrectBar[i]->Init("./img/Interface/UnCorrectBar.bmp", CorrectBarPos[i]);
	}

	m_ExitBar = new Object;
	m_ExitBar->Init("./img/buttonPause.bmp", ExitBarPos);

	font = TTF_OpenFont("./Font/Binggrae.ttf", 30 );
	timefont = TTF_OpenFont("./Font/Binggrae.ttf", 48);

	FontInit((unsigned short*)"1 - 1", &pText, &font);

	m_CurScene = SN_CH1_STAGE1;

	fTime = SDL_GetTicks();

	bCleared = false;
	bHint = false;
	m_fHintTime = 0;
}

void CInterfaceManager::Update()
{
	
	if (KEYINPUT->KEY_UP() && !bHint && m_fHintTime + 3000 < SDL_GetTicks())
	{
		m_fHintTime = SDL_GetTicks();
		bHint = true;
	}

	if (MOUSEINPUT->IsClick(ExitBarPos))
	{
		ResetCorrect();
		RESOURCEMANAGER->ResetSource();
		INTERFACEMANAGER->SetTimeRender();
		SCENEMANAGER->ResetScene();
		SCENEMANAGER->SetCurrentScene(SN_START);
	}
}

void CInterfaceManager::Render(SDL_Surface* scrSurface)
{
	m_CurScene = SCENEMANAGER->GetSceneNum();

	switch (m_CurScene)
	{
	case SN_CH1_STAGE1:
		FontInit((unsigned short*)"1 - 1", &pText, &font);
		break;
	case SN_CH1_STAGE2:
		FontInit((unsigned short*)"1 - 2", &pText, &font);
		break;
	case SN_CH1_STAGE3:
		FontInit((unsigned short*)"2 - 1", &pText, &font);
		break;
	case SN_CH1_STAGE4:
		FontInit((unsigned short*)"2 - 2", &pText, &font);
		break;
	}

	m_InGameEdge->Render(scrSurface);

	m_StageBar->Render(scrSurface);

	for (int i = 0; i < RESOURCEMANAGER->GetHp(); i++)
	{
		m_HPBar[i]->Render(scrSurface);
	}

	for (int i = 0; i < RESOURCEMANAGER->GetHint(); i++)
	{
		m_HintBar[i]->Render(scrSurface);
	}

	for (int i = 0; i < 5; i++)
	{
		m_CorrectBar[i]->Render(scrSurface);
	}

	m_ExitBar->Render(scrSurface);
	
	StageBarRender(scrSurface);
}

void CInterfaceManager::Release()
{
	delete m_InGameEdge;
	m_InGameEdge = NULL;

	delete m_StageBar;
	m_StageBar = NULL;

	for (int i = 0; i < 3; i++)
	{
		delete m_HPBar[i];
		m_HPBar[i] = NULL;
	}

	for (int i = 0; i < 3; i++)
	{
		delete m_HintBar[i];
		m_HintBar[i] = NULL;
	}

	delete m_ExitBar;
	m_ExitBar = NULL;
}

void CInterfaceManager::AddCorrect()
{
	delete m_CorrectBar[iCorrectCnt];
	m_CorrectBar[iCorrectCnt] = NULL;

	m_CorrectBar[iCorrectCnt] = new Object;
	m_CorrectBar[iCorrectCnt]->Init("./img/Interface/CorrectBar.bmp", CorrectBarPos[iCorrectCnt]);

	++iCorrectCnt;
}

void CInterfaceManager::ResetCorrect()
{
	for (int i = 0; i < 5; i++)
	{
		delete m_CorrectBar[i];
		m_CorrectBar[i] = NULL;

		m_CorrectBar[i] = new Object;
		m_CorrectBar[i]->Init("./Img/Interface/UnCorrectBar.bmp", CorrectBarPos[i]);
	}

	++m_CurScene;
	iCorrectCnt = 0;
	fTime = SDL_GetTicks();
}

void CInterfaceManager::FontInit(unsigned short* str, SDL_Surface** _Text, TTF_Font** _font)
{
	font = TTF_OpenFont("./Font/Binggrae.ttf", 30);

	SDL_Color color;
	color.r = 0;
	color.g = 0;
	color.b = 0;

	unsigned short unicode[128];
	han2unicode((char*)str, unicode);

	*_Text = TTF_RenderUNICODE_Blended(*_font, unicode, color);
}

void CInterfaceManager::StageBarRender(SDL_Surface* scrSurface)
{
	SDL_Rect scrPosit = { 620,15,100,100 };
	SDL_BlitSurface(pText, NULL, scrSurface, &scrPosit);
}

void CInterfaceManager::SetTimeRender()
{
	m_FinalTime = SDL_GetTicks() - fTime;
	
	int Sec = int(m_FinalTime / 1000);
	int Min = int(Sec / 60);

	char TimeStr[30];
	sprintf(TimeStr, "%02d∫– : %02d√ ", Min, Sec);
	FontInit((unsigned short*)TimeStr, &pTimeText, &timefont);
}

void CInterfaceManager::TimeRender(SDL_Surface* scrSurface)
{
	SDL_Rect scrPosit = { 375,227,100,100 };
	SDL_BlitSurface(pTimeText, NULL, scrSurface, &scrPosit);
}