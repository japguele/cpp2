#pragma once
#include "ICommand.h"
class AbilityCommand :
	public ICommand
{
public:
	AbilityCommand();
	~AbilityCommand();

	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

