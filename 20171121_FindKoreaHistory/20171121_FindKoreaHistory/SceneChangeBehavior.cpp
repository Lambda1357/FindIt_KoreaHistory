#include "stdafx.h"
#include "SceneChangeBehavior.h"

SceneChangeBehavior::SceneChangeBehavior(SceneNumber sn)
{
	destSn = sn;
}

void SceneChangeBehavior::OnClick()
{
	SCENEMANAGER->SetCurrentScene(destSn);
}
