#pragma once

#include <string>
#include "Player.hpp"
#include <memory>
#include "ClientCommand.h"
#include "CommandController.h"

class GameController
{
public:
	GameController();
	~GameController();
	void Execute(std::shared_ptr<Player>, const ClientCommand command);

private:
	std::shared_ptr<Game> game;
	CommandController input;
};

