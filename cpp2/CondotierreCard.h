#pragma once
#include "PlayerCard.h"
class CondotierreCard :
	public PlayerCard
{
public:
	CondotierreCard(std::shared_ptr<CommandController> controller);
	~CondotierreCard();

	virtual void StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game) override;
	virtual bool UseAbility(std::shared_ptr<Game> game, std::string target) override;
};

