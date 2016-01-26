#pragma once
#include "PlayerCard.h"
class KingCard :
	public PlayerCard
{
public:
	KingCard(std::shared_ptr<CommandController> controller);
	~KingCard();

	virtual void StartTurn() override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

