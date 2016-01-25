#pragma once
#include <string>
#include <memory>
#include "BuildingType.h"


class Player;
class Game;
class BuildCard
{
public:
	BuildCard(int goldcost, BuildingType type, std::string name);
	virtual ~BuildCard();

	int get_gold();
	BuildingType get_buildingtype();
	std::string get_name();
	void SetOwner(std::shared_ptr<Player> player);
	std::shared_ptr<Player> GetOwner();

	void Destroy();
private:
	int m_goldcost;
	BuildingType m_type;
	std::string m_name;
	std::shared_ptr<Player> owner;

};

