#include "BulletPlayer.h"

BulletPlayer::BulletPlayer()
{
	m_stop = true;
}

BulletPlayer::~BulletPlayer()
{
	m_currentAni = nullptr;
	if (m_DeathAni != nullptr)
		delete m_DeathAni;
	if (m_RunAni != nullptr)
		delete m_RunAni;
}

void BulletPlayer::Init()
{
	m_hitbox = new HitBox(sf::Vector2i(35, 25));
	m_hitbox->Init(sf::Vector2f(300, 0));
	m_hitbox->setPosition(screenWidth, groundY - 200);
	std::string pathBoss = "Character/";
	m_RunAni = new Animation(*Data->getTexture(pathBoss + "ArrowSpit"), sf::Vector2i(1, 1), 0.1f);
	m_DeathAni = new Animation(*Data->getTexture(pathBoss + "ArrowImpact"), sf::Vector2i(5, 1), 0.1f);
	m_currentAni = m_RunAni;
	m_hitbox->setTag(Tag::BULLETPLAYER);
}

void BulletPlayer::Update(float deltaTime)
{
	if (m_stop) return;
	if (m_hitbox->getAlive())
	{
		m_currentAni->Update(deltaTime);
		m_hitbox->move(this->getHitbox()->getVelogcity().x * deltaTime, 0);
		m_currentAni->setPosition(this->getHitbox()->getPosition());
		if (m_currentAni->getPosition().x >screenWidth+20)
		{
			/*m_hitbox->setPosition(m_startPoint);*/
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

void BulletPlayer::Render(sf::RenderWindow* window)
{
	if (m_stop) return;
	window->draw(*m_currentAni);
	window->draw(*m_hitbox);
}

void BulletPlayer::Reset()
{
	m_stop = false;
	m_DeathAni->Reset();
	m_RunAni->Reset();
	m_currentAni = m_RunAni;
	m_hitbox->setPosition(m_startPoint);
}
