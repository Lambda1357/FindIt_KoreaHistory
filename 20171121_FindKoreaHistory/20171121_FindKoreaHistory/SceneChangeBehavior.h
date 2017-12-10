#pragma once

#include "Button.h"
#include "SceneManager.h"


/*
 *단순 씬 이동 기능. 지정된 씬으로 이동함
 *기본 생성자 없음. SceneChangeButton(SceneNumber something)으로 생성해야 함
 */
class SceneChangeBehavior : public ButtonBehavior
{
private:
	SceneChangeBehavior();
	SceneNumber destSn;

public:
	SceneChangeBehavior(SceneNumber sn);
	void OnClick();

};