#pragma once
#include "ICommand.h"
class TakeCommand :
	public ICommand
{
public:
	TakeCommand();
	~TakeCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

