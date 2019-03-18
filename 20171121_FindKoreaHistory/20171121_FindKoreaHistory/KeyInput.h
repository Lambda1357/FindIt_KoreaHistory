#pragma once
#include "Singletone.h"
class CKeyInput : public Singletone<CKeyInput>
{
public:
	bool cur_ClickState, prv_ClickState;
public:
	void Init();
	void Update();
	void Destroy();

	inline void OnKeyDown() { cur_ClickState = true; }
	inline void OnKeyUp() { cur_ClickState = false; }
	inline bool GetClick() { return cur_ClickState; }
	inline bool GetPrevClick() { return prv_ClickState; }

	bool KEY_UP()
	{
		return (cur_ClickState == false && prv_ClickState == true);
	}
public:
	CKeyInput();
	virtual ~CKeyInput();
};

#define KEYINPUT CKeyInput::GetInstance()

