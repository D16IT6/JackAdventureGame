#pragma once
#include"IPState.h"
#include "IPlayer.h"
class PSAttackJump : public IPState
{
public:
	PSAttackJump (IPlayer* player);
	~PSAttackJump ();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPlayer* m_player;
	float m_currentTime;

	Animation* m_currentAnimation;
	Animation* m_animationFall;
	Animation* m_animationAttack;

};

