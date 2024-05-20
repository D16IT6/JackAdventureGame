#include "ParallelBackground.h"

void ParallelBackground::Init(int speed)
{
	
	std::list<std::string> nameLayer = { "Layer_0009_2","Layer_0008_3","Layer_0007_Lights", "Layer_0006_4","Layer_0005_5","Layer_0004_Lights","Layer_0003_6" ,"Layer_0002_7", "Layer_0001_8","Layer_0000_9" };
	int temp = 0;
	for (const auto name : nameLayer)
	{
		temp += 20;
		Layer* layer = new Layer;
		layer->Init(m_pathBg + name, speed+temp);
		m_listBackground.push_back(layer);
	}
}

void ParallelBackground::Update(float deltaTime)
{
	for (auto it : m_listBackground)
	{
		it->Update(deltaTime);
	}
}

void ParallelBackground::Render(sf::RenderWindow* window)
{
	for (auto it : m_listBackground)
	{
		it->Render(window);
	}
}
