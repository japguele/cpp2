#pragma once
#include "PlayerCard.h"
class KingCard :
	public PlayerCard
{
public:
	KingCard(std::shared_ptr<CommandController> controller);
	~KingCard();

	virtual void StartTurn(std::shared_ptr<Player> player) override;
};

