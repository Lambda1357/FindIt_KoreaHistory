#include "stdafx.h"
#include "SceneManager.h"

void SceneManager::Init()
{
	//add a Scene to SceneMap

	//Scene Initialize

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
	for (std::map<SceneNumber, Scene*>::iterator iter = sceneMap.begin; iter != sceneMap.end; iter++) iter->second->Destroy();
	ReleaseInstance();
}

void SceneManager::SetCurrentScene(SceneNumber sn)
{
	curSn = sn;
}
