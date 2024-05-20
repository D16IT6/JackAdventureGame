#include "BSJump.h"

BSJump::BSJump(IBoss* boss)
{
	m_boss = boss;
}

void BSJump::Init()
{
	std::string path = "Boss1/";
	m_animation = new Animation2d(*Data->getTexture(path + "jump-cycle"), sf::Vector2i(6, 3), 0.1f,17);
	m_currentTime = 0.f;
	m_changeTime = 3.f;
}

void BSJump::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	Animation2d * ani = (Animation2d*)m_animation;
	if (m_currentTime > m_changeTime&& (ani->getFrameTotals() - 1 == ani->getCurrentFrameCount()))
	{
		int lunkyState = rand() % 2;
		switch (lunkyState)
		{
		case 0:
			m_boss->changeNextState(STATE::ATTACK);
			break;
		case 1:
			m_boss->changeNextState(STATE::JUMPBITE);
			break;
		default:
			break;
		}
	}

	m_animation->setPosition(m_boss->getHitBox()->getPosition());
}

void BSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void BSJump::Reset()
{
	m_animation->Reset();
	m_currentTime = 0.f;
}

