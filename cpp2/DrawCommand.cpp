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

void DrawCommand::Execute(const ClientCommand command) {
	//TODO: geef 2 kaarten aan speler
	if (Game::getInstance().GetPhase() == Phase::GamePhase){
		if (command.get_player()->get_turn())
		{
			if (command.get_player()->Getpreturn()){

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

				std::vector<std::shared_ptr<BuildCard>> cards = Game::getInstance().GetDeck()->DrawCards(amount);
				std::string message;

				message += "You have drawn: \r\n";

				for (int i = 0; i < cards.size(); i++)
				{
					std::map <BuildingType, std::string>::const_iterator iValue = enumMap.find(cards.at(i)->get_buildingtype());

					message = message + "[" + std::to_string(i);
					message += "]";
					message += cards.at(i)->get_name() + " (";
					message += iValue->second + ", ";
					message = message + std::to_string(cards.at(i)->get_gold()) + ") : \r\n";
				}
				message += "\r\n\n";
				message += "Select which one you want to discard\r\n";
				command.get_client()->write(message);

				int y  = -1;
				while (y == -1 ||( !(y < cards.size()) && !(y > -1)))
				{		
					y = atoi(command.get_client()->readline().c_str());
				}
			

				auto temp = cards[y];
				cards.erase(cards.begin() + y);
				command.get_client()->write("removed card : " + temp->get_name() + " \n");
				command.get_client()->write("Please select an action\r\n");
				command.get_player()->add_buildcards(cards);
				command.get_player()->Setpreturn(false);



			}
		}	
	}
}