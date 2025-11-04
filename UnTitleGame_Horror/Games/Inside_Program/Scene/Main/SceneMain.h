#pragma once
#include"../Manager/SceneManager.h"
class SceneMain
{
public:
	SceneMain();
	~SceneMain();
	void Init();
	void End();
	SceneManager::SceneKind Update();
	void Draw();
private:
	bool m_HitToEnemy;
	bool m_ClearFlag;
};

