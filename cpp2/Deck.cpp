#include "stdafx.h"
#include "Deck.h"
#include "BuildingType.h"
#include <string>
#include "MurdererCard.h"
#include "ThiefCard.h"
#include "MageCard.h"
#include "KingCard.h"
#include "PreacherCard.h"
#include "MerchantCard.h"
#include "ArchitectCard.h"
#include "CondotierreCard.h"
#include "BuildCard.h"
#include "CommandController.h"

#include <algorithm>
#include <time.h>
Deck::Deck(std::shared_ptr<CommandController> controller)
{	
	io = std::make_shared<FileIO>();
	m_cards = std::vector<std::shared_ptr<BuildCard>>();
	m_playerCard = std::vector<std::shared_ptr<PlayerCard>>();;
	m_playerCardDeck = std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>>(new std::vector<std::shared_ptr<PlayerCard>>(m_playerCard));

	m_usedcards = std::vector<std::shared_ptr<BuildCard>>();

	rolesRegistery = std::unordered_map<string, std::shared_ptr<PlayerCard>>
	{
		{ "murderer", std::make_shared<MurdererCard>(controller) },
		{ "thief", std::make_shared<ThiefCard>(controller) },
		{ "mage", std::make_shared<MageCard>(controller) },
		{ "king", std::make_shared<KingCard>(controller) },
		{ "preacher", std::make_shared<PreacherCard>(controller) },
		{ "merchant", std::make_shared<MerchantCard>(controller) },
		{ "architect", std::make_shared<ArchitectCard>(controller) },
		{ "condotierre", std::make_shared<CondotierreCard>(controller) },
	};

	buildingRegistery = std::unordered_map<string, std::shared_ptr<BuildCard>>
	{
		{ "Landgoed", std::make_shared<BuildCard>(3, BuildingType::Koning,std::string("landgoed")) },
		{ "Kasteel", std::make_shared<BuildCard>(4, BuildingType::Koning, std::string("kasteel")) },
		{ "Paleis", std::make_shared<BuildCard>(5, BuildingType::Koning, std::string("palijs")) },

		{ "Taveerne", std::make_shared<BuildCard>(1, BuildingType::Koopman, std::string("taveerne")) },
		{ "Winkels", std::make_shared<BuildCard>(2, BuildingType::Koopman, std::string("winkels")) },
		{ "Markt", std::make_shared<BuildCard>(2, BuildingType::Koopman, std::string("markt")) },
		{ "Handelshuis", std::make_shared<BuildCard>(3, BuildingType::Koopman, std::string("handelshuis")) },
		{ "Haven", std::make_shared<BuildCard>(4, BuildingType::Koopman, std::string("haven")) },
		{ "Raadhuis", std::make_shared<BuildCard>(5, BuildingType::Koopman, std::string("raadhuis")) },

		{ "Tempel", std::make_shared<BuildCard>(1, BuildingType::Prediker, std::string("tempel")) },
		{ "Kerk", std::make_shared<BuildCard>(2, BuildingType::Prediker, std::string("kerk")) },
		{ "Klooster", std::make_shared<BuildCard>(3, BuildingType::Prediker, std::string("klooster")) },
		{ "Kathedraal", std::make_shared<BuildCard>(5, BuildingType::Prediker, std::string("kathedraal")) },

		{ "Wachttoren", std::make_shared<BuildCard>(1, BuildingType::Condotierre, std::string("wachttoren")) },
		{ "Gevangenis", std::make_shared<BuildCard>(2, BuildingType::Condotierre, std::string("gevangenis")) },
		{ "Toernooiveld", std::make_shared<BuildCard>(3, BuildingType::Condotierre, std::string("tournooiveld")) },
		{ "Burcht", std::make_shared<BuildCard>(5, BuildingType::Condotierre, std::string("burcht")) },
	};

	std::vector<string> roles = io->LoadRoles();
	std::vector<std::vector<string>> buildings = io->LoadBuildings();

	for each (string role in roles)
	{
		CreateRoles(role);
	}

	for each (std::vector<string> building in buildings)
	{
		CreateBuildings(building);
	}

	ShuffleBuildDeck();
	ShufflePlayerCards();

	goldPieces = 30;
}


Deck::~Deck()
{
}

void Deck::CreateRoles(string role)
{
	m_playerCard.push_back(rolesRegistery.at(role).get()->EmptyClone());
}

void Deck::CreateBuildings(vector<string> building)
{
	m_cards.push_back(buildingRegistery.at(building[0]).get()->EmptyClone());
}

std::vector<std::shared_ptr<BuildCard>> Deck::DrawCards(int ammount){
	std::vector<std::shared_ptr<BuildCard>> card = std::vector<std::shared_ptr<BuildCard>>();
	for (int x = 0; x < ammount; x++){
		card.push_back(m_cards.back());
		m_cards.pop_back();
	}
	return card;
		
}

void Deck::AddUsedCard(std::shared_ptr<BuildCard> card)
{
	m_usedcards.push_back(card);
}

void Deck::AddGoldPieces(int amount)
{
	goldPieces += amount;
}

int Deck::TakeGoldPieces(int amount)
{
	if (goldPieces > 0)
		goldPieces -= amount;
	else
		amount = 0;

	return amount;
}

int Deck::GetGoldAmount()
{
	return goldPieces;
}

std::string Deck::GetRemainingPlayerCardsString(){
	std::string string = "";
	if (m_playerCardDeck->size() > 0){
		for (int i = 0; i < m_playerCardDeck->size(); i++)
		{
			string = string + m_playerCardDeck->at(i)->GetName() + "\r\n";
		}
	}
	else{
		string = "no Remaining Player Cards";
	}
	return string;

}

std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>> Deck::GetRemainingPlayerCards(){
	return m_playerCardDeck;
}

std::vector<std::shared_ptr<PlayerCard>> Deck::GetAllPlayerCards()
{
	return m_playerCard;
}
void Deck::RoundReset(){
	m_playerCardDeck = std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>>(new std::vector<std::shared_ptr<PlayerCard>>(m_playerCard));
	ShufflePlayerCards();
}
std::shared_ptr<PlayerCard> Deck::RemoveCard(int x){
	if (x < m_playerCardDeck->size()){
		std::shared_ptr<PlayerCard> card = m_playerCardDeck->at(x);
		m_playerCardDeck->erase(m_playerCardDeck->begin() + x);
		return card;
	}
	else{
		return nullptr;
	}
}

void Deck::ShuffleBuildDeck(){
	srand(time(0));
	std::random_shuffle(m_cards.begin(), m_cards.end());
}

void Deck::ShufflePlayerCards(){
	srand(time(0));
	std::random_shuffle(m_playerCardDeck->begin(), m_playerCardDeck->end());
}