#pragma once
#include "CommandController.h"	
#include <set>
//class CommandController;
class PlayerCard
{
public:
	PlayerCard(std::shared_ptr<CommandController> controller);
	virtual ~PlayerCard();
	bool CanDoCommand(std::shared_ptr<ICommand> command);
	std::string GetName();
private:
	std::string m_name = "errorplayercard";
	std::set<std::shared_ptr<ICommand>> m_commands;

	
};

