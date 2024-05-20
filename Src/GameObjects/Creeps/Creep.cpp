#include "Creep.h"

Creep::Creep()
{
	m_stop = true;
}

Creep::~Creep()
{
	m_currentAni = nullptr;
	if (m_DeathAni != nullptr)
		delete m_DeathAni;
	if (m_RunAni != nullptr)
		delete m_RunAni;
}

void Creep::Init()
{
	m_hitbox = new HitBox(sf::Vector2i(45, 28));
	m_hitbox->Init(sf::Vector2f(200, 0));
	m_hitbox->setPosition(screenWidth, groundY);
	std::string pathRino = "Rino/";
	m_RunAni = new Animation(*Data->getTexture(pathRino + "Run (52x34)"), sf::Vector2i(6, 1), 0.1f);
	m_DeathAni = new Animation(*Data->getTexture(pathRino + "Hit (52x34)"), sf::Vector2i(5, 1), 0.1f);
	m_currentAni = m_RunAni;
}

void Creep::Update(float deltaTime)
{
	if (m_stop) return;
	if (m_hitbox->getAlive())
	{
		m_currentAni->Update(deltaTime);
		m_hitbox->move(-this->getHitbox()->getVelogcity().x * deltaTime, 0);
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
		m_currentAni = m_DeathAni;
		if (m_currentAni->getCurrentFrame().x != m_currentAni->getFrameNum().x - 1)
		{
			m_currentAni->Update(deltaTime);
			m_currentAni->setPosition(this->getHitbox()->getPosition());
		}
		else m_stop = true;
	}
	
}

void Creep::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
	window->draw(*m_hitbox);
}

void Creep::Reset()
{
	m_stop = false;
	m_DeathAni->Reset();
	m_RunAni->Reset();
	m_currentAni = m_RunAni;
	m_hitbox->setPosition(m_startPoint);
}
