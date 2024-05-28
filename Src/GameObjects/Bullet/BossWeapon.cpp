#include "BossWeapon.h"
BossWeapon::BossWeapon()
{
	m_Num = 2;
}

BossWeapon::~BossWeapon()
{
	for (auto it : m_listBullet)
		if (it != nullptr)
			delete it;
	m_listBullet.clear();

}

void BossWeapon::Init(CollisionManager& collisionManager)
{

	for (int i = 0; i < m_Num; i++)
	{
		BulletBoss* bulletB = new BulletBoss();
		bulletB->Init();
		bulletB->getHitbox()->setAlive(false);
		m_listBullet.push_back(bulletB);
		collisionManager.addObj(bulletB->getHitbox());
	}
}

void BossWeapon::Update(float deltaTime)
{
	for (auto it : m_listBullet)
	{
		it->Update(deltaTime);
	}
}

void BossWeapon::Render(sf::RenderWindow* window)
{
	for (auto it : m_listBullet)
	{
		it->Render(window);
	}
}

void BossWeapon::Fire(sf::Vector2f startPoint) {
	BulletBoss* bulletB = nullptr;
	for (auto it : m_listBullet)
	{
		if (!it->getHitbox()->getAlive() && it->getStop())
		{
			bulletB = it;
			break;
		}
	}
	if (bulletB == nullptr) return;
	bulletB->getHitbox()->setAlive(true);
	bulletB->setStartPoint(startPoint);
	bulletB->Reset();
}

