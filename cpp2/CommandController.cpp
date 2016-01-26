#include "stdafx.h"
#include "CommandController.h"
#include "RemoveCharacterCommand.h"
#include "PickCharacterCommand.h"
#include "TakeCommand.h"
#include "DrawCommand.h"
#include "AbilityCommand.h"
#include "PrintCommand.h"
#include "BuildCommand.h"
#include "EndTurnCommand.h"
#include "ICommand.h"
#include "CheatCommand.h"
CommandController::CommandController()
{
	commands = std::unordered_map<std::string, std::shared_ptr<ICommand>>();
	commands.insert({ "join", std::make_shared<JoinCommand>() });
	commands.insert({ "list", std::make_shared<ListCommand>() });
	commands.insert({ "chat", std::make_shared<ChatCommand>() });
	commands.insert({ "print", std::make_shared<PrintCommand>() });

	commands.insert({ "remove", std::make_shared<RemoveCharacterCommand>() });
	commands.insert({ "pick", std::make_shared<PickCharacterCommand>() });
	commands.insert({ "endturn", std::make_shared<EndTurnCommand>() });
	commands.insert({ "cheateriam", std::make_shared<CheatCommand>() });
	commands.insert({ "gold", std::make_shared<TakeCommand>() });
	commands.insert({ "draw", std::make_shared<DrawCommand>() });
	commands.insert({ "ability", std::make_shared<AbilityCommand>() });

	commands.insert({ "built", std::make_shared<BuildCommand>() });
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
	printf("Command controller Destroyed");
}
