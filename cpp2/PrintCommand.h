#pragma once
#include "ICommand.h"
class PrintCommand :
	public ICommand
{
public:
	PrintCommand();
	~PrintCommand();

	void Execute(const ClientCommand command);
};

