#include "PSJump.h"
PSJump::PSJump(IPlayer* player)
{
	m_player = player;
}

void PSJump::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path + "Jump"), sf::Vector2i(4, 1), 0.1f);
	m_animation->setModeAtEndFrame(true);
	m_currentTime = 0.f;
}

void PSJump::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
	m_currentTime += deltaTime;
	//std::cout << m_player->getHitBox()->getVelogcity().y <<"\n";
	float g = 10; 
	//v=g*t
	float v = g * m_currentTime;
	/*0.016468 / 0.832*/
	if (-m_player->getHitBox()->getVelogcity().y * deltaTime+v>=0)
	{
		m_player->changeNextState(STATE::FALL);
		m_currentTime = 0;
	}
	else m_player->getHitBox()->move(0,-m_player->getHitBox()->getVelogcity().y * deltaTime+v);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_player->getHitBox()->move(-m_player->getHitBox()->getVelogcity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_player->getHitBox()->move(m_player->getHitBox()->getVelogcity().x * deltaTime, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		m_player->prevState(IPState::JUMP);
		m_player->changeNextState(IPState::ATTACKJUMP);
	}
	if (!m_player->getHitBox()->getAlive())
	{
		m_player->changeNextState(IPState::FALL);
	}
	m_animation->setPosition(m_player->getHitBox()->getPosition());
	
}

void PSJump::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void PSJump::Reset()
{
	m_currentTime = 0.f;
	m_animation->Reset();
}


