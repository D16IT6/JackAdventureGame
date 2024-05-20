#pragma once
#include<map>
#include<list>
#include<string>
#include"../GameObjects/GameButton.h"
#include"../GameConfig.h"
#include"../GameObjects/Component/Animation2d.h"
#include <cstdlib>
#include <ctime>
#define Data ResourceManager::GetInstance()
class ResourceManager : public CSingleton<ResourceManager>
{
public:
	ResourceManager();
	~ResourceManager();
	void addTextture(std::string name);
	void removeTexture(std::string name);
	sf::Texture* getTexture(std::string name);

	void addFont(std::string name);
	void removeFont(std::string name);
	sf::Font* getFont(std::string name);
private:
	std::map<std::string,sf::Texture*> m_mapTexture;
	std::map<std::string,sf::Font*> m_mapFont;

	std::string m_pathData;
	std::string m_pathTexture;
	std::string m_pathFont;
};

