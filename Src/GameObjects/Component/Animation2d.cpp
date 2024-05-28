#include "Animation2d.h"

Animation2d::Animation2d(sf::Texture& texture, sf::Vector2i frameNum, float frameTime, int frameTotals) :Animation(texture, frameNum, frameTime)
{
	m_frameTotals = frameTotals;
	m_currentFrameNum = 0;
	this->setScale(-1, 1);
}

void Animation2d::Update(float DeltaTime)
{
	if (m_currentFrame.x == (m_frameNum.x-1) - 1 && m_modeStopAtEndFrame && m_currentFrameNum == m_frameTotals-1)
		return;
	m_currentTime += DeltaTime;
	if (m_currentTime >= m_frameTime)
	{
		m_currentFrame.x++;
		m_currentFrameNum++;
		if (m_currentFrame.x == m_frameNum.x|| ((m_currentFrame.y * m_frameNum.x + m_currentFrame.x) == m_frameTotals))
		{
			m_currentFrame.x = 0;
			m_currentFrame.y++;
			
		}
		if (m_currentFrame.y==m_frameNum.y)
		{
			m_currentFrame.y = 0;
			m_currentFrameNum = 0;
		}
		CaculateReactUV();
		ApplyReact();
		m_currentTime -= m_frameTime;

	}
	
}

void Animation2d::Reset()
{
	Animation::Reset();
	m_currentFrameNum = 0;
}
