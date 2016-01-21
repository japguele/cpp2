#pragma once
#include "BaseState.h"
class SetupState :
	public BaseState
{
public:
	SetupState();
	~SetupState();

	virtual void Enter() override;
	virtual void Execute() override;
	virtual void Exit() override;
};

