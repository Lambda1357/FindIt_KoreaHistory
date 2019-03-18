#include "stdafx.h"
#include "KeyInput.h"


CKeyInput::CKeyInput()
{
}


CKeyInput::~CKeyInput()
{
}

void CKeyInput::Init()
{
	cur_ClickState = prv_ClickState = false;
}

void CKeyInput::Update()
{
	prv_ClickState = cur_ClickState;
	cur_ClickState = false;
}

void CKeyInput::Destroy()
{
	ReleaseInstance();
}