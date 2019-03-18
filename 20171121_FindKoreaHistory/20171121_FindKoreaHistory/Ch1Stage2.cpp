#include "stdafx.h"
#include "Ch1Stage2.h"
#include "InterfaceManager.h"
#include "MouseInput.h"
#include "HiddenObject.h"
#include "ResourceManager.h"


CCh1Stage2::CCh1Stage2()
{
}


CCh1Stage2::~CCh1Stage2()
{
}

void CCh1Stage2::Init(char* ImgAdr)
{
	BackgroundInit(ImgAdr);

	RandomSetting();
}

int CCh1Stage2::Update()
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

void CCh1Stage2::Render(SDL_Surface* scrSurface)
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
void CCh1Stage2::Destroy()
{
	auto iter = vecHiddenObj.rbegin();
	while (iter != vecHiddenObj.rend())
	{
		(*iter)->Destroy();

		iter++;
	}

	BackgroundFree();
}

void CCh1Stage2::RandomSetting()
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
				FirstPos = { 869,397,114,72 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Smartphone.bmp", FirstPos);
				break;
			case 2:
				FirstPos = { 446,486,103,78 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Pencil.bmp", FirstPos);
				break;
			case 3:
				FirstPos = { 161,580,127,68 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Chicken.bmp", FirstPos);
				break;
			case 4:
				FirstPos = { 337,459,100,72 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Jewelry.bmp", FirstPos);
				break;
			case 5:
				FirstPos = { 952,505,78,46 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Plug.bmp", FirstPos);
				break;
			case 6:
				FirstPos = { 586,343,67,43 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Twitter.bmp", FirstPos);
				break;
			case 7:
				FirstPos = { 1016,273,79,98 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_HoneyButterChip.bmp", FirstPos);
				break;
			case 8:
				FirstPos = { 613,598,83,47 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Mp3.bmp", FirstPos);
				break;
			case 9:
				FirstPos = { 867,142,60,81 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Glass.bmp", FirstPos);
				break;
			case 10:
				FirstPos = { 981,613,48,31 };
				tmp->Init("./img/Chapter1/Stage2/Ch1_Stage2_Laptop.bmp", FirstPos);
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

void CCh1Stage2::Hint()
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