#include "stdafx.h"
#include "EndTurnCommand.h"
#include "Game.h"

EndTurnCommand::EndTurnCommand()
{
}


EndTurnCommand::~EndTurnCommand()
{
}

void EndTurnCommand::Execute(const ClientCommand command) {
	if (command.get_player()->get_turn()){
		Game::getInstance().EndTurn();
	}

}