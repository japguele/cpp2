#pragma once
#include "ICommand.h"
class DrawCommand :
	public ICommand
{
public:
	DrawCommand();
	~DrawCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

