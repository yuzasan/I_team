#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Map.h"

Bullet::Bullet(int type, const CVector2D& pos, float ang, float speed) :Base(type) {
	if (type == eType_Player_Bullet)
		m_img = COPY_RESOURCE("Bullet", CImage);
	else
		m_img = COPY_RESOURCE("Bullet2", CImage);

	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_rad = 8;
	m_ang = ang;
	m_speed = speed;
	m_cnt = 2;
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	//ˆÚ“®‘O‚ÌˆÊ’u
	m_pos_old = m_pos;
	m_pos += m_vec;

}

void Bullet::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Bullet::Collision(Base* b) {
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y));
			if (t != 0) {
				m_pos.x = m_pos_old.x;
				m_vec.x *= -1;
				m_cnt--;
			}
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y));
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y *= -1;
				m_cnt--;
			}
			if (m_cnt == 0) {
				SetKill();
				m_cnt = 2;
			}
		}
		break;
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}

		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b) && m_cnt == 1) {
			SetKill();
			b->SetKill();
		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;

	case eType_Player_Bullet:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;

	case eType_Enemy_Bullet:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b)) {
			SetKill();
			b->SetKill();
		}
		break;
	}
}