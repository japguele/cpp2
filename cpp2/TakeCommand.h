#pragma once
#include "ICommand.h"

class TakeCommand :
	public ICommand
{
public:
	TakeCommand();
	~TakeCommand();
	void Execute( const ClientCommand command);
};

