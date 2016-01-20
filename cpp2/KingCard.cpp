#include "stdafx.h"
#include "KingCard.h"
#include "Game.h"

KingCard::KingCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
}


KingCard::~KingCard()
{
}

void KingCard::StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Koning)
		{
			int amount = 1;
			player->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
		}
	}
}