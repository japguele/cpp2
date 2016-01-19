#pragma once
#include <unordered_map>

#include <sstream> 
#include "ClientCommand.h"
#include "JoinCommand.h"
#include "ListCommand.h"
#include "ChatCommand.h"

class CommandController
{
public:
	CommandController();
	~CommandController();
	std::shared_ptr<ICommand> GetCommand(ClientCommand command);
	std::shared_ptr<ICommand> GetCommand(std::string name);
private:
	std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

	
	
};

