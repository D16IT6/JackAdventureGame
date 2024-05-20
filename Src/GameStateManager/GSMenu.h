#pragma once
#include "GameStateBase.h"
class GSMenu :public GameStateBase
{
public:
	GSMenu();
	~GSMenu();
	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* renderWindow);
private:
	std::list<GameButton*> m_listButton;
	sf::Sprite m_background;
	sf::Text m_title;
};