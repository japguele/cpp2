#include "stdafx.h"
#include "AbilityCommand.h"
#include "PlayerCard.h"

AbilityCommand::AbilityCommand()
{
}


AbilityCommand::~AbilityCommand()
{
}

void AbilityCommand::Execute(const ClientCommand command) {
	//Todo gebruik de speciale ability van de huidige rol
	if (command.get_player()->get_turn()) 
	{
		auto roles = command.get_player()->GetCurrentRoles();
		
		for each (auto role in roles)
		{
			if (role->GetName() == command.get_strings().at(1))
			{
				role->UseAbility(command.get_strings().at(2));
			}
		}
	}
}