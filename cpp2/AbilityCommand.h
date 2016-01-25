#pragma once
#include "ICommand.h"
class AbilityCommand :
	public ICommand
{
public:
	AbilityCommand();
	~AbilityCommand();

	void Execute( const ClientCommand command);
};

