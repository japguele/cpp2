#pragma once
#include "ICommand.h"
class GameStateCommand :
	public ICommand
{
public:
	GameStateCommand();
	~GameStateCommand();

	void Execute(const ClientCommand command);
};

