#pragma once
#include "BuildingType.h"
#include <string>
class BuildCard
{
public:
	BuildCard(int goldcost, BuildingType type, std::string name);
	virtual ~BuildCard();

	int get_gold();
	BuildingType get_buildingtype();
	std::string get_name();
private:
	int m_goldcost;
	BuildingType m_type;
	std::string m_name;

};

