#include "ScoreManager.h"
#include <algorithm>
#include <fstream>
ScoreManager::ScoreManager()
{
    m_currentScore = 0;
    m_Num = 5;
}

int ScoreManager::getCurrentScore()
{
    return m_currentScore;
}

void ScoreManager::setCurrentScore(int score)
{
    m_currentScore = score;
}

void ScoreManager::UpdateHighScore()
{
    for (int i = 0; i < m_Num; i++)
    {
        if (m_currentScore> m_highScore[i])
        {
            std::swap(m_currentScore, m_highScore[i]);
        }
    }
    std::sort(m_highScore, m_highScore + m_Num, [](int a, int b) {return a > b; });
}

int ScoreManager::getBestScore()
{
    return m_highScore[0];
}

void ScoreManager::print()
{
    for (int i = 0; i < m_Num; i++)
    {
        printf("%d \n", m_highScore[i]);
    }
}

void ScoreManager::writeFile()
{
    std::fstream output;
    output.open("Score.data", std::ios::binary | std::ios::out);
    output.write((char*)m_highScore, sizeof(m_highScore));
    output.close();
    
}

void ScoreManager::readFile()
{
    std::fstream input;
    input.open("Score.data", std::ios::binary | std::ios::in);
    input.read((char*)m_highScore, sizeof(m_highScore));
    input.close();
}
int ScoreManager::getNum()
{
    return m_Num;
}

int* ScoreManager::getHighScore()
{
    return m_highScore;
}
