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
		
		bool abilityUsed = false;

		for each (auto role in roles)
		{
			if (command.get_strings().size() > 0 && role->GetName() == command.get_strings().at(1) && !role->IsDead())
			{
				if(command.get_strings().size() > 2)
					role->UseAbility(command.get_strings().at(2));

				else
					role->UseAbility("");

				abilityUsed = true;
			}	
		}

		if (!abilityUsed)
		{
			std::string message = "Ability could not be found!";
			message += "\r\n";
			command.get_player()->get_client()->write(message);
		}
	}
}