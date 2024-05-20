#include "Boss.h"
#include "BSAttack.h"
#include "BSJump.h"
#include "BSJumpbite.h"
Boss::Boss()
{
	 m_nextState=IBState::SNULL;
	
	 m_jumpState = new BSJump(this);
	 m_jumpbiteState = new BSJumpbite(this);
	 m_attackState = new BSAttack(this);
	 m_currentState=m_jumpState;
}

Boss::~Boss()
{
	if (m_jumpbiteState != nullptr)
		delete m_jumpbiteState;
	if (m_attackState != nullptr)
		delete m_attackState;
	if (m_jumpState != nullptr)
		delete m_jumpState;
	m_currentState = nullptr;
}

void Boss::changeNextState(IBState::STATE nextState)
{
	m_nextState = nextState;
}

void Boss::Init()
{
	m_jumpbiteState->Init();
	m_attackState->Init();;
	m_jumpState->Init();
	m_hitBox = new HitBox(sf::Vector2i(304-100, 246-50));
	m_hitBox->setPosition(100, groundY-(m_hitBox->getSize().y/2)+20);
	m_hitBox->Init(sf::Vector2f(100,0));
	m_hitBox->setTag(BOSS);
}

void Boss::Update(float deltaTime)
{
	performState();
	m_currentState->Update(deltaTime);
}

void Boss::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	window->draw(*m_hitBox);
}

HitBox* Boss::getHitBox()
{
	return m_hitBox;
}

void Boss::performState()
{
	if (m_nextState != IBState::SNULL)
	{
	switch (m_nextState)
		{
		case IBState::JUMPBITE:
			m_currentState = m_jumpbiteState;
				break;
		case IBState::ATTACK:
			m_currentState = m_attackState;
			break;
		case IBState::JUMP:
			m_currentState = m_jumpState;
			break;
		default:
			break;
		}
	m_nextState = IBState::SNULL;
	m_currentState->Reset();
	}
}
