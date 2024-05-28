#pragma once
#include "../../GameManager/ResourceManager.h";
enum Tag
{
	PLAYER,
	CREEP,
	BOSS,
	BULLETBOSS,
	BULLETPLAYER,
};
class HitBox : public sf::RectangleShape
{
public:
	HitBox (sf::Vector2i size);
	~HitBox ();
	void Init(sf::Vector2f velogcity);
	sf::Vector2f getVelogcity();
	void setVelocity(sf::Vector2f velocity) { m_velogcity = velocity; };
	void setTag(Tag tag) { m_tag = tag; };
	Tag getTag() {return m_tag;};
	void setAlive(bool alive) { m_isAlive=alive; };
	bool getAlive() { return m_isAlive; };
private:
	sf::Vector2f m_velogcity;
	bool m_isAlive ;
	Tag m_tag;
};
