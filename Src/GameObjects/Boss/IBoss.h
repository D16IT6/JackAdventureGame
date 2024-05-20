#pragma once
#include"IBState.h"
#include"../Component/HitBox.h"
class IBoss
{
public:
	virtual void changeNextState(IBState::STATE nextState) = 0;
	virtual HitBox* getHitBox() = 0;
protected:
};
