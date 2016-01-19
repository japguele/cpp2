#include "stdafx.h"
#include "ChatCommand.h"
#include "Game.h"

ChatCommand::ChatCommand()
{
}


ChatCommand::~ChatCommand()
{
}

void ChatCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command){
	std::string sentence = command.get_cmd();
	sentence = sentence.substr(sentence.find_first_of(" \t") + 1);
		game->SendMessageToAll(command.get_player()->get_name() + " : " + sentence);
}