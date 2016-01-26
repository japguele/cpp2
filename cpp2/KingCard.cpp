#include "stdafx.h"
#include "KingCard.h"
#include "Game.h"

KingCard::KingCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "king";
	type = PlayerType::KoningRole;
}


KingCard::~KingCard()
{
}

void KingCard::StartTurn()
{
	for (int i = 0; i < owner->get_buildcards()->size(); i++)
	{
		auto card = owner->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Koning)
		{
			int amount = 1;
			owner->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		}
	}
}

std::shared_ptr<PlayerCard> KingCard::EmptyClone()
{
	return std::make_shared<KingCard>(controller);
}