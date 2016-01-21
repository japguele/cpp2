#include "stdafx.h"
#include "BaseState.h"
#include "ListCommand.h"
#include "ChatCommand.h"

BaseState::BaseState()
{
	commands = std::unordered_map<std::string, std::shared_ptr<ICommand>>();
	commands.insert({ "list", std::shared_ptr<ListCommand>(new ListCommand()) });
	commands.insert({ "chat", std::shared_ptr<ChatCommand>(new ChatCommand()) });
}


BaseState::~BaseState()
{
}
