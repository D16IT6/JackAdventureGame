#include "BSJumpbite.h"

BSJumpbite::BSJumpbite(IBoss* boss)
{
	m_boss = boss;
}

void BSJumpbite::Init()
{
	std::string path = "Boss1/";
	m_animation = new Animation2d(*Data->getTexture(path+"jump-cycle-bite-attack"), sf::Vector2i(6,3), 0.1f,17);
	m_currentTime = 0.f;
	m_changeTime = 3.f;
}

void BSJumpbite::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation2d* ani = (Animation2d*)m_animation;
	if (m_currentTime > m_changeTime && (ani->getFrameTotals() - 1 == ani->getCurrentFrameCount()))
	{
		int lunkyState = rand() % 2;
		switch (lunkyState)
		{
		case 0:
			m_boss->changeNextState(STATE::ATTACK);
			break;
		case 1:
			m_boss->changeNextState(STATE::JUMP);
			break;
		default:
			break;
		}
	}
	if (m_boss->getHitBox()->getPosition().x < 300) {
		m_boss->getHitBox()->move(200 * deltaTime, 0);
	}
	m_animation->setPosition(m_boss->getHitBox()->getPosition());
}

void BSJumpbite::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}


void BSJumpbite::Reset()
{
	m_animation->Reset();
	m_currentTime = 0.f;
}

