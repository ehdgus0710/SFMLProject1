#pragma once

class Player;

class GameManager : public Singleton<GameManager>
{
	friend Singleton<GameManager>;
private:
	Player* player;

	sf::Text		victorytext;
	sf::Text		gameoverText;
	sf::Text		restartText;

	int score;

	bool isGameOver;
	bool isClear;
public:
	void SetPlayer(Player* player);
	Player* GetPlayer() { return player; }

	void AddScore(int point) { score += point; }
	int GetScore() { return score; }

	void OnGameOver();
	void OnClear();

	bool IsGameOver() { return isGameOver; }
	bool IsClear() { return isClear; }

public:
	void Init();
	void Release();
	void Render(sf::RenderWindow& window);


protected:
	GameManager();
	virtual ~GameManager() = default;
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
};

