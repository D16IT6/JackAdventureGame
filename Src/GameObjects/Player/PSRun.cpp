#include "PSRun.h"

PSRun::PSRun(IPlayer* player)
{
	m_player = player;
}

void PSRun::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path+"Run"), sf::Vector2i(8,1), 0.1f);
}

void PSRun::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player->changeNextState(JUMP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player->getHitBox()->move(-m_player->getHitBox()->getVelogcity().x*deltaTime,0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player->getHitBox()->move(m_player->getHitBox()->getVelogcity().x*deltaTime, 0);
	}
	if (!m_player->getHitBox()->getAlive())
	{
		m_player->changeNextState(IPState::DEATH);
	}
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSRun::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}


void PSRun::Reset()
{
	m_animation->Reset();
}
