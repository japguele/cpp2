#pragma once
#include <unordered_map>
#include "ICommand.h"
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
private:
	std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

	
	
};

