#include "stdafx.h"
#include "MageCard.h"
#include "Game.h"

MageCard::MageCard(std::shared_ptr<CommandController> controller) :
	PlayerCard(controller)
{
	m_name = "mage";
	type = PlayerType::MagierRole;
}


MageCard::~MageCard()
{
}

bool MageCard::UseAbility( std::string target)
{
	bool success = false;

	if(!abilityUsed)
	{
		std::map <std::string, PlayerType>::const_iterator iValue = playerEnumMap.find(target);
		if (iValue != playerEnumMap.end())
		{
			for each (auto card in Game::getInstance().GetDeck()->GetAllPlayerCards())
			{
				if (card->GetOwner() != nullptr && card->GetName() == target)
				{
					auto temp = owner->get_buildcards();
					owner->set_buildcards(card->GetOwner()->get_buildcards());
					card->GetOwner()->set_buildcards(temp);
					success = true;

					std::string message = "You have switched with the hand of the " + target;
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

std::shared_ptr<PlayerCard> MageCard::EmptyClone()
{
	return std::make_shared<MageCard>(controller);
}