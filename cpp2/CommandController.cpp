#include "stdafx.h"
#include "CommandController.h"
#include "RemoveCharacterCommand.h"
#include "PickCharacterCommand.h"
#include "TakeCommand.h"
#include "PrintCommand.h"
#include "ICommand.h"
CommandController::CommandController()
{
	commands = std::unordered_map<std::string, std::shared_ptr<ICommand>>();
	commands.insert({ "join", std::shared_ptr<JoinCommand>(new JoinCommand()) });
	commands.insert({ "list", std::shared_ptr<ListCommand>(new ListCommand()) });
	commands.insert({ "chat", std::shared_ptr<ChatCommand>(new ChatCommand()) });
	commands.insert({ "print", std::shared_ptr<PrintCommand>(new PrintCommand()) });

	commands.insert({ "remove", std::shared_ptr<RemoveCharacterCommand>(new RemoveCharacterCommand()) });
	commands.insert({ "pick", std::shared_ptr<PickCharacterCommand>(new PickCharacterCommand()) });

	commands.insert({ "gold", std::shared_ptr<TakeCommand>(new TakeCommand()) });
}

std::shared_ptr<ICommand> CommandController::GetCommand(std::string name){
	return commands.at(name);
}
std::shared_ptr<ICommand> CommandController::GetCommand(ClientCommand command)
{
	
	try{
			/* do stuff with word */
		return commands.at(command.get_strings().at(0).c_str());
	}
	catch (std::out_of_range) {
		command.get_client()->write("I don't know that.\n");
		
	}
	return nullptr;
}

CommandController::~CommandController()
{
}
