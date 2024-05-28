#pragma once
#include "../GameObjects/ScoreManager.h"
//#include"../GameManager/Singleton.h"
#include<list>
#define GSM GameStateMachine::GetInstance()
class GameStateBase;
enum StateTypes
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTINGS,
	ABOUT,
	HIGHSCORE,
	END,
};
class GameStateMachine :public CSingleton<GameStateMachine>
{
public:
	GameStateMachine ();
	~GameStateMachine ();
	void ChangeState(GameStateBase* gamestate);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();
	void PerformStateChange();
	GameStateBase* GetCurrentState() const;
	GameStateBase* GetNextState() const;
	bool NeedToChangeState();
	bool HasState();
private:
	std::list<GameStateBase*> m_stateStack;
	GameStateBase* m_activeState;
	GameStateBase* m_nextState;
	
};
