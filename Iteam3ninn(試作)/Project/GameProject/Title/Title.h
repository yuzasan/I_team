#pragma once
#include "../Base/Base.h"

class Title : public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
	CFont m_menu_text;
	CFont m_member_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};
