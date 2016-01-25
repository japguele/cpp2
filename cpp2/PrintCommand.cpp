#include "stdafx.h"
#include "PrintCommand.h"


PrintCommand::PrintCommand()
{
}


PrintCommand::~PrintCommand()
{
}

void PrintCommand::Execute(const ClientCommand command) 
{
	command.get_player()->Print();
}