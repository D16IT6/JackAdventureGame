#include "Layer.h"
void Layer::Init(std::string name, float speed)
{
	sf::Texture* texture = Data->getTexture(name);
	m_image1.setTexture(*texture);
	m_image2.setTexture(*texture);	
	m_size = (sf::Vector2i)texture->getSize();

	m_image1.setPosition(screenWidth/2, screenHeigth - m_size.y / 2);
	m_image1.setOrigin((sf::Vector2f)m_size / 2.f);

	m_image2.setPosition(m_size.x * 1.5f,  m_image1.getPosition().y);
	m_image2.setOrigin((sf::Vector2f)m_size/ 2.f);
	m_speed = speed;

}

void Layer::Update(float deltaTime)
{
	
	m_image1.move(-m_speed * deltaTime, 0);
	m_image2.move(-m_speed * deltaTime, 0);
	if (m_image2.getPosition().x <= screenWidth / 2)
	{
		m_image1.setPosition(screenWidth / 2, screenHeigth - m_size.y / 2);
		m_image2.setPosition(m_size.x * 1.5f, m_image1.getPosition().y);
	}
}

void Layer::Render(sf::RenderWindow * window)
{
	window->draw(m_image1);
	window->draw(m_image2);
}
