#pragma once
#include "Singletone.h"
#include "ResourceManager.h"
#include "SceneNumber.h"

class Object;
class CInterfaceManager : public Singletone<CInterfaceManager>
{
private:
	int iCorrectCnt;
	bool bCleared;
	bool bHint;
private:
	TTF_Font* font;
	TTF_Font* timefont;
	SDL_Surface* pText;
	SDL_Surface* pTimeText;
	int m_CurScene;
	float fTime;
	float m_FinalTime;
	float m_fHintTime;

	Object* m_HPBar[3];
	Object* m_HintBar[3];
	Object* m_CorrectBar[5];
	Object* m_StageBar;
	Object* m_InGameEdge;
	Object* m_ExitBar;

private:
	SDL_Rect HPBarPos[3];
	SDL_Rect HintBarPos[3];
	SDL_Rect CorrectBarPos[5];
	SDL_Rect ExitBarPos;
	SDL_Rect m_Pos;

	void FontInit(unsigned short* str, SDL_Surface** _Text, TTF_Font** _font);
	void StageBarRender(SDL_Surface* scrSurface);
private:
	int iHP;
	int iHint;
public:
	void Initialize();
	void Update();
	void Render(SDL_Surface* scrSurface);
	void Release();
public:
	void AddCorrect();

	void ResetCorrect();

	int GetCorrectCnt()
	{
		return iCorrectCnt;
	}

	void ResetTime()
	{ 
		fTime = SDL_GetTicks();
	}

	void SetCleared(bool _Clear)
	{
		bCleared = _Clear;
	}

	bool GetCleared()
	{
		return bCleared;
	}

	void SetHint(bool _Hint)
	{
		bHint = _Hint;
	}

	bool GetHint()
	{
		return bHint;
	}

	void SetTimeRender();
	void TimeRender(SDL_Surface * scrSurface);
public:
	CInterfaceManager();
	virtual ~CInterfaceManager();
};

#define INTERFACEMANAGER CInterfaceManager::GetInstance()