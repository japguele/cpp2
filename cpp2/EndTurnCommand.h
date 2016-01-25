#pragma once
#include "ICommand.h"
class EndTurnCommand :
	public ICommand
{
public:
	EndTurnCommand();
	~EndTurnCommand();

	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

