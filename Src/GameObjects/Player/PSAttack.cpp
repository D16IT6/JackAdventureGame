#include "PSAttack.h"
PSAttack::PSAttack(IPlayer* player)
{
	m_player = player;
}

void PSAttack::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path + "Attack"), sf::Vector2i(14, 1), 0.05f);
	m_animation->setModeAtEndFrame(true);
	m_currentTime = 0.f;
}

void PSAttack::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	sf::Vector2f pos=m_player->getHitBox()->getPosition();

	m_currentTime += deltaTime;
	float g = 10;
	//v=g*t
	if (m_animation->getCurrentFrame().x == m_animation->getFrameNum().x - 1)
	{
		m_player->getPlayerWeapon()->Fire(pos);
		m_player->changeNextState(RUN);
	}
	m_animation->setPosition(m_player->getHitBox()->getPosition());
}

void PSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void PSAttack::Reset()
{
	m_animation->Reset();
	m_currentTime = 0.f;
}



