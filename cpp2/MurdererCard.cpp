#include "stdafx.h"
#include "MurdererCard.h"
#include "Game.h"

MurdererCard::MurdererCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
}


MurdererCard::~MurdererCard()
{
}

bool MurdererCard::UseAbility(std::shared_ptr<Game> game, std::string target)
{
	bool success = false;
	
	std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
	if (iValue != playerEnumMap.end())
	{
		for each (auto card in game->GetDeck()->GetAllPlayerCards())
		{
			if (card->GetType() == iValue->second)
			{
				card->Die(game->GetCurrentPlayer());
				success = true;
			}
		}		
	}

	return success;
}

