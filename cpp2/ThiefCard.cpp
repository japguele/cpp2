#include "stdafx.h"
#include "ThiefCard.h"
#include "Game.h"

ThiefCard::ThiefCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "thief";
	type = PlayerType::DiefRole;
}


ThiefCard::~ThiefCard()
{
}

bool ThiefCard::UseAbility( std::string target)
{
	bool success = false;

	if (!abilityUsed)
	{
		std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
		if (iValue != playerEnumMap.end())
		{
			for each (auto card in Game::getInstance().GetDeck()->GetAllPlayerCards())
			{
				if (card->GetOwner() != nullptr && card->GetName() == target)
				{
					owner->AddGoldAmount(card->GetOwner()->GetGoldAmount());
					card->GetOwner()->SetGoldAmount(0);
					success = true;

					std::string message = "You have stolen all gold pieces from the " + target;
					message += "\r\n";
					owner->get_client()->write(message);

					abilityUsed = true;
				}
				else
				{
					std::string message = "Target could not be found: " + target;
					message += "\r\n";
					owner->get_client()->write(message);
				}
			}
		}
		else
		{
			std::string message = "Target does not exist: " + target;
			message += "\r\n";
			owner->get_client()->write(message);
		}
	}
	else
	{
		std::string message = "You have already used this ability this turn";
		message += "\r\n";
		owner->get_client()->write(message);
	}
	return success;
}

std::shared_ptr<PlayerCard> ThiefCard::EmptyClone()
{
	return std::make_shared<ThiefCard>(controller);
}