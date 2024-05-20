#include "GSPlay.h"

GSPlay::GSPlay()
{
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
	m_player.Init();
	m_collisionManager.addObj(m_player.getHitBox());

	m_boss.Init();
	m_collisionManager.addObj(m_boss.getHitBox());

	m_CreepManager.Init(m_collisionManager);
}

void GSPlay::Update(float deltaTime)
{
	
	if (m_player.getHitBox()->getAlive())
	{
		m_background.Update(deltaTime);
		
	}
	m_boss.Update(deltaTime);
	m_player.Update(deltaTime);
	m_CreepManager.Update(deltaTime);
	m_collisionManager.Update();
}

void GSPlay::Render(sf::RenderWindow* renderWindow)
{
	m_background.Render(renderWindow);
	m_boss.Render(renderWindow);
	m_player.Render(renderWindow);
	m_CreepManager.Render(renderWindow);
}

