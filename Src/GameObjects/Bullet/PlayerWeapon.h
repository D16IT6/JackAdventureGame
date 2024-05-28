
#pragma once
#include"../../GameManager/ResourceManager.h"
#include"BulletPlayer.h"
#include"../Collision/CollisionManager.h"
class PlayerWeapon
{
public:
	PlayerWeapon();
	~PlayerWeapon();
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Fire(sf::Vector2f startPoint);
private:
	std::list<BulletPlayer*> m_listBullet;
	int m_Num;
};
