#include "stdafx.h"
#include "Game.h"
#include "PlayerCard.h"
#include <unordered_map>

Game::Game(std::shared_ptr<CommandController> controller)
{
	deck = std::shared_ptr<Deck>(new Deck(controller));
	m_queplayers = std::queue<std::shared_ptr<Player>>();
	m_players = std::set<std::shared_ptr<Player>>();
	phase = Phase::SetupPhase;
}


Game::~Game()
{

}

const std::set<std::shared_ptr<Player>> Game::GetPlayers(){
	return m_players;
}

void Game::JoinGame(std::shared_ptr < Player > player){
	std::cout << "heyo";  
	
	if (m_players.find(player) == m_players.end()){
		
		m_queplayers.push(player);
		m_players.insert(player);
		SendMessageToAll("Player " + player->get_name() + " joined the game \n");
	}
	if (m_players.size() > 1){
		StartNewGame();
	}
}

void Game::StartNewGame(){	
	started = true;

	characterPhase = true;
	phase = Phase::CharacterPhase;

	//deck.shuffle();
	SendMessageToAll("Starting new game \r\n");
	m_queplayers.front().get()->set_turn(true);

	SendMessageToAll("Removing one random Charactercard from the deck \r\n");

	m_queplayers.front()->get_client()->write(deck->RemoveCard(0)->GetName() + "has been removed\r\n");
	SendMessageToAll("Player " + m_queplayers.front()->get_name() + " please select a Character card\r\n");

	m_queplayers.front()->get_client()->write("Remaining card : \r\n" + deck->GetRemainingPlayerCardsString());

}
void Game::ChooseCharater(){
}

void Game::ShuffleAcordingToPlayerCards(){
	//TODO sort to bij rules of player volgorde

}
void Game::EndTurn(){
	
	std::shared_ptr<Player> player = m_queplayers.front();
	player->set_turn(false);
	m_queplayers.pop();
	m_queplayers.push(player);
	m_queplayers.front()->set_turn(true);
	
	if (phase = Phase::CharacterPhase){
		if (deck->GetRemainingPlayerCards()->size() < 1){
			SendMessageToAll("All Playercards have been selected\r\n");			

			ShuffleAcordingToPlayerCards();
			characterPhase = false;
			phase = Phase::ChoicePhase;

			SendMessageToAll("Player " + m_queplayers.front().get()->get_name() + " its your turn \r\n");
			m_queplayers.front().get()->Print(std::shared_ptr<Game>(this));
		}
		else{
			SendMessageToAll("Player " + m_queplayers.front().get()->get_name() + " please remove one Character card\r\n");
			m_queplayers.front().get()->get_client()->write("Remaining cards : \r\n" + deck->GetRemainingPlayerCardsString());
		}
	}

	if (phase = Phase::ChoicePhase)
	{
		SendMessageToAll("Player " + m_queplayers.front().get()->get_name() + " its your turn \r\n");
	}
}

void Game::Preparation()
{
	for each (auto player in m_players)
	{
		int goldAmount = 2;
		int cardAmount = 4;

		player->AddGoldAmount(deck->TakeGoldPieces(goldAmount));
		
		player->add_buildcards(deck->DrawCards(cardAmount));
	}
	SendMessageToAll("All players have been dealt 2 goldpieces andn 4 building cards\r\n");
}

void Game::EndGame()
{
	std::unordered_map<std::string, int> scores;

	for each (auto player in m_players)
	{
		int score = 0;
		bool hasKoning = false;
		bool hasKoopman = false;
		bool hasPrediker = false;
		bool hasCondotierre = false;
		bool hasKeuze = false;

		auto buildings = player->get_buildings();
		for (int i = 0; i < buildings->size(); i++)
		{
			score += buildings->at(i)->get_gold();

			switch (buildings->at(i)->get_buildingtype())
			{
				case BuildingType::Condotierre :
					hasCondotierre = true;
					break;
				case BuildingType::Keuze:
					hasKeuze = true;
					break;
				case BuildingType::Koning:
					hasKoning = true;
					break;
				case BuildingType::Koopman:
					hasKoopman = true;
					break;
				case BuildingType::Prediker:
					hasPrediker = true;
					break;
				default:
					break;
			}
		}

		if (hasKoning && hasKoopman && hasPrediker && hasCondotierre && hasKeuze)
			score += 3;

		if (player->get_name() == m_queplayers.back()->get_name())
		{
			if (player->get_buildings()->size() >= 8)
				score += 4;
		}
		else
		{
			if (player->get_buildings()->size() >= 8)
				score += 2;
		}

		scores[player->get_name()] = score;
	}

	std::string winnername = "Error no name";
	int highestScore = 0;

	for each (auto var in scores)
	{
		if (var.second > highestScore)
		{
			highestScore = var.second;
			winnername = var.first;
		}
	}

	SendMessageToAll("Congratulations player " + winnername);
	SendMessageToAll("You Won!");
}

void Game::SendMessageToAll(std::string message){
	for (auto f : m_players) {
		f.get()->get_client()->write(message + "\r\n");
	}
	
}
bool Game::Started(){
	return started;
}

std::shared_ptr<Deck> Game::GetDeck()
{
	return deck;
}

std::shared_ptr<Player> Game::GetCurrentPlayer()
{
	return currentPlayer;
}

bool Game::CharacterPhase(){
	return characterPhase;
}