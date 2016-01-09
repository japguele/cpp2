#pragma once
#include "ICommand.h"
class ListCommand :
	public ICommand
{
public:
	ListCommand();
	~ListCommand();
	void Execute(std::shared_ptr<Game> game, const ClientCommand command);
};

