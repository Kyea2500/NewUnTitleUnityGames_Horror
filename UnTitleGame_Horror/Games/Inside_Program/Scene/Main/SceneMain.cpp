#include "SceneMain.h"

SceneMain::SceneMain()
{

}

SceneMain::~SceneMain()
{

}

void SceneMain::Init()
{

}

void SceneMain::End()
{

}

SceneManager::SceneKind SceneMain::Update()
{
	

	if (m_ClearFlag)
	{
		return SceneManager::SceneKind::kSceneClear;
	}

	else if (m_HitToEnemy)
	{
		return SceneManager::SceneKind::kSceneGameOver;
	}

	else
	{
		return SceneManager::SceneKind::kSceneMain;
	}
}

void SceneMain::Draw()
{

}
