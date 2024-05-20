#pragma once
#include "Animation.h"

class Animation2d : public Animation
{
public:
	Animation2d(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int frameTotals);
	void Update(float DeltaTime);
	void Reset();
	int getFrameTotals() { return m_frameTotals; };
	int getCurrentFrameCount() { return m_currentFrameNum; };
private:
	int m_frameTotals;
	int m_currentFrameNum;
};

