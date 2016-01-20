#pragma once
#include "PlayerCard.h"
class MurdererCard :
	public PlayerCard
{
public:
	MurdererCard(std::shared_ptr<CommandController> controller);
	~MurdererCard();

	virtual bool UseAbility(std::shared_ptr<Game> game, std::string target) override;
};

