#include "stdafx.h"
#include "Deck.h"
#include "BuildingType.h"
#include <string>

Deck::Deck()
{	
	m_cards = std::vector<std::shared_ptr<BuildCard>>();

	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(3, BuildingType::Koning,std::string("landgoed"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(4, BuildingType::Koning, std::string("kasteel"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(5, BuildingType::Koning, std::string("palijs"))));

	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(1, BuildingType::Koopman, std::string("taveerne"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(2, BuildingType::Koopman, std::string("winkels"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(2, BuildingType::Koopman, std::string("markt"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(3, BuildingType::Koopman, std::string("handelshuis"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(4, BuildingType::Koopman, std::string("haven"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(5, BuildingType::Koopman, std::string("raadhuis"))));

	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(1, BuildingType::Prediker, std::string("tempel"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(2, BuildingType::Prediker, std::string("kerk"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(3, BuildingType::Prediker, std::string("klooster"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(5, BuildingType::Prediker, std::string("kathedraal"))));

	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(1, BuildingType::Condotierre, std::string("wachttoren"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(2, BuildingType::Condotierre, std::string("gevangenis"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(3, BuildingType::Condotierre, std::string("tournooiveld"))));
	m_cards.push_back(std::shared_ptr<BuildCard>(new BuildCard(5, BuildingType::Condotierre, std::string("burcht"))));
}


Deck::~Deck()
{
}

std::vector<std::shared_ptr<BuildCard>> Deck::DrawCards(int ammount){
	std::vector<std::shared_ptr<BuildCard>> card = std::vector<std::shared_ptr<BuildCard>>();
	for (int x = 0; x < ammount; x++){
		card.push_back(m_cards.back());
		m_cards.pop_back();
	}
	return card;
		
}

void Deck::AddGoldPieces(int amount)
{
	goldPieces += amount;
}

int Deck::TakeGoldPieces(int amount)
{
	goldPieces -= amount;
	return amount;
}

int Deck::GetGoldAmount()
{
	return goldPieces;
}