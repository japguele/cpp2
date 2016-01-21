//
//  Player.hpp
//  socketexample
//
//  Created by Bob Polis on 23-11-15.
//  Copyright © 2015 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include <string>
#include <vector>
#include <memory>
#include "Socket.h"
#include "BuildCard.h"

class PlayerCard;
class Player {
public:
	Player() {}
	Player(const std::string& name, std::shared_ptr<Socket> client) : m_name{ name }, m_client{ client }, goldPieces{ 0 }, myTurn{ false }, currentRoles{ std::vector<std::shared_ptr<PlayerCard>>() }, m_cards{ new std::vector<std::shared_ptr<BuildCard>> }, buildings { new std::vector<std::shared_ptr<BuildCard>> } {}
	
	std::string get_name() const { return m_name; }
	void set_name(const std::string& new_name) { m_name = new_name; }
	bool get_turn(){ return myTurn; }
	void set_turn(const bool& turn){ myTurn = turn; }
	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> get_buildcards(){ return m_cards; }
	void add_buildcards(std::vector<std::shared_ptr<BuildCard>> cards) {
		for (int i = 0; i < cards.size(); i++)
		{
			m_cards->push_back(cards.at(i));
		}
	}
	std::shared_ptr<BuildCard> remove_buildcard(std::shared_ptr<BuildCard> card) {
		std::shared_ptr<BuildCard> rCard = nullptr;

		for (int i = 0; i < m_cards->size(); i++)
		{
			if (m_cards->at(i)->get_name() == card->get_name())
			{
				rCard = m_cards->at(i);
				m_cards->erase(m_cards->begin() + i);
			}
		}

		return rCard;
	}

	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> get_buildings() { return buildings; }
	void add_buildings(std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> cards) {
		for (int i = 0; i < cards->size(); i++)
		{
			buildings->push_back(cards->at(i));
		}
	}

	void add_building(std::shared_ptr<BuildCard> card) {
			buildings->push_back(card);
	}

	std::shared_ptr<BuildCard> remove_building(std::shared_ptr<BuildCard> card) {
		std::shared_ptr<BuildCard> rCard = nullptr;

		for (int i = 0; i < buildings->size(); i++)
		{
			if (buildings->at(i)->get_name() == card->get_name())
			{
				rCard = buildings->at(i);
				buildings->erase(buildings->begin() + i);
			}
		}

		return rCard;
	}

	void set_buildcards(std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> cards) { m_cards = cards; }

	std::shared_ptr<Socket> get_client(){ return m_client; }

	void SetCurrentRoles(std::vector<std::shared_ptr<PlayerCard>> new_roles) { currentRoles = new_roles; }
	std::vector<std::shared_ptr<PlayerCard>> GetCurrentRoles() { return currentRoles;  }

	void AddGoldAmount(int amount) { goldPieces = goldPieces + amount; }
	void SetGoldAmount(int amount) { goldPieces = amount; }
	int GetGoldAmount() { return goldPieces;  }

	void Print(std::shared_ptr<Game> game);

private:
	std::string m_name;
	std::vector<std::shared_ptr<PlayerCard>> currentRoles;
	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> m_cards;
	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> buildings;
	std::shared_ptr<Socket> m_client;

	int goldPieces;
	bool myTurn;
};

#endif /* Player_hpp */
