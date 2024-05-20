#pragma once
#include"../Component/HitBox.h"
class CollisionManager
{
public:
	void addObj(HitBox* hitbox);
	bool checkCollision(HitBox* a, HitBox* b);
	void Update();
private:
	std::list<HitBox*> m_listObj;

};
