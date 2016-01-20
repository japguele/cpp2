#include "stdafx.h"
#include "MageCard.h"
#include "Game.h"

MageCard::MageCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "mage";
}


MageCard::~MageCard()
{
}

bool MageCard::UseAbility(std::shared_ptr<Game> game, std::string target)
{
	bool success = false;

	std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
	if (iValue != playerEnumMap.end())
	{
		for each (auto card in game->GetDeck()->GetAllPlayerCards())
		{
			if (card->GetOwner() != nullptr)
			{
				auto temp = owner->get_buildcards();
				owner->set_buildcards(card->GetOwner()->get_buildcards());
				card->GetOwner()->set_buildcards(temp);
			}
		}
	}

	return success;
}
