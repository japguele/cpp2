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

void PreacherCard::StartTurn(std::shared_ptr<Player> player)
{
	for (int i = 0; i < player->get_buildcards()->size(); i++)
	{
		auto card = player->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Prediker)
		{
			int amount = 1;
			player->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		} 
	}
}

std::shared_ptr<PlayerCard> PreacherCard::EmptyClone()
{
	return std::make_shared<PreacherCard>(controller);
}