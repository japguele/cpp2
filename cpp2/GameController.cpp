#include "stdafx.h"
#include "GameController.h"


GameController::GameController()
{
	input = std::make_shared<CommandController>();
	game = std::make_shared<Game>(input);
}

GameController::~GameController()
{
	printf("Game controller Destroyed");
}

void GameController::Execute(std::shared_ptr<Player> player, const ClientCommand command){


	std::shared_ptr<ICommand> com = input->GetCommand(command);
	if (com){
		com->Execute(game,command);
	}	
}