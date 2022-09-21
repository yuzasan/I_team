#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game2.h"
#include "../Game/Game3.h"
#include "../Game/Game4.h"
#include "../Game/Game5.h"


Title::Title() :Base(eType_Scene), m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 128), m_menu_text("C:\\Windows\\Fonts\\msgothic.ttc", 50), m_member_text("C:\\Windows\\Fonts\\msgothic.ttc", 40) {
	m_img = COPY_RESOURCE("Title", CImage);
}

Title::~Title(){
	//全てのオブジェクトを破棄
	Base::KillAll();
	if (HOLD(CInput::eButton1)) {//Zキー
		//ゲームシーンへ
		Base::Add(new Game());
	}
	if (HOLD(CInput::eButton2)) {//Xキー
		//ゲームシーンへ
		Base::Add(new Game2());
	}
	if (HOLD(CInput::eButton3)) {//Cキー
		//ゲームシーンへ
		Base::Add(new Game3());
	}
	if (HOLD(CInput::eButton4)) {//Vキー
		//ゲームシーンへ
		Base::Add(new Game4());
	}
	if (HOLD(CInput::eButton5)) {//VK_SPACE
		//ゲームシーンへ
		Base::Add(new Game5());
	}
}

void Title::Update(){
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
	if (PUSH(CInput::eButton2)) {
		SetKill();
	}
	if (PUSH(CInput::eButton3)) {
		SetKill();
	}
	if (PUSH(CInput::eButton4)) {
		SetKill();
	}
	if (PUSH(CInput::eButton5)) {
		SetKill();
	}
}

void Title::Draw(){
	m_img.Draw();
	//文字表示
	m_title_text.Draw(156, 200, 255, 255, 0, "タンク");

	m_menu_text.Draw(156, 280, 0, 100, 100, "SPACE");
	m_menu_text.Draw(330, 280, 0, 100, 100, "操作説明");

	m_menu_text.Draw(1024, 112, 100, 0, 100, "HOLD C");
	m_menu_text.Draw(1024, 162, 100, 0, 100, "簡単");
	m_menu_text.Draw(1024, 262, 100, 0, 100, "HOLD X");
	m_menu_text.Draw(1024, 312, 100, 0, 100, "普通");
	m_menu_text.Draw(1024, 412, 100, 0, 100, "HOLD Z");
	m_menu_text.Draw(1024, 462, 100, 0, 100, "難しい");
	m_menu_text.Draw(1024, 562, 255, 0, 0, "HOLD V");
	m_menu_text.Draw(1024, 612, 255, 0, 0, "EXTRA");

	m_member_text.Draw(64, 512, 255, 255, 255, "メンバー");
	m_member_text.Draw(64, 612, 255, 255, 255, "成島航生 ");
	m_member_text.Draw(370, 612, 255, 255, 255, "三好唯斗");
	m_member_text.Draw(675, 612, 255, 255, 255, "森本英夫");
	

	/*
	m_title_text.Draw(64, 512, 0, 0, 0, "HOLD Z");
	m_title_text.Draw(512, 512, 0, 0, 0, "HOLD X");
	m_title_text.Draw(1024, 512, 0, 0, 0, "HOLD C");
	m_title_text.Draw(64, 612, 0, 0, 0, "難しい");
	m_title_text.Draw(512, 612, 0, 0, 0, "普通");
	m_title_text.Draw(1024, 612, 0, 0, 0, "簡単");

	m_menu_text.Draw(1024, 112, 0, 0, 0, "HOLD C");
	m_menu_text.Draw(1024, 212, 0, 0, 0, "簡単");
	m_menu_text.Draw(1024, 342, 0, 0, 0, "HOLD X");
	m_menu_text.Draw(1024, 442, 0, 0, 0, "普通");
	m_menu_text.Draw(1024, 572, 0, 0, 0, "HOLD Z");
	m_menu_text.Draw(1024, 672, 0, 0, 0, "難しい");
	*/
}

