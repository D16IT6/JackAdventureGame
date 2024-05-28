#include "BulletBoss.h"

BulletBoss::BulletBoss()
{
	m_stop = true;
}

BulletBoss::~BulletBoss()
{
	m_currentAni = nullptr;
	if (m_DeathAni != nullptr)
		delete m_DeathAni;
	if (m_RunAni != nullptr)
		delete m_RunAni;
}

void BulletBoss::Init()
{
	m_hitbox = new HitBox(sf::Vector2i(35, 25));
	m_hitbox->Init(sf::Vector2f(300, 0));
	m_hitbox->setPosition(screenWidth, groundY - 200);
	std::string pathBoss = "Boss1/";
	m_RunAni = new Animation2d(*Data->getTexture(pathBoss + "poison-spit"), sf::Vector2i(4, 3), 0.1f,12);
	m_DeathAni = new Animation2d(*Data->getTexture(pathBoss + "poison-impact"), sf::Vector2i(4, 3), 0.1f,12);
	m_currentAni = m_RunAni;
	m_hitbox->setTag(Tag::BULLETBOSS);
}

void BulletBoss::Update(float deltaTime)
{
	if (m_stop) return;
	if (m_hitbox->getAlive())
	{
		m_currentAni->Update(deltaTime);
		m_hitbox->move(this->getHitbox()->getVelogcity().x * deltaTime, 0);
		m_currentAni->setPosition(this->getHitbox()->getPosition());
		if (m_currentAni->getPosition().x <= -50)
		{
			m_hitbox->setPosition(m_startPoint);
			m_stop = true;
			m_hitbox->setAlive(false);
		}

	}
	else
	{
		if (!m_soundIsPlaying)
		{
			Data->playSound("impactsplat03");
			m_soundIsPlaying = true;
		}
		m_currentAni = m_DeathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(this->getHitbox()->getPosition());
		}
		else m_stop = true;
	}

}

void BulletBoss::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
	window->draw(*m_hitbox);
}

void BulletBoss::Reset()
{
	m_stop = false;
	m_soundIsPlaying = false;
	m_DeathAni->Reset();
	m_RunAni->Reset();
	m_currentAni = m_RunAni;
	m_hitbox->setPosition(m_startPoint);
}
