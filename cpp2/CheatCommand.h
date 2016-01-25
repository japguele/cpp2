#pragma once
#include "ICommand.h"
class CheatCommand :
	public ICommand
{
public:
	CheatCommand();
	~CheatCommand();
	void Execute(const ClientCommand command);
};

