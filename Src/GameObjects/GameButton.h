#pragma once	
#include"../GameManager/WindowConnector.h"
#include"../GameManager/ResourceManager.h"
class GameButton : public sf::RectangleShape
{
public:
	GameButton();
	~GameButton();

	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	
	void HandleTouchEvent();
	bool isHandle();
	void setOnclick(void(*clickFunc)());
private:
	//delegate hay pointerFuncion void kieu tra ve (ten con tro) (cac tham so)
	void (*m_btnClickFunc)();
	bool m_isHandling;
	std::string m_pathButton = "btn/";
};
