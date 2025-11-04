#pragma once
#include"../Manager/SceneManager.h"
class SceneTitle
{
public:
	SceneTitle();
	~SceneTitle();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};

