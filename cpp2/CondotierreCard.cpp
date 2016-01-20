#include "stdafx.h"
#include "CondotierreCard.h"
#include "Game.h"

CondotierreCard::CondotierreCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "condotierre";
}


CondotierreCard::~CondotierreCard()
{
}

void CondotierreCard::StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Condotierre)
		{
			int amount = 1;
			player->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
		}
	}
}

bool CondotierreCard::UseAbility(std::shared_ptr<Game> game, std::string target)
{
	bool success = false;
	
	for each (auto player in game->GetPlayers())
	{
		for (int i = 0; i < player->get_buildings()->size(); i++)
		{
			if (player->get_buildings()->at(i)->get_name() == target && player->get_buildings()->at(i)->get_gold() - 1 < owner->GetGoldAmount())
			{
				player->get_buildings()->at(i)->Destroy(game);
				owner->SetGoldAmount(owner->GetGoldAmount() - (player->get_buildings()->at(i)->get_gold() - 1));
			}
		}
	}

	return success;
}


