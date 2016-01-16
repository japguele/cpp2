#include "stdafx.h"
#include "PlayerCard.h"


PlayerCard::PlayerCard(std::unique_ptr<CommandController> controller)
{
	commands = std::set<std::shared_ptr<ICommand>>();
	commands.insert(controller->GetCommand("Join"));
	commands.insert(controller->GetCommand("Chat"));
	commands.insert(controller->GetCommand("List"));

}
bool PlayerCard::CanDoCommand(std::shared_ptr<ICommand> command){
	return (commands.find(command) != commands.end());
}

PlayerCard::~PlayerCard()
{
}
