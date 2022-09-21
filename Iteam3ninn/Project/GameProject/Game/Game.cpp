#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene){
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(32 * 3, 32 * 4)));
	Base::Add(new Enemy(CVector2D(32 * 28, 32 * 4)));
	Base::Add(new Enemy(CVector2D(32 * 28, 32 * 18)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 7)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 15)));


}

Game::~Game(){
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update(){
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}

	//敵全滅　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Enemy) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
