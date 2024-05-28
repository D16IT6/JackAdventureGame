#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
}

GSHighScore::~GSHighScore()
{
	for (auto it : m_listButton) {
		if (it != nullptr) {
			delete it;
		}
	}
	for (auto it : m_ListScore) {
		if (it != nullptr) {
			delete it;
		}
	}
}

void GSHighScore::Exit()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Init()
{
	//Background
	sf::Texture* textureBG = new sf::Texture();
	textureBG = Data->getTexture("Background layers/Background");
	m_background.setTexture(*textureBG);
	m_background.setPosition(screenWidth / 2, screenHeigth - textureBG->getSize().y / 2);
	m_background.setOrigin((sf::Vector2f)textureBG->getSize() / 2.f);

	//title
	m_title.setString("HIGHSCORE");
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
	exitButton->setPosition(screenWidth - screenWidth / 20, screenHeigth / 15);
	exitButton->setSize(sf::Vector2f(50, 50));
	exitButton->setOrigin(exitButton->getSize() / 2.f);
	m_listButton.push_back(exitButton);

	//ListScore
	for (int i = 0; i < ScoreManager::GetInstance()->getNum(); i++) {
		sf::Text* t = new sf::Text();
		t->setString("Top "+ std::to_string(i+1)+": " + std::to_string(ScoreManager::GetInstance()->getHighScore()[i]));
		t->setFont(*Data->getFont("Sakana"));
		t->setPosition(screenWidth / 2-50, screenHeigth / 2 - 50 + 30 * i);
		m_ListScore.push_back(t);
	}
}

void GSHighScore::Update(float deltaTime)
{
	for (auto button : m_listButton)
	{
		button->Update(deltaTime);
	}
}

void GSHighScore::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(m_background);
	renderWindow->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(renderWindow);
	}
	for (auto it : m_ListScore) {
		renderWindow->draw(*it);
	}
}
