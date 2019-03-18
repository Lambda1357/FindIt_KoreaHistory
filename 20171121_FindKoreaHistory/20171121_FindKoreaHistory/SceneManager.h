#pragma once

#include "Singletone.h"
#include "Scene.h"
#include "SceneNumber.h"

class SceneManager : public Singletone<SceneManager>
{
private:
	std::map<int, Scene*> sceneMap;
	int curSn;
	int oldSn;
	bool bEnd;
public:
	void Init();
	void Update();
	void Render(SDL_Surface* scrSurface);
	void Destroy();
	void SetCurrentScene(int sn);

	inline int GetSceneNum() { return curSn; }

	void ResetScene();
};

#define SCENEMANAGER SceneManager::GetInstance()