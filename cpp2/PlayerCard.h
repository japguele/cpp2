#pragma once
#include "CommandController.h"	
#include <set>
//class CommandController;
class PlayerCard
{
public:
	PlayerCard(std::shared_ptr<CommandController> controller);
	virtual ~PlayerCard();
	bool CanDoCommand(std::shared_ptr<ICommand> command);
	std::string GetName();

	void SetType(BuildingType _type);
	BuildingType GetType();

	virtual void StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game);
	virtual bool UseAbility();

protected:
	std::string m_name = "error playercard please override ";
	std::set<std::shared_ptr<ICommand>> m_commands;
	BuildingType type;
};

