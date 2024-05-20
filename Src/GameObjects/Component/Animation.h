#pragma once
#include<SFML/Graphics.hpp>

class Animation : public sf::Sprite
{
public:
	Animation(sf::Texture& texture,sf::Vector2i frameNum,float frameTime);
	void CaculateReactSize();
	void CaculateReactUV();
	void ApplyReact();
	virtual void Update(float DeltaTime);
	virtual void Reset();
	void setModeAtEndFrame(bool stop);
	sf::Vector2i getFrameNum() { return m_frameNum; };
	sf::Vector2i getCurrentFrame() { return m_currentFrame; };
protected:
	sf::Vector2i m_frameNum;
	sf::Vector2i m_currentFrame;
	float m_frameTime;
	float m_currentTime;

	sf::Vector2i m_reactUV;
	sf::Vector2i m_reactSize;
	sf::IntRect m_react;
	bool m_modeStopAtEndFrame;
};

