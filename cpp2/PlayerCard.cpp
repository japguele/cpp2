#include "stdafx.h"
#include "PlayerCard.h"
#include "CommandController.h"

PlayerCard::PlayerCard(std::shared_ptr<CommandController> controller)
{
    m_commands = std::set<std::shared_ptr<ICommand>>();
	m_commands.insert(controller->GetCommand("join"));
	m_commands.insert(controller->GetCommand("chat"));
	m_commands.insert(controller->GetCommand("list"));	

	playerEnumMap["murderer"] = MoordenaarRole;
	playerEnumMap["thief"] = DiefRole;
	playerEnumMap["mage"] = MagierRole;
	playerEnumMap["king"] = KoningRole;
	playerEnumMap["preacher"] = PredikerRole;
	playerEnumMap["merchant"] = KoopmanRole;
	playerEnumMap["architect"] = BouwmeesterRole;
	playerEnumMap["condotierre"] = CondotierreRole;

	buildingEnumMap["king"] = Koning;
	buildingEnumMap["preacher"] = Prediker;
	buildingEnumMap["architect"] = Koopman;
	buildingEnumMap["condotierre"] = Condotierre;
	buildingEnumMap["choice"] = Keuze;

	m_name = "error_no_name";
	dead = false;
	abilityUsed = false;
}

bool PlayerCard::CanDoCommand(std::shared_ptr<ICommand> command){
	return (m_commands.find(command) != m_commands.end());
}

PlayerCard::~PlayerCard()
{
}

std::string PlayerCard::GetName(){
	return m_name;
}

void PlayerCard::SetType(PlayerType _type)
{
	type = _type;
}

PlayerType PlayerCard::GetType()
{
	return type;
}

void PlayerCard::SetOwner(std::shared_ptr<Player> player)
{
	owner = player;
}

std::shared_ptr<Player> PlayerCard::GetOwner()
{
	return owner;
}

void PlayerCard::StartTurn(std::shared_ptr<Player> player)
{
}

bool PlayerCard::UseAbility(std::string target)
{
	return false;
}

void PlayerCard::Die(std::shared_ptr <Player> player)
{
	dead = true;
}

bool PlayerCard::IsDead()
{
	return dead;
}

void PlayerCard::Reset()
{
	abilityUsed = false;
	owner = nullptr;
	dead = false;
}