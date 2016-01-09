#pragma once
#include "ICommand.h"
class ChatCommand :
	public ICommand
{
public:
	ChatCommand();
	~ChatCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

