#include "stdafx.h"
#include "TakeCommand.h"
#include "Game.h"

TakeCommand::TakeCommand()
{
}


TakeCommand::~TakeCommand()
{
}

void TakeCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command) {
	//Todo geef 2 goudstukken aan de speler
	if (game->GetPhase() == Phase::GamePhase){
		if (command.get_player()->get_turn())
		{
			if (command.get_player()->Getpreturn()){
				command.get_player()->Setpreturn(false);
				int amount = 2;
				command.get_player()->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
				

				std::string message = "You have received ";
				message += std::to_string(amount) + " gold pieces \r\n";

				command.get_client()->write(message);
			}
		}
	}
}