#include "stdafx.h"
#include "MurdererCard.h"
#include "Game.h"

MurdererCard::MurdererCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "murderer";
	type = PlayerType::MoordenaarRole;
}


MurdererCard::~MurdererCard()
{
}

bool MurdererCard::UseAbility(std::string target)
{
	bool success = false;
	
	std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
	if (iValue != playerEnumMap.end())
	{
		for each (auto card in Game::getInstance().GetDeck()->GetAllPlayerCards())
		{
			if (card->GetType() == iValue->second)
			{
				card->Die();
				Game::getInstance().SendMessageToAll("Murderer has killed the " + target + " \r\n");
				success = true;
			}
		}		
	}

	return success;
}

std::shared_ptr<PlayerCard> MurdererCard::EmptyClone()
{
	return std::make_shared<MurdererCard>(controller);
}

