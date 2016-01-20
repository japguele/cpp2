#include "stdafx.h"
#include "DrawCommand.h"
#include "Game.h"

DrawCommand::DrawCommand()
{
}


DrawCommand::~DrawCommand()
{
}

void DrawCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command) {
	//TODO: geef 2 kaarten aan speler
	int amount = 2;
	command.get_player()->add_buildcards(game->GetDeck()->DrawCards(amount));
}