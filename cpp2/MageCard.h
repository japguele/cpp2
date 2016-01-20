#pragma once
#include "PlayerCard.h"
class MageCard :
	public PlayerCard
{
public:
	MageCard(std::shared_ptr<CommandController> controller);
	~MageCard();

	virtual bool UseAbility(std::shared_ptr<Game> game, std::string target) override;
};

