#include "stdafx.h"
#include "CheatCommand.h"
#include "ClientCommand.h"


CheatCommand::CheatCommand()
{
}


CheatCommand::~CheatCommand()
{
}

void CheatCommand::Execute(const ClientCommand command){
	//if (game->)
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
			command.get_player()->add_building(command.get_player()->get_buildcards()->at(0));
		
}