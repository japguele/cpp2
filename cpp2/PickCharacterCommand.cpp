#include "stdafx.h"
#include "PickCharacterCommand.h"
#include "Game.h"
#include "PlayerCard.h"

PickCharacterCommand::PickCharacterCommand()
{
}


PickCharacterCommand::~PickCharacterCommand()
{
}

void PickCharacterCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command){
	//if (game->)
	if (game->CharacterPhase()){
		if (command.get_player()->get_turn()){
			if (game->GetDeck()->GetRemainingPlayerCards()->size() % 2 != 0){
				std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> vec = game->GetDeck()->GetRemainingPlayerCards();
				bool done = false;
				std::vector<std::shared_ptr<PlayerCard>>::iterator temp;
				for (auto it = vec->begin(); it != vec->end() && !done; ++it) {
					/* std::cout << *-> ... */
					if (it->get()->GetName() == command.get_strings().at(1)){
						done = true;
						std::vector<std::shared_ptr<PlayerCard>>  vect = command.get_player()->GetCurrentRoles();
						vect.push_back(*it);
						command.get_player()->SetCurrentRoles(vect);
						temp = it;
						command.get_client()->write("Added " + it->get()->GetName() + " to your Characterlist \r\n");						
					}
				}
				
				if (!done){
					command.get_client()->write("card  " + command.get_strings().at(1) + " is not in the remaining characterlist \r\n");
				}
				else{
					vec->erase(temp);
					game->EndTurn();
				}
			}
		}
	}
}