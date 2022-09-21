#pragma once
#include "../Base/Base.h"

class Player2 : public Base {
	CImage m_img;
public:
	Player2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};