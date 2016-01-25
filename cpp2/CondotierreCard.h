#pragma once
#include "PlayerCard.h"
class CondotierreCard :
	public PlayerCard
{
public:
	CondotierreCard(std::shared_ptr<CommandController> controller);
	~CondotierreCard();

	virtual void StartTurn(std::shared_ptr<Player> player) override;
	virtual bool UseAbility(std::string target) override;
};

