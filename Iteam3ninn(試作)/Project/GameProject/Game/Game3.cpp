#include "Game3.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"

Game3::Game3() :Base(eType_Scene) {
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));


}

Game3::~Game3() {
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game3::Update() {
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}

	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
