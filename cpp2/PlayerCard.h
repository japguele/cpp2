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

	virtual void StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game);
	virtual bool UseAbility(std::shared_ptr<Game> game, std::string target);
	virtual void Die(std::shared_ptr<Player> player);

protected:
	std::string m_name = "errorplayercard";
	std::set<std::shared_ptr<ICommand>> m_commands;
	PlayerType type;
	std::shared_ptr<Player> owner;
	bool dead;

	std::map <std::string, PlayerType> playerEnumMap;
	std::map <std::string, BuildingType> buildingEnumMap;
};

