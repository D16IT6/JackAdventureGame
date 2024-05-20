#include "PSDeath.h"

PSDeath::PSDeath(IPlayer* player)
{
	m_player = player;
	m_timeRemain = 3.0f;
}

void PSDeath::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path + "Death"), sf::Vector2i(24, 1), 0.1f);
	m_animation->setModeAtEndFrame(true);
}

void PSDeath::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_animation->setPosition(m_player->getHitBox()->getPosition());
	/*m_currentTime += deltaTime;
	if (m_currentTime > m_timeRemain)
	{
		GSM->PopState();
	}*/
}

void PSDeath::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void PSDeath::Reset()
{
		m_currentTime = 0.f;
		m_animation->Reset();
}

