#include "stdafx.h"
#include "ThiefCard.h"
#include "Game.h"

ThiefCard::ThiefCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "thief";
}


ThiefCard::~ThiefCard()
{
}

bool ThiefCard::UseAbility(std::string target)
{
	bool success = false;

	std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
	if (iValue != playerEnumMap.end())
	{
		for each (auto card in Game::GetInstance()->GetDeck()->GetAllPlayerCards())
		{
			if (card->GetOwner() != nullptr)
			{
				owner->AddGoldAmount(card->GetOwner()->GetGoldAmount());
				card->GetOwner()->SetGoldAmount(0);
				success = true;
			}
		}
	}

	return success;
}