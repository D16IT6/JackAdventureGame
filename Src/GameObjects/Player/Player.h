#pragma once
#include"IPlayer.h"

class Player : public IPlayer 
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);
	void prevState(IPState::STATE prevState);
	IPState::STATE getPrevState() ;
	IPState* getCurrentState() ;
	void Init(CollisionManager& collisionManager);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	PlayerWeapon* getPlayerWeapon();
	HitBox* getHitBox();
private:
	void performState();
	HitBox* m_hitBox;
	IPState::STATE m_prevState;
	IPState::STATE m_nextState;
	IPState* m_currentState;
	IPState* m_runState;
	IPState* m_fallState;
	IPState* m_attackState;
	IPState* m_deathState;
	IPState* m_jumpState;
	IPState* m_attackJumpState;
	PlayerWeapon* m_playerWeapon;
};
