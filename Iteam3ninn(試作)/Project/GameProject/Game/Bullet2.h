#pragma once
#include "../Base/Base.h"

class Bullet2 : public Base {
	CImage m_img;
	float m_speed;
	int m_cnt;
public:
	Bullet2(int type, const CVector2D& pos, float ang, float speed);
	~Bullet2();
	void Update();
	void Draw();
	void Collision(Base* b);

};