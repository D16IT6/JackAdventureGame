#include "PSFall.h"

PSFall::PSFall(IPlayer* player)
{
	m_player = player;
}

void PSFall::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path + "Fall"), sf::Vector2i(2, 1), 0.1f);
	m_animation->setModeAtEndFrame(true);
	m_currentTime = 0.f;
}

void PSFall::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	float g = 10;
	//v=g*t
	float v = g * m_currentTime;
	if (m_player->getHitBox()->getPosition().y >= groundY-10)
	{
		if (!m_player->getHitBox()->getAlive())
		{
			m_player->changeNextState(IPState::DEATH);
		}
		else
		{
			m_player->changeNextState(STATE::RUN);
		}
		m_currentTime = 0;
	}
	m_player->getHitBox()->move(0,  v);
	if (m_player->getHitBox()->getAlive())
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_player->getHitBox()->move(-m_player->getHitBox()->getVelogcity().x * deltaTime, 0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_player->getHitBox()->move(m_player->getHitBox()->getVelogcity().x * deltaTime, 0);
		}
	}
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSFall::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void PSFall::Reset()
{
	m_currentTime = 0.f;
	m_animation->Reset();
}

