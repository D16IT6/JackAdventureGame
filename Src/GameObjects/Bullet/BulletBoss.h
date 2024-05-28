#pragma once
#include"../../GameManager/ResourceManager.h"
#include"../Component/HitBox.h"
class BulletBoss
{
public:
	BulletBoss();
	~BulletBoss();
	 void Init();
	 void Update(float deltaTime);
	 void Render(sf::RenderWindow* window);
	HitBox* getHitbox() { return m_hitbox; };
	void setStartPoint(sf::Vector2f startPoint) { m_startPoint = startPoint; };
	bool getStop() { return m_stop; };
	void Reset();
protected:
	sf::Vector2f m_startPoint;
	HitBox* m_hitbox;
	Animation* m_currentAni;
	Animation* m_RunAni;
	Animation* m_DeathAni;
	bool m_stop;
	bool m_soundIsPlaying;
};
