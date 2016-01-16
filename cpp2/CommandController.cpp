#include "stdafx.h"
#include "CommandController.h"


CommandController::CommandController()
{
	commands = std::unordered_map<std::string, std::shared_ptr<ICommand>>();
	commands.insert({ "join", std::shared_ptr<JoinCommand>(new JoinCommand()) });
	commands.insert({ "list", std::shared_ptr<ListCommand>(new ListCommand()) });
	commands.insert({ "chat", std::shared_ptr<ChatCommand>(new ChatCommand()) });
}

std::shared_ptr<ICommand> CommandController::GetCommand(std::string name){
	return commands.at(name);
}
std::shared_ptr<ICommand> CommandController::GetCommand(ClientCommand command)
{
	
	try{
		std::istringstream iss(command.get_cmd());
		std::string word;
		if (iss >> word) {
			/* do stuff with word */
			return commands.at(word);
		
		}
		else{
			command.get_client()->write("I don't know that.\n");
			
		}

	}
	catch (std::out_of_range) {
		command.get_client()->write("I don't know that.\n");
		
	}
	return nullptr;
}

CommandController::~CommandController()
{
}
