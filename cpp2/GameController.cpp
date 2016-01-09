#include "stdafx.h"
#include "GameController.h"


GameController::GameController()
{
	input = CommandController();
	game = std::shared_ptr<Game>(new Game());
}


GameController::~GameController()
{
}
void GameController::Execute(std::shared_ptr<Player> player, const ClientCommand command){


	std::shared_ptr<ICommand> com = input.GetCommand(command);
	if (com){
		com->Execute(game,command);
	}
	
}