#pragma once

#include "Button.h"
#include "SceneManager.h"


/*
 *�ܼ� �� �̵� ���. ������ ������ �̵���
 *�⺻ ������ ����. SceneChangeButton(SceneNumber something)���� �����ؾ� ��
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