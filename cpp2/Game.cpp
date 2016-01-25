#include "stdafx.h"
#include "Game.h"
#include "PlayerCard.h"
#include <unordered_map>
#include <algorithm>
Game::Game()
{
}

void Game::Init(std::shared_ptr<CommandController> controller)
{
	deck = std::shared_ptr<Deck>(new Deck(controller));
	m_queplayers = std::queue<std::shared_ptr<PlayerCard>>();
	m_players = std::vector<std::shared_ptr<Player>>();
	phase = Phase::SetupPhase;
}

Game::~Game()
{
	printf("Game Destroyed");
}

std::shared_ptr<Game> Game::GetInstance()
{
	if(!instance)
		instance = std::make_shared<Game>();

	return instance;
}

const std::vector<std::shared_ptr<Player>> Game::GetPlayers(){
	return m_players;
}

void Game::JoinGame(std::shared_ptr < Player > player){
	std::cout << "heyo";  
	if (!started){
		if (!(std::find(m_players.begin(), m_players.end(), player) != m_players.end())){		

			//m_queplayers.push(player);
			m_players.push_back(player);
			SendMessageToAll("Player " + player->get_name() + " joined the game \n");
		}
		else{
			player->get_client()->write("You allready Joined");
		}
		if (m_players.size() > 1){
			StartNewGame();
		}
	}
	else{
		player->get_client()->write("Games has allready started");
	}
}

void Game::StartNewGame(){	
	started = true;

	characterPhase = true;
	phase = Phase::CharacterPhase;

	//deck.shuffle();
	SendMessageToAll("Starting new game \r\n");
	m_players.at(0)->set_turn(true);

	SendMessageToAll("Removing one random Charactercard from the deck \r\n");

	m_players.at(0)->get_client()->write(deck->RemoveCard(0)->GetName() + "has been removed\r\n");
	SendMessageToAll("Player " + m_players.at(0)->get_name() + " please select a Character card\r\n");

	m_players.at(0)->get_client()->write("Remaining card : \r\n" + deck->GetRemainingPlayerCardsString());

}
void Game::ChooseCharater(){
}

void Game::ShuffleAcordingToPlayerCards(){
	//TODO sort to bij rules of player volgorde

}


void Game::EndTurn() {
	if (phase == Phase::CharacterPhase) {
		for (auto it = m_players.begin(); it != m_players.end(); ++it) {
			if (it->get()->get_turn()) {
				it->get()->set_turn(false);

			}
			else {
				//TODO does not work more then 2 players
				it->get()->set_turn(true);
			}
			/* std::cout << *it; ... */
		}

		std::shared_ptr<Player> p;

		for each(auto player in m_players) {
			if (player->get_turn()) {
				p = player;
			}
		}

		if (deck->GetRemainingPlayerCards()->size() < 1) {
			SendMessageToAll("All Playercards have been selected\r\n");

			ShuffleAcordingToPlayerCards();
			
			characterPhase = false;
			phase = Phase::GamePhase;

			for each (std::shared_ptr<PlayerCard> v in deck->GetAllPlayerCards()) {
				m_queplayers.push(v);
			}

			Preparation();
		}
		else {
			SendMessageToAll("Player " + p->get_name() + " please remove one Character card\r\n");
			p->get_client()->write("Remaining cards : \r\n" + deck->GetRemainingPlayerCardsString());
		}
	}
	if (phase == Phase::GamePhase)
	{
		for each (auto player in m_players)
		{
			player->set_turn(false);
		}
		m_queplayers.pop();
		std::shared_ptr<PlayerCard> currentRol = m_queplayers.front();

		while ((currentRol->IsDead() || currentRol->GetOwner() == nullptr) && m_queplayers.size() >= 0) {
			m_queplayers.pop();
			currentRol = m_queplayers.front();
		}
		if (currentRol->IsDead() || m_queplayers.size() == 0 || currentRol->GetOwner() == nullptr) {

			EndGameTurn();

			//TODO start new round
		}
		else {
			currentRol->GetOwner()->set_turn(true);
			SendMessageToAll("Player " + currentRol->GetOwner()->get_name() + " its your turn \r\n");
			currentRol->GetOwner()->Print();
		}
	}
}

void Game::EndGameTurn(){
	for each (std::shared_ptr<Player> p in m_players){
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

		if (player->get_name() == m_queplayers.front()->GetOwner()->get_name())
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