//
//  Player.cpp
//  socketexample
//
//  Created by Bob Polis on 23-11-15.
//  Copyright © 2015 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include "Player.hpp"
#include "PlayerCard.h"
#include "Game.h"
using namespace std;

void Player::Print()
{
	std::string message;

	std::map <BuildingType, std::string> enumMap =
	{
		{ Koning, "king" },
		{ Prediker, "preacher" },
		{ Koopman, "merchant" },
		{ Condotierre, "condotierre" },
		{ Keuze, "keuze" }
	};

	message += "You are a: ";
	for (int i = 0; i < currentRoles.size(); i++)
	{
		message += currentRoles.at(i)->GetName();
		
		if (i < currentRoles.size() - 1)
			message += ", ";
	}
	message += "\r\n";

	message += "Gold: " + std::to_string(goldPieces);
	message += "\r\n\n";

	message += "Buildings: \r\n";
	for (int i = 0; i < buildings->size(); i++)
	{
		std::map <BuildingType, std::string>::const_iterator iValue = enumMap.find(buildings->at(i)->get_buildingtype());

		message += buildings->at(i)->get_name() + " (";
		message += iValue->second + ", ";
		message += std::to_string(buildings->at(i)->get_gold()) + "):\r\n";
	}
	message += "\r\n\n";

	message += "Hand: \r\n";
	for (int i = 0; i < m_cards->size(); i++)
	{
		std::map <BuildingType, std::string>::const_iterator iValue = enumMap.find(m_cards->at(i)->get_buildingtype());

		message += m_cards->at(i)->get_name() + " (";		
		message += iValue->second + ", ";
		message += std::to_string(m_cards->at(i)->get_gold()) + "):\r\n";
	}	
	message += "\r\n\n";

	message += "Make a choice: \r\n";
	message += "\"gold\": Receive 2 gold pieces \r\n";
	message += "\"draw\": Draw 2 building cards. Choose one and discard the other \r\n";
	message += "\"ability\" + <role>: Use the ability of the selected role \r\n";
	message += "\r\n\n";

	get_client()->write(message);
}