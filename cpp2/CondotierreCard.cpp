#include "stdafx.h"
#include "CondotierreCard.h"
#include "Game.h"

CondotierreCard::CondotierreCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "condotierre";
	type = CondotierreRole;
}


CondotierreCard::~CondotierreCard()
{
}

void CondotierreCard::StartTurn()
{
	for (int i = 0; i < owner->get_buildcards()->size(); i++)
	{
		auto card = owner->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Condotierre)
		{
			int amount = 1;
			owner->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		}
	}
}

bool CondotierreCard::UseAbility(std::string target)
{
	bool success = false;
	if (!abilityUsed)
	{
		for each (auto player in Game::getInstance().GetPlayers())
		{
			if (player != owner){


				for (int i = 0; i < player->get_buildings()->size(); i++)
				{
					if (player->get_buildings()->at(i)->get_name() == target && player->get_buildings()->at(i)->get_gold() - 1 <= owner->GetGoldAmount() && player->get_buildings()->at(i)->get_buildingtype() != Prediker)
					{
						owner->SetGoldAmount(owner->GetGoldAmount() - (player->get_buildings()->at(i)->get_gold() - 1));

						Game::getInstance().GetDeck()->AddUsedCard(player->remove_building(player->get_buildings()->at(i)));
						abilityUsed = true;
						Game::getInstance().SendMessageToAll(" A building has been destroyed \r\n");

					}
				}
			}
		}
	}

	return success;
}

std::shared_ptr<PlayerCard> CondotierreCard::EmptyClone()
{
	return std::make_shared<CondotierreCard>(controller);
}

