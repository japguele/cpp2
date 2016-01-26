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

bool ArchitectCard::UseAbility(std::string target)
{
	bool success = false;

	int amount = 2;
	owner->add_buildcards(Game::getInstance().GetDeck()->DrawCards(amount));
	
	return success;
}

std::shared_ptr<PlayerCard> ArchitectCard::EmptyClone()
{
	return std::make_shared<ArchitectCard>(controller);
}