#pragma once

#include "../Base/Base.h"

class Game5 : public Base {
	CFont m_title_text;
public:
	Game5();
	~Game5();
	void Update();
	void Draw();
};
