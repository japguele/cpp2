#pragma once
#include "ICommand.h"

class JoinCommand :
	public ICommand
{
public:
	JoinCommand();
	~JoinCommand();
	void Execute(const ClientCommand command);
};

