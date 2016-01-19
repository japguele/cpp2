#pragma once
#include  <queue>
#include <memory>
#include "Player.hpp"
#include <set>
#include "Deck.h"
#include "CommandController.h"
class Game
{
public:
	Game(std::shared_ptr<CommandController> controller);
	~Game();
	void JoinGame(std::shared_ptr < Player > player );
	const std::set<std::shared_ptr<Player>> GetPlayers();
	void SendMessageToAll(const std::string message);
	bool Started();
	void StartNewGame();
	void ChooseCharater();
	void EndTurn();
	std::shared_ptr<Deck> GetDeck();
private:
	std::shared_ptr<Deck> deck;
	bool started = false;
	bool characterPhase = false;

	std::queue<std::shared_ptr<Player>> m_queplayers;
	std::set<std::shared_ptr<Player>> m_players;
	

};

