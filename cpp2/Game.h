#pragma once
#include  <queue>
#include <memory>
#include "Player.hpp"
#include <set>
#include "Deck.h"
#include "CommandController.h"
#include "Phase.h"
class Game
{
public:
	static Game& getInstance()
	{
		static Game    instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
	
	void Init(std::shared_ptr<CommandController> controller);
	~Game();
	void JoinGame(std::shared_ptr < Player > player);
	const std::vector<std::shared_ptr<Player>> GetPlayers();
	void SendMessageToAll(const std::string message);
	bool Started();
	void StartNewGame();
	void ChooseCharater();
	void EndTurn();
	void EndGame();
	void EndGameTurn();
	std::shared_ptr<Deck> GetDeck();
	std::shared_ptr<Player> GetCurrentPlayer();
	bool CharacterPhase();
	void ShuffleAcordingToPlayerCards();
	void Preparation();
	Phase GetPhase();
	void ResetKing();
private:
	Game(){};
	std::shared_ptr<Deck> deck;
	bool started = false;
	bool characterPhase = false;
	Phase phase = Phase::CharacterPhase;

	std::queue<std::shared_ptr<PlayerCard>> m_queplayers;
	std::vector<std::shared_ptr<Player>> m_players;

	std::shared_ptr<Player> currentPlayer;
};