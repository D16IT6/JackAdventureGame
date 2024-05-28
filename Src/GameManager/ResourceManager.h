#pragma once
#include<map>
#include<list>
#include<string>
#include"../GameObjects/GameButton.h"
#include"../GameConfig.h"
#include"../GameObjects/Component/Animation2d.h"
#include<SFML/Audio.hpp>
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

	void addSound(std::string name);
	void removeSound(std::string name);
	sf::Sound* getSound(std::string name);

	void addMusic(std::string name);
	void removeMusic(std::string name);
	sf::Music* getMusic(std::string name);

	void playMusic(std::string name);
	void playSound(std::string name);
	void setAllowSound(bool allow);
	bool getAllowSound();
private:
	std::map<std::string,sf::Texture*> m_mapTexture;
	std::map<std::string,sf::Font*> m_mapFont;
	std::map<std::string, sf::Sound*> m_mapSound;
	std::map<std::string, sf::Music*> m_mapMusic;

	std::string m_pathData;
	std::string m_pathTexture;
	std::string m_pathFont;
	std::string m_pathSound;
	bool m_allow;
};

