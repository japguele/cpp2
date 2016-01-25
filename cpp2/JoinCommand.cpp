#include "stdafx.h"
#include "JoinCommand.h"
#include "Game.h"

JoinCommand::JoinCommand()
{
}


JoinCommand::~JoinCommand()
{
}

void JoinCommand::Execute(const ClientCommand command){
	Game::GetInstance()->JoinGame(command.get_player());
}