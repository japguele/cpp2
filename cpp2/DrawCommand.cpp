#include "stdafx.h"
#include <map>
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
	//command.get_player()->add_buildcards(game->GetDeck()->DrawCards(amount));

	std::map <BuildingType, std::string> enumMap =
	{
		{ Koning, "king" },
		{ Prediker, "preacher" },
		{ Koopman, "merchant" },
		{ Condotierre, "condotierre" },
		{ Keuze, "keuze" }
	};

	auto cards = game->GetDeck()->DrawCards(amount);
	std::string message;

	message += "You have drawn: \r\n";

	for (int i = 0; i < cards.size(); i++)
	{
		std::map <BuildingType, std::string>::const_iterator iValue = enumMap.find(cards.at(i)->get_buildingtype());

		message += "[" + i; 
		message += "]";
		message += cards.at(i)->get_name() + " (";
		message += iValue->second + ", ";
		message += cards.at(i)->get_gold() + "):\r\n";
	}
	message += "\r\n\n";

	message += "Select which one you want to discard";
}