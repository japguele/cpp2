#pragma once
#include "PlayerCard.h"
class ArchitectCard :
	public PlayerCard
{
public:
	ArchitectCard(std::shared_ptr<CommandController> controller);
	~ArchitectCard();

	virtual bool UseAbility(std::string target) override;
};

