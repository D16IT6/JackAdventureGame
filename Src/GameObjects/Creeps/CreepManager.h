#pragma once
#include"../../GameManager/ResourceManager.h"
#include"CreepBat.h"
#include"CreepRino.h"
#include"../Collision/CollisionManager.h"
class CreepManager
{
public:
	CreepManager();
	~CreepManager();
	 void Init(CollisionManager& collisionManager);
	 void Update(float deltaTime);
	 void Render(sf::RenderWindow* window);
private:
	void SpwanRino();
	void SpwanBat();
	std::list<CreepBat*> m_listCreepBat;
	std::list<CreepRino*> m_listCreepRino;
	int m_creepNum;
	float m_currentTime;
	float m_timeSpwanCreep;
	
};
