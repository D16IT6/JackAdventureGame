#pragma once
#include"../GameManager/Singleton.h"

#define SCOREMANAGER ScoreManager::GetInstance()

class ScoreManager : public CSingleton<ScoreManager>
{
public:
	ScoreManager();
	int getCurrentScore();
	void setCurrentScore(int score);
	void UpdateHighScore();

	int getBestScore();
	void print();
	void writeFile();
	void readFile();
	int getNum();
	int* getHighScore();
private:
	int m_currentScore;
	int m_highScore[5];
	int m_Num;
};

