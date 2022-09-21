#pragma once
#include "../Base/Base.h"

class Enemy2 : public Base {
private:
	CImage m_img;
	int m_cnt;
public:
	Enemy2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};