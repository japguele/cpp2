#pragma once
#include "ICommand.h"
class ChatCommand :
	public ICommand
{
public:
	ChatCommand();
	~ChatCommand();
	void Execute(const ClientCommand command);
};

