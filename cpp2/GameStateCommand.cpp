#include "stdafx.h"
#include "GameStateCommand.h"
#include "Game.h"

GameStateCommand::GameStateCommand()
{
}


GameStateCommand::~GameStateCommand()
{
}

void GameStateCommand::Execute(const ClientCommand command){
	
	std::string message = "";
	for each(std::shared_ptr<Player> p in Game::getInstance().GetPlayers()){
		message = message + p->get_name() + " : \r\n building : \r\n";
		for each(std::shared_ptr<BuildCard> building in *p->get_buildings()){
			message = message + "[" + std::to_string(building->get_gold()) + "]" + building->get_name() + " \r\n";

		}		
		message = message + "gold : " + std::to_string(p->GetGoldAmount()) + " \r\n";	
	}
	command.get_client()->write(message);

}