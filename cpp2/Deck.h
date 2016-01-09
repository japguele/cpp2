#pragma once
#include "BuildCard.h"
#include <vector>
#include <memory>
class Deck
{
public:
	Deck();
	~Deck();

	std::vector<std::shared_ptr<BuildCard>> DrawCards(int ammount);
private:
std::vector<std::shared_ptr<BuildCard>> m_cards;
};

