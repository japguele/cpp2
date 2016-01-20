#pragma once
#include "BuildCard.h"
#include "PlayerType.h"
#include <vector>
#include <memory>

class PlayerCard;
class CommandController;
class Deck
{
public:
	Deck(std::shared_ptr<CommandController> controller);
	~Deck();

	std::shared_ptr<std::vector<std::shared_ptr<BuildCard>>> DrawCards(int ammount);
	int TakeGoldPieces(int amount);
	void AddGoldPieces(int amount);
	int GetGoldAmount();

	std::vector<std::shared_ptr<PlayerCard>> GetAllPlayerCards();
	std::vector<std::shared_ptr<PlayerCard>> GetRemainingPlayerCards();
	std::shared_ptr<PlayerCard> RemoveCard(int x);
	std::string GetRemainingPlayerCardsString();


private:
std::vector<std::shared_ptr<BuildCard>> m_cards;
std::vector<std::shared_ptr<PlayerCard>> m_playerCardDeck;
std::vector<std::shared_ptr<PlayerCard>> m_playerCard;
int goldPieces;
};

