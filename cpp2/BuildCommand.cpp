#include "stdafx.h"
#include "BuildCommand.h"
#include "Game.h"

BuildCommand::BuildCommand()
{
}


BuildCommand::~BuildCommand()
{
}

void BuildCommand::Execute(const ClientCommand command) {
	bool success = false;

	if (command.get_player()->get_turn())
	{
		for (int i = 0; i < command.get_player()->get_buildcards()->size(); i++)
		{
			if (command.get_player()->get_buildcards()->at(i)->get_name() == command.get_strings().at(1))
			{
				if (command.get_player()->get_buildcards()->at(i)->get_gold() < command.get_player()->GetGoldAmount())
				{
					//Pay
					command.get_player()->SetGoldAmount(command.get_player()->GetGoldAmount() - command.get_player()->get_buildcards()->at(i)->get_gold());
					Game::GetInstance()->GetDeck()->AddGoldPieces(command.get_player()->GetGoldAmount() - command.get_player()->get_buildcards()->at(i)->get_gold());

					//Build
					command.get_player()->add_building(command.get_player()->get_buildcards()->at(i));
					command.get_player()->remove_buildcard(command.get_player()->get_buildcards()->at(i));

					success = true;
				}
			}
			else
			{
				command.get_client()->write("You do not have enough money to buy that building!");
			}
		}
	}
}