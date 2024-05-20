#include "BSAttack.h"

BSAttack::BSAttack(IBoss* boss)
{
	m_boss = boss;
}

void BSAttack::Init()
{
	std::string path = "Boss1/";
	m_animation = new Animation2d(*Data->getTexture(path + "poison-attack"), sf::Vector2i(6, 3), 0.1f,17);
	m_currentTime = 0.f;
	m_changeTime = 3.f;
}

void BSAttack::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	sf::Vector2f pos = m_boss->getHitBox()->getPosition();
	pos.y += 27;
	m_currentTime += deltaTime;
	Animation2d* ani = (Animation2d*)m_animation;
	if (m_currentTime > m_changeTime && (ani->getFrameTotals() - 1 == ani->getCurrentFrameCount()))
	{
			m_boss->changeNextState(STATE::JUMPBITE);
	}
	if (m_boss->getHitBox()->getPosition().x >100)
	{
		m_boss->getHitBox()->move(-100 * deltaTime, 0);
	}
	m_animation->setPosition(pos);
}

void BSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void BSAttack::Reset()
{
	m_animation->Reset();
	m_currentTime = 0.f;
}



