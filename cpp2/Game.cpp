#include "stdafx.h"
#include "Game.h"


Game::Game()
{
	m_queplayers = std::queue<std::shared_ptr<Player>>();
	m_players = std::set<std::shared_ptr<Player>>();

	
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
	
}
void Game::SendMessageToAll(std::string message){
	for (auto f : m_players) {
		f.get()->get_client()->write(message + "\r\n");
	}
	
}