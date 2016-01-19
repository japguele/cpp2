#include "stdafx.h"
#include "PlayerCard.h"
#include "CommandController.h"

PlayerCard::PlayerCard(std::shared_ptr<CommandController> controller)
{
        m_commands = std::set<std::shared_ptr<ICommand>>();
	m_commands.insert(controller->GetCommand("join"));
	m_commands.insert(controller->GetCommand("chat"));
	m_commands.insert(controller->GetCommand("list"));	
}

bool PlayerCard::CanDoCommand(std::shared_ptr<ICommand> command){
	return (m_commands.find(command) != m_commands.end());
}

PlayerCard::~PlayerCard()
{
}

std::string PlayerCard::GetName(){
	return m_name;
}
