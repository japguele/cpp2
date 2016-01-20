#pragma once
#include <vector>
#include <memory>
<<<<<<< HEAD
#include "PlayerType.h"
=======
#include <unordered_map>
>>>>>>> refs/remotes/origin/master

class PlayerCard;
class BuildCard;
class CommandController;
class Deck
{
public:
	Deck(std::shared_ptr<CommandController> controller);
	~Deck();

	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> DrawCards(int ammount);
	void AddUsedCard(std::shared_ptr<BuildCard> card);

	int TakeGoldPieces(int amount);
	void AddGoldPieces(int amount);
	int GetGoldAmount();

	std::vector<std::shared_ptr<PlayerCard>> GetAllPlayerCards();
	std::vector<std::shared_ptr<PlayerCard>> GetRemainingPlayerCards();
	std::vector<std::shared_ptr<BuildCard>> DrawCards(int ammount);
	std::shared_ptr<PlayerCard> RemoveCard(int x);
	std::string GetRemainingPlayerCardsString();


private:
	std::vector<std::shared_ptr<BuildCard>> m_cards;
	std::vector<std::shared_ptr<BuildCard>> m_usedcards;
	std::vector<std::shared_ptr<PlayerCard>> m_playerCardDeck;
	std::vector<std::shared_ptr<PlayerCard>> m_playerCard;
	int goldPieces;
};

