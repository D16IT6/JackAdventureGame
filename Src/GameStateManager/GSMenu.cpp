#include "GSMenu.h"
#include "GameStateMachine.h"
#include<iostream>
GSMenu::GSMenu()
{
}

GSMenu::~GSMenu()
{
}

void GSMenu::Exit()
{

}

void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Init()
{
	//Background
	sf::Texture* textureBG = new sf::Texture();
	textureBG = Data->getTexture("Background layers/Background");
	m_background.setTexture(*textureBG);
	m_background.setPosition(screenWidth / 2, screenHeigth - textureBG->getSize().y / 2);
	m_background.setOrigin((sf::Vector2f)textureBG->getSize() / 2.f);

	//Title
	m_title.setString("MENU");
	m_title.setFont(*Data->getFont("Sakana"));
	m_title.setPosition(screenWidth / 2, screenHeigth / 10);
	sf::FloatRect titleBounds = m_title.getGlobalBounds();
	// Đặt gốc nằm chính giữa
	m_title.setOrigin(titleBounds.width / 2, titleBounds.height / 2);
	float scale = 1.5f; // Tỷ lệ 1.5 lần kích thước ban đầu
	m_title.setScale(scale, scale);

	//Playgame
	GameButton* playButton = new GameButton();
	playButton->Init("play");
	playButton->setOnclick([]() {GSM->ChangeState(StateTypes::PLAY); });
	playButton->setPosition(screenWidth / 2, screenHeigth / 2);
	playButton->setSize(sf::Vector2f(150, 150));
	playButton->setOrigin(playButton->getSize() / 2.f);
	m_listButton.push_back(playButton);

	//Exit
	GameButton* exitButton = new GameButton();
	exitButton->Init("close");
	exitButton->setOnclick([]() {WConnect->getWindow()->close(); });
	exitButton->setPosition(screenWidth / 2 + screenWidth / 4, screenHeigth / 1.2);
	exitButton->setOrigin(exitButton->getSize() / 2.f);
	m_listButton.push_back(exitButton);
	//Setting
	GameButton* settingsButton = new GameButton();
	settingsButton->Init("settings");
	settingsButton->setPosition(screenWidth / 2 - screenWidth / 4, screenHeigth / 1.2);
	settingsButton->setOrigin(settingsButton->getSize() / 2.f);
	settingsButton->setOnclick([]() {GSM->ChangeState(StateTypes::SETTINGS); });
	m_listButton.push_back(settingsButton);
	//highscore
	GameButton* prizeButton = new GameButton();
	prizeButton->Init("prize");
	prizeButton->setPosition(screenWidth / 2 - screenWidth / 12, screenHeigth / 1.2);
	prizeButton->setOrigin(prizeButton->getSize() / 2.f);
	prizeButton->setOnclick([]() {GSM->ChangeState(StateTypes::HIGHSCORE); });
	m_listButton.push_back(prizeButton);
	//about
	GameButton* aboutButton = new GameButton();
	aboutButton->Init("about");
	aboutButton->setPosition(screenWidth / 2 + screenWidth / 12, screenHeigth / 1.2);
	aboutButton->setOrigin(aboutButton->getSize() / 2.f);
	aboutButton->setOnclick([]() {GSM->ChangeState(StateTypes::ABOUT); });
	m_listButton.push_back(aboutButton);
}

void GSMenu::Update(float deltaTime)
{
	for (auto button : m_listButton)
	{
		button->Update(deltaTime);
	}
}

void GSMenu::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(m_background);
	renderWindow->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(renderWindow);
	}
}

