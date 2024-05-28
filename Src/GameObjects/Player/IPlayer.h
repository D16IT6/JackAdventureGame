#pragma once
#include"IPState.h"
#include"../Component/HitBox.h"
class IPlayer
{
public:
	virtual void changeNextState(IPState::STATE nextState) = 0;
	virtual void prevState(IPState::STATE prevState) = 0;
	virtual IPState* getCurrentState()=0;
	virtual IPState::STATE getPrevState() = 0;
	virtual HitBox* getHitBox() = 0;
	virtual PlayerWeapon* getPlayerWeapon() = 0;
protected:
};
