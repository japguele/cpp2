#pragma once
#include "PlayerCard.h"
class KingCard :
	public PlayerCard
{
public:
	KingCard(std::unique_ptr<CommandController> controller);
	~KingCard();

	void StartTurn();
	bool UseAbility();
};

