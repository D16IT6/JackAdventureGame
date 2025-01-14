#include "HitBox.h"

HitBox::HitBox(sf::Vector2i size):RectangleShape(sf::Vector2f(size))
{
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setFillColor(sf::Color(0, 0, 0, 0));
	/*this->setOutlineThickness(1);
	this->setOutlineColor(sf::Color::Red);*/
	m_velogcity = sf::Vector2f(0, 0);
	m_isAlive = true;
}

HitBox::~HitBox()
{
}

void HitBox::Init(sf::Vector2f velogcity)
{
	m_velogcity = velogcity;
}

sf::Vector2f HitBox::getVelogcity()
{
	return m_velogcity;
}
