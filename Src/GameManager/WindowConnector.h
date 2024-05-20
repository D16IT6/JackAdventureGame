#pragma once
#include "Singleton.h"
#include "SFML/Graphics.hpp"

#define WConnect WindowConnector::GetInstance()

class WindowConnector : public CSingleton<WindowConnector>
{
public:
	WindowConnector();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
private:
	sf::RenderWindow* m_window;
};

