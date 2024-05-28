#include "PSAttackJump.h"

PSAttackJump::PSAttackJump(IPlayer* player)
{
	m_player = player;
}

void PSAttackJump::Init()
{
	std::string path = "Character/";
	m_animationAttack = new Animation(*Data->getTexture(path + "Attack"), sf::Vector2i(14, 1), 0.05f);
	m_animationFall = new Animation(*Data->getTexture(path + "Fall"), sf::Vector2i(2, 1), 0.1f);
	m_currentAnimation = m_animationAttack;
	m_currentAnimation->setModeAtEndFrame(true);
}

void PSAttackJump::Update(float deltaTime)
{
	m_currentAnimation->Update(deltaTime);
	m_currentTime += deltaTime;
	float g = 10;
	//v=g*t
	float v = g * m_currentTime;
	if (m_currentAnimation->getCurrentFrame().x == m_currentAnimation->getFrameNum().x - 1&&m_currentAnimation==m_animationAttack)
	{
		sf::Vector2f pos = m_player->getHitBox()->getPosition();
		m_player->getPlayerWeapon()->Fire(pos);
		m_currentAnimation = m_animationFall;
		m_currentAnimation->setModeAtEndFrame(true);
	}

	m_player->getHitBox()->move(0, v);

	if (m_player->getHitBox()->getPosition().y > groundY - 10)
	{
		if (!m_player->getHitBox()->getAlive())
		{
			m_player->changeNextState(IPState::DEATH);
		}
		else
		{
			m_player->changeNextState(STATE::RUN);
		}
		m_currentTime = 0.f;
	}
	
	m_currentAnimation->setPosition(m_player->getHitBox()->getPosition());
}

void PSAttackJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_currentAnimation);
}


void PSAttackJump::Reset()
{
	m_currentAnimation = m_animationAttack;
	m_currentAnimation->setModeAtEndFrame(true);
	m_currentAnimation->Reset();
	m_currentTime = 0.f;
}



