#pragma once
#include"IBoss.h"

class Boss : public IBoss
{
public:
	Boss();
	~Boss();
	void changeNextState(IBState::STATE nextState);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
private:
	void performState();
	HitBox* m_hitBox;
	IBState::STATE m_nextState;
	IBState* m_currentState;
	IBState* m_jumpbiteState;
	IBState* m_attackState;
	IBState* m_jumpState;
};
