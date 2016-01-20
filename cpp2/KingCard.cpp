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

		if (card->get_buildingtype() == type)
		{
			int amount = 2;
			player->AddGoldAmount(amount);
			game->GetDeck()->TakeGoldPieces(amount);
		}
	}
}