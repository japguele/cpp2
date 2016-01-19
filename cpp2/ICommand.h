#pragma once
#include <memory>
#include "Player.hpp"
#include "ClientCommand.h"

class Game;
class ICommand
{
public:

	virtual void Execute(std::shared_ptr<Game> game, const ClientCommand command) = 0;
};

