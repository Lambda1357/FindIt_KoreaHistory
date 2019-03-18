#include "stdafx.h"
#include "Ch1Stage4.h"
#include "InterfaceManager.h"
#include "MouseInput.h"
#include "HiddenObject.h"


CCh1Stage4::CCh1Stage4()
{
}


CCh1Stage4::~CCh1Stage4()
{
}

void CCh1Stage4::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	RandomSetting();
}
int CCh1Stage4::Update()
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
void CCh1Stage4::Render(SDL_Surface* scrSurface)
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
void CCh1Stage4::Destroy()
{
	auto iter = vecHiddenObj.rbegin();
	while (iter != vecHiddenObj.rend())
	{
		(*iter)->Destroy();

		iter++;
	}

	BackgroundFree();
}

void CCh1Stage4::RandomSetting()
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
				FirstPos = { 286,516,33,28 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Wheel.bmp", FirstPos);
				break;
			case 2:
				FirstPos = { 560,477,57,63 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Jjanggwu.bmp", FirstPos);
				break;
			case 3:
				FirstPos = { 489,212,162,102 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Tablet.bmp", FirstPos);
				break;
			case 4:
				FirstPos = { 1074,575,66,61 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Psyworld.bmp", FirstPos);
				break;
			case 5:
				FirstPos = { 325,553,28,31 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Robot.bmp", FirstPos);
				break;
			case 6:
				FirstPos = { 915,333,28,31 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_BitSal.bmp", FirstPos);
				break;
			case 7:
				FirstPos = { 1091,344,27,23 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Mirror.bmp", FirstPos);
				break;
			case 8:
				FirstPos = { 988,185,41,38 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_BiBi.bmp", FirstPos);
				break;
			case 9:
				FirstPos = { 156,372,37,31 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Facebook.bmp", FirstPos);
				break;
			case 10:
				FirstPos = { 141,163,305,106 };
				tmp->Init("./img/Chapter1/Stage4/Ch1_Stage4_Alphago.bmp", FirstPos);
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

void CCh1Stage4::Hint()
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