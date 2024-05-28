#pragma once
#include "../../GameManager/ResourceManager.h"
#include"../../GameStateManager/GameStateMachine.h"
#include"../../GameObjects/Bullet/BossWeapon.h"
class IBState
{
public:
	enum STATE
	{
		JUMP,
		JUMPBITE,
		ATTACK,
		SNULL
	};
	virtual void Init()=0;
	virtual void Update(float deltaTime)=0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset()=0;
};

