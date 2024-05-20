#include "PSAttack.h"

PSAttack::PSAttack(IPlayer* player)
{
	m_player = player;
}

void PSAttack::Init()
{
	std::string path = "Character/";
	m_animation = new Animation(*Data->getTexture(path + "Attack"), sf::Vector2i(8, 1), 0.1f);
}

void PSAttack::Update(float deltaTime)
{
	m_animation->Update(deltaTime);
}

void PSAttack::Render(sf::RenderWindow* window)
{
	window->draw(*m_animation);
}

void PSAttack::Reset()
{
	m_animation->Reset();
}



