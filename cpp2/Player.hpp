//
//  Player.hpp
//  socketexample
//
//  Created by Bob Polis on 23-11-15.
//  Copyright © 2015 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include "BuildCard.h"
#include <string>
#include <vector>
#include <memory>
#include "Socket.h"
class Player {
public:
	Player() {}
	Player(const std::string& name, std::shared_ptr<Socket> client) : m_name{ name } ,m_client{client} {}
	
	std::string get_name() const { return m_name; }
	void set_name(const std::string& new_name) { m_name = new_name; }
	bool get_turn(){ return myTurn; }
	void set_turn(const bool& turn){ myTurn = turn; }
	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> get_buildcards(){ return m_cards; }
	std::shared_ptr<Socket> get_client(){ return m_client; }
private:
	std::string m_name;
	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> m_cards;
	std::shared_ptr<Socket> m_client;
	bool myTurn;
};

#endif /* Player_hpp */
