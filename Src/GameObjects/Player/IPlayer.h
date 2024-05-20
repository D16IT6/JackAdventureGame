#pragma once
#include"IPState.h"
#include"../Component/HitBox.h"
class IPlayer
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
protected:
};
