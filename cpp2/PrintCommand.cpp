#include "stdafx.h"
#include "PrintCommand.h"


PrintCommand::PrintCommand()
{
}


PrintCommand::~PrintCommand()
{
}

void PrintCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command) 
{
	command.get_player()->Print(game);
}