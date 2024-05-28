#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Init()
{
	//Background
	sf::Texture* textureBG = new sf::Texture();
	textureBG = Data->getTexture("Background layers/Background");
	m_background.setTexture(*textureBG);
	m_background.setPosition(screenWidth / 2, screenHeigth - textureBG->getSize().y / 2);
	m_background.setOrigin((sf::Vector2f)textureBG->getSize() / 2.f);

	//Title
	m_title.setString("END GAME!");
	m_title.setFont(*Data->getFont("Sakana"));
	m_title.setPosition(screenWidth / 2, screenHeigth / 10);
	sf::FloatRect titleBounds = m_title.getGlobalBounds();
	// Đặt gốc nằm chính giữa
	m_title.setOrigin(titleBounds.width / 2, titleBounds.height / 2);
	float scale = 1.5f; // Tỷ lệ 1.5 lần kích thước ban đầu
	m_title.setScale(scale, scale);



	//REPLAY
	GameButton* prizeButton = new GameButton();
	prizeButton->Init("restart");
	prizeButton->setPosition(screenWidth / 2 - screenWidth / 3, screenHeigth / 1.2);
	prizeButton->setOrigin(prizeButton->getSize() / 2.f);
	prizeButton->setOnclick([]() {
		GSM->PopState();
		GSM->ChangeState(PLAY);
		SCOREMANAGER->UpdateHighScore();
		SCOREMANAGER->writeFile();
		});
	m_listButton.push_back(prizeButton);
	//MENU
	GameButton* aboutButton = new GameButton();
	aboutButton->Init("menu");
	aboutButton->setPosition(screenWidth / 2 + screenWidth / 3, screenHeigth / 1.2);
	aboutButton->setOrigin(aboutButton->getSize() / 2.f);
	aboutButton->setOnclick([]() {
		GSM->PopState();
		GSM->PopState();
		SCOREMANAGER->UpdateHighScore();
		SCOREMANAGER->writeFile();
		});
	m_listButton.push_back(aboutButton);

	//BestScore
	m_bestScore.setString("BEST SCORE:" + std::to_string(SCOREMANAGER->getBestScore()));
	m_bestScore.setFont(*Data->getFont("Sakana"));
	m_bestScore.setPosition(screenWidth / 2, screenHeigth / 2);
	sf::FloatRect bestBounds = m_bestScore.getGlobalBounds();
	// Đặt gốc nằm chính giữa
	m_bestScore.setOrigin(bestBounds.width / 2, bestBounds.height / 2);
	float scale1 = 1.5f; // Tỷ lệ 1.5 lần kích thước ban đầu
	m_bestScore.setScale(scale, scale);

	//CurrentScore
	m_currentScore.setString("YOUR SCORE:"+std::to_string(SCOREMANAGER->getCurrentScore()));
	m_currentScore.setFont(*Data->getFont("Sakana"));
	m_currentScore.setPosition(screenWidth / 2, screenHeigth / 3);
	sf::FloatRect currentBounds = m_currentScore.getGlobalBounds();
	// Đặt gốc nằm chính giữa
	m_currentScore.setOrigin(currentBounds.width / 2, currentBounds.height / 2);
	float scale2 = 1.5f; // Tỷ lệ 1.5 lần kích thước ban đầu
	m_currentScore.setScale(scale, scale);
}

void GSEnd::Update(float deltaTime)
{
	for (auto button : m_listButton)
	{
		button->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(m_background);
	renderWindow->draw(m_title);
	for (auto button : m_listButton) {
		button->Render(renderWindow);
	}
	renderWindow->draw(m_bestScore);
	renderWindow->draw(m_currentScore);
}
