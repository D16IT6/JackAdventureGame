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

	//AllowSound
	GameButton* soundButton = new GameButton();
	
	/*music_off*/
	soundButton->Init("misic");
	/*[] khai bao ham
	() chuyen tham so
	{} than ham*/
	soundButton->setOnclick([]() {
			Data->setAllowSound(true);
		});
	soundButton->setPosition(screenWidth / 2 + screenWidth / 12, screenHeigth / 2);
	if (!Data->getAllowSound())
	{
		soundButton->setSize(sf::Vector2f(50, 50));
	}
	else
	{
		soundButton->setSize(sf::Vector2f(100, 100));
	}
	soundButton->setOrigin(soundButton->getSize() / 2.f);
	m_listButton.push_back(soundButton);

	GameButton* soundButtonOff = new GameButton();

	/*music_off*/
	soundButtonOff->Init("music_off");
	soundButtonOff->setOnclick([]() {
		Data->setAllowSound(false);
		});
	soundButtonOff->setPosition(screenWidth / 2 - screenWidth / 12, screenHeigth / 2);

	if (Data->getAllowSound())
	{
		soundButtonOff->setSize(sf::Vector2f(50, 50));
	}
	else
	{
		soundButtonOff->setSize(sf::Vector2f(100, 100));
	}
	soundButtonOff->setOrigin(soundButtonOff->getSize() / 2.f);
	m_listButton.push_back(soundButtonOff);
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
