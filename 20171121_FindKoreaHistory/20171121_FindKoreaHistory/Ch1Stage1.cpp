#include "stdafx.h"
#include <iostream>
#include "Ch1Stage1.h"
#include "HiddenObject.h"
#include "InterfaceManager.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "MouseInput.h"


CCh1Stage1::CCh1Stage1()
{
}


CCh1Stage1::~CCh1Stage1()
{
}

void CCh1Stage1::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	RandomSetting();
}

int CCh1Stage1::Update()
{
	if (RESOURCEMANAGER->GetHp() <= 0)
	{
		SCENEMANAGER->ResetScene();
		RESOURCEMANAGER->ResetSource();
		INTERFACEMANAGER->SetTimeRender();
		INTERFACEMANAGER->ResetCorrect();
		return -2;
	}

	if (INTERFACEMANAGER->GetCorrectCnt() == 5)
	{
		INTERFACEMANAGER->SetTimeRender();
		INTERFACEMANAGER->ResetCorrect();
		return -1;
	}

	INTERFACEMANAGER->Update();

	if (INTERFACEMANAGER->GetHint() == true && RESOURCEMANAGER->GetHint() > 0)
	{
		Hint();
	}

	int iCnt = 0;

	auto iter = vecHiddenObj.begin();
	while (iter != vecHiddenObj.end())
	{
		(*iter)->Update();

		if (MOUSEINPUT->IsClick((*iter)->GetRect()))
		{
			if (!(*iter)->GetChecked())
				INTERFACEMANAGER->AddCorrect();

			(*iter)->SetClicked(true);
			(*iter)->SetChecked(true);
			++iCnt;
			printf("정답\n");
			break;
		}
		iter++;
	}

	SDL_Rect Screenrc = { 128,72,1024,576 };
	if (iCnt == 0 && MOUSEINPUT->GetClick() == true && MOUSEINPUT->GetPrevClick() == false && MOUSEINPUT->IsClick(Screenrc))
	{
		printf("오답\n");
		RESOURCEMANAGER->SubHp();
	}

	return 0;
}

void CCh1Stage1::Render(SDL_Surface* scrSurface)
{
	SDL_BlitSurface(background, NULL, scrSurface, NULL);

	auto iter = vecHiddenObj.begin();
	while (iter != vecHiddenObj.end())
	{
		(*iter)->Render(scrSurface);

		iter++;
	}

	INTERFACEMANAGER->Render(scrSurface);
}

void CCh1Stage1::Destroy()
{
	auto iter = vecHiddenObj.rbegin();
	while (iter != vecHiddenObj.rend())
	{
		(*iter)->Destroy();

		iter++;
	}

	BackgroundFree();

}

void CCh1Stage1::RandomSetting()
{
	SDL_Rect FirstPos;
	CHiddenObject* tmp;

	int iOldNum[4] = { 0. };
	int iCnt = 0;

	while (true)
	{
		bool bOverlap = false;
		int num = (rand() % 10) + 1;

		printf("%d \n", num);

		for (int i = 0; i < 4; i++)
		{
			if (num == iOldNum[i])
			{
				bOverlap = true;
				break;
			}
		}

		if (bOverlap)
			continue;

		else
		{
			tmp = new CHiddenObject();

			switch (num)
			{
			case 1:
				FirstPos = { 129,375,36,35 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Umbrella.bmp", FirstPos);
				break;
			case 2:
				FirstPos = { 197,554,173,90 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Pokachip.bmp", FirstPos);
				break;
			case 3:
				FirstPos = { 701,388,26,14 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Gun.bmp", FirstPos);
				break;
			case 4:
				FirstPos = { 734,471,112,18 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Folk.bmp", FirstPos);
				break;
			case 5:
				FirstPos = { 746,185,83,120 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_SmartPhone.bmp", FirstPos);
				break;
			case 6:
				FirstPos = { 989,274,48,48 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_MyChu.bmp", FirstPos);
				break;
			case 7:
				FirstPos = { 1034,593,50,52 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_OhYes.bmp", FirstPos);
				break;
			case 8:
				FirstPos = { 1104,577,35,46 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Book.bmp", FirstPos);
				break;
			case 9:
				FirstPos = { 262,77,48,49 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Heos.bmp", FirstPos);
				break;
			case 10:
				FirstPos = { 1015,581,11,46 };
				tmp->Init("./img/Chapter1/Stage1/Ch1_Stage1_Unknown.bmp", FirstPos);
				break;
			}

			vecHiddenObj.push_back(tmp);

			if (iCnt == 4)
				break;

			iOldNum[iCnt] = num;
			++iCnt;
		}
	}
}

void CCh1Stage1::Hint()
{
	auto iter = vecHiddenObj.begin();
	for (auto iter = vecHiddenObj.begin();
		iter != vecHiddenObj.end(); ++iter)
	{
		if ((*iter)->GetClicked() || (*iter)->GetHint() == true)
			continue;

		else
		{
			RESOURCEMANAGER->SubHint();
			INTERFACEMANAGER->SetHint(false);
			(*iter)->SetHint(true);
			break;
		}
	}
}