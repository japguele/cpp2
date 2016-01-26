#pragma once
#include "CommandController.h"	
#include "PlayerType.h"
#include "BuildCard.h"
#include <set>
#include <map>
//class CommandController;
class PlayerCard
{
public:
	PlayerCard(std::shared_ptr<CommandController> controller);
	virtual ~PlayerCard();
	bool CanDoCommand(std::shared_ptr<ICommand> command);
	std::string GetName();

	void SetType(PlayerType _type);
	PlayerType GetType();

	void SetOwner(std::shared_ptr<Player> player);
	std::shared_ptr<Player> GetOwner();

	bool IsDead();
	void Reset();

	virtual void StartTurn();
	virtual bool UseAbility(std::string target);
	void Die();

	virtual std::shared_ptr<PlayerCard> EmptyClone() = 0;
protected:
	std::shared_ptr<CommandController> controller;
	std::string m_name;
	std::set<std::shared_ptr<ICommand>> m_commands;
	PlayerType type;
	bool abilityUsed;
	std::shared_ptr<Player> owner = nullptr;
	bool dead;

	std::map <std::string, PlayerType> playerEnumMap;
	std::map <std::string, BuildingType> buildingEnumMap;
};

