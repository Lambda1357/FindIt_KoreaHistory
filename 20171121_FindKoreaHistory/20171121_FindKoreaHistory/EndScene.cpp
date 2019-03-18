#include "stdafx.h"
#include "EndScene.h"
#include "Object.h"
#include "InterfaceManager.h"
#include "MouseInput.h"

CEndScene::CEndScene()
{
}


CEndScene::~CEndScene()
{
	Destroy();
}

void CEndScene::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);
	SDL_Rect m_Pos;

	m_Pos = { 116,486,648,150 };
	pFailBar = new Object;
	pFailBar->Init("./img/Clear/fail.bmp", m_Pos);
	pSuccessBar = new Object;
	pSuccessBar->Init("./img/Clear/Success.bmp", m_Pos);

	m_Pos = { 0,0,70,70 };
	pNextBar = new Object;
	pNextBar->Init("./img/Clear/Close.bmp", m_Pos);

	m_Pos = { 814,90,350,400 };
	pFailChar = new Object;
	pFailChar->Init("./img/Clear/Character_Fail.bmp", m_Pos);
	pSuccessChar = new Object;
	pSuccessChar->Init("./img/Clear/Character_Success.bmp", m_Pos);
}
int CEndScene::Update()
{
	SDL_Rect scrPosit = { 0,0,70,70 };

	if (MOUSEINPUT->IsClick(scrPosit))
	{
		return -1;
	}
	
	return 0;
}
void CEndScene::Render(SDL_Surface* scrSurface)
{
	SDL_BlitSurface(background, NULL, scrSurface, NULL);

	INTERFACEMANAGER->TimeRender(scrSurface);
	pNextBar->Render(scrSurface);

	if (INTERFACEMANAGER->GetCleared())
	{
		pSuccessBar->Render(scrSurface);
		pSuccessChar->Render(scrSurface);
	}

	else
	{
		pFailBar->Render(scrSurface);
		pFailChar->Render(scrSurface);
	}
}
void CEndScene::Destroy()
{
	delete pFailBar;
	pFailBar = NULL;
	delete pSuccessBar;
	pSuccessBar = NULL;
	delete pNextBar;
	pNextBar = NULL;
	delete pFailChar;
	pFailChar = NULL;
	delete pSuccessChar;
	pSuccessChar = NULL;
}
