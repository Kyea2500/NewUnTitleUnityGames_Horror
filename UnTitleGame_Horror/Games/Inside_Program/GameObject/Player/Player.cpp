#include "Player.h"
#include"../../Dive/game.h"
#include"../../../Outside_Program/Library/DX_Files_VC/DxLib.h"
namespace
{
	// プレイヤーの移動速度
	constexpr float kPlayerNormalSpeed = 40.0f;
	// ダッシュ時の移動速度
	constexpr float kPlayerDashSpeed = 80.0f;

	// プレイヤーの行動速度調整
	constexpr float kMoveAdjustment = 3.0f;

	// プレイヤーの当たり判定半径
	constexpr float kColRadius = 85.0f;

	// プレイヤーが立札を読むための当たり判定半径
	constexpr float kColRadiusSign = 200.0f; // 立札の当たり判定半径

	// ジャンプの回数
	constexpr int kMaxJumpCount = 2; // 最大ジャンプ回数

	// プレイヤーの当たり判定
	constexpr int kPlayerColor = 16;
	// プレイヤーの重力
	constexpr float kGravity = -0.5f; // 重力の値

	// プレイヤーのジャンプ力
	constexpr float kJumpPower = 22.0f;

	//// プレイヤーの移動加速度
	//constexpr float kMoveAccel = 6.00f;

	// 移動減速率()
	constexpr float kMoveDecRate = 10.0f;

	// プレイヤーの吹っ飛び率
	constexpr float kHitPower = 60.0f;

}

Player::Player():NowState(kNormal),
m_Transform(std::make_shared<Transform>()),
m_Velocity(std::make_shared<Velocity>()),
m_Speed(0),
m_isMove(false),
m_isAlive(true)
{
}

Player::~Player()
{
}

void Player::Init()
{
	m_Transform->SetPosition(VGet(0.0f, 0.0f, 0.0f));
	m_Velocity->GetVelocity() = VGet(0.0f, 0.0f, 0.0f); // 初期速度を設定
}

void Player::Update()
{
	Pad::Update();
	UpdateMove();
}

void Player::Draw()
{
}

void Player::UpdateMove()
{
	// プレイヤーの移動処理
	m_isMove = false; // 移動中フラグを初期化

	// 移動速度を設定
// 1ボタン(Aボタン)を押している場合はダッシュ速度
	if (Pad::IsPress(PAD_INPUT_1))
	{
		// ダッシュ中の移動速度
		m_Speed = kPlayerDashSpeed;
	}
	// 1ボタン(Aボタン)を押していない場合は通常の移動速度
	else
	{
		// 通常の移動速度
		m_Speed = kPlayerNormalSpeed;
	}

	if (!m_isMove)
	{
		//m_vec.x = 0.0f; // 水平方向の移動ベクトルをリセット
		m_Velocity->SetVelocityX(0.0f); // X軸の速度をリセット

		//m_vec.z = 0.0f; // 垂直方向の移動ベクトルをリセット
		m_Velocity->SetVelocityZ(0.0f); // Z軸の速度をリセット
	}

	// 上下左右の入力に応じて移動ベクトルを更新
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		// 上に移動
		//m_vec.z += speed;
		m_Velocity->SetVelocityZ(m_Velocity->GetVelocityZ() + m_Speed);
		m_isMove = true; // 移動中にする
	}
	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		// 下に移動
	//	m_vec.z -= speed;
		m_Velocity->SetVelocityZ(m_Velocity->GetVelocityZ() - m_Speed);
		m_isMove = true; // 移動中にする
	}
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		// 左に移動
	//	m_vec.x -= speed;
		m_Velocity->SetVelocityX(m_Velocity->GetVelocityX() - m_Speed);
		m_isMove = true; // 移動中にする
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		// 右に移動
//		m_vec.x += speed;
		m_Velocity->SetVelocityX(m_Velocity->GetVelocityX() + m_Speed);
		m_isMove = true; // 移動中にする
	}

	//	移動の正規化
	// 移動ベクトルがゼロでない場合に正規化を行う
	if (m_Velocity->GetVelocityX() != 0.0f || m_Velocity->GetVelocityZ() != 0.0f)
	{
		m_Velocity->VectorNormalizeXZ(); // XZ平面での正規化
	}

	m_Velocity->SetVelocityZ(m_Velocity->GetVelocityZ() * kMoveAdjustment);
	m_Velocity->SetVelocityX(m_Velocity->GetVelocityX() * kMoveAdjustment);

	// 位置を更新
	/*m_pos = VecAdd(m_pos, m_vec);*/

	m_Transform->SetPosition(VAdd(m_Transform->GetPosition(), m_Velocity->GetVelocity()));
}

