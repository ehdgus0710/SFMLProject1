#include "stdafx.h"
#include "GameManager.h"

GameManager::GameManager()
	: score(0)
	, player(nullptr)
	, isGameOver(false)
	, isClear(false)
{
}

void GameManager::OnGameOver()
{
	TimeManager::GetInstance().SetTimeScale(0.f);
	isGameOver = true;
}

void GameManager::OnClear()
{
	TimeManager::GetInstance().SetTimeScale(0.f);
	isClear = true;
}

void GameManager::Init()
{
	score = 0;
	isGameOver = false;
	isClear = false;

	victorytext.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));
	victorytext.setString("! VICTORY !");
	victorytext.setFillColor(sf::Color::Yellow);
	victorytext.setCharacterSize(200);
	victorytext.setPosition(1150.f * 0.5f, 1080.f * 0.5f - 100.f);
	victorytext.setOrigin(100.f, 100.f);

	gameoverText.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));
	gameoverText.setString("GAME OVER");
	gameoverText.setFillColor(sf::Color::Red);
	gameoverText.setCharacterSize(200);
	gameoverText.setPosition(1150.f * 0.5f, 1080.f * 0.5f - 100.f);
	gameoverText.setOrigin(100.f, 100.f);

	restartText.setFont(ResourcesManager<sf::Font>::GetInstance().Get("KOMIKAP"));
	restartText.setString("GAME RESTART : Click SpaceBar");
	restartText.setFillColor(sf::Color::Black);
	restartText.setCharacterSize(100);
	restartText.setOrigin(50.f, 50.f);
	restartText.setPosition(500.f * 0.5f, 1080.f * 0.5f + 100.f);

}

void GameManager::Release()
{
}

void GameManager::Render(sf::RenderWindow& window)
{
	if (isClear)
	{
		window.draw(victorytext);
		window.draw(restartText);
	}
	else if (isGameOver)
	{
		window.draw(gameoverText);
		window.draw(restartText);
	}
}

void GameManager::SetPlayer(Player* player)
{
	this->player = player;
}