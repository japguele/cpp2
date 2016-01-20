#include "stdafx.h"
#include "PlayerCard.h"
#include "CommandController.h"

PlayerCard::PlayerCard(std::shared_ptr<CommandController> controller)
{
    m_commands = std::set<std::shared_ptr<ICommand>>();
	m_commands.insert(controller->GetCommand("join"));
	m_commands.insert(controller->GetCommand("chat"));
	m_commands.insert(controller->GetCommand("list"));	

	playerEnumMap["moordenaar"] = MoordenaarRole;
	playerEnumMap["dief"] = DiefRole;
	playerEnumMap["magier"] = MagierRole;
	playerEnumMap["koning"] = KoningRole;
	playerEnumMap["prediker"] = PredikerRole;
	playerEnumMap["koopman"] = KoopmanRole;
	playerEnumMap["bouwmeester"] = BouwmeesterRole;
	playerEnumMap["condotierre"] = CondotierreRole;

	buildingEnumMap["koning"] = Koning;
	buildingEnumMap["prediker"] = Prediker;
	buildingEnumMap["koopman"] = Koopman;
	buildingEnumMap["condotierre"] = Condotierre;
	buildingEnumMap["keuze"] = Keuze;

	dead = false;
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

void PlayerCard::StartTurn(std::shared_ptr<Player> player, std::shared_ptr<Game> game)
{
}

bool PlayerCard::UseAbility(std::shared_ptr<Game> game, std::string target)
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