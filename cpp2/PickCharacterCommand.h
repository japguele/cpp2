#pragma once
#include "ICommand.h"
class PickCharacterCommand :
	public ICommand
{
public:
	PickCharacterCommand();
	~PickCharacterCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

