#pragma once
#include "ICommand.h"
class PickCharacterCommand :
	public ICommand
{
public:
	PickCharacterCommand();
	~PickCharacterCommand();
	void Execute( const ClientCommand command);
};

