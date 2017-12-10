#include "stdafx.h"
#include "SceneManager.h"

void SceneManager::Init()
{
	//add a Scene to sceneMap
	sceneMap[SN_START] = new StartScene;

	//Scene Initialize
	sceneMap[SN_START]->Init("./img/backgroundStart.bmp");

	//Set Current SceneNumber to Start Scene
	curSn = SN_START;
}

void SceneManager::Update()
{
	sceneMap[curSn]->Update();
}

void SceneManager::Render(SDL_Surface* scrSurface)
{
	sceneMap[curSn]->Render(scrSurface);
}

void SceneManager::Destroy()
{
	for (std::map<SceneNumber, Scene*>::iterator iter = sceneMap.begin(); iter != sceneMap.end(); iter++) iter->second->Destroy();
	ReleaseInstance();
}

void SceneManager::SetCurrentScene(SceneNumber sn)
{
	auto iter = sceneMap.find(sn);
	if (iter != sceneMap.end())
		curSn = sn;
	else
		printf("%d번 씬에서 %d번 씬으로 이동할수 없습니다!\n", curSn, sn);
}
