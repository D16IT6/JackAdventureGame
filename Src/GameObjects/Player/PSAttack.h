#pragma once
#include"IPState.h"
#include"IPlayer.h"

class PSAttack : public IPState
{
public:
	PSAttack(IPlayer* player);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IPlayer* m_player;
	Animation* m_animation;
	float m_currentTime;
};
