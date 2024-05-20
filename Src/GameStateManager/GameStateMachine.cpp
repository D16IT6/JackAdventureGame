#include "GameStateMachine.h"
#include "GameStateBase.h"
GameStateMachine::GameStateMachine()
{
	m_activeState = nullptr;
	m_nextState = nullptr;
}

GameStateMachine::~GameStateMachine()
{
	while (!m_stateStack.empty())
	{
		delete(m_stateStack.back());
		m_stateStack.pop_back();
	}
}

void GameStateMachine::ChangeState(GameStateBase* gamestate)
{
	m_nextState = gamestate;
}

void GameStateMachine::ChangeState(StateTypes st)
{
	GameStateBase* gs = GameStateBase::CreateState(st);
	ChangeState(gs);
}

void GameStateMachine::PushState(StateTypes st)
{
	GameStateBase* gs = GameStateBase::CreateState(st);
	if (!m_stateStack.empty()) {
		m_stateStack.back()->Pause();
	}
	ChangeState(gs);
}

void GameStateMachine::PopState()
{
	if (!m_stateStack.empty())
	{
		m_stateStack.back()->Exit();
		m_stateStack.pop_back();//Xoá khỏi stack
	}
	if (!m_stateStack.empty())
	{
		m_stateStack.back()->Resume();
	}
	m_activeState = m_stateStack.back();
		
}


void GameStateMachine::PerformStateChange()
{
	if (m_nextState != nullptr)
	{
		if (!m_stateStack.empty()) {
			m_stateStack.back()->Exit();
		}
		m_stateStack.push_back(m_nextState);
		m_stateStack.back()->Init();
		m_activeState = m_nextState;
			
	}
	m_nextState = nullptr;
}

GameStateBase* GameStateMachine::GetCurrentState() const
{
	return m_activeState;
}

GameStateBase* GameStateMachine::GetNextState() const
{
	return m_nextState;
}

bool GameStateMachine::NeedToChangeState()
{
	return m_nextState!=nullptr;
}

bool GameStateMachine::HasState()
{
	return m_stateStack.size()>0;
}
