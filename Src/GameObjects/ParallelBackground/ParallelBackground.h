#pragma once
#include"../../GameManager/ResourceManager.h"
#include"Layer.h"
class ParallelBackground
{
public:
	void Init(int speed);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<Layer*> m_listBackground;
	std::string m_pathBg = "Background layers/";
};

