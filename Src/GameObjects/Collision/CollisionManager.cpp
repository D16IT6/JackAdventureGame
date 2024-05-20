#include "CollisionManager.h"

void CollisionManager::addObj(HitBox* hitbox)
{
	m_listObj.push_back(hitbox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
	//Kiem tra co giao nhau hay khong
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::Update()
{
	for (auto a : m_listObj)
	{
		if (!a->getAlive()) continue;
		for (auto b : m_listObj)
		{
			if (!b->getAlive()) continue;
			if (a->getTag() == b->getTag()) continue;
			if (!checkCollision(a, b)) continue;
			if (a->getTag() == PLAYER)
			{
				if (b->getTag() == CREEP)
				{
					a->setAlive(false);
					b->setAlive(false);
				}

				else if (b->getTag() == BOSS) {
					a->setAlive(false);
				}
			}
			if (a->getTag() == BOSS && b->getTag() == CREEP)
			{
				b->setAlive(false);
			}

		}
	}
}
