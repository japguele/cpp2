#include "stdafx.h"
#include "PreacherCard.h"
#include "Game.h"

PreacherCard::PreacherCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "preacher";
}


PreacherCard::~PreacherCard()
{
}

void PreacherCard::StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Prediker)
		{
			int amount = 1;
			player->AddGoldAmount(game->GetDeck()->TakeGoldPieces(amount));
		} 
	}
}
