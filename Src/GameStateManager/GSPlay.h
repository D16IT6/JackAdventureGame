#pragma once
#pragma once
#include "GameStateBase.h"
#include "../GameObjects/ParallelBackground/ParallelBackground.h"
#include "../GameObjects/Player/Player.h"
#include "../GameObjects/Creeps/CreepManager.h"
#include "../GameObjects/Collision/CollisionManager.h"
#include "../GameObjects/Boss/Boss.h"
class GSPlay :public GameStateBase
{
public:
	GSPlay();
	~GSPlay();
	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* renderWindow);
private:
	ParallelBackground m_background;
	Player m_player;
	CreepManager m_CreepManager;
	CollisionManager m_collisionManager;
	Boss m_boss;
};