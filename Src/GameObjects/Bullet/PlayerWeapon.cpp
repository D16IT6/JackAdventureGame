#include "PlayerWeapon.h"
PlayerWeapon::PlayerWeapon()
{
	m_Num = 5;
}

PlayerWeapon::~PlayerWeapon()
{
	for (auto it : m_listBullet)
		if (it != nullptr)
			delete it;
	m_listBullet.clear();

}

void PlayerWeapon::Init(CollisionManager& collisionManager)
{

	for (int i = 0; i < m_Num; i++)
	{
		BulletPlayer* bulletB = new BulletPlayer();
		bulletB->Init();
		bulletB->getHitbox()->setAlive(false);
		m_listBullet.push_back(bulletB);
		collisionManager.addObj(bulletB->getHitbox());
	}
}

void PlayerWeapon::Update(float deltaTime)
{
	for (auto it : m_listBullet)
	{
		it->Update(deltaTime);
	}
}

void PlayerWeapon::Render(sf::RenderWindow* window)
{
	for (auto it : m_listBullet)
	{
		it->Render(window);
	}
}

void PlayerWeapon::Fire(sf::Vector2f startPoint) {
	BulletPlayer* bulletP = nullptr;
	for (auto it : m_listBullet)
	{
		if (!it->getHitbox()->getAlive() && it->getStop())
		{
			bulletP = it;
			break;
		}
	}
	if (bulletP == nullptr) return;
	bulletP->getHitbox()->setAlive(true);
	bulletP->setStartPoint(startPoint);
	bulletP->Reset();
}

