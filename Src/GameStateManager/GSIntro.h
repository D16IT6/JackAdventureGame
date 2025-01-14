#pragma once
#include "GameStateBase.h"
class GSIntro :public GameStateBase
{
public:
	GSIntro();
	~GSIntro();
	void Exit() ;
	void Pause() ;
	void Resume();

	void Init();
	 void Update(float deltaTime) ;
	 void Render(sf::RenderWindow* renderWindow) ;
private:
	sf::Sprite m_Logo;
	float currentTime;
};