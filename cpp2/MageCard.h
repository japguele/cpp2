#pragma once
#include "PlayerCard.h"
class MageCard :
	public PlayerCard
{
public:
	MageCard(std::shared_ptr<CommandController> controller);
	~MageCard();

	virtual bool UseAbility(std::string target) override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

