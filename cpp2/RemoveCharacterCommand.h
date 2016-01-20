#pragma once
#include "ICommand.h"
class RemoveCharacterCommand :
	public ICommand
{
public:
	RemoveCharacterCommand();
	~RemoveCharacterCommand();

	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

