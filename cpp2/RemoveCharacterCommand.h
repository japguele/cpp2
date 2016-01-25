#pragma once
#include "ICommand.h"
class RemoveCharacterCommand :
	public ICommand
{
public:
	RemoveCharacterCommand();
	~RemoveCharacterCommand();

	void Execute(const ClientCommand command);
};

