#include "GSIntro.h"
#include <fstream>
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
    std::fstream input("texture.txt", std::ios::in);
    std::string name;
    getline(input, name);
    Data->addTextture(name);
    input.close();
    sf::Texture* texture = Data->getTexture("Logo");
    m_Logo.setTexture(*texture);
    m_Logo.setPosition(screenWidth / 2, screenHeigth / 2);
    m_Logo.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
}

void GSIntro::Update(float deltaTime)
{
    currentTime += deltaTime;
    if (currentTime > 2.f)
    {
        GameStateMachine::GetInstance()->ChangeState(StateTypes::MENU);
    }
}

void GSIntro::Render(sf::RenderWindow* renderWindow)
{
    renderWindow->draw(m_Logo);
}


