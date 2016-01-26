#pragma once
#include "PlayerCard.h"
class CondotierreCard :
	public PlayerCard
{
public:
	CondotierreCard(std::shared_ptr<CommandController> controller);
	~CondotierreCard();

	virtual void StartTurn() override;
	virtual bool UseAbility(std::string target) override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

