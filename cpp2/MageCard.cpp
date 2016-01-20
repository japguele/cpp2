#include "stdafx.h"
#include "MageCard.h"
#include "Game.h"

MageCard::MageCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
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
		//Get all cards of targets hand;
	}

	return success;
}
