#include "GameButton.h"

GameButton::GameButton()
{
	m_isHandling = false;
}

GameButton::~GameButton()
{
}

void GameButton::Init(std::string name)
{
	this->setTexture(Data->getTexture(m_pathButton + name));
	this->setSize(sf::Vector2f(100, 100));
}

void GameButton::Update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		HandleTouchEvent();
	}
}

void GameButton::Render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::HandleTouchEvent()
{
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WConnect->getWindow()))){
		m_btnClickFunc();
		m_isHandling=true;
	}
}

bool GameButton::isHandle()
{
	return m_isHandling;
}

void GameButton::setOnclick(void(*clickFunc)())
{
	m_btnClickFunc = clickFunc;
}
