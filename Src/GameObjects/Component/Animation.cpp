#include"Animation.h"
Animation::Animation(sf::Texture& texture, sf::Vector2i frameNum, float frameTime)
{
	m_frameNum = frameNum;
	m_frameTime = frameTime;
	this->setTexture(texture);
	m_currentFrame = sf::Vector2i(0, 0);
	m_currentTime = 0.f;
	CaculateReactSize();
	CaculateReactUV();
	ApplyReact();
	this->setOrigin((sf::Vector2f)m_reactSize / 2.f);
	m_modeStopAtEndFrame = false;
}

void Animation::CaculateReactSize()
{
	m_reactSize = sf::Vector2i(this->getTexture()->getSize().x / m_frameNum.x, this->getTexture()->getSize().y / m_frameNum.y);
}

void Animation::CaculateReactUV()
{
	m_reactUV.x = m_currentFrame.x * m_reactSize.x;
	m_reactUV.y = m_currentFrame.y * m_reactSize.y;
}

void Animation::ApplyReact()
{
	m_react = sf::IntRect(m_reactUV, m_reactSize);
	this->setTextureRect(m_react);
}

void Animation::Update(float DeltaTime)
{
	if (m_currentFrame.x == m_frameNum.x - 1 && m_modeStopAtEndFrame)
		return;
	m_currentTime += DeltaTime;
	if (m_currentTime >= m_frameTime)
	{
		m_currentFrame.x++;
		if (m_currentFrame.x == m_frameNum.x)
		{
			m_currentFrame.x = 0;
		}

		CaculateReactUV();
		ApplyReact();
		m_currentTime-=m_frameTime;
	}
}

void Animation::Reset()
{
	m_currentFrame.x = 0;
	m_currentTime = 0.1f;
}

void Animation::setModeAtEndFrame(bool stop)
{
	m_modeStopAtEndFrame = stop;
}
