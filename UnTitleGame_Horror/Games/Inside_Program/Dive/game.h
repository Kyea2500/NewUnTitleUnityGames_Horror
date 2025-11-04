#pragma once
#include"../../Outside_Program/Library/DX_Files_VC/DxLib.h"
namespace Game
{
	// 画面情報を定数定義
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 640;
	constexpr int kColorBitNum = 32;

	constexpr bool kDefaultWindowMode = true;
}

namespace Pad
{
	// プロトタイプ宣言

	/// <summary>
	/// パッドの入力状態更新処理
	/// 1フレームに1回のみ呼び出す
	/// </summary>
	
	int padInput = 0;  // 現在のフレームのパッド入力
	int lastInput = 0; // ひとつ前のフレームのパッド入力

	void Update()
	{
		// 前のフレームに押されていたボタンの情報を覚えておく
		lastInput = padInput;
		// 個のフレームに押されているボタンの情報を取得する
		padInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	}

	/// <summary>
	/// Press判定の取得
	/// </summary>
	/// <param name="button">判定を行いたいボタン</param>
	/// <returns>押されていたらtrue,押されていなかったらfalse</returns>
	bool IsPress(int button)
	{
		return (padInput & button);
	}

	/// <summary>
	/// Trigger判定(押された瞬間)の取得
	/// </summary>
	/// <param name="button">判定を行いたいボタン</param>
	/// <returns>ボタンが押された瞬間true,それ以外はfalse</returns>
	bool IsTrigger(int button)
	{
		// (padInput & button) == 0の場合false
		// それ以外の場合はtrueが入る
		bool isNow = (padInput & button);
		bool isLast = (lastInput & button);
		return (isNow && !isLast);
	}
}