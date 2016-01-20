//
//  ClientCommand.h
//  socketexample
//
//  Created by Bob Polis on 27/11/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#ifndef __socketexample__ClientCommand__
#define __socketexample__ClientCommand__

#include <string>
#include <memory>

#include <sstream> 
class Player;
class Socket;

class ClientCommand {
public:
	ClientCommand(const std::string& cmd, std::shared_ptr<Socket> client, std::shared_ptr<Player> player)
		: cmd{ cmd }, client{ client }, player{ player }, strings{ std::vector<std::string>() }
	{		
			std::istringstream iss(cmd);
			std::string word;
			while (iss >> word) {
				/* do stuff with word */
				strings.push_back(word);
			}			
	}

    std::string get_cmd() const { return cmd; }
	std::shared_ptr<Socket> get_client() const { return client; }
    std::shared_ptr<Player> get_player() const { return player; }
	std::vector<std::string> get_strings() const { return strings; }

private:
    std::string cmd;
	std::shared_ptr<Socket> client;
    std::shared_ptr<Player> player;
	std::vector<std::string> strings;
};

#endif /* defined(__socketexample__ClientCommand__) */
