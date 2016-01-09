#include "stdafx.h"
#include "BuildCard.h"


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
BuildCard::~BuildCard()
{
}
