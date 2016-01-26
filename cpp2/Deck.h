#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "PlayerType.h"
#include "FileIO.h"

class PlayerCard;
class BuildCard;
class CommandController;
class Deck
{
public:
	Deck(std::shared_ptr<CommandController> controller);
	~Deck();

	void AddUsedCard(std::shared_ptr<BuildCard> card);

	int TakeGoldPieces(int amount);
	void AddGoldPieces(int amount);
	int GetGoldAmount();

	std::vector<std::shared_ptr<PlayerCard>> GetAllPlayerCards();
	std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> GetRemainingPlayerCards();
	std::vector<std::shared_ptr<BuildCard>> DrawCards(int amount);
	std::shared_ptr<PlayerCard> RemoveCard(int x);
	std::string GetRemainingPlayerCardsString();
	void RoundReset();
	void ShuffleBuildDeck();
	void ShufflePlayerCards();

	void CreateRoles(string role);
	void CreateBuildings(vector<string> building);
private:
	std::unordered_map<string, std::shared_ptr<PlayerCard>> rolesRegistery;
	std::unordered_map<string, std::shared_ptr<BuildCard>> buildingRegistery;

	std::vector<std::shared_ptr<BuildCard>> m_cards;
	std::vector<std::shared_ptr<BuildCard>> m_usedcards;
	std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> m_playerCardDeck;
	std::vector<std::shared_ptr<PlayerCard>> m_playerCard;
	int goldPieces;

	std::shared_ptr<FileIO> io;
};

