#pragma once
#include"IBState.h"
#include"IBoss.h"

class BSJumpbite: public IBState
{
public:
	BSJumpbite(IBoss* boss);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();
private:
	IBoss* m_boss;
	Animation* m_animation;
	float m_currentTime;
	float m_changeTime;
};
