#pragma once
#include "ICommand.h"
class BuildCommand :
	public ICommand
{
public:
	BuildCommand();
	~BuildCommand();

	void Execute( const ClientCommand command);
};

