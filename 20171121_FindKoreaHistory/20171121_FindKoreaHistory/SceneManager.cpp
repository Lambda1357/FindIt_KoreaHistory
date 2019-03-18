#include "stdafx.h"
#include "SceneManager.h"
#include "InterfaceManager.h"

#include "StartScene.h"
#include "HowTo.h"
#include "CutScene1.h"
#include "Ch1Stage1.h"
#include "CutScene2.h"
#include "Ch1Stage2.h"
#include "Ch1Stage3.h"
#include "Ch1Stage4.h"
#include "EndScene.h"

void SceneManager::Init()
{
	//add a Scene to sceneMap
	sceneMap[SN_START] = new StartScene;
	sceneMap[SN_HOWTO] = new CHowTo;
	sceneMap[SN_CUTSCENE1] = new CCutScene1;
	sceneMap[SN_CH1_STAGE1] = new CCh1Stage1;
	sceneMap[SN_CUTSCENE2] = new CCutScene2;
	sceneMap[SN_CH1_STAGE2] = new CCh1Stage2;
	sceneMap[SN_CH1_STAGE3] = new CCh1Stage3;
	sceneMap[SN_CH1_STAGE4] = new CCh1Stage4;
	sceneMap[SN_END] = new CEndScene;

	//Scene Initialize
	sceneMap[SN_START]->Init("./img/backgroundStart.bmp");
	sceneMap[SN_HOWTO]->Init("./img/backgroundStart.bmp");
	sceneMap[SN_CUTSCENE1]->Init("./img/CutScenes/CutScene1/IntroBG.bmp");
	sceneMap[SN_CH1_STAGE1]->Init("./img/Chapter1/Stage1/Chapter1_Stage1BG.bmp");
	sceneMap[SN_CUTSCENE2]->Init("./img/CutScenes/CutScene2/DialogBackground.bmp");
	sceneMap[SN_CH1_STAGE2]->Init("./img/Chapter1/Stage2/Chapter1_Stage2BG.bmp");
	sceneMap[SN_CH1_STAGE3]->Init("./img/Chapter1/Stage3/Chapter1_Stage3BG.bmp");
	sceneMap[SN_CH1_STAGE4]->Init("./img/Chapter1/Stage4/Chapter1_Stage4BG.bmp");
	sceneMap[SN_END]->Init("./img/Clear/EndingScreen.bmp");

	//Set Current SceneNumber to Start Scene
	curSn = SN_START;
	bEnd = false;
}

void SceneManager::Update()
{
	int iFlag = sceneMap[curSn]->Update();

	if (iFlag == 1)
	{
		INTERFACEMANAGER->SetCleared(false);
		SetCurrentScene(curSn + 1);
		bEnd = false;
	}

	if (iFlag == -1)
	{
		if (!bEnd)
		{
			INTERFACEMANAGER->SetCleared(true);
			oldSn = curSn;
			SetCurrentScene(SN_END);
			bEnd = true;
		}

		else
		{
			if (oldSn == SN_CH1_STAGE4)
			{
				ResetScene();
				SetCurrentScene(SN_START);
			}

			else
			{
				RESOURCEMANAGER->ResetSource();
				INTERFACEMANAGER->SetTimeRender();
				INTERFACEMANAGER->ResetCorrect();
				INTERFACEMANAGER->SetCleared(false);
				SetCurrentScene(oldSn + 1);
				bEnd = false;
			}
		}
	}

	else if (iFlag == -2)
	{
		INTERFACEMANAGER->SetCleared(false);
		oldSn = -1;
		SetCurrentScene(SN_END);
		bEnd = true;
	}

	else if (iFlag == -3)
	{
		INTERFACEMANAGER->SetCleared(false);
		oldSn = 0;
		SetCurrentScene(SN_START);
		bEnd = false;
	}
}

void SceneManager::Render(SDL_Surface* scrSurface)
{
	sceneMap[curSn]->Render(scrSurface);
}

void SceneManager::Destroy()
{
	for (std::map<int, Scene*>::iterator iter = sceneMap.begin(); iter != sceneMap.end(); iter++) iter->second->Destroy();
	ReleaseInstance();
}

void SceneManager::SetCurrentScene(int sn)
{
	auto iter = sceneMap.find(sn);
	if (iter != sceneMap.end())
	{
		curSn = sn;
	}
	else
		printf("%d번 씬에서 %d번 씬으로 이동할수 없습니다!\n", curSn, sn);

	INTERFACEMANAGER->ResetTime();
}

void SceneManager::ResetScene()
{
	for (auto iter = sceneMap.begin();
		iter != sceneMap.end(); ++iter)
	{
		if (iter->first != SN_START && iter->first != SN_END)
		{
			iter->second->Destroy();
			delete iter->second;
			iter->second = NULL;
		}
	}

	Init();
}