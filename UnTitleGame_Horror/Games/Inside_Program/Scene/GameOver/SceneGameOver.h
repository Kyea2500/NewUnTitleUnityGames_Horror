#pragma once
#include"../Manager/SceneManager.h"
class SceneGameOver
{
public:
	SceneGameOver();
	~SceneGameOver();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
};