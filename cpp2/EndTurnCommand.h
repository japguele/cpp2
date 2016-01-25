#pragma once
#include "ICommand.h"
class EndTurnCommand :
	public ICommand
{
public:
	EndTurnCommand();
	~EndTurnCommand();

	void Execute(const ClientCommand command);
};

