#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_pathData = "./Data/";
	m_pathTexture = m_pathData + "Textures/";
	m_pathFont = m_pathData + "Fonts/";
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
		if (it->second != nullptr);
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
		if (it->second != nullptr);
		return it->second;
	}
	sf::Font* font = new sf::Font;
	font->loadFromFile(m_pathFont + name + ".ttf");
	m_mapFont.insert(std::pair<std::string, sf::Font* >(name, font));
	return font;
}
