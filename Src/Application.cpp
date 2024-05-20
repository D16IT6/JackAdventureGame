#include"Application.h"
#include"GameStateManager/GameStateBase.h"
void Application::Run()
{
	srand(time(NULL));
	Init();
	sf::Clock clock;
	float deltaTime = 0.f;
	while (m_window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_window->close();
		}
		Update(deltaTime);
		Render();
	}
}

void Application::Init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeigth), titleApp);
	m_window->setFramerateLimit(60);
	m_window->setVerticalSyncEnabled(false);
	GSM->ChangeState(StateTypes::INTRO);
	WConnect->setWindow(m_window);
}

void Application::Update(float deltaTime)
{
	if (GSM->NeedToChangeState())
	{
		GSM->PerformStateChange();
	}
	GSM->GetCurrentState()->Update(deltaTime);
}

void Application::Render()
{
	m_window->clear(sf::Color::White);
	GSM->GetCurrentState()->Render(m_window);
	m_window->display();
}

Application::~Application()
{
	if (m_window != nullptr)
		delete m_window;
}
