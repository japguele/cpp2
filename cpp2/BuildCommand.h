#pragma once
#include "ICommand.h"
class BuildCommand :
	public ICommand
{
public:
	BuildCommand();
	~BuildCommand();

	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

