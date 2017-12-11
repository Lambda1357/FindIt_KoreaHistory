#include "stdafx.h"
#include "CutScene.h"

void CutScene::Init(char* imgAdr)
{
	BackgroundInit("./img/backgroundStart.bmp");

}

void CutScene::Update()
{

}

void CutScene::PutScreenObject(Object* nObj)
{
	scrList.push_back(nObj);
}

void CutScene::PutScreenObject(char* imgAdr)
{
	Object* tmp = new Object;
	SDL_Rect r_tmp = { 0,0,1280,720 };
	tmp->Init(imgAdr, r_tmp);

	scrList.push_back(tmp);
}

void CutScene::PutScreenObject(char * imgAdr, SDL_Rect rct)
{
	Object* tmp = new Object;
	tmp->Init(imgAdr, rct);

	scrList.push_back(tmp);
}
