#pragma once
#include  <queue>
#include <memory>
#include "Player.hpp"
#include <set>
class Game
{
public:
	Game();
	~Game();
	void JoinGame(std::shared_ptr < Player > player );
	const std::set<std::shared_ptr<Player>> GetPlayers();
	void SendMessageToAll(const std::string message);
private:
	std::queue<std::shared_ptr<Player>> m_queplayers;
	std::set<std::shared_ptr<Player>> m_players;


};

