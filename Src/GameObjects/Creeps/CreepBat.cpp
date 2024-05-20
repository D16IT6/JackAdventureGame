#include "CreepBat.h"

void CreepBat::Init()
{
	m_hitbox = new HitBox(sf::Vector2i(35, 25));
	m_hitbox->Init(sf::Vector2f(300, 0));
	m_hitbox->setPosition(screenWidth, groundY-200);
	m_startPoint = sf::Vector2f(screenWidth+100, groundY-200);
	std::string pathBat = "Bat/";
	m_RunAni = new Animation(*Data->getTexture(pathBat + "Flying (46x30)"), sf::Vector2i(7, 1), 0.1f);
	m_DeathAni = new Animation(*Data->getTexture(pathBat + "Hit (46x30)"), sf::Vector2i(5, 1), 0.1f);
	m_currentAni = m_RunAni;
	m_hitbox->setTag(Tag::CREEP);
}
