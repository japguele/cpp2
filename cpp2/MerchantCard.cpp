#include "stdafx.h"
#include "MerchantCard.h"
#include "Game.h"

MerchantCard::MerchantCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "Merchant";
}


MerchantCard::~MerchantCard()
{
}

void MerchantCard::StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Koopman)
		{
			int amount = 1;
			player->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
		}
	}
}

bool MerchantCard::UseAbility(std::shared_ptr<Game> game, std::string target)
{
	bool success = false;

	int amount = 1;
	owner->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
	success = true;

	return success;
}