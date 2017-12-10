#pragma once

#include "Singletone.h"
#include "Scene.h"
#include "SceneNumber.h"

class SceneManager : public Singletone<SceneManager>
{
private:
	std::map<SceneNumber, Scene*> sceneMap;
	SceneNumber curSn;

public:
	void Init();
	void Update();
	void Render(SDL_Surface* scrSurface);
	void Destroy();
	void SetCurrentScene(SceneNumber sn);

};

#define SCENEMANAGER SceneManager::GetInstance()