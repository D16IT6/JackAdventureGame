#pragma once
#include "../../GameManager/ResourceManager.h"
#include"../../GameStateManager/GameStateMachine.h"
#include"../../GameObjects/Bullet/PlayerWeapon.h"
class IPState
{
public:
	enum STATE
	{
		RUN,
		JUMP,
		FALL,
		DEATH,
		ATTACK,
		ATTACKJUMP,
		SNULL
	};
	virtual void Init()=0;
	virtual void Update(float deltaTime)=0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset()=0;
};

