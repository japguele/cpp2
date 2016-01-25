#include "stdafx.h"
#include "MurdererCard.h"
#include "Game.h"

MurdererCard::MurdererCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "murderer";
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
		for each (auto card in Game::GetInstance()->GetDeck()->GetAllPlayerCards())
		{
			if (card->GetType() == iValue->second)
			{
				card->Die(Game::GetInstance()->GetCurrentPlayer());
				success = true;
			}
		}		
	}

	return success;
}

