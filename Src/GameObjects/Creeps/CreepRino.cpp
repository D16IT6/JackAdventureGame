#include "CreepRino.h"

void CreepRino::Init()
{
	m_hitbox = new HitBox(sf::Vector2i(45, 28));
	m_hitbox->Init(sf::Vector2f(200, 0));
	m_hitbox->setPosition(screenWidth+100, groundY);
	m_startPoint = sf::Vector2f(screenWidth, groundY);
	std::string pathRino = "Rino/";
	m_RunAni = new Animation(*Data->getTexture(pathRino + "Run (52x34)"), sf::Vector2i(6, 1), 0.1f);
	m_DeathAni = new Animation(*Data->getTexture(pathRino + "Hit (52x34)"), sf::Vector2i(5, 1), 0.1f);
	m_currentAni = m_RunAni;
	m_hitbox->setTag(Tag::CREEP);
}
