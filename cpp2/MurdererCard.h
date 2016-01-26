#pragma once
#include "PlayerCard.h"
class MurdererCard :
	public PlayerCard
{
public:
	MurdererCard(std::shared_ptr<CommandController> controller);
	~MurdererCard();

	virtual bool UseAbility( std::string target) override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

