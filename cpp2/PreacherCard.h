#pragma once
#include "PlayerCard.h"
class PreacherCard :
	public PlayerCard
{
public:
	PreacherCard(std::shared_ptr<CommandController> controller);
	~PreacherCard();

	virtual void StartTurn(std::shared_ptr<Player> player) override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

