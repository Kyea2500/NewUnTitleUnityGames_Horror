#pragma once
#include"../ObjectBase.h"
#include"../../Dive/Vec/Vec3.h"
class Player:public ObjectBase
{
public:
	//共通処理
	Player();
	~Player();
	void Init()override;
	void End();
	void Update()override;
	void Draw()override;
private:
	// 共通処理の中で、外部に渡さずに継承するための処理
	// 移動の変化や描画の変更など
	void UpdateMove();
private:
	enum state
	{
		kNormal,
		kMove,
		kDash,
		kHide,
		kEvent,
		kNum
	};
private:
	std::shared_ptr<Transform> m_Transform;
	std::shared_ptr<Velocity> m_Velocity;

	state NowState;	// 現在のキャラの状態
	float m_Speed;	// 移動速度
	bool m_isAlive; // 生存しているかどうか。	true:生存	false:死亡
	bool m_isMove;

};

