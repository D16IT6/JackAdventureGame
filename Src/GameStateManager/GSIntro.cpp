#include "GSIntro.h"

GSIntro::GSIntro()
{
    currentTime = 0.f;
}

GSIntro::~GSIntro()
{
}

void GSIntro::Exit()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Init()
{
    sf::Texture* texture = Data->getTexture("Logo");
    m_Logo.setTexture(*texture);
    m_Logo.setPosition(screenWidth / 2, screenHeigth / 2);
    m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
}

void GSIntro::Update(float deltaTime)
{
    currentTime += deltaTime;
    if (currentTime > 0.f)
    {
        GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
    }
}

void GSIntro::Render(sf::RenderWindow* renderWindow)
{
    renderWindow->draw(m_Logo);
}


