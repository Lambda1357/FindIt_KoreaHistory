#include "stdafx.h"
#include "Ch1Stage3.h"
#include "InterfaceManager.h"
#include "MouseInput.h"
#include "HiddenObject.h"


CCh1Stage3::CCh1Stage3()
{
}


CCh1Stage3::~CCh1Stage3()
{
}

void CCh1Stage3::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	RandomSetting();
}

int CCh1Stage3::Update()
{
	if (RESOURCEMANAGER->GetHp() <= 0)
	{
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
void CCh1Stage3::Render(SDL_Surface* scrSurface)
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
void CCh1Stage3::Destroy()
{
	auto iter = vecHiddenObj.rbegin();
	while (iter != vecHiddenObj.rend())
	{
		(*iter)->Destroy();

		iter++;
	}

	BackgroundFree();
}

void CCh1Stage3::RandomSetting()
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
				FirstPos = { 210,446,39,64 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Mic.bmp", FirstPos);
				break;
			case 2:
				FirstPos = { 140,529,82,109 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Siga.bmp", FirstPos);
				break;
			case 3:
				FirstPos = { 716, 321,17,36 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Lipstick.bmp", FirstPos);
				break;
			case 4:
				FirstPos = { 670,374,104,156 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Chello.bmp", FirstPos);
				break;
			case 5:
				FirstPos = { 801,516,133,113 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stag3_ClockNeedle.bmp", FirstPos);
				break;
			case 6:
				FirstPos = { 1077,534,69,53 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Coffee.bmp", FirstPos);
				break;
			case 7:
				FirstPos = { 1078,589,65,57 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Stone.bmp", FirstPos);
				break;
			case 8:
				FirstPos = { 928,168,46,45 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Clock.bmp", FirstPos);
				break;
			case 9:
				FirstPos = { 927,251,245,232 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Car.bmp", FirstPos);
				break;
			case 10:
				FirstPos = { 601,81,86,109 };
				tmp->Init("./img/Chapter1/Stage3/Ch1_Stage3_Lamp.bmp", FirstPos);
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

void CCh1Stage3::Hint()
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