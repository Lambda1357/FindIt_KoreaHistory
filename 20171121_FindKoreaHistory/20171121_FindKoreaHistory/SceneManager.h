#pragma once

#include "Singletone.h"
#include "Scene.h"

enum SceneNumber
{
	SN_START,
	SN_INGAME,
	SN_RESULT
};

class SceneManager : public Singletone<SceneManager>
{
private:
	std::map<SceneNumber, Scene*> sceneMap;

public:
	void Init();
	void Update();
	void Render(SDL_Surface* scrSurface);
	void Destroy();
};

#define SCENEMANAGER SceneManager::GetInstance()