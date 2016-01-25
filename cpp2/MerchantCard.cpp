#include "stdafx.h"
#include "MerchantCard.h"
#include "Game.h"

MerchantCard::MerchantCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "merchant";
}


MerchantCard::~MerchantCard()
{
}

void MerchantCard::StartTurn(std::shared_ptr<Player> player)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Koopman)
		{
			int amount = 1;
			player->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		}
	}
}

bool MerchantCard::UseAbility(std::string target)
{
	bool success = false;
	if (!abilityUsed)
	{	
		int amount = 1;
		owner->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		success = true;
	
		std::string message = "You have received extra gold!";
		message += "\r\n";
		owner->get_client()->write(message);
		abilityUsed = true;
	}
	else
	{
		std::string message = "You have already used this ability this turn";
		message += "\r\n";
		owner->get_client()->write(message);
	}
	return success;
}