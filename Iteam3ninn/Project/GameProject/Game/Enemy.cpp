#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(const CVector2D& pos) :Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//半径
	m_rad = 16;

}

void Enemy::Update() {
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b) {
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 120) {
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}
}

void Enemy::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();

}

void Enemy::Collision(Base* b) {
	switch (b->m_type) {

	case eType_Player:
		if (Base::CollisionCircle(this, b)) {


			CVector2D V = m_pos - b->m_pos;
			float l = V.Length();
			float s = m_rad + b->m_rad - l;
			V.Normalize();
			m_pos += V * s;
		}
		break;
	}

}