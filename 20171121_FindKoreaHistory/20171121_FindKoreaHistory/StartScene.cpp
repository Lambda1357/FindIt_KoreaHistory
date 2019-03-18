#include "stdafx.h"
#include "StartScene.h"
#include "Behaviors.h"


void StartScene::Init(char* ImgAdr)
{
	SDL_Rect r_tmpStart = { 875,456,250,80 };
	SDL_Rect r_tmpHowto = { 875,556,250,80 };
	Button* tmp;
	BackgroundInit(ImgAdr);

	tmp = new Button;
	tmp->Init("./img/ButtonStart.bmp", r_tmpStart, new SceneChangeBehavior(SN_CUTSCENE1));
	v_ObjectList.push_back(tmp);

	tmp = new Button;
	tmp->Init("./img/ButtonHowto.bmp", r_tmpHowto, new SceneChangeBehavior(SN_HOWTO));
	v_ObjectList.push_back(tmp);
}

int StartScene::Update()
{
	auto iter = v_ObjectList.begin();
	while (iter != v_ObjectList.end())
	{
		(*iter)->Update();


		iter++;
	}

	return 0;
}

void StartScene::Render(SDL_Surface* scrSurface)
{
	SDL_BlitSurface(background, NULL, scrSurface, NULL);

	auto iter = v_ObjectList.begin();
	while (iter != v_ObjectList.end())
	{
		(*iter)->Render(scrSurface);

		iter++;
	}
}

void StartScene::Destroy()
{
	auto iter = v_ObjectList.rbegin();
	while (iter != v_ObjectList.rend())
	{
		(*iter)->Destroy();

		iter++;
	}

	BackgroundFree();
}
