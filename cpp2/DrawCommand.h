#pragma once
#include "ICommand.h"
class DrawCommand :
	public ICommand
{
public:
	DrawCommand();
	~DrawCommand();
	void Execute(const ClientCommand command);
};

