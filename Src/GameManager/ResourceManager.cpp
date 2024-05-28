#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_pathData = "./Data/";
	m_pathTexture = m_pathData + "Textures/";
	m_pathFont = m_pathData + "Fonts/";
	m_pathSound = m_pathData + "Sounds/";
	m_allow = true;
}

ResourceManager::~ResourceManager()
{
	for (auto it : m_mapTexture) {
		if (it.second != nullptr)
			delete it.second;
	}
	m_mapTexture.clear();
	for (auto it : m_mapFont) {
		if (it.second != nullptr)
			delete it.second;
	}
	m_mapFont.clear();

}

void ResourceManager::addTextture(std::string name)
{
	sf::Texture * texture = new sf::Texture;
	texture->loadFromFile(m_pathTexture + name + ".png");
	auto it = m_mapTexture.find(name);
	if(it!=m_mapTexture.end())
	m_mapTexture.insert(std::pair<std::string,sf::Texture * >(name,texture));
}

void ResourceManager::removeTexture(std::string name)
{
	auto it = m_mapTexture.find(name);
	if (it == m_mapTexture.end())
		return;
	if (it->second != nullptr)
		delete it->second;
	m_mapTexture.erase(it);
}

sf::Texture * ResourceManager::getTexture(std::string name)
{
	auto it = m_mapTexture.find(name);
	if (it != m_mapTexture.end())
	{
		if (it->second != nullptr)
		return it->second;
	}
	sf::Texture* texture = new sf::Texture;
	std::string pathImage = m_pathTexture + name + ".png";
	texture->loadFromFile(pathImage);
	m_mapTexture.insert(std::pair<std::string, sf::Texture* >(name, texture));
	return texture;
}

void ResourceManager::addFont(std::string name)
{
	sf::Font* font = new sf::Font;
	font->loadFromFile(m_pathFont + name + ".ttf");
	auto it = m_mapFont.find(name);
	if (it != m_mapFont.end())
		m_mapFont.insert(std::pair<std::string, sf::Font* >(name, font));
}

void ResourceManager::removeFont(std::string name)
{
	auto it = m_mapFont.find(name);
	if (it == m_mapFont.end())
		return;
	if (it->second != nullptr)
		delete it->second;
	m_mapFont.erase(it);
}

sf::Font* ResourceManager::getFont(std::string name)
{
	auto it = m_mapFont.find(name);
	if (it != m_mapFont.end())
	{
		if (it->second != nullptr)
		return it->second;
	}
	sf::Font* font = new sf::Font;
	font->loadFromFile(m_pathFont + name + ".ttf");
	m_mapFont.insert(std::pair<std::string, sf::Font* >(name, font));
	return font;
}

void ResourceManager::addSound(std::string name)
{
	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* buffer = new sf::SoundBuffer;

	buffer->loadFromFile(m_pathSound + name + ".wav");
	sound->setBuffer(*buffer);
	auto it = m_mapSound.find(name);
	if (it != m_mapSound.end())
		m_mapSound.insert(std::pair<std::string, sf::Sound* >(name, sound));
}

void ResourceManager::removeSound(std::string name)
{
	auto it = m_mapSound.find(name);
	if (it == m_mapSound.end())
		return;
	if (it->second != nullptr)
		delete it->second;
	m_mapSound.erase(it);
}

sf::Sound* ResourceManager::getSound(std::string name)
{
	auto it = m_mapSound.find(name);
	if (it != m_mapSound.end())
	{
		if (it->second != nullptr)
			return it->second;
	}

	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* buffer = new sf::SoundBuffer;

	buffer->loadFromFile(m_pathSound + name + ".wav");
	sound->setBuffer(*buffer);

	m_mapSound.insert(std::pair<std::string, sf::Sound* >(name, sound));

	return sound;
}

void ResourceManager::addMusic(std::string name)
{
	sf::Music* music = new sf::Music;
	music->openFromFile(m_pathSound + name + ".wav");
	auto it = m_mapMusic.find(name);
	if (it != m_mapMusic.end())
		m_mapMusic.insert(std::pair<std::string, sf::Music* >(name, music));
}

void ResourceManager::removeMusic(std::string name)
{
	auto it = m_mapMusic.find(name);
	if (it == m_mapMusic.end())
		return;
	if (it->second != nullptr)
		delete it->second;
	m_mapMusic.erase(it);
}

sf::Music* ResourceManager::getMusic(std::string name)
{
	auto it = m_mapMusic.find(name);
	if (it != m_mapMusic.end())
	{
		if (it->second != nullptr)
			return it->second;
	}
	sf::Music* music = new sf::Music;
	music->openFromFile(m_pathSound + name + ".wav");

	m_mapMusic.insert(std::pair<std::string, sf::Music* >(name, music));
	return music;
}

void ResourceManager::playMusic(std::string name)
{
	if (m_allow)
	{
		Data->getMusic(name)->play();
	}
}

void ResourceManager::playSound(std::string name)
{
	if (m_allow)
	{
		Data->getSound(name)->play();
	}
}

void ResourceManager::setAllowSound(bool allow)
{
	m_allow = allow;
}

bool ResourceManager::getAllowSound()
{
	return m_allow;
}
