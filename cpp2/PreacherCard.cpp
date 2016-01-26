#include "stdafx.h"
#include "PreacherCard.h"
#include "Game.h"

PreacherCard::PreacherCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "preacher";
	type = PlayerType::PredikerRole;
}


PreacherCard::~PreacherCard()
{
}

void PreacherCard::StartTurn()
{
	for (int i = 0; i < owner->get_buildcards()->size(); i++)
	{
		auto card = owner->get_buildcards()->at(i);

		if (card->get_buildingtype() == BuildingType::Prediker)
		{
			int amount = 1;
			owner->AddGoldAmount(Game::getInstance().GetDeck()->TakeGoldPieces(amount));
		} 
	}
}

std::shared_ptr<PlayerCard> PreacherCard::EmptyClone()
{
	return std::make_shared<PreacherCard>(controller);
}