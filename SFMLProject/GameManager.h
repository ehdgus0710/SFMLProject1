#pragma once

class Player;

class GameManager : public Singleton<GameManager>
{
	friend Singleton<GameManager>;
private:
	Player* player;

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

protected:
	GameManager();
	virtual ~GameManager() = default;
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
};

