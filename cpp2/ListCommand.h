#pragma once
#include "ICommand.h"
class ListCommand :
	public ICommand
{
public:
	ListCommand();
	~ListCommand();
	void Execute(const ClientCommand command);
};

