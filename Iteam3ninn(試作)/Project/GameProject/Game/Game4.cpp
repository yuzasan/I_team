#include "Game4.h"
#include "Map.h"
#include "Player2.h"
#include "Enemy2.h"
#include "../Title/Title.h"

Game4::Game4() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 22) {
	Base::Add(new Map());
	Base::Add(new Player2(CVector2D(32 * 3, 32 * 4)));
	Base::Add(new Enemy2(CVector2D(32 * 28, 32 * 4)));
	Base::Add(new Enemy2(CVector2D(32 * 28, 32 * 18)));
	Base::Add(new Enemy2(CVector2D(32 * 37, 32 * 10)));
	Base::Add(new Enemy2(CVector2D(32 * 17, 32 * 7)));
	Base::Add(new Enemy2(CVector2D(32 * 17, 32 * 15)));


}

Game4::~Game4() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game4::Update() {
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}

	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void Game4::Draw(){
	if (PUSH(CInput::eMouseL)) {
		m_cnt--;
	}
	m_title_text.Draw(10, 20, 255, 0, 0, "残り残弾:%d",m_cnt);
}
