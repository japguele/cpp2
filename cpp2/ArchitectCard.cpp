#include "stdafx.h"
#include "ArchitectCard.h"
#include "Game.h"

ArchitectCard::ArchitectCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "architect";
	type = PlayerType::BouwmeesterRole;
}


ArchitectCard::~ArchitectCard()
{
}


void ArchitectCard::StartTurn()
{
	int amount = 2;
	owner->add_buildcards(Game::getInstance().GetDeck()->DrawCards(amount));
	owner->get_client()->write("You recieve 2 buildcard for being the architect \r\n");

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