#pragma once
#include "ICommand.h"
class PrintCommand :
	public ICommand
{
public:
	PrintCommand();
	~PrintCommand();

	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

