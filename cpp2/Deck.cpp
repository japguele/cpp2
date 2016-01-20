#include "stdafx.h"
#include "Deck.h"
#include "BuildingType.h"
#include <string>
#include "PlayerCard.h"
#include "CommandController.h"
Deck::Deck(std::shared_ptr<CommandController> controller)
{	
	m_cards = std::vector<std::shared_ptr<BuildCard>>();

	m_playerCardDeck = std::shared_ptr<std::vector<std::shared_ptr<PlayerCard>>>(new std::vector<std::shared_ptr<PlayerCard>>());

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
	
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
		m_playerCardDeck->push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
	//m_playerCardDeck.push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));	
//	m_playerCardDeck.push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
	//m_playerCardDeck.push_back(std::shared_ptr<PlayerCard>(new PlayerCard(controller)));
	
	


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
std::string Deck::GetRemainingPlayerCardsString(){
	std::string string = "";
	if (m_playerCardDeck->size() > 0){
		for each (std::shared_ptr<PlayerCard> card in *m_playerCardDeck)
		{
			string = string + card->GetName() + "\r\n";

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