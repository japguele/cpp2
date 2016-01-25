#pragma once
#include "PlayerCard.h"
class MerchantCard :
	public PlayerCard
{
public:
	MerchantCard(std::shared_ptr<CommandController> controller);
	~MerchantCard();

	virtual bool UseAbility(std::string target) override;
	virtual void StartTurn(std::shared_ptr<Player> player) override;
};

