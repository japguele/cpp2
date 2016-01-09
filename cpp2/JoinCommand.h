#pragma once
#include "ICommand.h"

class JoinCommand :
	public ICommand
{
public:
	JoinCommand();
	~JoinCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

