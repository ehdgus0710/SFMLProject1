#pragma once
class GameManager : public Singleton<GameManager>
{
	friend Singleton<GameManager>;
private:
	bool reStart;

public:
	void SetReStart(bool reStart);
	bool GetReStart() { return reStart; }

public:
	void Release();

protected:
	GameManager();
	virtual ~GameManager() = default;
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
};

