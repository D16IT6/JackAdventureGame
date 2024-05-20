#include "GSSetting.h"

GSSettings::GSSettings()
{
}

GSSettings::~GSSettings()
{
}

void GSSettings::Exit()
{
}

void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}

void GSSettings::Init()
{
	//Background
	sf::Texture* textureBG = new sf::Texture();
	textureBG = Data->getTexture("Background layers/Background");
	m_background.setTexture(*textureBG);
	m_background.setPosition(screenWidth / 2, screenHeigth - textureBG->getSize().y / 2);
	m_background.setOrigin((sf::Vector2f)textureBG->getSize() / 2.f);
	
	//title
	m_title.setString("SETTING");
	m_title.setFont(*Data->getFont("Sakana"));
	
	m_title.setPosition(screenWidth / 2, screenHeigth / 10);
	sf::FloatRect titleBounds = m_title.getGlobalBounds();
	// Đặt gốc nằm chính giữa
	m_title.setOrigin(titleBounds.width / 2, titleBounds.height / 2);
	float scale = 1.5f; // Tỷ lệ 1.5 lần kích thước ban đầu
	m_title.setScale(scale, scale);


	//Exit
	GameButton* exitButton = new GameButton();
	exitButton->Init("close_2");
	exitButton->setOnclick([]() {GSM->PopState(); });
	exitButton->setPosition(screenWidth  - screenWidth / 20, screenHeigth /15);
	exitButton->setSize(sf::Vector2f(50, 50));
	exitButton->setOrigin(exitButton->getSize() / 2.f);
	m_listButton.push_back(exitButton);
}

void GSSettings::Update(float deltaTime)
{
	for (auto button : m_listButton)
	{
		button->Update(deltaTime);
	}
}

void GSSettings::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(m_background);
	renderWindow->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(renderWindow);
	}
}
