#include "stdafx.h"
#include "EndTurnCommand.h"
#include "Game.h"

EndTurnCommand::EndTurnCommand()
{
}


EndTurnCommand::~EndTurnCommand()
{
}

void EndTurnCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command) {
	if (command.get_player()->get_turn()){
		game->EndTurn();
	}

}