#pragma once

#include "../Base/Base.h"

class Game4 : public Base {
	CFont m_title_text;
public:
	Game4();
	~Game4();
	void Update();
	void Draw();
};
