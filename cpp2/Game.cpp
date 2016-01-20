#include "stdafx.h"
#include "Game.h"
#include "PlayerCard.h"

Game::Game(std::shared_ptr<CommandController> controller)
{
	m_queplayers = std::queue<std::shared_ptr<Player>>();
	m_players = std::set<std::shared_ptr<Player>>();
	deck = std::shared_ptr<Deck>(new Deck(controller));
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
	//deck.shuffle();
	SendMessageToAll("Starting new game \r\n");
	m_queplayers.front().get()->set_turn(true);

	SendMessageToAll("Removing one random Charactercard from the deck \r\n");

	m_queplayers.front()->get_client()->write("Playercard remove is " + deck->RemoveCard(0)->GetName());
	SendMessageToAll("Player " + m_queplayers.front()->get_name() + " please select a Character card\r\n");

	m_queplayers.front()->get_client()->write("Remaining card : " + deck->GetRemainingPlayerCardsString());

}
void Game::ChooseCharater(){

	



}
void Game::EndTurn(){
	
	std::shared_ptr<Player> player = m_queplayers.front();
	player->set_turn(false);
	m_queplayers.pop();
	m_queplayers.push(player);
	m_queplayers.front()->set_turn(true);
	
	if (characterPhase){
		SendMessageToAll("Player : " + m_queplayers.front().get()->get_name() + " please remove one Character card\r\n");
	}
	else{
		SendMessageToAll("Player : " + m_queplayers.front().get()->get_name() + " its your turn \r\n");
	}


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