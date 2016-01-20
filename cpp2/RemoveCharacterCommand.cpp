#include "stdafx.h"
#include "RemoveCharacterCommand.h"
#include "Game.h"
#include "PlayerCard.h"

RemoveCharacterCommand::RemoveCharacterCommand()
{
}


RemoveCharacterCommand::~RemoveCharacterCommand()
{
}

void RemoveCharacterCommand::Execute(std::shared_ptr<Game> game, const ClientCommand command){
	if (game->CharacterPhase()){
		if (command.get_player()->get_turn()){
			if (game->GetDeck()->GetRemainingPlayerCards()->size() % 2 == 0){
				std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> vec = game->GetDeck()->GetRemainingPlayerCards();
				bool done = false;
				std::vector<std::shared_ptr<PlayerCard>>::iterator temp;
				for (auto it = vec->begin(); it != vec->end() && !done; ++it) {
					/* std::cout << *it; ... */
					if (it->get()->GetName() == command.get_strings().at(1)){
						done = true;
						
						temp = it;
						command.get_client()->write("Removed Player card \r\n");
						command.get_client()->write("Please select a PlayerCard \r\n");
					}

				}
					
				
				if (!done){
					command.get_client()->write("Could not remove that Player card \r\n");
				}
				else{
					vec->erase(temp);
				}


			}

		}


	}

}