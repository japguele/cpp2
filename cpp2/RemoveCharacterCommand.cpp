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

void RemoveCharacterCommand::Execute(const ClientCommand command){
	if (Game::GetInstance()->CharacterPhase()){
		if (command.get_player()->get_turn()){
			if (Game::GetInstance()->GetDeck()->GetRemainingPlayerCards()->size() % 2 == 0){
				std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> vec = Game::GetInstance()->GetDeck()->GetRemainingPlayerCards();
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