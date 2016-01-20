#include "stdafx.h"
#include "ArchitectCard.h"
#include "Game.h"

ArchitectCard::ArchitectCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "architect";
}


ArchitectCard::~ArchitectCard()
{
}

bool ArchitectCard::UseAbility(std::shared_ptr<Game> game, std::string target)
{
	bool success = false;

	int amount = 2;
	owner->add_buildcards(game->GetDeck()->DrawCards(amount));
	
	return success;
}
