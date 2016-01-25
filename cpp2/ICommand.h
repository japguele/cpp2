#pragma once
#include <memory>
#include "Player.hpp"
#include "ClientCommand.h"

class Game;
class ICommand
{
public:

	virtual void Execute(const ClientCommand command) = 0;
};

