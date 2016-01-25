#include "stdafx.h"
#include "TakeCommand.h"
#include "Game.h"

TakeCommand::TakeCommand()
{
}


TakeCommand::~TakeCommand()
{
}

void TakeCommand::Execute(const ClientCommand command) {
	//Todo geef 2 goudstukken aan de speler
	if (command.get_player()->get_turn())
	{
		int amount = 2;
		command.get_player()->AddGoldAmount(amount);
		Game::GetInstance()->GetDeck()->TakeGoldPieces(amount);

		std::string message = "You have received ";
		message += std::to_string(amount) + " gold pieces \r\n";

		command.get_client()->write(message);
	}
}