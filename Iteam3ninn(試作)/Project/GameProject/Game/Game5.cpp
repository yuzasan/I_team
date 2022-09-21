#include "Game5.h"
#include "Map.h"
#include "Player2.h"
#include "../Title/Title.h"

Game5::Game5() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 32) {
	Base::Add(new Map());
	Base::Add(new Player2(CVector2D(32 * 3, 32 * 4)));
}

Game5::~Game5() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game5::Update() {
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}

	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}

	//エンターキーでゲームシーン終了
	if (PUSH(CInput::eButton10)) {
		SetKill();
	}
}

void Game5::Draw() {
	m_title_text.Draw(750, 100, 255, 255, 255, "WASD 移動");
	m_title_text.Draw(750, 180, 255, 255, 255, "マウスで方向転換");
	m_title_text.Draw(750, 260, 255, 255, 255, "左クリックで発射");
	m_title_text.Draw(750, 340, 255, 255, 255, "敵を押せる");
	m_title_text.Draw(750, 420, 255, 255, 255, "自分の弾に当たる");
	m_title_text.Draw(750, 500, 255, 255, 255, "enterでタイトルに戻る");
	m_title_text.Draw(750, 580, 255, 255, 255, "自分or敵が全滅の時zキーで戻る");
}