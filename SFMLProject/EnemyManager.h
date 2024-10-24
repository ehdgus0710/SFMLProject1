#pragma once

class Enemy;

class EnemyManager : public Singleton<EnemyManager>
{
	friend Singleton<EnemyManager>;
private:
	std::unordered_map<int, Enemy*> enemyMap;

	float			respawnTime;
	float			currentCreateTime;
	int				respawnCount;
	sf::Vector2f	createPosition;
	int				createWidthRange;

	GameObject*		player;
	int				currentCreateIndex;
	int				createEnemyCount;

public:
	void SetCreateInfo(const sf::Vector2f& createPos, int createWidthRange, float respawnTime, int createCount);
	void SetRespawnCount(int count);
	void SetRespawnTime(float time);

	void RespwanEnemy();
	void CreateEnemy(const std::string& name, int count);
	void SetDisabledEnemy(const std::string& name);
	Enemy* GetMonsterToAEnabled();

	void SetPlayer(GameObject* player);
	GameObject* GetPlayer() { return player; }

public:
	void Init();
	void Release();
	void Update(float deltaTime);

protected:
	EnemyManager();
	virtual ~EnemyManager() = default;
	EnemyManager(const EnemyManager&) = delete;
	EnemyManager& operator=(const EnemyManager&) = delete;
};

