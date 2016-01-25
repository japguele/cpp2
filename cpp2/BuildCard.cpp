#include "stdafx.h"
#include "BuildCard.h"
#include "Game.h"

BuildCard::BuildCard(int goldcost, BuildingType type,std::string name)
{
	m_name = name;
	m_goldcost = goldcost;
	m_type = type;
}

int BuildCard::get_gold(){
	return m_goldcost;
}
BuildingType BuildCard::get_buildingtype(){
	return m_type;
}
std::string BuildCard::get_name(){
	return m_name;
}

void BuildCard::SetOwner(std::shared_ptr<Player> player)
{
	owner = player;
}

std::shared_ptr<Player> BuildCard::GetOwner()
{
	return owner;
}

void BuildCard::Destroy()
{
	if (owner != nullptr)
	{
		Game::getInstance().GetDeck()->AddUsedCard(owner->remove_building(std::shared_ptr<BuildCard>(this)));
	}
}

BuildCard::~BuildCard()
{
}
