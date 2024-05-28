#pragma once
#include"../../GameManager/ResourceManager.h"
#include"BulletBoss.h"
#include"../Collision/CollisionManager.h"
class BossWeapon
{
public:
	BossWeapon();
	~BossWeapon();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Fire(sf::Vector2f startPoint);
private:
	std::list<BulletBoss*> m_listBullet;
	int m_Num;
};
