#pragma once
#include "PlayerCard.h"
class ThiefCard :
	public PlayerCard
{
public:
	ThiefCard(std::shared_ptr<CommandController> controller);
	~ThiefCard();

	virtual bool UseAbility(std::shared_ptr<Game> game, std::string target) override;
};

