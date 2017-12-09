#pragma once

#include "SceneManager.h"
#include "Button.h"

/*
 *�ܼ� �� �̵� ���. ������ ������ �̵���
 *�⺻ ������ ����. SceneChangeButton(SceneNumber something)���� �����ؾ� ��
 */
class SceneChangeBehavior : public Button::ButtonBehavior
{
private:
	SceneChangeBehavior();
	SceneNumber destSn;

public:
	SceneChangeBehavior(SceneNumber sn);
	void OnClick();

};