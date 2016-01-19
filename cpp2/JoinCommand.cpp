#include "stdafx.h"
#include "JoinCommand.h"
#include "Game.h"

JoinCommand::JoinCommand()
{
}


JoinCommand::~JoinCommand()
{
}

void JoinCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command){
	game->JoinGame(command.get_player());


}