#include "Player.h"
#include "PSRun.h"
#include "PSAttack.h"
#include "PSDeath.h"
#include "PSFall.h"
#include "PSJump.h"
#include "PSAttackJump.h"
Player::Player()
{
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_fallState = new PSFall(this);
	m_attackState = new PSAttack(this);
	m_deathState = new PSDeath(this);
	m_jumpState = new PSJump(this);
	m_attackJumpState = new  PSAttackJump(this);
	m_currentState = m_runState;
	m_playerWeapon = new PlayerWeapon();
}

Player::~Player()
{
	if (m_runState != nullptr)
		delete m_runState;
	if (m_attackState != nullptr)
		delete m_attackState;
	if (m_deathState != nullptr)
		delete m_deathState;
	if (m_fallState != nullptr)
		delete m_fallState;
	if (m_jumpState != nullptr)
		delete m_jumpState;
	if (m_attackJumpState != nullptr)
		delete m_attackJumpState;
	if (m_playerWeapon != nullptr)
		delete m_playerWeapon;
	m_currentState = nullptr;
}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::prevState(IPState::STATE prevState)
{
	m_prevState=prevState;
}

IPState::STATE Player::getPrevState()
{
	return m_prevState;
}

IPState* Player::getCurrentState()
{
	return m_currentState;
}

void Player::Init(CollisionManager& collisionManager)
{
	m_runState->Init();
	m_fallState->Init();
	m_attackState->Init();
	m_deathState->Init();
	m_jumpState->Init();
	m_attackJumpState->Init();
	m_hitBox = new HitBox(sf::Vector2i(15, 30));
	m_hitBox->setPosition(screenWidth / 2, groundY);
	//init(toc do x 200 y 500)
	m_hitBox->Init(sf::Vector2f(200, 500));
	m_hitBox->setTag(PLAYER);

	collisionManager.addObj(m_hitBox);
	m_playerWeapon->Init(collisionManager);
}

void Player::Update(float deltaTime)
{
	performState();
	m_playerWeapon->Update(deltaTime);
	m_currentState->Update(deltaTime);

}

void Player::Render(sf::RenderWindow* window)
{
	m_playerWeapon->Render(window);
	m_currentState->Render(window);
	window->draw(*m_hitBox);
}

PlayerWeapon* Player::getPlayerWeapon()
{
	return m_playerWeapon;
}

HitBox* Player::getHitBox()
{
	return m_hitBox;
}

void Player::performState()
{
	if (m_nextState != IPState::SNULL)
	{
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IPState::DEATH:
			m_currentState = m_deathState;
			break;
		case IPState::FALL:
			m_currentState = m_fallState;
			break;
		case IPState::JUMP:
			m_currentState = m_jumpState;
			break;
		case IPState::ATTACKJUMP:
			m_currentState = m_attackJumpState;
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}


}
