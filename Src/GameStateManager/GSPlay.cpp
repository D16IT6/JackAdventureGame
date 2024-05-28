#include "GSPlay.h"

GSPlay::GSPlay()
{
	m_currentScore = 0;
	m_currentTime = 0.f;
}

GSPlay::~GSPlay()
{
}

void GSPlay::Exit()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Init()
{
	m_background.Init(100);
	m_player.Init(m_collisionManager);
	m_boss.Init(m_collisionManager);
	m_collisionManager.addObj(m_boss.getHitBox());

	m_CreepManager.Init(m_collisionManager);

	m_currentTextScore.setFont(*Data->getFont("Sakana"));
	m_currentTextScore.setPosition(50, 50);
	m_currentTextScore.setFillColor(sf::Color::White);
	m_currentTextScore.setString("0");
	Data->playMusic("Uprising");
	Data->getMusic("Uprising")->setLoop(true);
	Data->getMusic("Uprising")->setVolume(30);

}

void GSPlay::Update(float deltaTime)
{
	
	if (m_player.getHitBox()->getAlive())
	{
		m_background.Update(deltaTime);

		m_currentTime += deltaTime;
		if (m_currentTime >= 0.5f)
		{
			m_currentScore++;
			m_currentTextScore.setString(std::to_string(m_currentScore));
			m_currentTime -= 0.5f;
		}
	}
	else
	{
		SCOREMANAGER->setCurrentScore(m_currentScore);
	}
	m_player.Update(deltaTime);
	m_boss.Update(deltaTime);
	m_CreepManager.Update(deltaTime);
	m_collisionManager.Update();

}

void GSPlay::Render(sf::RenderWindow* renderWindow)
{
	m_background.Render(renderWindow);
	m_boss.Render(renderWindow);
	m_player.Render(renderWindow);
	m_CreepManager.Render(renderWindow);
	renderWindow->draw(m_currentTextScore);
}

