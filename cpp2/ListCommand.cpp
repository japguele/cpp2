#include "stdafx.h"
#include "ListCommand.h"
#include "Game.h"

ListCommand::ListCommand()
{
}


ListCommand::~ListCommand()
{
}
void ListCommand::Execute(const ClientCommand command){
	//std::set<std::shared_ptr<Player>> players = 
	command.get_client()->write("the following players are currently in the game : \n");
	for (auto it : Game::getInstance().GetPlayers()){
		command.get_client()->write(it->get_name() + "\n");
		}

}