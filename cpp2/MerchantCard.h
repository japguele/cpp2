#pragma once
#include "PlayerCard.h"
class MerchantCard :
	public PlayerCard
{
public:
	MerchantCard(std::shared_ptr<CommandController> controller);
	~MerchantCard();

	virtual bool UseAbility( std::string target) override;
	virtual void StartTurn() override;

	virtual std::shared_ptr<PlayerCard> EmptyClone() override;
};

