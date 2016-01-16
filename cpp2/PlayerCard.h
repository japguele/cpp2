#pragma once
#include "CommandController.h"	
class PlayerCard
{
public:
	PlayerCard(std::unique_ptr<CommandController> controller);
	virtual ~PlayerCard();
	bool CanDoCommand(std::shared_ptr<ICommand> command);

private:
	std::set<std::shared_ptr<ICommand>> commands;

	
};

