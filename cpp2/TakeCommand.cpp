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
	int amount = 2;
	command.get_player()->AddGoldAmount(amount);
	game->GetDeck()->TakeGoldPieces(amount);

	std::string message = "You have received ";
	message += std::to_string(amount) + " gold pieces \r\n";

	command.get_client()->write(message);
}